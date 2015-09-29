/*=============================================================================

	Library: Silver

	Copyright (c) Azriel Hoh

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

		http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.

=============================================================================*/

#include <cstdio>

#include <azriel/cppmicroservices/core/include/usGetModuleContext.h>
#include <azriel/sl_ax_engine/AutexousiousService.h>

US_USE_NAMESPACE

#ifndef US_BUILD_SHARED_LIBS
	#include <azriel/cppmicroservices/core/include/usModuleImport.h>
	US_IMPORT_MODULE(CppMicroServices)
	US_IMPORT_MODULE(sl_core_application)
	US_IMPORT_MODULE(sl_ax_engine)
	US_IMPORT_MODULE(sl_ax_main)
#endif

#include "sl_ax_main/Block.h"
#include "Activator.h"

int main(int argc, char const *argv[]) {
	printf(" === Auto load dirs ===\n");
	auto autoLoadPaths = ModuleSettings::GetAutoLoadPaths();
	for (auto path : autoLoadPaths) {
		printf("auto load: %s\n", path.c_str());
	}

	printf("\n");
	printf(" === Module Locations ===\n");
	ModuleContext* mc = GetModuleContext();
	auto modules = mc->GetModules();
	for (auto module : modules) {
		printf("%s: %s\n", module->GetName().c_str(), module->GetLocation().c_str());
	}

	printf("\n");
	printf(" === Module Properties ===\n");
	for (auto module : modules) {
		printf("  == %s\n ==", module->GetName().c_str());
		printf("  module.autoload_dir: %s\n", module->GetProperty("module.autoload_dir").ToString().c_str());
	}

	auto axServiceReferenceU = mc->GetServiceReference("sl::ax::engine::AutexousiousService");
	auto axServiceMap = mc->GetService(axServiceReferenceU);
	auto axService = (sl::ax::engine::AutexousiousService*) axServiceMap["sl::ax::engine::AutexousiousService"];
	return axService->runApplication("sl::ax::engine::StartupActivity");
}
