/* $Id$ */

#ifndef NEWGRF_CONFIG_H
#define NEWGRF_CONFIG_H

/* GRF config bit flags */
enum {
	GCF_DISABLED,
	GCF_NOT_FOUND,
	GCF_ACTIVATED,
};

typedef struct GRFConfig {
	char *filename;
	char *name;
	char *info;
	uint32 grfid;

	uint8 flags;
	uint8 md5sum[16];
	uint32 param[0x80];
	uint8 num_params;

	struct GRFConfig *next;
} GRFConfig;

/* First item in list of all scanned NewGRFs */
extern GRFConfig *_all_grfs;

/* First item in list of current GRF set up */
extern GRFConfig *_grfconfig;

/* First item in list of default GRF set up */
extern GRFConfig *_grfconfig_newgame;

void ScanNewGRFFiles(void);
const GRFConfig *FindGRFConfig(uint32 grfid, uint8 *md5sum);
void ClearGRFConfigList(GRFConfig *config);
void ResetGRFConfig(bool defaults);
bool IsGoodGRFConfigList(void);
bool FillGRFDetails(GRFConfig *config);

#endif /* NEWGRF_CONFIG_H */
