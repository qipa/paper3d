const char MSVC2012VCXPROJ_STR[] = 
"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
"<Project DefaultTargets=\"Build\" ToolsVersion=\"4.0\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">\n"
"  <ItemGroup Label=\"ProjectConfigurations\">\n"
"    <ProjectConfiguration Include=\"Debug|Win32\">\n"
"      <Configuration>Debug</Configuration>\n"
"      <Platform>Win32</Platform>\n"
"    </ProjectConfiguration>\n"
"    <ProjectConfiguration Include=\"Release|Win32\">\n"
"      <Configuration>Release</Configuration>\n"
"      <Platform>Win32</Platform>\n"
"    </ProjectConfiguration>\n"
"  </ItemGroup>\n"
"  <PropertyGroup Label=\"Globals\">\n"
"    <ProjectGuid>{BDD09E6E-9DDC-4BAA-AF89-04DBB46FB191}</ProjectGuid>\n"
"    <RootNamespace>project</RootNamespace>\n"
"    <Keyword>Win32Proj</Keyword>\n"
"  </PropertyGroup>\n"
"  <Import Project=\"$(VCTargetsPath)\\Microsoft.Cpp.Default.props\" />\n"
"  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|Win32'\" Label=\"Configuration\">\n"
"    <ConfigurationType>Application</ConfigurationType>\n"
"    <PlatformToolset>v110</PlatformToolset>\n"
"    <CharacterSet>Unicode</CharacterSet>\n"
"    <WholeProgramOptimization>true</WholeProgramOptimization>\n"
"  </PropertyGroup>\n"
"  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\" Label=\"Configuration\">\n"
"    <ConfigurationType>Application</ConfigurationType>\n"
"    <PlatformToolset>v110</PlatformToolset>\n"
"    <CharacterSet>Unicode</CharacterSet>\n"
"  </PropertyGroup>\n"
"  <Import Project=\"$(VCTargetsPath)\\Microsoft.Cpp.props\" />\n"
"  <ImportGroup Label=\"ExtensionSettings\">\n"
"  </ImportGroup>\n"
"  <ImportGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|Win32'\" Label=\"PropertySheets\">\n"
"    <Import Project=\"$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists('$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props')\" Label=\"LocalAppDataPlatform\" />\n"
"  </ImportGroup>\n"
"  <ImportGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\" Label=\"PropertySheets\">\n"
"    <Import Project=\"$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props\" Condition=\"exists('$(UserRootDir)\\Microsoft.Cpp.$(Platform).user.props')\" Label=\"LocalAppDataPlatform\" />\n"
"  </ImportGroup>\n"
"  <PropertyGroup Label=\"UserMacros\" />\n"
"  <PropertyGroup>\n"
"    <_ProjectFileVersion>11.0.60315.1</_ProjectFileVersion>\n"
"  </PropertyGroup>\n"
"  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\">\n"
"    <OutDir>..\\..\\bin\\msvc2012\\</OutDir>\n"
"    <IntDir>$(Configuration)\\</IntDir>\n"
"  </PropertyGroup>\n"
"  <PropertyGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|Win32'\">\n"
"    <OutDir>..\\..\\bin\\msvc2012\\</OutDir>\n"
"    <IntDir>$(Configuration)\\</IntDir>\n"
"  </PropertyGroup>\n"
"  <ItemDefinitionGroup Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\">\n"
"    <ClCompile>\n"
"      <Optimization>Disabled</Optimization>\n"
"      <PreprocessorDefinitions>WIN32;_DEBUG;_CONSOLE;_CRT_SECURE_NO_WARNINGS;%%(PreprocessorDefinitions)</PreprocessorDefinitions>\n"
"      <MinimalRebuild>true</MinimalRebuild>\n"
"      <BasicRuntimeChecks>EnableFastChecks</BasicRuntimeChecks>\n"
"      <RuntimeLibrary>MultiThreadedDebugDLL</RuntimeLibrary>\n"
"      <PrecompiledHeader />\n"
"      <WarningLevel>Level3</WarningLevel>\n"
"      <DebugInformationFormat>EditAndContinue</DebugInformationFormat>\n"
"      <CallingConvention>Cdecl</CallingConvention>\n"
"      <CompileAs>Default</CompileAs>\n"
"      <AdditionalIncludeDirectories>$(FIROOT)\\Paper3D\\include;$(FIROOT)\\Tech\\include</AdditionalIncludeDirectories>\n"
"    </ClCompile>\n"
"    <Link>\n"
"      <AdditionalDependencies>paper3d.lib;pplatform.lib;pfoundation.lib;zlib.lib;libpng.lib;tinyxml.lib;libEGL.lib;libGLESv2.lib;%%(AdditionalDependencies)</AdditionalDependencies>\n"
"      <OutputFile>$(OutDir)$(ProjectName).exe</OutputFile>\n"
"      <AdditionalLibraryDirectories>$(FIROOT)\\Tech\\lib\\msvc2012\\Debug;$(FIROOT)\\Paper3D\\lib\\msvc2012\\Debug;$(FIROOT)\\Tech\\3rdparty\\platforms\\msvc2012\\libpng\\lib\\Debug\\;$(FIROOT)\\Tech\\3rdparty\\platforms\\msvc2012\\tinyxml\\lib\\Debug\\;$(FIROOT)\\Tech\\3rdparty\\platforms\\msvc2012\\zlib\\lib\\Debug\\;$(FIROOT)\\Tech\\3rdparty\\platforms\\msvc2012\\gles20\\lib;%%(AdditionalLibraryDirectories)</AdditionalLibraryDirectories>\n"
"      <GenerateDebugInformation>true</GenerateDebugInformation>\n"
"      <SubSystem>Console</SubSystem>\n"
"    </Link>\n"
"    <PostBuildEvent />\n"
"    <PostBuildEvent>\n"
"      <Command>copy $(FIROOT)\\Tech\\bin\\msvc2012\\libEGL.dll $(OutDir)\n"
"copy $(FIROOT)\\Tech\\bin\\msvc2012\\libGLESv2.dll $(OutDir)\n"
"$(FIROOT)\\Tools\\bin\\msvc2012\\archiver.exe -o $(OutDir)\\$(ProjectName).par $(ProjectDir)..\\..\\res\n"
"copy $(OutDir)\\$(ProjectName).par $(ProjectDir)..\\..\\res\n"
"</Command>\n"
"    </PostBuildEvent>\n"
"  </ItemDefinitionGroup>\n"
"  <ItemDefinitionGroup Condition=\"'$(Configuration)|$(Platform)'=='Release|Win32'\">\n"
"    <ClCompile>\n"
"      <Optimization>MaxSpeed</Optimization>\n"
"      <IntrinsicFunctions>true</IntrinsicFunctions>\n"
"      <PreprocessorDefinitions>WIN32;NDEBUG;_CONSOLE;%%(PreprocessorDefinitions)</PreprocessorDefinitions>\n"
"      <RuntimeLibrary>MultiThreadedDLL</RuntimeLibrary>\n"
"      <FunctionLevelLinking>true</FunctionLevelLinking>\n"
"      <PrecompiledHeader />\n"
"      <WarningLevel>Level3</WarningLevel>\n"
"      <DebugInformationFormat>ProgramDatabase</DebugInformationFormat>\n"
"      <CompileAs>Default</CompileAs>\n"
"      <AdditionalIncludeDirectories>$(FIROOT)\\Paper3D\\include;$(FIROOT)\\Tech\\include</AdditionalIncludeDirectories>\n"
"    </ClCompile>\n"
"    <Link>\n"
"      <SubSystem>Console</SubSystem>\n"
"      <AdditionalLibraryDirectories>$(FIROOT)\\Tech\\lib\\msvc2012\\Release;$(FIROOT)\\Paper3D\\lib\\msvc2012\\Release;$(FIROOT)\\Tech\\3rdparty\\platforms\\msvc2012\\libpng\\lib\\Release\\;$(FIROOT)\\Tech\\3rdparty\\platforms\\msvc2012\\tinyxml\\lib\\Release\\;$(FIROOT)\\Tech\\3rdparty\\platforms\\msvc2012\\zlib\\lib\\Release\\;$(FIROOT)\\Tech\\3rdparty\\platforms\\msvc2012\\gles20\\lib;%%(AdditionalLibraryDirectories)</AdditionalLibraryDirectories>\n"
"      <AdditionalDependencies>paper3d.lib;pplatform.lib;pfoundation.lib;zlib.lib;libpng.lib;tinyxml.lib;libEGL.lib;libGLESv2.lib;%%(AdditionalDependencies)</AdditionalDependencies>\n"
"    </Link>\n"
"    <PostBuildEvent>\n"
"      <Command>copy $(FIROOT)\\Tech\\bin\\msvc2012\\libEGL.dll $(OutDir)\n"
"copy $(FIROOT)\\Tech\\bin\\msvc2012\\libGLESv2.dll $(OutDir)\n"
"$(FIROOT)\\Tools\\bin\\msvc2012\\archiver.exe -o $(OutDir)\\$(ProjectName).par $(ProjectDir)..\\..\\res\n"
"copy $(OutDir)\\$(ProjectName).par $(ProjectDir)..\\..\\res</Command>\n"
"    </PostBuildEvent>\n"
"  </ItemDefinitionGroup>\n"
"  <ItemGroup>\n"
"    <ClCompile Include=\"..\\..\\src\\main.cpp\" />\n"
"    <ClCompile Include=\"..\\..\\src\\mycontext.cpp\" />\n"
"    <ClCompile Include=\"..\\..\\src\\myscene.cpp\" />\n"
"    <ClCompile Include=\"..\\..\\src\\pmain.cpp\">\n"
"      <PreprocessToFile Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\">false</PreprocessToFile>\n"
"      <PreprocessSuppressLineNumbers Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\">false</PreprocessSuppressLineNumbers>\n"
"      <PreprocessKeepComments Condition=\"'$(Configuration)|$(Platform)'=='Debug|Win32'\">false</PreprocessKeepComments>\n"
"    </ClCompile>\n"
"  </ItemGroup>\n"
"  <ItemGroup>\n"
"    <ClInclude Include=\"..\\..\\src\\mycontext.h\" />\n"
"    <ClInclude Include=\"..\\..\\src\\myscene.h\" />\n"
"  </ItemGroup>\n"
"  <Import Project=\"$(VCTargetsPath)\\Microsoft.Cpp.targets\" />\n"
"  <ImportGroup Label=\"ExtensionTargets\">\n"
"  </ImportGroup>\n"
"</Project>";