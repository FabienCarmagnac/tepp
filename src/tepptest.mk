##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=tepptest
ConfigurationName      :=Debug
WorkspacePath          := "C:\cygwin\home\ut1xg8\tepp\tepp"
ProjectPath            := "C:\cygwin\home\ut1xg8\tepp\tepp\src"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=ut1xg8
Date                   :=05/23/14
CodeLitePath           :="C:\work\bin\CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="tepptest.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS := -std=c++11 -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\work\bin\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\work\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/tepptest_main$(ObjectSuffix) $(IntermediateDirectory)/tepptest_test_cyclic_buffer$(ObjectSuffix) $(IntermediateDirectory)/tepptest_test_datetime$(ObjectSuffix) $(IntermediateDirectory)/tepptest_test_env$(ObjectSuffix) $(IntermediateDirectory)/tepptest_test_read_csv$(ObjectSuffix) $(IntermediateDirectory)/tepptest_test_scheduler$(ObjectSuffix) $(IntermediateDirectory)/tepptest_test_stdstat$(ObjectSuffix) $(IntermediateDirectory)/tepptest_test_string_tools$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/tepptest_main$(ObjectSuffix): tepptest/main.cpp $(IntermediateDirectory)/tepptest_main$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin/home/ut1xg8/tepp/tepp/src/tepptest/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tepptest_main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tepptest_main$(DependSuffix): tepptest/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tepptest_main$(ObjectSuffix) -MF$(IntermediateDirectory)/tepptest_main$(DependSuffix) -MM "tepptest/main.cpp"

$(IntermediateDirectory)/tepptest_main$(PreprocessSuffix): tepptest/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tepptest_main$(PreprocessSuffix) "tepptest/main.cpp"

$(IntermediateDirectory)/tepptest_test_cyclic_buffer$(ObjectSuffix): tepptest/test_cyclic_buffer.cpp $(IntermediateDirectory)/tepptest_test_cyclic_buffer$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin/home/ut1xg8/tepp/tepp/src/tepptest/test_cyclic_buffer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tepptest_test_cyclic_buffer$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tepptest_test_cyclic_buffer$(DependSuffix): tepptest/test_cyclic_buffer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tepptest_test_cyclic_buffer$(ObjectSuffix) -MF$(IntermediateDirectory)/tepptest_test_cyclic_buffer$(DependSuffix) -MM "tepptest/test_cyclic_buffer.cpp"

$(IntermediateDirectory)/tepptest_test_cyclic_buffer$(PreprocessSuffix): tepptest/test_cyclic_buffer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tepptest_test_cyclic_buffer$(PreprocessSuffix) "tepptest/test_cyclic_buffer.cpp"

$(IntermediateDirectory)/tepptest_test_datetime$(ObjectSuffix): tepptest/test_datetime.cpp $(IntermediateDirectory)/tepptest_test_datetime$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin/home/ut1xg8/tepp/tepp/src/tepptest/test_datetime.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tepptest_test_datetime$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tepptest_test_datetime$(DependSuffix): tepptest/test_datetime.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tepptest_test_datetime$(ObjectSuffix) -MF$(IntermediateDirectory)/tepptest_test_datetime$(DependSuffix) -MM "tepptest/test_datetime.cpp"

$(IntermediateDirectory)/tepptest_test_datetime$(PreprocessSuffix): tepptest/test_datetime.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tepptest_test_datetime$(PreprocessSuffix) "tepptest/test_datetime.cpp"

$(IntermediateDirectory)/tepptest_test_env$(ObjectSuffix): tepptest/test_env.cpp $(IntermediateDirectory)/tepptest_test_env$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin/home/ut1xg8/tepp/tepp/src/tepptest/test_env.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tepptest_test_env$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tepptest_test_env$(DependSuffix): tepptest/test_env.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tepptest_test_env$(ObjectSuffix) -MF$(IntermediateDirectory)/tepptest_test_env$(DependSuffix) -MM "tepptest/test_env.cpp"

