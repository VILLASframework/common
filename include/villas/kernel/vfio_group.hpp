/** Virtual Function IO wrapper around kernel API
 *
 * @file
 * @author Niklas Eiling <niklas.eiling@eonerc.rwth-aachen.de>
 * @author Steffen Vogel <svogel2@eonerc.rwth-aachen.de>
 * @author Daniel Krebs <github@daniel-krebs.net>
 * @copyright 2022, Niklas Eiling
 * @copyright 2014-2021, Steffen Vogel
 * @copyright 2018, Daniel Krebs
 *********************************************************************************/

#pragma once

#include <list>
#include <vector>
#include <memory>

#include <linux/vfio.h>
#include <sys/mman.h>

#include <villas/kernel/vfio_device.hpp>
#include <villas/log.hpp>

namespace villas {
namespace kernel {
namespace vfio {

class Group {

public:
	using Ptr = std::shared_ptr<Group>;

	Group(int index, bool iommuEnabled);
	~Group();

	void setAttachedToContainer()
	{
		attachedToContainer = true;
	}

	bool isAttachedToContainer()
	{
		return attachedToContainer;
	}

	int getFileDescriptor()
	{
		return fd;
	}

	int getIndex()
	{
		return index;
	}

	Device::Ptr attachDevice(Device::Ptr device);
	Device::Ptr attachDevice(const std::string& name, const kernel::pci::Device *pci_device = nullptr);

	bool checkStatus();
	void dump();

private:
	// VFIO group file descriptor
	int fd;

	// Index of the IOMMU group as listed under /sys/kernel/iommu_groups/
	int index;

	bool attachedToContainer;

	// Status of group
	struct vfio_group_status status;

	// All devices owned by this group
	std::list<Device::Ptr> devices;

	Logger log;
};

} // namespace vfio
} // namespace kernel
} // namespace villas
