#
# Copyright (C) 2021 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit some common Rising stuff.
$(call inherit-product, vendor/rising/config/rising.mk)

# Inherit from vayu device
$(call inherit-product, device/xiaomi/vayu/device.mk)

# Device Identifiers
RISING_MAINTAINER := ste0090
RISING_CHIPSET := SDM860

WITH_GMS := true
TARGET_USE_GOOGLE_TELEPHONY := true
TARGET_ENABLE_BLUR := true
TARGET_PREBUILT_PIXEL_LAUNCHER := false
TARGET_FACE_UNLOCK_SUPPORTED := true
USER_BUILD_NO_CHANGELOG := 1
TARGET_DISABLE_EPPE := true
INLINE_KERNEL_BUILDING := true

PRODUCT_NAME := rising_vayu
PRODUCT_DEVICE := vayu
PRODUCT_MANUFACTURER := Xiaomi
PRODUCT_BRAND := POCO
PRODUCT_MODEL := POCO X3 Pro

PRODUCT_GMS_CLIENTID_BASE := android-xiaomi

PRODUCT_BUILD_PROP_OVERRIDES += \
    PRIVATE_BUILD_DESC="vayu_global-user 13 RKQ1.200826.002 V14.0.3.0.TJUMIXM release-keys"

BUILD_FINGERPRINT := POCO/vayu_global/vayu:13/RKQ1.200826.002/V14.0.3.0.TJUMIXM:user/release-keys
