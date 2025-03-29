project "ProjectName"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++23"
    targetdir (binarydir .. outputdir)
    objdir (objectdir .. outputdir)
    
    include {
        "include",
        "src"
    }

    files { 
        "include/**.hpp",
        "src/**.cpp",
        "src/**.hpp"
        "src/**.h",
        "src/**.c"
    }

    fitler "toolset:gcc or clang"
        buildoptions {
            "-Wall",
            "-Wextra"
            "-Wno-unused"
        }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"