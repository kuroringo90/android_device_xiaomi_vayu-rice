#
# Copyright (C) 2021 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/aosp_base_telephony.mk)

# Inherit some common stuff.
$(call inherit-product, vendor/calyx/config/common.mk)

# Inherit from vayu device
$(call inherit-product, device/xiaomi/vayu/device.mk)

PRODUCT_NAME := calyx_vayu
PRODUCT_DEVICE := vayu
PRODUCT_MANUFACTURER := Xiaomi
PRODUCT_BRAND := POCO
PRODUCT_MODEL := POCO X3 Pro

PRODUCT_BUILD_PROP_OVERRIDES += \
    PRIVATE_BUILD_DESC="vayu_global-user 12 RKQ1.200826.002 V13.0.8.0.SJUMIXM release-keys"

BUILD_FINGERPRINT := Xiaomi/vayu_global/vayu:12/RKQ1.200826.002/V13.0.8.0.SJUMIXM:user/release-keys
