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

#include <vector>
#include <iostream>

#include "Activator.h"

namespace sl {
namespace ax {
namespace main {

Activator::Activator() :
		context(nullptr),
		axService(nullptr) {
}

Activator::~Activator() {
}

sl::ax::engine::AutexousiousService* Activator::getAxService() const {
	return this->axService;
}

void Activator::Load(ModuleContext* context) {
	ModuleSettings::SetAutoLoadingEnabled(true);

	this->context = context;
	this->context->AddServiceListener(this, &Activator::ServiceChanged);

	std::vector<ServiceReference<sl::ax::engine::AutexousiousService> > refs =
			this->context->GetServiceReferences<sl::ax::engine::AutexousiousService>();

	if (!refs.empty()) {
		// Get a reference to the first service object.
		this->ref = refs.front();
		this->axService = this->context->GetService(this->ref);
	}
}

void Activator::Unload(ModuleContext* context) {
}

void Activator::ServiceChanged(const ServiceEvent event) {
	// MutexLocker lock(&m_mutex);
	if (event.GetType() == ServiceEvent::REGISTERED) {
		if (!this->ref) {
			// Get a reference to the service object.
			this->ref = event.GetServiceReference();
			this->axService = this->context->GetService(this->ref);
		}
	}
	// If an Autexousious service was unregistered, see if it
	// was the one we were using. If so, unget the service
	// and try to query to get another one.
	else if (event.GetType() == ServiceEvent::UNREGISTERING) {
		if (event.GetServiceReference() == this->ref) {
			// Unget service object and null references.
			this->context->UngetService(this->ref);
			this->ref = 0;
			this->axService = NULL;

			// Query to see if we can get another service.
			std::vector<ServiceReference<sl::ax::engine::AutexousiousService> > refs;
			try {
				refs = this->context->GetServiceReferences<sl::ax::engine::AutexousiousService>();
			} catch (const std::invalid_argument& e) {
				std::cout << e.what() << std::endl;
			}

			if (!refs.empty()) {
				// Get a reference to the first service object.
				this->ref = refs.front();
				this->axService = this->context->GetService(this->ref);
			}
		}
	}
}

} /* namespace main */
} /* namespace ax */
} /* namespace sl */

US_EXPORT_MODULE_ACTIVATOR(sl::ax::main::Activator)
