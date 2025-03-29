workspace "projectname"
   architecture "x64"
   configurations { 
      "Debug",
      "Release"
   }
   flags {
      "MultiProcessorCompile"
   }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
testsdir =  outputdir .. "/tests"

IncludeDir = {}
IncludeDir["projectname"] = "%{wks.location}/projectname/include"

include "projectname"

group "tests"
   include "tests/unit/exampletest"
group ""