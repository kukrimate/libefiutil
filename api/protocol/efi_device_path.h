/*
 * EFI device path protocol
 */

#ifndef EFI_DEVICE_PATH_H
#define EFI_DEVICE_PATH_H

#define EFI_DEVICE_PATH_PROTOCOL_GUID \
  { 0x09576e91, 0x6d3f, 0x11d2, 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, \
	0x72, 0x3b}

typedef struct efi_device_path_protocol efi_device_path_protocol;
struct efi_device_path_protocol {
	efi_u8 type;
	efi_u8 sub_type;
	efi_u8 length[2];
};

/* Media Device Path */
#define MEDIA_DEVICE_PATH 0x04

/* Hard Drive Device Path Sub-type */
#define MEDIA_HARDDRIVE_DP 0x01
typedef struct {
	efi_device_path_protocol	header;
	efi_u32				partition_number;
	efi_u64				partition_start;
	efi_u64				partition_size;
	efi_u8				signature[16];
	efi_u8				mbr_type;
	efi_u8				signature_type;
} harddrive_device_path;

#define MBR_TYPE_PCAT                       0x01
#define MBR_TYPE_EFI_PARTITION_TABLE_HEADER 0x02

#define NO_DISK_SIGNATURE   0x00
#define SIGNATURE_TYPE_MBR  0x01
#define SIGNATURE_TYPE_GUID 0x02

/* File Path Device Path Sub-type */
#define MEDIA_FILEPATH_DP 0x04
typedef struct {
	efi_device_path_protocol	header;
	efi_ch16			path_name[1];
} filepath_device_path;

/* End of Device Path */
#define END_DEVICE_PATH_TYPE             0x7f
#define END_ENTIRE_DEVICE_PATH_SUBTYPE   0xff
#define END_INSTANCE_DEVICE_PATH_SUBTYPE 0x01

#endif
