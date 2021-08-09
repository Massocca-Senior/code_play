#
# Copyright (C) 2006-2020 oppo.com
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=demo_id
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define KernelPackage/demo_id
  SUBMENU:=Vendor modules
  TITLE:=Module for of_match and id table test
  AUTOLOAD:=$(call AutoLoad,70,demo_id)
  FILES:=$(PKG_BUILD_DIR)/demo_id.ko
endef

define Build/Compile
	$(MAKE) -C "$(LINUX_DIR)" \
		$(KERNEL_MAKE_FLAGS) \
		SUBDIRS="$(PKG_BUILD_DIR)" \
		EXTRA_CFLAGS="$(BUILDFLAGS)" \
		modules
endef

$(eval $(call KernelPackage,demo_id))
