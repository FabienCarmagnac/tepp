##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=tepp
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName).dll
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="tepp.txt"
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
CXXFLAGS := -std=c++11 -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\work\bin\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\work\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/tepp_book$(ObjectSuffix) $(IntermediateDirectory)/tepp_book_entry$(ObjectSuffix) $(IntermediateDirectory)/tepp_datetime$(ObjectSuffix) $(IntermediateDirectory)/tepp_env$(ObjectSuffix) $(IntermediateDirectory)/tepp_logger$(ObjectSuffix) $(IntermediateDirectory)/tepp_stdstat$(ObjectSuffix) $(IntermediateDirectory)/tepp_string_tools$(ObjectSuffix) $(IntermediateDirectory)/order_execution$(ObjectSuffix) $(IntermediateDirectory)/order_virtual_market$(ObjectSuffix) $(IntermediateDirectory)/pugixml_pugixml$(ObjectSuffix) \
	$(IntermediateDirectory)/scheduler_scheduler_realtime$(ObjectSuffix) $(IntermediateDirectory)/scheduler_scheduler_replay$(ObjectSuffix) 



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
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)
	@$(MakeDirCommand) "C:\cygwin\home\ut1xg8\tepp\tepp/.build-debug"
	@echo rebuilt > "C:\cygwin\home\ut1xg8\tepp\tepp/.build-debug/tepp"

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/tepp_book$(ObjectSuffix): tepp/book.cpp $(IntermediateDirectory)/tepp_book$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin/home/ut1xg8/tepp/tepp/src/tepp/book.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tepp_book$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tepp_book$(DependSuffix): tepp/book.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tepp_book$(ObjectSuffix) -MF$(IntermediateDirectory)/tepp_book$(DependSuffix) -MM "tepp/book.cpp"

$(IntermediateDirectory)/tepp_book$(PreprocessSuffix): tepp/book.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tepp_book$(PreprocessSuffix) "tepp/book.cpp"

$(IntermediateDirectory)/tepp_book_entry$(ObjectSuffix): tepp/book_entry.cpp $(IntermediateDirectory)/tepp_book_entry$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin/home/ut1xg8/tepp/tepp/src/tepp/book_entry.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tepp_book_entry$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tepp_book_entry$(DependSuffix): tepp/book_entry.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tepp_book_entry$(ObjectSuffix) -MF$(IntermediateDirectory)/tepp_book_entry$(DependSuffix) -MM "tepp/book_entry.cpp"

$(IntermediateDirectory)/tepp_book_entry$(PreprocessSuffix): tepp/book_entry.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tepp_book_entry$(PreprocessSuffix) "tepp/book_entry.cpp"

$(IntermediateDirectory)/tepp_datetime$(ObjectSuffix): tepp/datetime.cpp $(IntermediateDirectory)/tepp_datetime$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin/home/ut1xg8/tepp/tepp/src/tepp/datetime.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tepp_datetime$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tepp_datetime$(DependSuffix): tepp/datetime.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tepp_datetime$(ObjectSuffix) -MF$(IntermediateDirectory)/tepp_datetime$(DependSuffix) -MM "tepp/datetime.cpp"

$(IntermediateDirectory)/tepp_datetime$(PreprocessSuffix): tepp/datetime.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tepp_datetime$(PreprocessSuffix) "tepp/datetime.cpp"

$(IntermediateDirectory)/tepp_env$(ObjectSuffix): tepp/env.cpp $(IntermediateDirectory)/tepp_env$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin/home/ut1xg8/tepp/tepp/src/tepp/env.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tepp_env$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tepp_env$(DependSuffix): tepp/env.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tepp_env$(ObjectSuffix) -MF$(IntermediateDirectory)/tepp_env$(DependSuffix) -MM "tepp/env.cpp"

$(IntermediateDirectory)/tepp_env$(PreprocessSuffix): tepp/env.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tepp_env$(PreprocessSuffix) "tepp/env.cpp"

$(IntermediateDirectory)/tepp_logger$(ObjectSuffix): tepp/logger.cpp $(IntermediateDirectory)/tepp_logger$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin/home/ut1xg8/tepp/tepp/src/tepp/logger.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tepp_logger$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tepp_logger$(DependSuffix): tepp/logger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tepp_logger$(ObjectSuffix) -MF$(IntermediateDirectory)/tepp_logger$(DependSuffix) -MM "tepp/logger.cpp"

$(IntermediateDirectory)/tepp_logger$(PreprocessSuffix): tepp/logger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tepp_logger$(PreprocessSuffix) "tepp/logger.cpp"

$(IntermediateDirectory)/tepp_stdstat$(ObjectSuffix): tepp/stdstat.cpp $(IntermediateDirectory)/tepp_stdstat$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin/home/ut1xg8/tepp/tepp/src/tepp/stdstat.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tepp_stdstat$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tepp_stdstat$(DependSuffix): tepp/stdstat.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tepp_stdstat$(ObjectSuffix) -MF$(IntermediateDirectory)/tepp_stdstat$(DependSuffix) -MM "tepp/stdstat.cpp"

$(IntermediateDirectory)/tepp_stdstat$(PreprocessSuffix): tepp/stdstat.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tepp_stdstat$(PreprocessSuffix) "tepp/stdstat.cpp"

$(IntermediateDirectory)/tepp_string_tools$(ObjectSuffix): tepp/string_tools.cpp $(IntermediateDirectory)/tepp_string_tools$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin/home/ut1xg8/tepp/tepp/src/tepp/string_tools.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tepp_string_tools$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tepp_string_tools$(DependSuffix): tepp/string_tools.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tepp_string_tools$(ObjectSuffix) -MF$(IntermediateDirectory)/tepp_string_tools$(DependSuffix) -MM "tepp/string_tools.cpp"

