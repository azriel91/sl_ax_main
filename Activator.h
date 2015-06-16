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

#ifndef __SL_AX_MAIN__ACTIVATOR_H
#define __SL_AX_MAIN__ACTIVATOR_H

#include <azriel/cppmicroservices/core/include/usModuleActivator.h>
#include <azriel/cppmicroservices/core/include/usModuleContext.h>
#include <azriel/sl_ax_engine/AutexousiousService.h>

#include "sl_ax_main/Block.h"

US_USE_NAMESPACE

namespace sl {
namespace ax {
namespace main {

class US_ABI_LOCAL Activator : public ModuleActivator {
private:
	ModuleContext* context;
	ServiceReference<sl::ax::engine::AutexousiousService> ref;
	sl::ax::engine::AutexousiousService* axService;

public:
	Activator();
	virtual ~Activator();
	sl::ax::engine::AutexousiousService* getAxService() const;

private:
	void Load(ModuleContext* context);
	void Unload(ModuleContext* context);
	void ServiceChanged(const ServiceEvent event);
};

} /* namespace main */
} /* namespace ax */
} /* namespace sl */

#endif /* __SL_AX_MAIN__ACTIVATOR_H */
