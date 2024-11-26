LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := RemovePackagesVayu
LOCAL_MODULE_CLASS := APPS
LOCAL_MODULE_TAGS := optional
LOCAL_OVERRIDES_PACKAGES := Updater LocationHistoryPrebuilt PrebuiltGoogleTelemetryTvp WallpaperEmojiPrebuilt-v470 WallpaperEffect GoogleFeedback GooglePrintRecommendationService AmbientStreaming talkback
LOCAL_UNINSTALLABLE_MODULE := true
LOCAL_CERTIFICATE := PRESIGNED
LOCAL_SRC_FILES := /dev/null
include $(BUILD_PREBUILT)