$(IntermediateDirectory)/tepp_string_tools$(PreprocessSuffix): tepp/string_tools.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tepp_string_tools$(PreprocessSuffix) "tepp/string_tools.cpp"

$(IntermediateDirectory)/order_execution$(ObjectSuffix): tepp/order/execution.cpp $(IntermediateDirectory)/order_execution$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin/home/ut1xg8/tepp/tepp/src/tepp/order/execution.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/order_execution$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/order_execution$(DependSuffix): tepp/order/execution.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/order_execution$(ObjectSuffix) -MF$(IntermediateDirectory)/order_execution$(DependSuffix) -MM "tepp/order/execution.cpp"

$(IntermediateDirectory)/order_execution$(PreprocessSuffix): tepp/order/execution.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/order_execution$(PreprocessSuffix) "tepp/order/execution.cpp"

$(IntermediateDirectory)/order_virtual_market$(ObjectSuffix): tepp/order/virtual_market.cpp $(IntermediateDirectory)/order_virtual_market$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin/home/ut1xg8/tepp/tepp/src/tepp/order/virtual_market.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/order_virtual_market$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/order_virtual_market$(DependSuffix): tepp/order/virtual_market.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/order_virtual_market$(ObjectSuffix) -MF$(IntermediateDirectory)/order_virtual_market$(DependSuffix) -MM "tepp/order/virtual_market.cpp"

$(IntermediateDirectory)/order_virtual_market$(PreprocessSuffix): tepp/order/virtual_market.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/order_virtual_market$(PreprocessSuffix) "tepp/order/virtual_market.cpp"

$(IntermediateDirectory)/pugixml_pugixml$(ObjectSuffix): tepp/pugixml/pugixml.cpp $(IntermediateDirectory)/pugixml_pugixml$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin/home/ut1xg8/tepp/tepp/src/tepp/pugixml/pugixml.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pugixml_pugixml$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pugixml_pugixml$(DependSuffix): tepp/pugixml/pugixml.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pugixml_pugixml$(ObjectSuffix) -MF$(IntermediateDirectory)/pugixml_pugixml$(DependSuffix) -MM "tepp/pugixml/pugixml.cpp"

$(IntermediateDirectory)/pugixml_pugixml$(PreprocessSuffix): tepp/pugixml/pugixml.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pugixml_pugixml$(PreprocessSuffix) "tepp/pugixml/pugixml.cpp"

$(IntermediateDirectory)/scheduler_scheduler_realtime$(ObjectSuffix): tepp/scheduler/scheduler_realtime.cpp $(IntermediateDirectory)/scheduler_scheduler_realtime$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin/home/ut1xg8/tepp/tepp/src/tepp/scheduler/scheduler_realtime.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/scheduler_scheduler_realtime$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/scheduler_scheduler_realtime$(DependSuffix): tepp/scheduler/scheduler_realtime.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/scheduler_scheduler_realtime$(ObjectSuffix) -MF$(IntermediateDirectory)/scheduler_scheduler_realtime$(DependSuffix) -MM "tepp/scheduler/scheduler_realtime.cpp"

$(IntermediateDirectory)/scheduler_scheduler_realtime$(PreprocessSuffix): tepp/scheduler/scheduler_realtime.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/scheduler_scheduler_realtime$(PreprocessSuffix) "tepp/scheduler/scheduler_realtime.cpp"

$(IntermediateDirectory)/scheduler_scheduler_replay$(ObjectSuffix): tepp/scheduler/scheduler_replay.cpp $(IntermediateDirectory)/scheduler_scheduler_replay$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/cygwin/home/ut1xg8/tepp/tepp/src/tepp/scheduler/scheduler_replay.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/scheduler_scheduler_replay$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/scheduler_scheduler_replay$(DependSuffix): tepp/scheduler/scheduler_replay.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/scheduler_scheduler_replay$(ObjectSuffix) -MF$(IntermediateDirectory)/scheduler_scheduler_replay$(DependSuffix) -MM "tepp/scheduler/scheduler_replay.cpp"

$(IntermediateDirectory)/scheduler_scheduler_replay$(PreprocessSuffix): tepp/scheduler/scheduler_replay.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/scheduler_scheduler_replay$(PreprocessSuffix) "tepp/scheduler/scheduler_replay.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/tepp_book$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tepp_book$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tepp_book$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tepp_book_entry$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tepp_book_entry$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tepp_book_entry$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tepp_datetime$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tepp_datetime$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tepp_datetime$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tepp_env$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tepp_env$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tepp_env$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tepp_logger$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tepp_logger$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tepp_logger$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tepp_stdstat$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tepp_stdstat$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tepp_stdstat$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tepp_string_tools$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tepp_string_tools$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tepp_string_tools$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/order_execution$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/order_execution$(DependSuffix)
	$(RM) $(IntermediateDirectory)/order_execution$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/order_virtual_market$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/order_virtual_market$(DependSuffix)
	$(RM) $(IntermediateDirectory)/order_virtual_market$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/pugixml_pugixml$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/pugixml_pugixml$(DependSuffix)
	$(RM) $(IntermediateDirectory)/pugixml_pugixml$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/scheduler_scheduler_realtime$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/scheduler_scheduler_realtime$(DependSuffix)
	$(RM) $(IntermediateDirectory)/scheduler_scheduler_realtime$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/scheduler_scheduler_replay$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/scheduler_scheduler_replay$(DependSuffix)
	$(RM) $(IntermediateDirectory)/scheduler_scheduler_replay$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile)
	$(RM) "../.build-debug/tepp"