$(IntermediateDirectory)/tepptest_test_env$(PreprocessSuffix): tepptest/test_env.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tepptest_test_env$(PreprocessSuffix) "tepptest/test_env.cpp"

$(IntermediateDirectory)/tepptest_test_read_csv$(ObjectSuffix): tepptest/test_read_csv.cpp $(IntermediateDirectory)/tepptest_test_read_csv$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin/home/ut1xg8/tepp/tepp/src/tepptest/test_read_csv.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tepptest_test_read_csv$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tepptest_test_read_csv$(DependSuffix): tepptest/test_read_csv.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tepptest_test_read_csv$(ObjectSuffix) -MF$(IntermediateDirectory)/tepptest_test_read_csv$(DependSuffix) -MM "tepptest/test_read_csv.cpp"

$(IntermediateDirectory)/tepptest_test_read_csv$(PreprocessSuffix): tepptest/test_read_csv.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tepptest_test_read_csv$(PreprocessSuffix) "tepptest/test_read_csv.cpp"

$(IntermediateDirectory)/tepptest_test_scheduler$(ObjectSuffix): tepptest/test_scheduler.cpp $(IntermediateDirectory)/tepptest_test_scheduler$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin/home/ut1xg8/tepp/tepp/src/tepptest/test_scheduler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tepptest_test_scheduler$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tepptest_test_scheduler$(DependSuffix): tepptest/test_scheduler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tepptest_test_scheduler$(ObjectSuffix) -MF$(IntermediateDirectory)/tepptest_test_scheduler$(DependSuffix) -MM "tepptest/test_scheduler.cpp"

$(IntermediateDirectory)/tepptest_test_scheduler$(PreprocessSuffix): tepptest/test_scheduler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tepptest_test_scheduler$(PreprocessSuffix) "tepptest/test_scheduler.cpp"

$(IntermediateDirectory)/tepptest_test_stdstat$(ObjectSuffix): tepptest/test_stdstat.cpp $(IntermediateDirectory)/tepptest_test_stdstat$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin/home/ut1xg8/tepp/tepp/src/tepptest/test_stdstat.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tepptest_test_stdstat$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tepptest_test_stdstat$(DependSuffix): tepptest/test_stdstat.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tepptest_test_stdstat$(ObjectSuffix) -MF$(IntermediateDirectory)/tepptest_test_stdstat$(DependSuffix) -MM "tepptest/test_stdstat.cpp"

$(IntermediateDirectory)/tepptest_test_stdstat$(PreprocessSuffix): tepptest/test_stdstat.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tepptest_test_stdstat$(PreprocessSuffix) "tepptest/test_stdstat.cpp"

$(IntermediateDirectory)/tepptest_test_string_tools$(ObjectSuffix): tepptest/test_string_tools.cpp $(IntermediateDirectory)/tepptest_test_string_tools$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin/home/ut1xg8/tepp/tepp/src/tepptest/test_string_tools.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tepptest_test_string_tools$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tepptest_test_string_tools$(DependSuffix): tepptest/test_string_tools.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tepptest_test_string_tools$(ObjectSuffix) -MF$(IntermediateDirectory)/tepptest_test_string_tools$(DependSuffix) -MM "tepptest/test_string_tools.cpp"

$(IntermediateDirectory)/tepptest_test_string_tools$(PreprocessSuffix): tepptest/test_string_tools.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tepptest_test_string_tools$(PreprocessSuffix) "tepptest/test_string_tools.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/tepptest_main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_test_cyclic_buffer$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_test_cyclic_buffer$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_test_cyclic_buffer$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_test_datetime$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_test_datetime$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_test_datetime$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_test_env$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_test_env$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_test_env$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_test_read_csv$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_test_read_csv$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_test_read_csv$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_test_scheduler$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_test_scheduler$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_test_scheduler$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_test_stdstat$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_test_stdstat$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_test_stdstat$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_test_string_tools$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_test_string_tools$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tepptest_test_string_tools$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../.build-debug/tepptest"


