package main

import (
	"fmt"
	"log"
	"os"
	"path/filepath"
	"runtime"

	"github.com/magefile/mage/sh"
)

var (
	tmpDir    string
	goldenDir string
	apisDir   string
	binDir    string
	tplDir    string
	apigear   string
	input     string
)

func init() {
	wd, err := os.Getwd()
	must(err)
	binDir = filepath.Join(wd, "bin")
	tmpDir = filepath.Join(wd, "tmp")
	goldenDir = filepath.Join(wd, "goldenmaster")
	apisDir = filepath.Join(wd, "testbed-apis")
	tplDir = filepath.Join(wd)
	apigear = filepath.Join(binDir, "apigear")
	if runtime.GOOS == "windows" {
		apigear = filepath.Join(binDir, "apigear.exe")
	}
	input = filepath.Join(apisDir, "apigear")
}

func must(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func gitClone(url, dir string) error {
	return sh.RunV("git", "clone", "--depth=1", url, dir)
}

func runDiff(dir1, dir2 string) error {
	return sh.RunV("git", "--no-pager", "diff", "--no-index", dir1, dir2)
}

func goInstall(pkg string) error {
	env := map[string]string{
		"GOBIN": binDir,
	}
	return sh.RunWithV(env, "go", "install", pkg)
}

func genX(target string) error {
	fmt.Printf("using apigear: %s\n", apigear)
	return sh.RunV(apigear, "g", "x", "-t", tplDir, "-o", target, "-i", input, "--force")
}

func rmDir(dir string) {
	must(sh.Rm(dir))
}

// Install installs the apigear cli and testbed-apis.
func Install() {
	rmDir("testbed-apis")
	goInstall("github.com/apigear-io/cli/cmd/apigear@latest")
	gitClone("https://github.com/apigear-io/go-testbed-apis.git", "testbed-apis")
}

// Golden generates the golden master.
func Golden() {
	rmDir(goldenDir)
	genX(goldenDir)
}

// Diff runs the generator and compares the output with the golden master.
func Diff() {
	rmDir(tmpDir)
	genX(tmpDir)
	runDiff(goldenDir, tmpDir)
}

func Gen() {
	genX(tmpDir)
}

// Clean removes all generated files.
func Clean() {
	rmDir(tmpDir)
	rmDir(apisDir)
}
