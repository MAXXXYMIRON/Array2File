import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "AxBase"
    Depends { name: "Qt"; submodules: ["core","gui","widgets"]}

    architectures: ["x86_64"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: ["ole32","oleaut32","user32","gdi32","advapi32","uuid","Qt5Cored;-lole32;-loleaut32;-luser32;-lgdi32;-ladvapi32;-luuid;;"]
    staticLibsRelease: ["ole32","oleaut32","user32","gdi32","advapi32","uuid","Qt5Core;-lole32;-loleaut32;-luser32;-lgdi32;-ladvapi32;-luuid;;"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5AxBased"
    libNameForLinkerRelease: "Qt5AxBase"
    libFilePathDebug: "C:/Qt/5.13.1/mingw73_64/lib/libQt5AxBased.a"
    libFilePathRelease: "C:/Qt/5.13.1/mingw73_64/lib/libQt5AxBase.a"
    pluginTypes: []
    moduleConfig: ["lex","yacc","depend_includepath","testcase_targets","import_qpa_plugin","windows","qt_build_extra","file_copies","qmake_use","qt","warn_on","release","link_prl","debug_and_release","release","no_plugin_manifest","win32","mingw","gcc","copy_dir_files","sse2","aesni","sse3","ssse3","sse4_1","sse4_2","compile_examples","largefile","optimize_debug","rdrnd","shani","x86SimdAlways","prefix_build","force_independent","utf8_source","create_prl","link_prl","prepare_docs","qt_docs_targets","no_private_qt_headers_warning","QTDIR_build","qt_example_installs","exceptions_off","testcase_exceptions","release","ReleaseBuild","Release","build_pass","release","ReleaseBuild","Release","build_pass","static","relative_qt_rpath","git_build","qmake_cache","target_qt","c++11","strict_c++","c++14","c++1z","c99","c11","qt_install_headers","need_fwd_pri","qt_install_module","debug_and_release","build_all","create_cmake","skip_target_version_ext","compiler_supports_fpmath","create_pc","release","ReleaseBuild","Release","build_pass","have_target","staticlib","exclusive_builds","no_autoqmake","thread","uic","opengl","moc","resources"]
    cpp.defines: ["QT_AXBASE_LIB"]
    cpp.includePaths: ["C:/Qt/5.13.1/mingw73_64/include","C:/Qt/5.13.1/mingw73_64/include/ActiveQt"]
    cpp.libraryPaths: ["C:/openssl/lib","C:/Utils/my_sql/mysql-5.7.25-winx64/lib","C:/Utils/postgresql/pgsql/lib","C:/openssl/lib","C:/Utils/my_sql/mysql-5.7.25-winx64/lib","C:/Utils/postgresql/pgsql/lib"]
    isStaticLibrary: true
Group {
        files: [Qt["axbase"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
