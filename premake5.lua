project "shapes-2D"
language "C++"
cppdialect "C++17"

filter "system:macosx"
   buildoptions {
      "-Wall",
      "-Wextra",
      "-Wpedantic",
      "-Wconversion",
      "-Wno-unused-parameter"
   }
filter {}

pchheader "geo/pch.hpp"
pchsource "src/pch.cpp"

staticruntime "off"
kind "StaticLib"

targetdir("bin/" .. outputdir)
objdir("build/" .. outputdir)

files {
   "src/**.cpp",
   "include/**.hpp"
}

includedirs {
   "include",
   "%{wks.location}/debug-tools/include",
   "%{wks.location}/profile-tools/include",
   "%{wks.location}/ini-parser/include",
   "%{wks.location}/vendor/glm",
}
