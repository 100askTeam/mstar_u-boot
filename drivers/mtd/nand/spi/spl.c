#include <dm/uclass.h>
#include <linux/mtd/mtd.h>

static struct udevice *dev;
static struct mtd_info *mtd;

int spl_spinand_peb_size(void)
{
	return mtd->erasesize;
}

int spl_spinand_init(void)
{
	int ret;

	ret = uclass_get_device_by_driver(UCLASS_MTD, DM_DRIVER_GET(spinand), &dev);
	if (ret){
		//printf("Failed to probe spi-nand: %d\n", ret);
		return ret;
	}

	mtd = dev_get_uclass_priv(dev);

	return 0;
}

int spl_spinand_read_block(int block, int offset, int len, void *dst)
{
	int ret;
	size_t rlen;
	loff_t nandoff = (spl_spinand_peb_size() * block) + offset;

	printf("b: %x, o: %x, d: %08x, l: %x\n", block, offset, (unsigned) dst, len);
	ret = mtd_read(mtd, nandoff, len, &rlen, dst);
	printf("mtd read ret = %d, rlen %d\n", ret, (unsigned) rlen);

	       return ret;

	//return mtd_read(mtd, nandoff, len, &rlen, dst);
}
