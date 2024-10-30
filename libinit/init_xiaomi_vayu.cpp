/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libinit_dalvik_heap.h>
#include <libinit_variant.h>

#include "vendor_init.h"

#define FINGERPRINT "POCO/vayu_global/vayu:13/RKQ1.200826.002/V14.0.3.0.TJUMIXM:user/release-keys"

#include <android-base/logging.h>
#include <android-base/properties.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>
using android::base::GetProperty;
/*
 * SetProperty does not allow updating read only properties and as a result
 * does not work for our use case. Write "OverrideProperty" to do practically
 * the same thing as "SetProperty" without this restriction.
 */
void OverrideProperty(const char* name, const char* value) {
    size_t valuelen = strlen(value);
    prop_info* pi = (prop_info*)__system_property_find(name);
    if (pi != nullptr) {
        __system_property_update(pi, value, valuelen);
    } else {
        __system_property_add(name, strlen(name), value, valuelen);
    }
}

static const variant_info_t bhima_info = {
    .hwc_value = "INDIA",
    .sku_value = "",

    .brand = "POCO",
    .device = "bhima",
    .mod_device = "vayu_in_global",
    .marketname = "POCO X3 Pro",
    .model = "M2102J20SI",
    .build_fingerprint = FINGERPRINT,

    .nfc = false,
};

static const variant_info_t vayu_info = {
    .hwc_value = "",
    .sku_value = "",

    .brand = "POCO",
    .device = "vayu",
    .mod_device = "vayu_global",
    .marketname = "POCO X3 Pro",
    .model = "M2102J20SG",
    .build_fingerprint = FINGERPRINT,

    .nfc = true,
};

static const std::vector<variant_info_t> variants = {
    bhima_info,
    vayu_info,
};

void vendor_load_properties() {
    set_dalvik_heap();
    search_variant(variants);
    property_override("ro.rising.chipset", "Snapdragon 860 (7nm)");
    property_override("ro.rising.maintainer", "Ste0090 • honokascape");
}
