workspace "projectname"
   architecture "x64"

   configurations { 
      "Debug",
      "Release"
   }

   flags {
      "MultiProcessorCompile"
   }
   
binarydir = "bin"
objectdir = "bin/int"
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
   
IncludeDir = {}
IncludeDir["projectname"] = "%{wks.location}/projectname/include"


include "projectname"

group "tests"
   include "tests"
group ""