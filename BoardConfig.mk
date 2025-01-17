#
# Copyright (C) 2015 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

#
# This file sets variables that control the way modules are built
# thorughout the system. It should not be used to conditionally
# disable makefiles (the proper mechanism to control what gets
# included in a build is to use PRODUCT_PACKAGES in a product
# definition file).
#

# WARNING: This line must come *before* including the proprietary
# variant, so that it gets overwritten by the parent (which goes
# against the traditional rules of inheritance).

# Inherit from common a5-common
-include device/htc/a5-common/BoardConfigCommon.mk

# Assert
TARGET_OTA_ASSERT_DEVICE := htc_a5,htc_a5dwg,htc_a5dug,a5,a5dwg,a5dug

# Audio
AUDIO_FEATURE_ENABLED_MULTI_VOICE_SESSIONS := true
AUDIO_FEATURE_HTC_DUAL_SIM := true

# HIDL
DEVICE_MANIFEST_FILE += device/htc/a5dwg/manifest.xml

# Vendor Init
TARGET_INIT_VENDOR_LIB := //device/htc/a5dwg:libinit_a5dwg
TARGET_RECOVERY_DEVICE_MODULES += libinit_a5dwg

# Inherit from the proprietary version
-include vendor/htc/a5dwg/BoardConfigVendor.mk
