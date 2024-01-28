# RandomCustomGraph

RandomCustomGraph is a Qt application developed in C++ and QML that reads values over the TCP-IP protocol and plots them on a custom graph using QQuickPaintedItem along with QPainter. The project is designed to run on both Windows and Ubuntu platforms.

## Table of Contents

- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)

## Features

- Reads 8 values over the TCP-IP protocol.
- Plots the values on a custom graph using QQuickPaintedItem and QPainter.
- Supports both Windows and Ubuntu platforms.

## Prerequisites

- Qt 5.15 or later installed on your system.
- C++ compiler compatible with Qt (e.g., GCC for Linux, MSVC for Windows).

## Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/your-username/RandomCustomGraph.git
    cd RandomCustomGraph
    ```

2. Build the project using Qt Creator or qmake:

    ```bash
    qmake
    make
    ```

    (For Windows, you may use Qt Creator or Visual Studio)

## Usage

1. Run the executable after building the project:

    ```bash
    ./RandomCustomGraph    # On Linux
    RandomCustomGraph.exe  # On Windows
    ```

2. The application will start, read random values over UDP, and plot them on the custom graph.

## Contributing

We welcome contributions to RandomCustomGraph. To contribute, follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature/your-feature`).
3. Make your changes and commit them (`git commit -am 'Add some feature'`).
4. Push to the branch (`git push origin feature/your-feature`).
5. Create a new Pull Request.
