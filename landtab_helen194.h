// landtab_helen194: definitions for HELEN 194 point shapes
//
//

#ifndef STASM_LANDTAB_helen194_H
#define STASM_LANDTAB_helen194_H

// Note that the AT_Hat bit is ignored if pyr lev > HAT_START_LEV

static const LANDMARK_INFO LANDMARK_INFO_TAB[194] = // 194 points
{
    //   par pre next weight bits
    {  40, 139, 1, 1., AT_Beard        }, // 000	L_Jaw
    {  39, -1, -1, 1., AT_Beard        }, // 001 	L_Jaw
    {  38, -1, -1, 1., AT_Beard        }, // 002 	L_JawNoseLine
    {  37, -1, -1, 1., AT_Beard        }, // 003 	L_Jaw
    {  36, -1, -1, 1., AT_Beard        }, // 004
    {  35, -1, -1, 1., AT_Beard        }, // 005
    {  34, -1, -1, 1., AT_Beard        }, // 006 	L_MouthLine
    {  33, -1, -1, 1., AT_Beard        }, // 007
    {  32, -1, -1, 1., AT_Beard        }, // 008
    {  31, -1, -1, 1., AT_Beard        }, // 009
    {  30, -1, -1, 1., AT_Beard        }, // 010
    {  29, -1, -1, 1., AT_Beard        }, // 011
    {  28, -1, -1, 1., AT_Beard        }, // 012
    {  27, -1, -1, 1., AT_Beard        }, // 013
    {  26, -1, -1, 1., AT_Beard        }, // 014
    {  25, -1, -1, 1., AT_Beard        }, // 015
    {  24, -1, -1, 1., AT_Beard        }, // 016
    {  23, -1, -1, 1., AT_Beard        }, // 017
    {  22, -1, -1, 1., AT_Beard | AT_Mustache     }, // 018
    {  21, -1, -1, 1., AT_Beard | AT_Mustache     }, // 019
    {  -1, -1, -1, 1., AT_Beard | AT_Mustache     }, // 020 	CTipOfChin
    {  19, -1, -1, 1., AT_Beard | AT_Mustache     }, // 021
    {  18, -1, -1, 1., AT_Beard | AT_Mustache     }, // 022
    {  17, -1, -1, 1., AT_Beard   | AT_Hat   }, // 023
    {  16, -1, -1, 1., AT_Beard   | AT_Hat   }, // 024
    {  15, -1, -1, 1., AT_Beard   | AT_Hat   }, // 025
    {  14, -1, -1, 1., AT_Beard   | AT_Hat   }, // 026
    {  13, -1, -1, 1., AT_Beard   | AT_Hat   }, // 027
    {  12, -1, -1, 1., AT_Beard   | AT_Hat   }, // 028
    {  11, -1, -1, 1., AT_Beard   | AT_Hat   }, // 029
    {  10, -1, -1, 1., AT_Beard   | AT_Hat   }, // 030
    {  9, -1, -1, 1., AT_Beard   | AT_Hat   }, // 031
    {  8, -1, -1, 1., AT_Beard   | AT_Hat   }, // 032
    {  7, -1, -1, 1., AT_Beard   | AT_Hat   }, // 033
    {  6, -1, -1, 1., AT_Beard   | AT_Hat   }, // 034
    {  5, -1, -1, 1., AT_Beard   | AT_Hat   }, // 035
    {  4, -1, -1, 1., AT_Beard   | AT_Hat   }, // 036
    {  3, -1, -1, 1., AT_Beard   | AT_Hat   }, // 037
    {  2, -1, -1, 1., AT_Beard   | AT_Hat   }, // 038
    {  1, -1, -1, 1., AT_Beard   | AT_Hat   }, // 039
    {  0, 39, 119, 1., AT_Beard   | AT_Hat   }, // 040 	R_Jaw
    
    {  57, 40, 42, 1., AT_Glasses | AT_Hat }, // 041 	L_Nose
    {  56, -1, -1, 1., AT_Glasses | AT_Hat }, // 042
    {  55, -1, -1, 1., AT_Hat   }, // 043
    {  54, -1, -1, 1., AT_Hat   }, // 044
    {  53, -1, -1, 1., AT_Hat   }, // 045
    {  52, -1, -1, 1., AT_Hat   }, // 046
    {  51, -1, -1, 1., AT_Hat   }, // 047
    {  50, -1, -1, 1., AT_Hat   }, // 048
    {  -1, -1, -1, 1., AT_Hat   }, // 049 	CNoseTip
    {  48, -1, -1, 1., AT_Hat   }, // 050
    {  47, -1, -1, 1., AT_Hat   }, // 051
    {  46, -1, -1, 1., AT_Hat   }, // 052
    {  45, -1, -1, 1., AT_Hat   }, // 053
    {  44, -1, -1, 1., AT_Hat   }, // 054
    {  43, -1, -1, 1., AT_Hat   }, // 055
    {  42, -1, -1, 1., AT_Glasses | AT_Hat }, // 056
    {  41, 56, 0, 1., AT_Glasses | AT_Hat }, // 057 	R_Nose
    
    {  72, 86, 59, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 058  L_UU_Mouth
    {  71, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 059
    {  70, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 060
    {  69, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 061
    {  68, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 062
    {  67, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 063
    {  66, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 064
    {  -1, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 065  UUMiddle
    {  64, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 066
    {  63, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 067
    {  62, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 068
    {  61, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 069
    {  60, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 070
    {  59, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 071
    {  58, 71, 73, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 072  R_UU_Mouth
    
    {  86, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 073   R_LL_Mouth
    {  85, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 074
    {  84, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 075
    {  83, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 076
    {  82, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 077
    {  81, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 078
    {  80, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 079 //
    {  79, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 080 //
    {  78, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 081
    {  77, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 082
    {  76, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 083
    {  75, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 084
    {  74, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 085
    {  73, -1, -1, 1., AT_Mustache | AT_Beard  | AT_Hat }, // 086   L_LL
    { 100, -1, -1, 1., AT_Hat   }, // 087 	L_UL
    {  99, -1, -1, 1., AT_Hat   }, // 088
    {  98, -1, -1, 1., AT_Hat   }, // 089
    {  97, -1, -1, 1., AT_Hat   }, // 090
    {  96, -1, -1, 1., AT_Hat   }, // 091
    {  95, -1, -1, 1., AT_Hat   }, // 092
    {  94, -1, -1, 1., AT_Hat   }, // 093
    {  93, -1, -1, 1., AT_Hat   }, // 094
    {  92, -1, -1, 1., AT_Hat   }, // 095
    {  91, -1, -1, 1., AT_Hat   }, // 096
    {  90, -1, -1, 1., AT_Hat   }, // 097
    {  89, -1, -1, 1., AT_Hat   }, // 098
    {  88, -1, -1, 1., AT_Hat   }, // 099
    {  87, -1, -1, 1., AT_Hat   }, // 100 	R_UL
    {  113, -1, 102, 1., AT_Hat   }, // 101
    {  112, -1, -1, 1., AT_Hat   }, // 102
    {  111, -1, -1, 1., AT_Hat   }, // 103
    {  110, -1, -1, 1., AT_Hat   }, // 104
    {  109, -1, -1, 1., AT_Hat   }, // 105
    {  108, -1, -1, 1., AT_Hat   }, // 106
    {   -1, -1, -1, 1., AT_Hat   }, // 107
    {  106, -1, -1, 1., AT_Hat   }, // 108
    {  105, -1, -1, 1., AT_Hat   }, // 109
    {  104, -1, -1, 1., AT_Hat   }, // 110
    {  103, -1, -1, 1., AT_Hat   }, // 111
    {  102, -1, -1, 1., AT_Hat   }, // 112
    {  101, -1, 87, 1., AT_Hat   }, // 113 	L_LU
    
    { 134, 153, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 114    R_Eye_LCorner
    { 135, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 115
    { 136, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 116
    { 137, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 117
    { 138, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 118
    { 139, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 119
    { 140, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 120
    { 141, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 121
    { 142, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 122
    { 143, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 123
    { 144, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 124
    { 145, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 125    R_Eye_RCorner
    { 146, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 126
    { 147, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 127
    { 148, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 128
    { 149, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 129
    { 150, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 130
    { 151, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 131
    { 152, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 132
    { 153, -1, 134, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 133
    { 114, 133, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 134    L_Eye_RCorner
    { 115, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 135
    { 116, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 136
    { 117, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 137
    { 118, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 138
    { 119, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 139
    { 120, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 140
    { 121, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 141
    { 122, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 142
    { 123, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 143
    { 124, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 144
    { 125, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 145    R_Eye_LCorner
    { 126, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 146
    { 127, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 147
    { 128, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 148
    { 129, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 149
    { 130, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 150
    { 131, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 151
    { 132, -1, -1, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 152
    { 133, -1, 114, 1., AT_Glasses | AT_BadEye  | AT_Hat }, // 153
    
    { 174, 153, -1, 1., AT_Hat   }, // 154    R_EyeBrow_U
    { 175, -1, -1, 1., AT_Hat   }, // 155
    { 176, -1, -1, 1., AT_Hat   }, // 156
    { 177, -1, -1, 1., AT_Hat   }, // 157
    { 178, -1, -1, 1., AT_Hat   }, // 158
    { 179, -1, -1, 1., AT_Hat   }, // 159
    { 180, -1, -1, 1., AT_Hat   }, // 160
    { 181, -1, -1, 1., AT_Hat   }, // 161
    { 182, -1, -1, 1., AT_Hat   }, // 162
    { 183, -1, -1, 1., AT_Hat   }, // 163
    { 184, -1, -1, 1., AT_Glasses  | AT_Hat }, // 164    R_EyeBrow_L
    { 185, -1, -1, 1., AT_Glasses  | AT_Hat }, // 165
    { 186, -1, -1, 1., AT_Glasses  | AT_Hat }, // 166
    { 187, -1, -1, 1., AT_Glasses  | AT_Hat }, // 167
    { 188, -1, -1, 1., AT_Glasses  | AT_Hat }, // 168
    { 189, -1, -1, 1., AT_Glasses  | AT_Hat }, // 169
    { 190, -1, -1, 1., AT_Glasses  | AT_Hat }, // 170
    { 191, -1, -1, 1., AT_Glasses  | AT_Hat }, // 171
    { 192, -1, -1, 1., AT_Glasses  | AT_Hat }, // 172
    { 193, -1, 174, 1., AT_Glasses  | AT_Hat }, // 173
    
    { 154, 133, -1, 1., AT_Hat   }, // 174    L_EyeBrow_U
    { 155, -1, -1, 1., AT_Hat   }, // 175
    { 156, -1, -1, 1., AT_Hat   }, // 176
    { 157, -1, -1, 1., AT_Hat   }, // 177
    { 158, -1, -1, 1., AT_Hat   }, // 178
    { 159, -1, -1, 1., AT_Hat   }, // 179
    { 160, -1, -1, 1., AT_Hat   }, // 180
    { 161, -1, -1, 1., AT_Hat   }, // 181
    { 162, -1, -1, 1., AT_Hat   }, // 182
    { 163, -1, -1, 1., AT_Hat   }, // 183
    { 164, -1, -1, 1., AT_Glasses | AT_Hat  }, // 184    L_EyeBrow_L
    { 165, -1, -1, 1., AT_Glasses | AT_Hat  }, // 185
    { 166, -1, -1, 1., AT_Glasses | AT_Hat  }, // 186
    { 167, -1, -1, 1., AT_Glasses | AT_Hat  }, // 187
    { 168, -1, -1, 1., AT_Glasses | AT_Hat  }, // 188
    { 169, -1, -1, 1., AT_Glasses | AT_Hat  }, // 189
    { 170, -1, -1, 1., AT_Glasses | AT_Hat  }, // 190
    { 171, -1, -1, 1., AT_Glasses | AT_Hat  }, // 191
    { 172, -1, -1, 1., AT_Glasses | AT_Hat  }, // 192
    { 173, -1, 154, 1., AT_Glasses | AT_Hat  }, // 193
};

#endif // STASM_LANDTAB_helen194_H
