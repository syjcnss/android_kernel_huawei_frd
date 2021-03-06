#ifndef _LINUX_HISI_BCI_BATTERY_H
#define _LINUX_HISI_BCI_BATTERY_H


enum charge_status_event{
    VCHRG_POWER_NONE_EVENT = 0,
    VCHRG_NOT_CHARGING_EVENT,
    VCHRG_START_CHARGING_EVENT,
    VCHRG_START_AC_CHARGING_EVENT,
    VCHRG_START_USB_CHARGING_EVENT,
    VCHRG_CHARGE_DONE_EVENT,
    VCHRG_STOP_CHARGING_EVENT,
    VCHRG_POWER_SUPPLY_OVERVOLTAGE,
    VCHRG_POWER_SUPPLY_WEAKSOURCE,
    VCHRG_STATE_WDT_TIMEOUT,
    BATTERY_LOW_WARNING,
    BATTERY_LOW_SHUTDOWN,
    BATTERY_MOVE,
};

#define CURRENT_OFFSET    (10)

#define ERROR_BATT_NOT_EXIST               (10403)
#define ERROR_BATT_TEMP_LOW                (10404)
#define ERROR_BATT_VOLT_HIGH               (10405)
#define ERROR_BATT_VOLT_LOW                (10406)
#define ERROR_BATT_TERMINATE_TOO_EARLY     (10407)
#define ERROR_BATT_NOT_TERMINATE           (10408)
#define ERROR_BATT_BAD_CURR_SENSOR         (10409)
#define ERROR_VBUS_VOLT_HIGH               (10410)
#define ERROR_WATCHDOG_RESET               (10411)
#define ERROR_CHARGE_CURR_OVERHIGH         (10412)
#define ERROR_DISCHARGE_CURR_OVERHIGH      (10413)
#define ERROR_CHARGE_CURR_ZERO             (10414)
#define ERROR_UFCAPCITY_DEBOUNCE_100       (0x0800)
#define ERROR_FCC_DEBOUNCE                 (0x1000)
#define ERROR_CAPACITY_CHANGE_FAST         (0x2000)
#define ERROR_BATT_TEMP_STAY               (0x4000)
#define ERROR_UFCAPCITY_DEBOUNCE_OTHER     (0x8000)
#define ERROR_CHARGE_TEMP_FAULT            (10415)
#define ERROR_CHARGE_BATT_TEMP_SHUTDOWN    (10416)
#define ERROR_CHARGE_BATT_CAPACITY         (10417)
#define ERROR_CHARGE_CHARGER_TS            (10418)
#define ERROR_CHARGE_OTG                   (10419)
#define ERROR_FCC_INVALID                  (10430)


#define IMPOSSIBLE_IAVG            (9999)

/* State-of-Charge-Threshold 1 bit */
#define BQ_FLAG_SOC1             (1<<2)
/* State-of-Charge-Threshold Final bit */
#define BQ_FLAG_SOCF             (1<<1)
#define BQ_FLAG_LOCK       		 (BQ_FLAG_SOC1 | BQ_FLAG_SOCF)


#define BAT_VOL_3200    (3200)
#define BAT_VOL_3500    (3500)
#define BAT_VOL_3550    (3550)
#define BAT_VOL_3600    (3600)
#define BAT_VOL_3700    (3700)
#define BAT_VOL_3800    (3800)
#define BAT_VOL_3850    (3850)
#define BAT_VOL_3900    (3900)
#define BAT_VOL_3950    (3950)
#define BAT_VOL_4000    (4000)
#define BAT_VOL_4200    (4200)
#define BAT_VOL_4250    (4250)

#define RECHG_PROTECT_THRESHOLD    (150)

enum plugin_status {
    /* no charger plugin */
    PLUGIN_DEVICE_NONE,
   /* plugin usb charger */
    PLUGIN_USB_CHARGER,
   /* plugin ac charger */
   PLUGIN_AC_CHARGER,
};


typedef enum{
    BAT_BOARD_SFT  = 0,
    BAT_BOARD_UDP  = 1,
    BAT_BOARD_ASIC = 2,
    BAT_BOARD_MAX
}battery_board_type_en;
int hisi_register_notifier(struct notifier_block *nb,
                unsigned int events);
int hisi_unregister_notifier(struct notifier_block *nb,
                unsigned int events);
int hisi_bci_show_capacity(void);
struct class *hw_power_get_class(void);
struct dsm_client *get_battery_dclient(void);
extern enum fcp_check_stage_type  fcp_get_stage_status(void);
#endif
