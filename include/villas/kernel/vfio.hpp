//TODO: Move to cmake args
//#define FPGA_PLATFORM
#define FPGA_PCI

#if defined(FPGA_PLATFORM)
    #define KERNEL_MODULE_VFIO
#endif

#if defined(FPGA_PCI)
    #define KERNEL_MODULE_VFIO
    #define KERNEL_MODULE_VFIO_PCI
    #define KERNEL_MODULE_VFIO_IOMMU_TYPE1
#endif

static constexpr const char* const requiredKernelModules[] = {
    #if defined(KERNEL_MODULE_VFIO)
    "vfio",
    #endif // KERNEL_MODULE_VFIO_PCI

    #if defined(KERNEL_MODULE_VFIO_PCI)
    "vfio_pci",
    #endif // KERNEL_MODULE_VFIO_PCI
    
    #if defined(KERNEL_MODULE_VFIO_IOMMU_TYPE1)
    "vfio_iommu_type1"
    #endif // KERNEL_MODULE_VFIO_IOMMU_TYPE1
};