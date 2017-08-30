# ARTTECH 3135
A public repository for SAIC ARTTECH 3135 / 5135 Interactive Art and Creative Code.

The course website is located at [https://saic-ats.github.io/ARTTECH-3135/](https://saic-ats.github.io/ARTTECH-3135/).

## Course Repository

This repository contains materials for the course. The [Syllabus](docs/syllabus.md), assignments and lecture notes are located in the `docs/` folder. Code examples are listed by Week and Assignment number in the root directory.  

### Course Documents

The syllabus, assignments and lecture notes located in the `docs/` folder are written in [markdown](https://en.wikipedia.org/wiki/Markdown) and formatted for the web using [Jekyll](https://jekyllrb.com/), a static website generator. Each time a file is updated in the `docs/` folder, those changes are incorporated into the course website, which is generated and hosted for free by [Github Pages](https://pages.github.com/).

The course documents are licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](https://creativecommons.org/licenses/by-nc-sa/4.0/) ![by-nc-sa](https://i.creativecommons.org/l/by-nc-sa/4.0/80x15.png).

### Code Examples

The example code is located in the root directory and organized by [zero-indexed](https://en.wikipedia.org/wiki/Zero-based_numbering) course week number (e.g. `Week_00`, `Week_01`, etc.) or a [zero-indexed](https://en.wikipedia.org/wiki/Zero-based_numbering) assignment number (e.g. `Assignment_00`, `Assignment_01`, etc.). Each example is documented with [inline comments](https://en.wikipedia.org/wiki/Comment_%28computer_programming%29%23Inline_comment_.28End-of-line.29) and a `README.md` as needed.

The example and assignment code is licensed under an [MIT license](LICENSE.md). For more information about open source licenses, see [The Legal Side of Open Source](https://opensource.guide/legal/).

## Repository Installation

### Location

The examples in this repository are primarily written using [openFrameworks](https://github.com/openframeworks/openFrameworks). To keep example paths simple, this repository can be placed in your openFrameworks root folder. Your openFrameworks directory should look something like this:

```
openFrameworks/
├── ARTTECH-3135
│   ├── CONTRIBUTING.md
│   ├── README.md
│   ├── LICENSE.md
│   ├── docs
│   ├── Week_00
│   └── ...
├── CHANGELOG.md
├── CODE_OF_CONDUCT.md
├── CONTRIBUTING.md
├── LICENSE.md
├── README.md
├── addons
├── apps
├── docs
├── examples
├── export
├── libs
├── other
├── projectGenerator-osx
├── scripts
├── tests
├── tutorials
└── ...
```

### Read-Only Installation

1. [Download and setup](http://openframeworks.cc/download/) openFrameworks. The location of your installation is referred to as the `OF_ROOT`.

2. In the terminal, change your working directory to your openFrameworks root:
  - `cd OF_ROOT/`
2. Clone the repository
  - `git clone https://github.com/SAIC-ATS/ARTTECH-3135.git`
3. To update your copy to the latest ..
  - `git pull`

### Contributor Installation (optional)

See `CONTRIBUTING.md`.
