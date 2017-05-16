/* COPYRIGHT (c) 2016-2017 Nova Labs SRL
 *
 * All rights reserved. All use of this software and documentation is
 * subject to the License Agreement located in the file LICENSE.
 */

#pragma once

#include <ModuleConfiguration.hpp>
#include <core/mw/CoreModule.hpp>

namespace sensors {}

// Forward declarations
namespace sensors {
class L3GD20H_Gyro;
class LSM303D_Acc;
class LSM303D_Mag;
}

#if CORE_USE_CONFIGURATION_STORAGE
namespace core {
namespace mw {
class CoreConfigurationStorage;
}
}
#endif

class Module:
    public core::mw::CoreModule
{
public:
// --- DEVICES ----------------------------------------------------------------
    static sensors::L3GD20H_Gyro& gyro;
    static sensors::LSM303D_Acc&  acc;
    static sensors::LSM303D_Mag&  mag;
// ----------------------------------------------------------------------------

    static bool
    initialize();


#if CORE_USE_CONFIGURATION_STORAGE
    static core::mw::CoreConfigurationStorage& configurationStorage;
#endif
    Module();
    virtual ~Module() {}
};
