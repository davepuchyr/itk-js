title: Node.js Hello World!
---

This example, walks through how to compile a *hello world* executable written in C++ to JavaScript and execute it with the [Node.js](https://nodejs.org/) runtime!

Before getting started, make sure [Node.js](https://nodejs.org/en/download/) and [Docker](https://docs.docker.com/install/) are installed. On Linux, make sure you can run [`docker` without `sudo`](https://askubuntu.com/questions/477551/how-can-i-use-docker-without-sudo). On Windows, make sure [Shared Drives are enabled in the Docker settings](https://docs.docker.com/docker-for-windows/troubleshoot/#volume-mounting-requires-shared-drives-for-linux-containers). On Windows, also install [Git Bash](https://git-scm.com/), and run shell commands in *Git Bash*.

First, let's create a new folder to house our project.

```
mkdir NodeHelloWorld
cd NodeHelloWorld
```

Initialize the Node *package.json* file:

```
npm init --yes
```

Add `itk` and [`fs-extra`](https://www.npmjs.com/package/fs-extra) to your project's dependencies:

```
npm install --save itk fs-extra
```

Let's write some code! Populate *hello.cxx* with our Hello World program:

```
#include <iostream>

int main() {
  std::cout << "Hello world!" << std::endl;
  return 0;
}
```

Next, provide a [CMake](https://cmake.org/) build configuration at *CMakeLists.txt*:

```
cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

set(hello_SRCS hello.cxx)
if(EMSCRIPTEN)
  include(ITKBridgeJavaScript)
  web_add_executable(hello ${hello_SRCS})
else()
  add_executable(hello ${hello_SRCS})
endif()
```

We use the `web_add_executable` command to build executables with itk.js. This command is provided by the `ITKBridgeJavaScript` CMake module. This module, along with the [Emscripten](https://kripken.github.io/emscripten-site/) toolchain, is contained in the itk.js [dockcross](https://github.com/dockcross/dockcross) Docker image.

The same code can also be built and tested with native build tools with the standard `add_executable` CMake command.

Next, build the program with the itk.js CLI, `itk-js`. This is shipped with the `itk` package, and the CLI can be executed from the local *node_modules* folder with [`npx`](https://www.npmjs.com/package/npx). The `itk-js` CLI will invoke the toolchain contained in the dockcross Docker image. Pass the local source code directory root into `itk-js build` to perform the build.

```
npx itk-js build .
```

The project is built in `./web-build`.

To execute the project, create an `index.js` file to [invoke the module](../api/node_pipelines.html):

```
const path = require('path')
const runPipelineNode = require('itk/runPipelineNode')

const pipelinePath = path.resolve(__dirname, 'web-build', 'hello')
runPipelineNode(pipelinePath)
```

And run it!

```
npx node ./index.js
```

Congratulations! You just executed a C++ program compiled to JavaScript. 🎉
