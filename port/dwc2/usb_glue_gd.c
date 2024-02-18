#include "usb_config.h"
#include "stdint.h"
#include "usb_dwc2_reg.h"

/* you can find this config in function:usb_core_init, file:drv_usb_core.c, for example:
 *
 *  usb_regs->gr->GCCFG |= GCCFG_PWRON | GCCFG_VBUSACEN | GCCFG_VBUSBCEN;
 * 
*/

uint32_t usbd_get_dwc2_gccfg_conf(uint32_t reg_base)
{
#ifdef CONFIG_USB_HS
    return 0;
#else
    return ((1 << 16) | (1 << 18) | (1 << 19));
#endif
}

uint32_t usbh_get_dwc2_gccfg_conf(uint32_t reg_base)
{
#ifdef CONFIG_USB_DWC2_ULPI_PHY
    return 0;
#else
    return ((1 << 16) | (1 << 18) | (1 << 19));
#endif
}