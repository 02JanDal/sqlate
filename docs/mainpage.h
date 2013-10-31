/**
 *
 * @mainpage SQLate
 *
 * @section intro_sec Introduction
 *
 * SQLate is a C++ library that allows you to write compile-time checked SQL
 * queries. This makes it possible to find bugs faster.
 *
 * SQLate builds on top of the Qt Toolkit
 * (<a href="http://qt-project.org/">qt-project.org</a>).
 * SQLate is written and maintained by Klarälvdalens Datakonsult (KDAB,
 * <a href="http://kdab.com/">kdab.com</a>).
 *
 * More information is available
 * <a href="https://github.com/KDAB/sqlate">here</a>
 *
 * @section install_sec Compilation and Installation
 *
 * Currently the only way to get SQLate is by compiling it from source.
 *
 * Prerequisites:
 * - Qt
 * (<a href="http://qt-project.org/downloads">qt-project.org/downloads</a>)
 * - A C++ compiler supported by Qt
 * - CMake (<a href="http://cmake.org/">cmake.org</a>)
 * - Optional: Git (<a href="http://git-scm.com/">git-scm.com</a>)
 *
 * @subsection getting_sec Getting the Source
 *
 * Using Git:
 * @code
 * git clone https://github.com/KDAB/sqlate.git sqlate
 * @endcode
 *
 * @subsection compiling_sec Compiling
 *
 * @code
 * cd sqlate
 * mkdir build && cd build
 * cmake ..
 * make
 * @endcode
 *
 * @subsection installing_sec Installing
 *
 * @code
 * sudo make install
 * @endcode
 * This will install SQLate to the default prefix (/usr/local on linux based
 * system)
 *
 * You can use
 * @code
 * cmake -DCMAKE_INSTALL_PREFIX=installdir ..
 * @endcode
 * instead of @c cmake @c .. in the compilation step to choose a different one
 *
 * @section getting_started_sec Getting Started
 *
 * Go @subpage getting_started_page for help on getting started
 *
 * You might also want to checkout the examples.
 *
 * Other pages with more information:
 * - @subpage createtable_and_schemaupdater_page
 * - @subpage database_management_page
 * - @subpage transactions_page
 * - @subpage watchers_and_monitors_page
 */
