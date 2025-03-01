##
####
########
################
################################
################################################################
# https://docs.qmk.fm/config_options#features-that-can-be-enabled

KEY_OVERRIDE_ENABLE = yes
SEND_STRING_ENABLE = yes
CAPS_WORD_ENABLE = yes

# AUTOCORRECT_ENABLE ?= yes
CAPS_WORD_ENABLE ?= yes
CONSOLE_ENABLE ?= yes
# GRAVE_ESC_ENABLE ?= no
# NKRO_ENABLE ?= no
# SPACE_CADET_ENABLE ?= no
# TAP_DANCE_ENABLE ?= no

################################

ACHORDION_ENABLE ?= yes
CUSTOM_SHIFT_KEYS_ENABLE ?= no
LAYER_LOCK_ENABLE ?= no
ORBITAL_MOUSE_ENABLE ?= no
SENTENCE_CASE_ENABLE ?= no

################################################################

DEFERRED_EXEC_ENABLE = yes

ROOT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
include ${ROOT_DIR}../../../../../rules.mk

################################################################

COMBO_ENABLE = no  # avoid compile error, TODO: remove eventually
# EXTRAKEY_ENABLE = yes
# LTO_ENABLE = yes
# MOUSEKEY_ENABLE = yes
# REPEAT_KEY_ENABLE = yes
# UNICODE_ENABLE = no
# UNICODEMAP_ENABLE = no
# UCIS_ENABLE = no
# UNICODE_COMMON = yes

################################################################
################################
################
########
####
##
