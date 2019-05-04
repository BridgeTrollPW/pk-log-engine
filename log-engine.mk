##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=log-engine
ConfigurationName      :=Debug
WorkspacePath          :=/home/bt/checkout/log-engine
ProjectPath            :=/home/bt/checkout/log-engine
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=bt
Date                   :=04/05/19
CodeLitePath           :=/home/bt/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
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
ObjectsFileList        :="log-engine.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
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
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_engine_Dispatcher.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_util_logger_Logger.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_util_ErrorHandler.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_util_Exception.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_modules_StartRoutine_StartRoutine.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_modules_RuleProcessor_RuleProcessor.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_engine_Dispatcher.cpp$(ObjectSuffix): src/engine/Dispatcher.cpp $(IntermediateDirectory)/src_engine_Dispatcher.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bt/checkout/log-engine/src/engine/Dispatcher.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_engine_Dispatcher.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_engine_Dispatcher.cpp$(DependSuffix): src/engine/Dispatcher.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_engine_Dispatcher.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_engine_Dispatcher.cpp$(DependSuffix) -MM src/engine/Dispatcher.cpp

$(IntermediateDirectory)/src_engine_Dispatcher.cpp$(PreprocessSuffix): src/engine/Dispatcher.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_engine_Dispatcher.cpp$(PreprocessSuffix) src/engine/Dispatcher.cpp

$(IntermediateDirectory)/src_util_logger_Logger.cpp$(ObjectSuffix): src/util/logger/Logger.cpp $(IntermediateDirectory)/src_util_logger_Logger.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bt/checkout/log-engine/src/util/logger/Logger.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_util_logger_Logger.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_util_logger_Logger.cpp$(DependSuffix): src/util/logger/Logger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_util_logger_Logger.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_util_logger_Logger.cpp$(DependSuffix) -MM src/util/logger/Logger.cpp

$(IntermediateDirectory)/src_util_logger_Logger.cpp$(PreprocessSuffix): src/util/logger/Logger.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_util_logger_Logger.cpp$(PreprocessSuffix) src/util/logger/Logger.cpp

$(IntermediateDirectory)/src_util_ErrorHandler.cpp$(ObjectSuffix): src/util/ErrorHandler.cpp $(IntermediateDirectory)/src_util_ErrorHandler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bt/checkout/log-engine/src/util/ErrorHandler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_util_ErrorHandler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_util_ErrorHandler.cpp$(DependSuffix): src/util/ErrorHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_util_ErrorHandler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_util_ErrorHandler.cpp$(DependSuffix) -MM src/util/ErrorHandler.cpp

$(IntermediateDirectory)/src_util_ErrorHandler.cpp$(PreprocessSuffix): src/util/ErrorHandler.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_util_ErrorHandler.cpp$(PreprocessSuffix) src/util/ErrorHandler.cpp

$(IntermediateDirectory)/src_util_Exception.cpp$(ObjectSuffix): src/util/Exception.cpp $(IntermediateDirectory)/src_util_Exception.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bt/checkout/log-engine/src/util/Exception.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_util_Exception.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_util_Exception.cpp$(DependSuffix): src/util/Exception.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_util_Exception.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_util_Exception.cpp$(DependSuffix) -MM src/util/Exception.cpp

$(IntermediateDirectory)/src_util_Exception.cpp$(PreprocessSuffix): src/util/Exception.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_util_Exception.cpp$(PreprocessSuffix) src/util/Exception.cpp

$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix): src/main.cpp $(IntermediateDirectory)/src_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bt/checkout/log-engine/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.cpp$(DependSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.cpp$(DependSuffix) -MM src/main.cpp

$(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix): src/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix) src/main.cpp

$(IntermediateDirectory)/src_modules_StartRoutine_StartRoutine.cpp$(ObjectSuffix): src/modules/StartRoutine/StartRoutine.cpp $(IntermediateDirectory)/src_modules_StartRoutine_StartRoutine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bt/checkout/log-engine/src/modules/StartRoutine/StartRoutine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_modules_StartRoutine_StartRoutine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_modules_StartRoutine_StartRoutine.cpp$(DependSuffix): src/modules/StartRoutine/StartRoutine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_modules_StartRoutine_StartRoutine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_modules_StartRoutine_StartRoutine.cpp$(DependSuffix) -MM src/modules/StartRoutine/StartRoutine.cpp

$(IntermediateDirectory)/src_modules_StartRoutine_StartRoutine.cpp$(PreprocessSuffix): src/modules/StartRoutine/StartRoutine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_modules_StartRoutine_StartRoutine.cpp$(PreprocessSuffix) src/modules/StartRoutine/StartRoutine.cpp

$(IntermediateDirectory)/src_modules_RuleProcessor_RuleProcessor.cpp$(ObjectSuffix): src/modules/RuleProcessor/RuleProcessor.cpp $(IntermediateDirectory)/src_modules_RuleProcessor_RuleProcessor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/bt/checkout/log-engine/src/modules/RuleProcessor/RuleProcessor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_modules_RuleProcessor_RuleProcessor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_modules_RuleProcessor_RuleProcessor.cpp$(DependSuffix): src/modules/RuleProcessor/RuleProcessor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_modules_RuleProcessor_RuleProcessor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_modules_RuleProcessor_RuleProcessor.cpp$(DependSuffix) -MM src/modules/RuleProcessor/RuleProcessor.cpp

$(IntermediateDirectory)/src_modules_RuleProcessor_RuleProcessor.cpp$(PreprocessSuffix): src/modules/RuleProcessor/RuleProcessor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_modules_RuleProcessor_RuleProcessor.cpp$(PreprocessSuffix) src/modules/RuleProcessor/RuleProcessor.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


