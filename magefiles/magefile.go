package main

import (
	"log"
	"os"
	"path/filepath"
	"runtime"

	"github.com/magefile/mage/sh"
)

var (
	goldenDir string
	tmpDir    string
	solFile   string
	apigear   string
	binDir    string
)

func init() {
	cwd, err := os.Getwd()
	if err != nil {
		log.Fatal(err)
	}
	if runtime.GOOS == "windows" {
		apigear = filepath.Join(cwd, "bin", "apigear.exe")
	} else {
		apigear = filepath.Join(cwd, "bin", "apigear")
	}
	tmpDir = filepath.Join(cwd, "tmp")
	goldenDir = filepath.Join(cwd, "goldenmaster")
	binDir = filepath.Join(cwd, "bin")
	solFile = filepath.Join(cwd, "apigear", "goldenmaster.solution.yaml")
}

func must(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func goInstall(pkg string) {
	env := map[string]string{
		"GOBIN": binDir,
	}
	must(sh.RunWithV(env, "go", "install", pkg))
}

func genSolution(sol string) {
	must(sh.RunV(apigear, "generate", "solution", sol))
}

func rmDir(dir string) {
	must(sh.Rm(dir))
}

func mvDir(src, dst string) {
	must(os.Rename(src, dst))
}

// Install installs the apigear cli and testbed-apis.
func Install() {
	goInstall("github.com/apigear-io/cli/cmd/apigear@latest")
}

func GenGolden() {
	rmDir(goldenDir)
	rmDir(tmpDir)
	genSolution(solFile)
	mvDir(tmpDir, goldenDir)
}

func GenTest() {
	rmDir(tmpDir)
	genSolution(solFile)
}

// Clean removes all generated files.
func Clean() {
	rmDir(tmpDir)
}
