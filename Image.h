static int swidth = 24; // change these
static int sheight = 29; // change these


static const int header_data[]  = { // add data here
0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xffe
,0xee9
,0x997
,0x777
,0x77b
,0xbbe
,0xeef
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xffc
,0xcc1
,0x110
,0x000
,0x000
,0x002
,0x225
,0x55e
,0xeef
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xffe
,0xee4
,0x440
,0x000
,0x000
,0x000
,0x004
,0x442
,0x226
,0x66f
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xffe
,0xee0
,0x001
,0x110
,0x000
,0x000
,0x001
,0x110
,0x000
,0x00e
,0xeef
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xffd
,0xdd0
,0x004
,0x441
,0x110
,0x003
,0x334
,0x441
,0x110
,0x00b
,0xbbf
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xffe
,0xee3
,0x337
,0x774
,0x443
,0x33a
,0xaa9
,0x992
,0x220
,0x009
,0x99f
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xffe
,0xee4
,0x441
,0x119
,0x857
,0x745
,0x555
,0x554
,0x440
,0x009
,0x99f
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfe2
,0x21b
,0x94d
,0xb3d
,0xb3c
,0xa3c
,0xa71
,0x110
,0x007
,0x77f
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xffe
,0xee6
,0x53c
,0x92d
,0xb3d
,0xb5c
,0xa3c
,0xa34
,0x310
,0x115
,0x55f
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfe4
,0x44a
,0x94b
,0xa4b
,0xa3b
,0xa4c
,0xb84
,0x434
,0x442
,0x22d
,0xddf
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xffc
,0xcc3
,0x33c
,0xcbc
,0xb7c
,0xb7c
,0xcbe
,0xeeb
,0xbb0
,0x000
,0x005
,0x55e
,0xeef
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xffe
,0xee3
,0x339
,0x99e
,0xeed
,0xdcd
,0xdde
,0xeee
,0xeee
,0xee3
,0x330
,0x000
,0x00a
,0xaaf
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xffe
,0xee7
,0x773
,0x33e
,0xeee
,0xeee
,0xeee
,0xeee
,0xeef
,0xffe
,0xee8
,0x880
,0x000
,0x001
,0x11d
,0xddf
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xffb
,0xbb0
,0x006
,0x66e
,0xeee
,0xeed
,0xdde
,0xeef
,0xffe
,0xeed
,0xddc
,0xcc0
,0x000
,0x000
,0x004
,0x44f
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xff4
,0x440
,0x00c
,0xcce
,0xeef
,0xffe
,0xeef
,0xfff
,0xfff
,0xffe
,0xeed
,0xdd6
,0x661
,0x110
,0x000
,0x00b
,0xbbf
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xffd
,0xdd1
,0x115
,0x55e
,0xeef
,0xffe
,0xeef
,0xfff
,0xfff
,0xfff
,0xfff
,0xffe
,0xeed
,0xdd1
,0x111
,0x110
,0x005
,0x55f
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xff8
,0x880
,0x00b
,0xbbf
,0xfff
,0xffe
,0xeee
,0xeef
,0xfff
,0xfff
,0xfff
,0xfff
,0xffe
,0xee2
,0x220
,0x000
,0x001
,0x11e
,0xeef
,0xfff
,0xfff
,0xfff
,0xfff
,0xffe
,0xee3
,0x332
,0x22e
,0xeef
,0xfff
,0xffe
,0xeee
,0xeef
,0xfff
,0xfff
,0xfff
,0xfff
,0xffe
,0xee3
,0x330
,0x000
,0x000
,0x00b
,0xbbf
,0xfff
,0xfff
,0xfff
,0xfff
,0xff8
,0x881
,0x114
,0x44e
,0xeef
,0xfff
,0xffe
,0xeee
,0xeef
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xff4
,0x440
,0x000
,0x000
,0x009
,0x99f
,0xfff
,0xfff
,0xfff
,0xfff
,0xfe7
,0x663
,0x206
,0x66f
,0xfff
,0xfff
,0xffe
,0xeef
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xfee
,0xee4
,0x441
,0x111
,0x110
,0x009
,0x99f
,0xfff
,0xfff
,0xfff
,0xffe
,0xeec
,0xb5d
,0xa07
,0x62b
,0xbbe
,0xfef
,0xffe
,0xeee
,0xeef
,0xfff
,0xfff
,0xfff
,0xffe
,0xeee
,0xc54
,0x410
,0x000
,0x003
,0x31d
,0xcaf
,0xfff
,0xfff
,0xeee
,0xedb
,0xb8b
,0x91d
,0xa0d
,0xa04
,0x318
,0x88e
,0xeee
,0xeee
,0xeef
,0xfff
,0xfff
,0xfff
,0xffd
,0xddd
,0xa06
,0x500
,0x000
,0x00a
,0x80e
,0xc7f
,0xfff
,0xffd
,0xc7c
,0xa1b
,0x90c
,0xa0d
,0xa0d
,0xa0a
,0x800
,0x006
,0x66e
,0xeef
,0xfff
,0xfff
,0xfff
,0xfff
,0xffb
,0xbbc
,0xa0a
,0x807
,0x619
,0x80d
,0xa0d
,0xb2e
,0xedf
,0xffd
,0xb5d
,0xa0d
,0xa0d
,0xa0d
,0xa0d
,0xa0c
,0xa05
,0x400
,0x00c
,0xccf
,0xfff
,0xfff
,0xfff
,0xfff
,0xffa
,0xa9c
,0x91d
,0xa0c
,0xa0d
,0xa0d
,0xb0d
,0xa0d
,0xb3e
,0xedb
,0xa6c
,0xa0d
,0xb0d
,0xb0d
,0xb0d
,0xb0d
,0xa0c
,0x90a
,0xa8e
,0xeef
,0xfff
,0xfff
,0xffe
,0xeea
,0xaa3
,0x21c
,0x90d
,0xb0d
,0xb0d
,0xa0d
,0xa0d
,0xb0d
,0xb0d
,0xc5b
,0xa5c
,0x90d
,0xa0d
,0xa0d
,0xb0d
,0xb0d
,0xb0d
,0xa0a
,0x82a
,0xaad
,0xddc
,0xcca
,0xaa5
,0x550
,0x003
,0x20c
,0xa0d
,0xb0d
,0xa0d
,0xa0c
,0xa0c
,0xa0d
,0xb4e
,0xecc
,0xb6a
,0x81a
,0x80b
,0x91b
,0x90d
,0xa0d
,0xa0d
,0xa0a
,0x811
,0x100
,0x000
,0x000
,0x000
,0x000
,0x004
,0x30c
,0xa0d
,0xa0c
,0xa0c
,0x90c
,0xa3e
,0xdbf
,0xeef
,0xffe
,0xeee
,0xedd
,0xcab
,0xa79
,0x839
,0x71a
,0x81a
,0x818
,0x727
,0x77a
,0xaab
,0xbbb
,0xbbb
,0xbba
,0xaa8
,0x86a
,0x80c
,0x90b
,0x90c
,0xa5e
,0xeef
,0xeef
,0xfff
,0xfff
,0xfff
,0xfff
,0xfff
,0xeee
,0xeed
,0xdca
,0xa7a
,0x96d
,0xccf
,0xfef
,0xfff
,0xfff
,0xfff
,0xfff
,0xffe
,0xeea
,0xa7a
,0x95c
,0xb8e
,0xeef
,0xfff
,0xfff
,0xfff
,0xfff
};
