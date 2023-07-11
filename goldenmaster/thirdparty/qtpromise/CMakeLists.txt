include(FetchContent)

FetchContent_Declare(qtpromise
  GIT_REPOSITORY https://github.com/simonbrunel/qtpromise.git
  GIT_TAG v0.7.0
  GIT_SHALLOW true
)

# CMake v3.14+
FetchContent_MakeAvailable(qtpromise)
