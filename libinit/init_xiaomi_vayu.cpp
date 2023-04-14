/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libinit_dalvik_heap.h>
#include <libinit_variant.h>

#include "vendor_init.h"
#include <cstdlib>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>
#include <sys/sysinfo.h>
#include <android-base/properties.h>
#include "property_service.h"

using android::base::GetProperty;
using std::string;

void property_override(string prop, string value)
{
    auto pi = (prop_info*) __system_property_find(prop.c_str());

    if (pi != nullptr)
        __system_property_update(pi, value.c_str(), value.size());
    else
        __system_property_add(prop.c_str(), prop.size(), value.c_str(), value.size());
}

static const variant_info_t vayu_global_info = {
    .hwc_value = "GLOBAL",
    .sku_value = "",

    .brand = "POCO",
    .device = "vayu",
    .mod_device = "vayu_global",
    .marketname = "POCO X3 Pro",
    .model = "M2102J20SG",
    .build_fingerprint = "POCO/vayu_global/vayu:13/RKQ1.200826.002/V14.0.1.0.TJUMIXM:user/release-keys",

    .nfc = true,
};

static const variant_info_t vayu_eea_info = {
    .hwc_value = "EEA",
    .sku_value = "",

    .brand = "POCO",
    .device = "vayu",
    .mod_device = "vayu_eea_global",
    .marketname = "POCO X3 Pro",
    .model = "M2102J20SG",
    .build_fingerprint = "POCO/vayu_eea/vayu:12/RKQ1.200826.002/V13.0.6.0.SJUEUXM:user/release-keys",

    .nfc = true,
};

static const variant_info_t bhima_info = {
    .hwc_value = "INDIA",
    .sku_value = "",

    .brand = "POCO",
    .device = "bhima",
    .mod_device = "vayu_in_global",
    .marketname = "POCO X3 Pro",
    .model = "M2102J20SI",
    .build_fingerprint = "POCO/bhima_in/bhima:12/RKQ1.200826.002/V13.0.5.0.SJUINXM:user/release-keys",

    .nfc = false,
};

static const std::vector<variant_info_t> variants = {
    vayu_global_info,
    vayu_eea_info,
    bhima_info,
};

void vendor_load_properties() {
    set_dalvik_heap();
    search_variant(variants);

    // Misc
    property_override("ro.rising.chipset", "SDM860");
    property_override("ro.rising.device", "POCO X3 PRO");
    property_override("ro.rising.maintainer", "ste0090 | restintrip");

}
