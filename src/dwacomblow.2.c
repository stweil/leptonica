/*====================================================================*
 -  Copyright (C) 2001 Leptonica.  All rights reserved.
 -
 -  Redistribution and use in source and binary forms, with or without
 -  modification, are permitted provided that the following conditions
 -  are met:
 -  1. Redistributions of source code must retain the above copyright
 -     notice, this list of conditions and the following disclaimer.
 -  2. Redistributions in binary form must reproduce the above
 -     copyright notice, this list of conditions and the following
 -     disclaimer in the documentation and/or other materials
 -     provided with the distribution.
 -
 -  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 -  ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 -  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 -  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL ANY
 -  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 -  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 -  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 -  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 -  OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 -  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 -  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *====================================================================*/

/*!
 *     Low-level fast binary morphology with auto-generated sels
 *
 *      Dispatcher:
 *             int32_t    fmorphopgen_low_2()
 *
 *      Static Low-level:
 *             void       fdilate_2_*()
 *             void       ferode_2_*()
 */

#ifdef HAVE_CONFIG_H
#include <config_auto.h>
#endif  /* HAVE_CONFIG_H */

#include "allheaders.h"

static void  fdilate_2_0(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_0(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_1(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_1(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_2(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_2(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_3(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_3(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_4(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_4(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_5(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_5(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_6(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_6(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_7(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_7(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_8(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_8(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_9(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_9(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_10(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_10(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_11(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_11(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_12(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_12(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_13(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_13(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_14(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_14(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_15(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_15(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_16(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_16(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_17(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_17(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_18(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_18(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_19(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_19(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_20(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_20(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_21(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_21(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_22(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_22(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_23(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_23(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_24(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_24(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_25(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_25(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_26(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_26(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_27(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_27(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_28(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_28(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_29(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_29(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_30(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_30(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_31(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_31(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_32(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_32(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_33(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_33(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_34(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_34(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_35(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_35(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_36(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_36(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_37(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_37(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_38(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_38(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_39(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_39(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_40(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_40(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_41(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_41(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_42(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_42(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_43(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_43(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_44(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_44(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_45(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_45(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_46(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_46(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_47(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_47(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_48(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_48(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_49(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_49(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_50(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_50(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_51(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_51(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_52(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_52(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_53(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_53(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_54(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_54(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_55(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_55(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_56(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_56(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_57(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_57(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_58(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_58(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_59(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_59(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_60(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_60(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_61(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_61(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_62(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_62(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_63(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_63(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_64(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_64(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_65(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_65(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_66(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_66(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_67(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_67(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_68(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_68(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_69(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_69(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_70(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_70(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_71(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_71(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_72(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_72(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_73(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_73(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_74(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_74(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  fdilate_2_75(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);
static void  ferode_2_75(uint32_t *, int32_t, int32_t, int32_t, uint32_t *, int32_t);


/*---------------------------------------------------------------------*
 *                          Fast morph dispatcher                      *
 *---------------------------------------------------------------------*/
/*!
 *  fmorphopgen_low_2()
 *
 *       a dispatcher to appropriate low-level code
 */
int32_t
fmorphopgen_low_2(uint32_t  *datad,
                  int32_t    w,
                  int32_t    h,
                  int32_t    wpld,
                  uint32_t  *datas,
                  int32_t    wpls,
                  int32_t    index)
{

    switch (index)
    {
    case 0:
        fdilate_2_0(datad, w, h, wpld, datas, wpls);
        break;
    case 1:
        ferode_2_0(datad, w, h, wpld, datas, wpls);
        break;
    case 2:
        fdilate_2_1(datad, w, h, wpld, datas, wpls);
        break;
    case 3:
        ferode_2_1(datad, w, h, wpld, datas, wpls);
        break;
    case 4:
        fdilate_2_2(datad, w, h, wpld, datas, wpls);
        break;
    case 5:
        ferode_2_2(datad, w, h, wpld, datas, wpls);
        break;
    case 6:
        fdilate_2_3(datad, w, h, wpld, datas, wpls);
        break;
    case 7:
        ferode_2_3(datad, w, h, wpld, datas, wpls);
        break;
    case 8:
        fdilate_2_4(datad, w, h, wpld, datas, wpls);
        break;
    case 9:
        ferode_2_4(datad, w, h, wpld, datas, wpls);
        break;
    case 10:
        fdilate_2_5(datad, w, h, wpld, datas, wpls);
        break;
    case 11:
        ferode_2_5(datad, w, h, wpld, datas, wpls);
        break;
    case 12:
        fdilate_2_6(datad, w, h, wpld, datas, wpls);
        break;
    case 13:
        ferode_2_6(datad, w, h, wpld, datas, wpls);
        break;
    case 14:
        fdilate_2_7(datad, w, h, wpld, datas, wpls);
        break;
    case 15:
        ferode_2_7(datad, w, h, wpld, datas, wpls);
        break;
    case 16:
        fdilate_2_8(datad, w, h, wpld, datas, wpls);
        break;
    case 17:
        ferode_2_8(datad, w, h, wpld, datas, wpls);
        break;
    case 18:
        fdilate_2_9(datad, w, h, wpld, datas, wpls);
        break;
    case 19:
        ferode_2_9(datad, w, h, wpld, datas, wpls);
        break;
    case 20:
        fdilate_2_10(datad, w, h, wpld, datas, wpls);
        break;
    case 21:
        ferode_2_10(datad, w, h, wpld, datas, wpls);
        break;
    case 22:
        fdilate_2_11(datad, w, h, wpld, datas, wpls);
        break;
    case 23:
        ferode_2_11(datad, w, h, wpld, datas, wpls);
        break;
    case 24:
        fdilate_2_12(datad, w, h, wpld, datas, wpls);
        break;
    case 25:
        ferode_2_12(datad, w, h, wpld, datas, wpls);
        break;
    case 26:
        fdilate_2_13(datad, w, h, wpld, datas, wpls);
        break;
    case 27:
        ferode_2_13(datad, w, h, wpld, datas, wpls);
        break;
    case 28:
        fdilate_2_14(datad, w, h, wpld, datas, wpls);
        break;
    case 29:
        ferode_2_14(datad, w, h, wpld, datas, wpls);
        break;
    case 30:
        fdilate_2_15(datad, w, h, wpld, datas, wpls);
        break;
    case 31:
        ferode_2_15(datad, w, h, wpld, datas, wpls);
        break;
    case 32:
        fdilate_2_16(datad, w, h, wpld, datas, wpls);
        break;
    case 33:
        ferode_2_16(datad, w, h, wpld, datas, wpls);
        break;
    case 34:
        fdilate_2_17(datad, w, h, wpld, datas, wpls);
        break;
    case 35:
        ferode_2_17(datad, w, h, wpld, datas, wpls);
        break;
    case 36:
        fdilate_2_18(datad, w, h, wpld, datas, wpls);
        break;
    case 37:
        ferode_2_18(datad, w, h, wpld, datas, wpls);
        break;
    case 38:
        fdilate_2_19(datad, w, h, wpld, datas, wpls);
        break;
    case 39:
        ferode_2_19(datad, w, h, wpld, datas, wpls);
        break;
    case 40:
        fdilate_2_20(datad, w, h, wpld, datas, wpls);
        break;
    case 41:
        ferode_2_20(datad, w, h, wpld, datas, wpls);
        break;
    case 42:
        fdilate_2_21(datad, w, h, wpld, datas, wpls);
        break;
    case 43:
        ferode_2_21(datad, w, h, wpld, datas, wpls);
        break;
    case 44:
        fdilate_2_22(datad, w, h, wpld, datas, wpls);
        break;
    case 45:
        ferode_2_22(datad, w, h, wpld, datas, wpls);
        break;
    case 46:
        fdilate_2_23(datad, w, h, wpld, datas, wpls);
        break;
    case 47:
        ferode_2_23(datad, w, h, wpld, datas, wpls);
        break;
    case 48:
        fdilate_2_24(datad, w, h, wpld, datas, wpls);
        break;
    case 49:
        ferode_2_24(datad, w, h, wpld, datas, wpls);
        break;
    case 50:
        fdilate_2_25(datad, w, h, wpld, datas, wpls);
        break;
    case 51:
        ferode_2_25(datad, w, h, wpld, datas, wpls);
        break;
    case 52:
        fdilate_2_26(datad, w, h, wpld, datas, wpls);
        break;
    case 53:
        ferode_2_26(datad, w, h, wpld, datas, wpls);
        break;
    case 54:
        fdilate_2_27(datad, w, h, wpld, datas, wpls);
        break;
    case 55:
        ferode_2_27(datad, w, h, wpld, datas, wpls);
        break;
    case 56:
        fdilate_2_28(datad, w, h, wpld, datas, wpls);
        break;
    case 57:
        ferode_2_28(datad, w, h, wpld, datas, wpls);
        break;
    case 58:
        fdilate_2_29(datad, w, h, wpld, datas, wpls);
        break;
    case 59:
        ferode_2_29(datad, w, h, wpld, datas, wpls);
        break;
    case 60:
        fdilate_2_30(datad, w, h, wpld, datas, wpls);
        break;
    case 61:
        ferode_2_30(datad, w, h, wpld, datas, wpls);
        break;
    case 62:
        fdilate_2_31(datad, w, h, wpld, datas, wpls);
        break;
    case 63:
        ferode_2_31(datad, w, h, wpld, datas, wpls);
        break;
    case 64:
        fdilate_2_32(datad, w, h, wpld, datas, wpls);
        break;
    case 65:
        ferode_2_32(datad, w, h, wpld, datas, wpls);
        break;
    case 66:
        fdilate_2_33(datad, w, h, wpld, datas, wpls);
        break;
    case 67:
        ferode_2_33(datad, w, h, wpld, datas, wpls);
        break;
    case 68:
        fdilate_2_34(datad, w, h, wpld, datas, wpls);
        break;
    case 69:
        ferode_2_34(datad, w, h, wpld, datas, wpls);
        break;
    case 70:
        fdilate_2_35(datad, w, h, wpld, datas, wpls);
        break;
    case 71:
        ferode_2_35(datad, w, h, wpld, datas, wpls);
        break;
    case 72:
        fdilate_2_36(datad, w, h, wpld, datas, wpls);
        break;
    case 73:
        ferode_2_36(datad, w, h, wpld, datas, wpls);
        break;
    case 74:
        fdilate_2_37(datad, w, h, wpld, datas, wpls);
        break;
    case 75:
        ferode_2_37(datad, w, h, wpld, datas, wpls);
        break;
    case 76:
        fdilate_2_38(datad, w, h, wpld, datas, wpls);
        break;
    case 77:
        ferode_2_38(datad, w, h, wpld, datas, wpls);
        break;
    case 78:
        fdilate_2_39(datad, w, h, wpld, datas, wpls);
        break;
    case 79:
        ferode_2_39(datad, w, h, wpld, datas, wpls);
        break;
    case 80:
        fdilate_2_40(datad, w, h, wpld, datas, wpls);
        break;
    case 81:
        ferode_2_40(datad, w, h, wpld, datas, wpls);
        break;
    case 82:
        fdilate_2_41(datad, w, h, wpld, datas, wpls);
        break;
    case 83:
        ferode_2_41(datad, w, h, wpld, datas, wpls);
        break;
    case 84:
        fdilate_2_42(datad, w, h, wpld, datas, wpls);
        break;
    case 85:
        ferode_2_42(datad, w, h, wpld, datas, wpls);
        break;
    case 86:
        fdilate_2_43(datad, w, h, wpld, datas, wpls);
        break;
    case 87:
        ferode_2_43(datad, w, h, wpld, datas, wpls);
        break;
    case 88:
        fdilate_2_44(datad, w, h, wpld, datas, wpls);
        break;
    case 89:
        ferode_2_44(datad, w, h, wpld, datas, wpls);
        break;
    case 90:
        fdilate_2_45(datad, w, h, wpld, datas, wpls);
        break;
    case 91:
        ferode_2_45(datad, w, h, wpld, datas, wpls);
        break;
    case 92:
        fdilate_2_46(datad, w, h, wpld, datas, wpls);
        break;
    case 93:
        ferode_2_46(datad, w, h, wpld, datas, wpls);
        break;
    case 94:
        fdilate_2_47(datad, w, h, wpld, datas, wpls);
        break;
    case 95:
        ferode_2_47(datad, w, h, wpld, datas, wpls);
        break;
    case 96:
        fdilate_2_48(datad, w, h, wpld, datas, wpls);
        break;
    case 97:
        ferode_2_48(datad, w, h, wpld, datas, wpls);
        break;
    case 98:
        fdilate_2_49(datad, w, h, wpld, datas, wpls);
        break;
    case 99:
        ferode_2_49(datad, w, h, wpld, datas, wpls);
        break;
    case 100:
        fdilate_2_50(datad, w, h, wpld, datas, wpls);
        break;
    case 101:
        ferode_2_50(datad, w, h, wpld, datas, wpls);
        break;
    case 102:
        fdilate_2_51(datad, w, h, wpld, datas, wpls);
        break;
    case 103:
        ferode_2_51(datad, w, h, wpld, datas, wpls);
        break;
    case 104:
        fdilate_2_52(datad, w, h, wpld, datas, wpls);
        break;
    case 105:
        ferode_2_52(datad, w, h, wpld, datas, wpls);
        break;
    case 106:
        fdilate_2_53(datad, w, h, wpld, datas, wpls);
        break;
    case 107:
        ferode_2_53(datad, w, h, wpld, datas, wpls);
        break;
    case 108:
        fdilate_2_54(datad, w, h, wpld, datas, wpls);
        break;
    case 109:
        ferode_2_54(datad, w, h, wpld, datas, wpls);
        break;
    case 110:
        fdilate_2_55(datad, w, h, wpld, datas, wpls);
        break;
    case 111:
        ferode_2_55(datad, w, h, wpld, datas, wpls);
        break;
    case 112:
        fdilate_2_56(datad, w, h, wpld, datas, wpls);
        break;
    case 113:
        ferode_2_56(datad, w, h, wpld, datas, wpls);
        break;
    case 114:
        fdilate_2_57(datad, w, h, wpld, datas, wpls);
        break;
    case 115:
        ferode_2_57(datad, w, h, wpld, datas, wpls);
        break;
    case 116:
        fdilate_2_58(datad, w, h, wpld, datas, wpls);
        break;
    case 117:
        ferode_2_58(datad, w, h, wpld, datas, wpls);
        break;
    case 118:
        fdilate_2_59(datad, w, h, wpld, datas, wpls);
        break;
    case 119:
        ferode_2_59(datad, w, h, wpld, datas, wpls);
        break;
    case 120:
        fdilate_2_60(datad, w, h, wpld, datas, wpls);
        break;
    case 121:
        ferode_2_60(datad, w, h, wpld, datas, wpls);
        break;
    case 122:
        fdilate_2_61(datad, w, h, wpld, datas, wpls);
        break;
    case 123:
        ferode_2_61(datad, w, h, wpld, datas, wpls);
        break;
    case 124:
        fdilate_2_62(datad, w, h, wpld, datas, wpls);
        break;
    case 125:
        ferode_2_62(datad, w, h, wpld, datas, wpls);
        break;
    case 126:
        fdilate_2_63(datad, w, h, wpld, datas, wpls);
        break;
    case 127:
        ferode_2_63(datad, w, h, wpld, datas, wpls);
        break;
    case 128:
        fdilate_2_64(datad, w, h, wpld, datas, wpls);
        break;
    case 129:
        ferode_2_64(datad, w, h, wpld, datas, wpls);
        break;
    case 130:
        fdilate_2_65(datad, w, h, wpld, datas, wpls);
        break;
    case 131:
        ferode_2_65(datad, w, h, wpld, datas, wpls);
        break;
    case 132:
        fdilate_2_66(datad, w, h, wpld, datas, wpls);
        break;
    case 133:
        ferode_2_66(datad, w, h, wpld, datas, wpls);
        break;
    case 134:
        fdilate_2_67(datad, w, h, wpld, datas, wpls);
        break;
    case 135:
        ferode_2_67(datad, w, h, wpld, datas, wpls);
        break;
    case 136:
        fdilate_2_68(datad, w, h, wpld, datas, wpls);
        break;
    case 137:
        ferode_2_68(datad, w, h, wpld, datas, wpls);
        break;
    case 138:
        fdilate_2_69(datad, w, h, wpld, datas, wpls);
        break;
    case 139:
        ferode_2_69(datad, w, h, wpld, datas, wpls);
        break;
    case 140:
        fdilate_2_70(datad, w, h, wpld, datas, wpls);
        break;
    case 141:
        ferode_2_70(datad, w, h, wpld, datas, wpls);
        break;
    case 142:
        fdilate_2_71(datad, w, h, wpld, datas, wpls);
        break;
    case 143:
        ferode_2_71(datad, w, h, wpld, datas, wpls);
        break;
    case 144:
        fdilate_2_72(datad, w, h, wpld, datas, wpls);
        break;
    case 145:
        ferode_2_72(datad, w, h, wpld, datas, wpls);
        break;
    case 146:
        fdilate_2_73(datad, w, h, wpld, datas, wpls);
        break;
    case 147:
        ferode_2_73(datad, w, h, wpld, datas, wpls);
        break;
    case 148:
        fdilate_2_74(datad, w, h, wpld, datas, wpls);
        break;
    case 149:
        ferode_2_74(datad, w, h, wpld, datas, wpls);
        break;
    case 150:
        fdilate_2_75(datad, w, h, wpld, datas, wpls);
        break;
    case 151:
        ferode_2_75(datad, w, h, wpld, datas, wpls);
        break;
    }

    return 0;
}


/*--------------------------------------------------------------------------*
 *                 Low-level auto-generated static routines                 *
 *--------------------------------------------------------------------------*/
/*
 *  N.B.  In all the low-level routines, the part of the image
 *        that is accessed has been clipped by 32 pixels on
 *        all four sides.  This is done in the higher level
 *        code by redefining w and h smaller and by moving the
 *        start-of-image pointers up to the beginning of this
 *        interior rectangle.
 */
static void
fdilate_2_0(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 1) | (*(sptr + 1) >> 31)) |
                    ((*(sptr) >> 1) | (*(sptr - 1) << 31));
        }
    }
}

static void
ferode_2_0(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 1) | (*(sptr - 1) << 31)) &
                    ((*(sptr) << 1) | (*(sptr + 1) >> 31));
        }
    }
}

static void
fdilate_2_1(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls)) |
                    (*(sptr - wpls));
        }
    }
}

static void
ferode_2_1(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls)) &
                    (*(sptr + wpls));
        }
    }
}

static void
fdilate_2_2(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*sptr);
        }
    }
}

static void
ferode_2_2(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*sptr);
        }
    }
}

static void
fdilate_2_3(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*sptr);
        }
    }
}

static void
ferode_2_3(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*sptr);
        }
    }
}

static void
fdilate_2_4(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 2) | (*(sptr + 1) >> 30)) |
                    ((*(sptr) >> 1) | (*(sptr - 1) << 31));
        }
    }
}

static void
ferode_2_4(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 2) | (*(sptr - 1) << 30)) &
                    ((*(sptr) << 1) | (*(sptr + 1) >> 31));
        }
    }
}

static void
fdilate_2_5(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls2;

    wpls2 = 2 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls2)) |
                    (*(sptr - wpls));
        }
    }
}

static void
ferode_2_5(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls2;

    wpls2 = 2 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls2)) &
                    (*(sptr + wpls));
        }
    }
}

static void
fdilate_2_6(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*sptr);
        }
    }
}

static void
ferode_2_6(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*sptr);
        }
    }
}

static void
fdilate_2_7(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*sptr);
        }
    }
}

static void
ferode_2_7(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*sptr);
        }
    }
}

static void
fdilate_2_8(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 2) | (*(sptr + 1) >> 30)) |
                    ((*(sptr) >> 2) | (*(sptr - 1) << 30));
        }
    }
}

static void
ferode_2_8(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 2) | (*(sptr - 1) << 30)) &
                    ((*(sptr) << 2) | (*(sptr + 1) >> 30));
        }
    }
}

static void
fdilate_2_9(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls2;

    wpls2 = 2 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls2)) |
                    (*(sptr - wpls2));
        }
    }
}

static void
ferode_2_9(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls2;

    wpls2 = 2 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls2)) &
                    (*(sptr + wpls2));
        }
    }
}

static void
fdilate_2_10(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 3) | (*(sptr + 1) >> 29)) |
                    (*sptr) |
                    ((*(sptr) >> 3) | (*(sptr - 1) << 29));
        }
    }
}

static void
ferode_2_10(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 3) | (*(sptr - 1) << 29)) &
                    (*sptr) &
                    ((*(sptr) << 3) | (*(sptr + 1) >> 29));
        }
    }
}

static void
fdilate_2_11(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls3;

    wpls3 = 3 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls3)) |
                    (*sptr) |
                    (*(sptr - wpls3));
        }
    }
}

static void
ferode_2_11(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls3;

    wpls3 = 3 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls3)) &
                    (*sptr) &
                    (*(sptr + wpls3));
        }
    }
}

static void
fdilate_2_12(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 3) | (*(sptr + 1) >> 29)) |
                    ((*(sptr) >> 2) | (*(sptr - 1) << 30));
        }
    }
}

static void
ferode_2_12(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 3) | (*(sptr - 1) << 29)) &
                    ((*(sptr) << 2) | (*(sptr + 1) >> 30));
        }
    }
}

static void
fdilate_2_13(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls2;
int32_t             wpls3;

    wpls2 = 2 * wpls;
    wpls3 = 3 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls3)) |
                    (*(sptr - wpls2));
        }
    }
}

static void
ferode_2_13(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls2;
int32_t             wpls3;

    wpls2 = 2 * wpls;
    wpls3 = 3 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls3)) &
                    (*(sptr + wpls2));
        }
    }
}

static void
fdilate_2_14(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 4) | (*(sptr + 1) >> 28)) |
                    (*sptr) |
                    ((*(sptr) >> 4) | (*(sptr - 1) << 28));
        }
    }
}

static void
ferode_2_14(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 4) | (*(sptr - 1) << 28)) &
                    (*sptr) &
                    ((*(sptr) << 4) | (*(sptr + 1) >> 28));
        }
    }
}

static void
fdilate_2_15(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls4;

    wpls4 = 4 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls4)) |
                    (*sptr) |
                    (*(sptr - wpls4));
        }
    }
}

static void
ferode_2_15(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls4;

    wpls4 = 4 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls4)) &
                    (*sptr) &
                    (*(sptr + wpls4));
        }
    }
}

static void
fdilate_2_16(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 4) | (*(sptr + 1) >> 28)) |
                    ((*(sptr) >> 3) | (*(sptr - 1) << 29));
        }
    }
}

static void
ferode_2_16(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 4) | (*(sptr - 1) << 28)) &
                    ((*(sptr) << 3) | (*(sptr + 1) >> 29));
        }
    }
}

static void
fdilate_2_17(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls3;
int32_t             wpls4;

    wpls3 = 3 * wpls;
    wpls4 = 4 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls4)) |
                    (*(sptr - wpls3));
        }
    }
}

static void
ferode_2_17(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls3;
int32_t             wpls4;

    wpls3 = 3 * wpls;
    wpls4 = 4 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls4)) &
                    (*(sptr + wpls3));
        }
    }
}

static void
fdilate_2_18(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 5) | (*(sptr + 1) >> 27)) |
                    (*sptr) |
                    ((*(sptr) >> 5) | (*(sptr - 1) << 27));
        }
    }
}

static void
ferode_2_18(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 5) | (*(sptr - 1) << 27)) &
                    (*sptr) &
                    ((*(sptr) << 5) | (*(sptr + 1) >> 27));
        }
    }
}

static void
fdilate_2_19(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls5;

    wpls5 = 5 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls5)) |
                    (*sptr) |
                    (*(sptr - wpls5));
        }
    }
}

static void
ferode_2_19(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls5;

    wpls5 = 5 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls5)) &
                    (*sptr) &
                    (*(sptr + wpls5));
        }
    }
}

static void
fdilate_2_20(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 6) | (*(sptr + 1) >> 26)) |
                    ((*(sptr) << 2) | (*(sptr + 1) >> 30)) |
                    ((*(sptr) >> 2) | (*(sptr - 1) << 30)) |
                    ((*(sptr) >> 6) | (*(sptr - 1) << 26));
        }
    }
}

static void
ferode_2_20(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 6) | (*(sptr - 1) << 26)) &
                    ((*(sptr) >> 2) | (*(sptr - 1) << 30)) &
                    ((*(sptr) << 2) | (*(sptr + 1) >> 30)) &
                    ((*(sptr) << 6) | (*(sptr + 1) >> 26));
        }
    }
}

static void
fdilate_2_21(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls2;
int32_t             wpls6;

    wpls2 = 2 * wpls;
    wpls6 = 6 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls6)) |
                    (*(sptr + wpls2)) |
                    (*(sptr - wpls2)) |
                    (*(sptr - wpls6));
        }
    }
}

static void
ferode_2_21(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls2;
int32_t             wpls6;

    wpls2 = 2 * wpls;
    wpls6 = 6 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls6)) &
                    (*(sptr - wpls2)) &
                    (*(sptr + wpls2)) &
                    (*(sptr + wpls6));
        }
    }
}

static void
fdilate_2_22(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 6) | (*(sptr + 1) >> 26)) |
                    (*sptr) |
                    ((*(sptr) >> 6) | (*(sptr - 1) << 26));
        }
    }
}

static void
ferode_2_22(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 6) | (*(sptr - 1) << 26)) &
                    (*sptr) &
                    ((*(sptr) << 6) | (*(sptr + 1) >> 26));
        }
    }
}

static void
fdilate_2_23(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls6;

    wpls6 = 6 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls6)) |
                    (*sptr) |
                    (*(sptr - wpls6));
        }
    }
}

static void
ferode_2_23(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls6;

    wpls6 = 6 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls6)) &
                    (*sptr) &
                    (*(sptr + wpls6));
        }
    }
}

static void
fdilate_2_24(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 8) | (*(sptr + 1) >> 24)) |
                    ((*(sptr) << 3) | (*(sptr + 1) >> 29)) |
                    ((*(sptr) >> 2) | (*(sptr - 1) << 30)) |
                    ((*(sptr) >> 7) | (*(sptr - 1) << 25));
        }
    }
}

static void
ferode_2_24(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 8) | (*(sptr - 1) << 24)) &
                    ((*(sptr) >> 3) | (*(sptr - 1) << 29)) &
                    ((*(sptr) << 2) | (*(sptr + 1) >> 30)) &
                    ((*(sptr) << 7) | (*(sptr + 1) >> 25));
        }
    }
}

static void
fdilate_2_25(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls2;
int32_t             wpls3;
int32_t             wpls7;
int32_t             wpls8;

    wpls2 = 2 * wpls;
    wpls3 = 3 * wpls;
    wpls7 = 7 * wpls;
    wpls8 = 8 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls8)) |
                    (*(sptr + wpls3)) |
                    (*(sptr - wpls2)) |
                    (*(sptr - wpls7));
        }
    }
}

static void
ferode_2_25(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls2;
int32_t             wpls3;
int32_t             wpls7;
int32_t             wpls8;

    wpls2 = 2 * wpls;
    wpls3 = 3 * wpls;
    wpls7 = 7 * wpls;
    wpls8 = 8 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls8)) &
                    (*(sptr - wpls3)) &
                    (*(sptr + wpls2)) &
                    (*(sptr + wpls7));
        }
    }
}

static void
fdilate_2_26(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 7) | (*(sptr + 1) >> 25)) |
                    (*sptr) |
                    ((*(sptr) >> 7) | (*(sptr - 1) << 25));
        }
    }
}

static void
ferode_2_26(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 7) | (*(sptr - 1) << 25)) &
                    (*sptr) &
                    ((*(sptr) << 7) | (*(sptr + 1) >> 25));
        }
    }
}

static void
fdilate_2_27(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls7;

    wpls7 = 7 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls7)) |
                    (*sptr) |
                    (*(sptr - wpls7));
        }
    }
}

static void
ferode_2_27(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls7;

    wpls7 = 7 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls7)) &
                    (*sptr) &
                    (*(sptr + wpls7));
        }
    }
}

static void
fdilate_2_28(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 6) | (*(sptr + 1) >> 26)) |
                    ((*(sptr) >> 5) | (*(sptr - 1) << 27));
        }
    }
}

static void
ferode_2_28(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 6) | (*(sptr - 1) << 26)) &
                    ((*(sptr) << 5) | (*(sptr + 1) >> 27));
        }
    }
}

static void
fdilate_2_29(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls5;
int32_t             wpls6;

    wpls5 = 5 * wpls;
    wpls6 = 6 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls6)) |
                    (*(sptr - wpls5));
        }
    }
}

static void
ferode_2_29(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls5;
int32_t             wpls6;

    wpls5 = 5 * wpls;
    wpls6 = 6 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls6)) &
                    (*(sptr + wpls5));
        }
    }
}

static void
fdilate_2_30(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 9) | (*(sptr + 1) >> 23)) |
                    ((*(sptr) << 3) | (*(sptr + 1) >> 29)) |
                    ((*(sptr) >> 3) | (*(sptr - 1) << 29)) |
                    ((*(sptr) >> 9) | (*(sptr - 1) << 23));
        }
    }
}

static void
ferode_2_30(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 9) | (*(sptr - 1) << 23)) &
                    ((*(sptr) >> 3) | (*(sptr - 1) << 29)) &
                    ((*(sptr) << 3) | (*(sptr + 1) >> 29)) &
                    ((*(sptr) << 9) | (*(sptr + 1) >> 23));
        }
    }
}

static void
fdilate_2_31(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls3;
int32_t             wpls9;

    wpls3 = 3 * wpls;
    wpls9 = 9 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls9)) |
                    (*(sptr + wpls3)) |
                    (*(sptr - wpls3)) |
                    (*(sptr - wpls9));
        }
    }
}

static void
ferode_2_31(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls3;
int32_t             wpls9;

    wpls3 = 3 * wpls;
    wpls9 = 9 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls9)) &
                    (*(sptr - wpls3)) &
                    (*(sptr + wpls3)) &
                    (*(sptr + wpls9));
        }
    }
}

static void
fdilate_2_32(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 10) | (*(sptr + 1) >> 22)) |
                    ((*(sptr) << 5) | (*(sptr + 1) >> 27)) |
                    (*sptr) |
                    ((*(sptr) >> 5) | (*(sptr - 1) << 27)) |
                    ((*(sptr) >> 10) | (*(sptr - 1) << 22));
        }
    }
}

static void
ferode_2_32(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 10) | (*(sptr - 1) << 22)) &
                    ((*(sptr) >> 5) | (*(sptr - 1) << 27)) &
                    (*sptr) &
                    ((*(sptr) << 5) | (*(sptr + 1) >> 27)) &
                    ((*(sptr) << 10) | (*(sptr + 1) >> 22));
        }
    }
}

static void
fdilate_2_33(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls5;
int32_t             wpls10;

    wpls5 = 5 * wpls;
    wpls10 = 10 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls10)) |
                    (*(sptr + wpls5)) |
                    (*sptr) |
                    (*(sptr - wpls5)) |
                    (*(sptr - wpls10));
        }
    }
}

static void
ferode_2_33(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls5;
int32_t             wpls10;

    wpls5 = 5 * wpls;
    wpls10 = 10 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls10)) &
                    (*(sptr - wpls5)) &
                    (*sptr) &
                    (*(sptr + wpls5)) &
                    (*(sptr + wpls10));
        }
    }
}

static void
fdilate_2_34(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 9) | (*(sptr + 1) >> 23)) |
                    (*sptr) |
                    ((*(sptr) >> 9) | (*(sptr - 1) << 23));
        }
    }
}

static void
ferode_2_34(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 9) | (*(sptr - 1) << 23)) &
                    (*sptr) &
                    ((*(sptr) << 9) | (*(sptr + 1) >> 23));
        }
    }
}

static void
fdilate_2_35(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls9;

    wpls9 = 9 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls9)) |
                    (*sptr) |
                    (*(sptr - wpls9));
        }
    }
}

static void
ferode_2_35(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls9;

    wpls9 = 9 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls9)) &
                    (*sptr) &
                    (*(sptr + wpls9));
        }
    }
}

static void
fdilate_2_36(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 11) | (*(sptr + 1) >> 21)) |
                    ((*(sptr) << 4) | (*(sptr + 1) >> 28)) |
                    ((*(sptr) >> 3) | (*(sptr - 1) << 29)) |
                    ((*(sptr) >> 10) | (*(sptr - 1) << 22));
        }
    }
}

static void
ferode_2_36(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 11) | (*(sptr - 1) << 21)) &
                    ((*(sptr) >> 4) | (*(sptr - 1) << 28)) &
                    ((*(sptr) << 3) | (*(sptr + 1) >> 29)) &
                    ((*(sptr) << 10) | (*(sptr + 1) >> 22));
        }
    }
}

static void
fdilate_2_37(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls3;
int32_t             wpls4;
int32_t             wpls10;
int32_t             wpls11;

    wpls3 = 3 * wpls;
    wpls4 = 4 * wpls;
    wpls10 = 10 * wpls;
    wpls11 = 11 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls11)) |
                    (*(sptr + wpls4)) |
                    (*(sptr - wpls3)) |
                    (*(sptr - wpls10));
        }
    }
}

static void
ferode_2_37(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls3;
int32_t             wpls4;
int32_t             wpls10;
int32_t             wpls11;

    wpls3 = 3 * wpls;
    wpls4 = 4 * wpls;
    wpls10 = 10 * wpls;
    wpls11 = 11 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls11)) &
                    (*(sptr - wpls4)) &
                    (*(sptr + wpls3)) &
                    (*(sptr + wpls10));
        }
    }
}

static void
fdilate_2_38(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 12) | (*(sptr + 1) >> 20)) |
                    ((*(sptr) << 6) | (*(sptr + 1) >> 26)) |
                    (*sptr) |
                    ((*(sptr) >> 6) | (*(sptr - 1) << 26)) |
                    ((*(sptr) >> 12) | (*(sptr - 1) << 20));
        }
    }
}

static void
ferode_2_38(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 12) | (*(sptr - 1) << 20)) &
                    ((*(sptr) >> 6) | (*(sptr - 1) << 26)) &
                    (*sptr) &
                    ((*(sptr) << 6) | (*(sptr + 1) >> 26)) &
                    ((*(sptr) << 12) | (*(sptr + 1) >> 20));
        }
    }
}

static void
fdilate_2_39(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls6;
int32_t             wpls12;

    wpls6 = 6 * wpls;
    wpls12 = 12 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls12)) |
                    (*(sptr + wpls6)) |
                    (*sptr) |
                    (*(sptr - wpls6)) |
                    (*(sptr - wpls12));
        }
    }
}

static void
ferode_2_39(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls6;
int32_t             wpls12;

    wpls6 = 6 * wpls;
    wpls12 = 12 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls12)) &
                    (*(sptr - wpls6)) &
                    (*sptr) &
                    (*(sptr + wpls6)) &
                    (*(sptr + wpls12));
        }
    }
}

static void
fdilate_2_40(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 12) | (*(sptr + 1) >> 20)) |
                    ((*(sptr) << 4) | (*(sptr + 1) >> 28)) |
                    ((*(sptr) >> 4) | (*(sptr - 1) << 28)) |
                    ((*(sptr) >> 12) | (*(sptr - 1) << 20));
        }
    }
}

static void
ferode_2_40(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 12) | (*(sptr - 1) << 20)) &
                    ((*(sptr) >> 4) | (*(sptr - 1) << 28)) &
                    ((*(sptr) << 4) | (*(sptr + 1) >> 28)) &
                    ((*(sptr) << 12) | (*(sptr + 1) >> 20));
        }
    }
}

static void
fdilate_2_41(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls4;
int32_t             wpls12;

    wpls4 = 4 * wpls;
    wpls12 = 12 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls12)) |
                    (*(sptr + wpls4)) |
                    (*(sptr - wpls4)) |
                    (*(sptr - wpls12));
        }
    }
}

static void
ferode_2_41(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls4;
int32_t             wpls12;

    wpls4 = 4 * wpls;
    wpls12 = 12 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls12)) &
                    (*(sptr - wpls4)) &
                    (*(sptr + wpls4)) &
                    (*(sptr + wpls12));
        }
    }
}

static void
fdilate_2_42(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 11) | (*(sptr + 1) >> 21)) |
                    (*sptr) |
                    ((*(sptr) >> 11) | (*(sptr - 1) << 21));
        }
    }
}

static void
ferode_2_42(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 11) | (*(sptr - 1) << 21)) &
                    (*sptr) &
                    ((*(sptr) << 11) | (*(sptr + 1) >> 21));
        }
    }
}

static void
fdilate_2_43(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls11;

    wpls11 = 11 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls11)) |
                    (*sptr) |
                    (*(sptr - wpls11));
        }
    }
}

static void
ferode_2_43(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls11;

    wpls11 = 11 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls11)) &
                    (*sptr) &
                    (*(sptr + wpls11));
        }
    }
}

static void
fdilate_2_44(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 14) | (*(sptr + 1) >> 18)) |
                    ((*(sptr) << 7) | (*(sptr + 1) >> 25)) |
                    (*sptr) |
                    ((*(sptr) >> 7) | (*(sptr - 1) << 25)) |
                    ((*(sptr) >> 14) | (*(sptr - 1) << 18));
        }
    }
}

static void
ferode_2_44(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 14) | (*(sptr - 1) << 18)) &
                    ((*(sptr) >> 7) | (*(sptr - 1) << 25)) &
                    (*sptr) &
                    ((*(sptr) << 7) | (*(sptr + 1) >> 25)) &
                    ((*(sptr) << 14) | (*(sptr + 1) >> 18));
        }
    }
}

static void
fdilate_2_45(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls7;
int32_t             wpls14;

    wpls7 = 7 * wpls;
    wpls14 = 14 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls14)) |
                    (*(sptr + wpls7)) |
                    (*sptr) |
                    (*(sptr - wpls7)) |
                    (*(sptr - wpls14));
        }
    }
}

static void
ferode_2_45(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls7;
int32_t             wpls14;

    wpls7 = 7 * wpls;
    wpls14 = 14 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls14)) &
                    (*(sptr - wpls7)) &
                    (*sptr) &
                    (*(sptr + wpls7)) &
                    (*(sptr + wpls14));
        }
    }
}

static void
fdilate_2_46(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 15) | (*(sptr + 1) >> 17)) |
                    ((*(sptr) << 9) | (*(sptr + 1) >> 23)) |
                    ((*(sptr) << 3) | (*(sptr + 1) >> 29)) |
                    ((*(sptr) >> 3) | (*(sptr - 1) << 29)) |
                    ((*(sptr) >> 9) | (*(sptr - 1) << 23)) |
                    ((*(sptr) >> 15) | (*(sptr - 1) << 17));
        }
    }
}

static void
ferode_2_46(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 15) | (*(sptr - 1) << 17)) &
                    ((*(sptr) >> 9) | (*(sptr - 1) << 23)) &
                    ((*(sptr) >> 3) | (*(sptr - 1) << 29)) &
                    ((*(sptr) << 3) | (*(sptr + 1) >> 29)) &
                    ((*(sptr) << 9) | (*(sptr + 1) >> 23)) &
                    ((*(sptr) << 15) | (*(sptr + 1) >> 17));
        }
    }
}

static void
fdilate_2_47(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls3;
int32_t             wpls9;
int32_t             wpls15;

    wpls3 = 3 * wpls;
    wpls9 = 9 * wpls;
    wpls15 = 15 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls15)) |
                    (*(sptr + wpls9)) |
                    (*(sptr + wpls3)) |
                    (*(sptr - wpls3)) |
                    (*(sptr - wpls9)) |
                    (*(sptr - wpls15));
        }
    }
}

static void
ferode_2_47(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls3;
int32_t             wpls9;
int32_t             wpls15;

    wpls3 = 3 * wpls;
    wpls9 = 9 * wpls;
    wpls15 = 15 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls15)) &
                    (*(sptr - wpls9)) &
                    (*(sptr - wpls3)) &
                    (*(sptr + wpls3)) &
                    (*(sptr + wpls9)) &
                    (*(sptr + wpls15));
        }
    }
}

static void
fdilate_2_48(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 13) | (*(sptr + 1) >> 19)) |
                    (*sptr) |
                    ((*(sptr) >> 13) | (*(sptr - 1) << 19));
        }
    }
}

static void
ferode_2_48(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 13) | (*(sptr - 1) << 19)) &
                    (*sptr) &
                    ((*(sptr) << 13) | (*(sptr + 1) >> 19));
        }
    }
}

static void
fdilate_2_49(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls13;

    wpls13 = 13 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls13)) |
                    (*sptr) |
                    (*(sptr - wpls13));
        }
    }
}

static void
ferode_2_49(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls13;

    wpls13 = 13 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls13)) &
                    (*sptr) &
                    (*(sptr + wpls13));
        }
    }
}

static void
fdilate_2_50(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 16) | (*(sptr + 1) >> 16)) |
                    ((*(sptr) << 8) | (*(sptr + 1) >> 24)) |
                    (*sptr) |
                    ((*(sptr) >> 8) | (*(sptr - 1) << 24)) |
                    ((*(sptr) >> 16) | (*(sptr - 1) << 16));
        }
    }
}

static void
ferode_2_50(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 16) | (*(sptr - 1) << 16)) &
                    ((*(sptr) >> 8) | (*(sptr - 1) << 24)) &
                    (*sptr) &
                    ((*(sptr) << 8) | (*(sptr + 1) >> 24)) &
                    ((*(sptr) << 16) | (*(sptr + 1) >> 16));
        }
    }
}

static void
fdilate_2_51(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls8;
int32_t             wpls16;

    wpls8 = 8 * wpls;
    wpls16 = 16 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls16)) |
                    (*(sptr + wpls8)) |
                    (*sptr) |
                    (*(sptr - wpls8)) |
                    (*(sptr - wpls16));
        }
    }
}

static void
ferode_2_51(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls8;
int32_t             wpls16;

    wpls8 = 8 * wpls;
    wpls16 = 16 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls16)) &
                    (*(sptr - wpls8)) &
                    (*sptr) &
                    (*(sptr + wpls8)) &
                    (*(sptr + wpls16));
        }
    }
}

static void
fdilate_2_52(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 18) | (*(sptr + 1) >> 14)) |
                    ((*(sptr) << 11) | (*(sptr + 1) >> 21)) |
                    ((*(sptr) << 4) | (*(sptr + 1) >> 28)) |
                    ((*(sptr) >> 3) | (*(sptr - 1) << 29)) |
                    ((*(sptr) >> 10) | (*(sptr - 1) << 22)) |
                    ((*(sptr) >> 17) | (*(sptr - 1) << 15));
        }
    }
}

static void
ferode_2_52(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 18) | (*(sptr - 1) << 14)) &
                    ((*(sptr) >> 11) | (*(sptr - 1) << 21)) &
                    ((*(sptr) >> 4) | (*(sptr - 1) << 28)) &
                    ((*(sptr) << 3) | (*(sptr + 1) >> 29)) &
                    ((*(sptr) << 10) | (*(sptr + 1) >> 22)) &
                    ((*(sptr) << 17) | (*(sptr + 1) >> 15));
        }
    }
}

static void
fdilate_2_53(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls3;
int32_t             wpls4;
int32_t             wpls10;
int32_t             wpls11;
int32_t             wpls17;
int32_t             wpls18;

    wpls3 = 3 * wpls;
    wpls4 = 4 * wpls;
    wpls10 = 10 * wpls;
    wpls11 = 11 * wpls;
    wpls17 = 17 * wpls;
    wpls18 = 18 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls18)) |
                    (*(sptr + wpls11)) |
                    (*(sptr + wpls4)) |
                    (*(sptr - wpls3)) |
                    (*(sptr - wpls10)) |
                    (*(sptr - wpls17));
        }
    }
}

static void
ferode_2_53(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls3;
int32_t             wpls4;
int32_t             wpls10;
int32_t             wpls11;
int32_t             wpls17;
int32_t             wpls18;

    wpls3 = 3 * wpls;
    wpls4 = 4 * wpls;
    wpls10 = 10 * wpls;
    wpls11 = 11 * wpls;
    wpls17 = 17 * wpls;
    wpls18 = 18 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls18)) &
                    (*(sptr - wpls11)) &
                    (*(sptr - wpls4)) &
                    (*(sptr + wpls3)) &
                    (*(sptr + wpls10)) &
                    (*(sptr + wpls17));
        }
    }
}

static void
fdilate_2_54(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 17) | (*(sptr + 1) >> 15)) |
                    ((*(sptr) << 6) | (*(sptr + 1) >> 26)) |
                    ((*(sptr) >> 5) | (*(sptr - 1) << 27)) |
                    ((*(sptr) >> 16) | (*(sptr - 1) << 16));
        }
    }
}

static void
ferode_2_54(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 17) | (*(sptr - 1) << 15)) &
                    ((*(sptr) >> 6) | (*(sptr - 1) << 26)) &
                    ((*(sptr) << 5) | (*(sptr + 1) >> 27)) &
                    ((*(sptr) << 16) | (*(sptr + 1) >> 16));
        }
    }
}

static void
fdilate_2_55(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls5;
int32_t             wpls6;
int32_t             wpls16;
int32_t             wpls17;

    wpls5 = 5 * wpls;
    wpls6 = 6 * wpls;
    wpls16 = 16 * wpls;
    wpls17 = 17 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls17)) |
                    (*(sptr + wpls6)) |
                    (*(sptr - wpls5)) |
                    (*(sptr - wpls16));
        }
    }
}

static void
ferode_2_55(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls5;
int32_t             wpls6;
int32_t             wpls16;
int32_t             wpls17;

    wpls5 = 5 * wpls;
    wpls6 = 6 * wpls;
    wpls16 = 16 * wpls;
    wpls17 = 17 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls17)) &
                    (*(sptr - wpls6)) &
                    (*(sptr + wpls5)) &
                    (*(sptr + wpls16));
        }
    }
}

static void
fdilate_2_56(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 18) | (*(sptr + 1) >> 14)) |
                    ((*(sptr) << 9) | (*(sptr + 1) >> 23)) |
                    (*sptr) |
                    ((*(sptr) >> 9) | (*(sptr - 1) << 23)) |
                    ((*(sptr) >> 18) | (*(sptr - 1) << 14));
        }
    }
}

static void
ferode_2_56(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 18) | (*(sptr - 1) << 14)) &
                    ((*(sptr) >> 9) | (*(sptr - 1) << 23)) &
                    (*sptr) &
                    ((*(sptr) << 9) | (*(sptr + 1) >> 23)) &
                    ((*(sptr) << 18) | (*(sptr + 1) >> 14));
        }
    }
}

static void
fdilate_2_57(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls9;
int32_t             wpls18;

    wpls9 = 9 * wpls;
    wpls18 = 18 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls18)) |
                    (*(sptr + wpls9)) |
                    (*sptr) |
                    (*(sptr - wpls9)) |
                    (*(sptr - wpls18));
        }
    }
}

static void
ferode_2_57(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls9;
int32_t             wpls18;

    wpls9 = 9 * wpls;
    wpls18 = 18 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls18)) &
                    (*(sptr - wpls9)) &
                    (*sptr) &
                    (*(sptr + wpls9)) &
                    (*(sptr + wpls18));
        }
    }
}

static void
fdilate_2_58(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 20) | (*(sptr + 1) >> 12)) |
                    ((*(sptr) << 12) | (*(sptr + 1) >> 20)) |
                    ((*(sptr) << 4) | (*(sptr + 1) >> 28)) |
                    ((*(sptr) >> 4) | (*(sptr - 1) << 28)) |
                    ((*(sptr) >> 12) | (*(sptr - 1) << 20)) |
                    ((*(sptr) >> 20) | (*(sptr - 1) << 12));
        }
    }
}

static void
ferode_2_58(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 20) | (*(sptr - 1) << 12)) &
                    ((*(sptr) >> 12) | (*(sptr - 1) << 20)) &
                    ((*(sptr) >> 4) | (*(sptr - 1) << 28)) &
                    ((*(sptr) << 4) | (*(sptr + 1) >> 28)) &
                    ((*(sptr) << 12) | (*(sptr + 1) >> 20)) &
                    ((*(sptr) << 20) | (*(sptr + 1) >> 12));
        }
    }
}

static void
fdilate_2_59(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls4;
int32_t             wpls12;
int32_t             wpls20;

    wpls4 = 4 * wpls;
    wpls12 = 12 * wpls;
    wpls20 = 20 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls20)) |
                    (*(sptr + wpls12)) |
                    (*(sptr + wpls4)) |
                    (*(sptr - wpls4)) |
                    (*(sptr - wpls12)) |
                    (*(sptr - wpls20));
        }
    }
}

static void
ferode_2_59(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls4;
int32_t             wpls12;
int32_t             wpls20;

    wpls4 = 4 * wpls;
    wpls12 = 12 * wpls;
    wpls20 = 20 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls20)) &
                    (*(sptr - wpls12)) &
                    (*(sptr - wpls4)) &
                    (*(sptr + wpls4)) &
                    (*(sptr + wpls12)) &
                    (*(sptr + wpls20));
        }
    }
}

static void
fdilate_2_60(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 21) | (*(sptr + 1) >> 11)) |
                    ((*(sptr) << 14) | (*(sptr + 1) >> 18)) |
                    ((*(sptr) << 7) | (*(sptr + 1) >> 25)) |
                    (*sptr) |
                    ((*(sptr) >> 7) | (*(sptr - 1) << 25)) |
                    ((*(sptr) >> 14) | (*(sptr - 1) << 18)) |
                    ((*(sptr) >> 21) | (*(sptr - 1) << 11));
        }
    }
}

static void
ferode_2_60(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 21) | (*(sptr - 1) << 11)) &
                    ((*(sptr) >> 14) | (*(sptr - 1) << 18)) &
                    ((*(sptr) >> 7) | (*(sptr - 1) << 25)) &
                    (*sptr) &
                    ((*(sptr) << 7) | (*(sptr + 1) >> 25)) &
                    ((*(sptr) << 14) | (*(sptr + 1) >> 18)) &
                    ((*(sptr) << 21) | (*(sptr + 1) >> 11));
        }
    }
}

static void
fdilate_2_61(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls7;
int32_t             wpls14;
int32_t             wpls21;

    wpls7 = 7 * wpls;
    wpls14 = 14 * wpls;
    wpls21 = 21 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls21)) |
                    (*(sptr + wpls14)) |
                    (*(sptr + wpls7)) |
                    (*sptr) |
                    (*(sptr - wpls7)) |
                    (*(sptr - wpls14)) |
                    (*(sptr - wpls21));
        }
    }
}

static void
ferode_2_61(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls7;
int32_t             wpls14;
int32_t             wpls21;

    wpls7 = 7 * wpls;
    wpls14 = 14 * wpls;
    wpls21 = 21 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls21)) &
                    (*(sptr - wpls14)) &
                    (*(sptr - wpls7)) &
                    (*sptr) &
                    (*(sptr + wpls7)) &
                    (*(sptr + wpls14)) &
                    (*(sptr + wpls21));
        }
    }
}

static void
fdilate_2_62(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 20) | (*(sptr + 1) >> 12)) |
                    ((*(sptr) << 10) | (*(sptr + 1) >> 22)) |
                    (*sptr) |
                    ((*(sptr) >> 10) | (*(sptr - 1) << 22)) |
                    ((*(sptr) >> 20) | (*(sptr - 1) << 12));
        }
    }
}

static void
ferode_2_62(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 20) | (*(sptr - 1) << 12)) &
                    ((*(sptr) >> 10) | (*(sptr - 1) << 22)) &
                    (*sptr) &
                    ((*(sptr) << 10) | (*(sptr + 1) >> 22)) &
                    ((*(sptr) << 20) | (*(sptr + 1) >> 12));
        }
    }
}

static void
fdilate_2_63(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls10;
int32_t             wpls20;

    wpls10 = 10 * wpls;
    wpls20 = 20 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls20)) |
                    (*(sptr + wpls10)) |
                    (*sptr) |
                    (*(sptr - wpls10)) |
                    (*(sptr - wpls20));
        }
    }
}

static void
ferode_2_63(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls10;
int32_t             wpls20;

    wpls10 = 10 * wpls;
    wpls20 = 20 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls20)) &
                    (*(sptr - wpls10)) &
                    (*sptr) &
                    (*(sptr + wpls10)) &
                    (*(sptr + wpls20));
        }
    }
}

static void
fdilate_2_64(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 20) | (*(sptr + 1) >> 12)) |
                    ((*(sptr) << 7) | (*(sptr + 1) >> 25)) |
                    ((*(sptr) >> 6) | (*(sptr - 1) << 26)) |
                    ((*(sptr) >> 19) | (*(sptr - 1) << 13));
        }
    }
}

static void
ferode_2_64(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 20) | (*(sptr - 1) << 12)) &
                    ((*(sptr) >> 7) | (*(sptr - 1) << 25)) &
                    ((*(sptr) << 6) | (*(sptr + 1) >> 26)) &
                    ((*(sptr) << 19) | (*(sptr + 1) >> 13));
        }
    }
}

static void
fdilate_2_65(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls6;
int32_t             wpls7;
int32_t             wpls19;
int32_t             wpls20;

    wpls6 = 6 * wpls;
    wpls7 = 7 * wpls;
    wpls19 = 19 * wpls;
    wpls20 = 20 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls20)) |
                    (*(sptr + wpls7)) |
                    (*(sptr - wpls6)) |
                    (*(sptr - wpls19));
        }
    }
}

static void
ferode_2_65(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls6;
int32_t             wpls7;
int32_t             wpls19;
int32_t             wpls20;

    wpls6 = 6 * wpls;
    wpls7 = 7 * wpls;
    wpls19 = 19 * wpls;
    wpls20 = 20 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls20)) &
                    (*(sptr - wpls7)) &
                    (*(sptr + wpls6)) &
                    (*(sptr + wpls19));
        }
    }
}

static void
fdilate_2_66(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 23) | (*(sptr + 1) >> 9)) |
                    ((*(sptr) << 14) | (*(sptr + 1) >> 18)) |
                    ((*(sptr) << 5) | (*(sptr + 1) >> 27)) |
                    ((*(sptr) >> 4) | (*(sptr - 1) << 28)) |
                    ((*(sptr) >> 13) | (*(sptr - 1) << 19)) |
                    ((*(sptr) >> 22) | (*(sptr - 1) << 10));
        }
    }
}

static void
ferode_2_66(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 23) | (*(sptr - 1) << 9)) &
                    ((*(sptr) >> 14) | (*(sptr - 1) << 18)) &
                    ((*(sptr) >> 5) | (*(sptr - 1) << 27)) &
                    ((*(sptr) << 4) | (*(sptr + 1) >> 28)) &
                    ((*(sptr) << 13) | (*(sptr + 1) >> 19)) &
                    ((*(sptr) << 22) | (*(sptr + 1) >> 10));
        }
    }
}

static void
fdilate_2_67(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls4;
int32_t             wpls5;
int32_t             wpls13;
int32_t             wpls14;
int32_t             wpls22;
int32_t             wpls23;

    wpls4 = 4 * wpls;
    wpls5 = 5 * wpls;
    wpls13 = 13 * wpls;
    wpls14 = 14 * wpls;
    wpls22 = 22 * wpls;
    wpls23 = 23 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls23)) |
                    (*(sptr + wpls14)) |
                    (*(sptr + wpls5)) |
                    (*(sptr - wpls4)) |
                    (*(sptr - wpls13)) |
                    (*(sptr - wpls22));
        }
    }
}

static void
ferode_2_67(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls4;
int32_t             wpls5;
int32_t             wpls13;
int32_t             wpls14;
int32_t             wpls22;
int32_t             wpls23;

    wpls4 = 4 * wpls;
    wpls5 = 5 * wpls;
    wpls13 = 13 * wpls;
    wpls14 = 14 * wpls;
    wpls22 = 22 * wpls;
    wpls23 = 23 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls23)) &
                    (*(sptr - wpls14)) &
                    (*(sptr - wpls5)) &
                    (*(sptr + wpls4)) &
                    (*(sptr + wpls13)) &
                    (*(sptr + wpls22));
        }
    }
}

static void
fdilate_2_68(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 22) | (*(sptr + 1) >> 10)) |
                    ((*(sptr) << 11) | (*(sptr + 1) >> 21)) |
                    (*sptr) |
                    ((*(sptr) >> 11) | (*(sptr - 1) << 21)) |
                    ((*(sptr) >> 22) | (*(sptr - 1) << 10));
        }
    }
}

static void
ferode_2_68(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 22) | (*(sptr - 1) << 10)) &
                    ((*(sptr) >> 11) | (*(sptr - 1) << 21)) &
                    (*sptr) &
                    ((*(sptr) << 11) | (*(sptr + 1) >> 21)) &
                    ((*(sptr) << 22) | (*(sptr + 1) >> 10));
        }
    }
}

static void
fdilate_2_69(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls11;
int32_t             wpls22;

    wpls11 = 11 * wpls;
    wpls22 = 22 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls22)) |
                    (*(sptr + wpls11)) |
                    (*sptr) |
                    (*(sptr - wpls11)) |
                    (*(sptr - wpls22));
        }
    }
}

static void
ferode_2_69(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls11;
int32_t             wpls22;

    wpls11 = 11 * wpls;
    wpls22 = 22 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls22)) &
                    (*(sptr - wpls11)) &
                    (*sptr) &
                    (*(sptr + wpls11)) &
                    (*(sptr + wpls22));
        }
    }
}

static void
fdilate_2_70(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 24) | (*(sptr + 1) >> 8)) |
                    ((*(sptr) << 16) | (*(sptr + 1) >> 16)) |
                    ((*(sptr) << 8) | (*(sptr + 1) >> 24)) |
                    (*sptr) |
                    ((*(sptr) >> 8) | (*(sptr - 1) << 24)) |
                    ((*(sptr) >> 16) | (*(sptr - 1) << 16)) |
                    ((*(sptr) >> 24) | (*(sptr - 1) << 8));
        }
    }
}

static void
ferode_2_70(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 24) | (*(sptr - 1) << 8)) &
                    ((*(sptr) >> 16) | (*(sptr - 1) << 16)) &
                    ((*(sptr) >> 8) | (*(sptr - 1) << 24)) &
                    (*sptr) &
                    ((*(sptr) << 8) | (*(sptr + 1) >> 24)) &
                    ((*(sptr) << 16) | (*(sptr + 1) >> 16)) &
                    ((*(sptr) << 24) | (*(sptr + 1) >> 8));
        }
    }
}

static void
fdilate_2_71(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls8;
int32_t             wpls16;
int32_t             wpls24;

    wpls8 = 8 * wpls;
    wpls16 = 16 * wpls;
    wpls24 = 24 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls24)) |
                    (*(sptr + wpls16)) |
                    (*(sptr + wpls8)) |
                    (*sptr) |
                    (*(sptr - wpls8)) |
                    (*(sptr - wpls16)) |
                    (*(sptr - wpls24));
        }
    }
}

static void
ferode_2_71(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls8;
int32_t             wpls16;
int32_t             wpls24;

    wpls8 = 8 * wpls;
    wpls16 = 16 * wpls;
    wpls24 = 24 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls24)) &
                    (*(sptr - wpls16)) &
                    (*(sptr - wpls8)) &
                    (*sptr) &
                    (*(sptr + wpls8)) &
                    (*(sptr + wpls16)) &
                    (*(sptr + wpls24));
        }
    }
}

static void
fdilate_2_72(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 25) | (*(sptr + 1) >> 7)) |
                    ((*(sptr) << 15) | (*(sptr + 1) >> 17)) |
                    ((*(sptr) << 5) | (*(sptr + 1) >> 27)) |
                    ((*(sptr) >> 5) | (*(sptr - 1) << 27)) |
                    ((*(sptr) >> 15) | (*(sptr - 1) << 17)) |
                    ((*(sptr) >> 25) | (*(sptr - 1) << 7));
        }
    }
}

static void
ferode_2_72(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 25) | (*(sptr - 1) << 7)) &
                    ((*(sptr) >> 15) | (*(sptr - 1) << 17)) &
                    ((*(sptr) >> 5) | (*(sptr - 1) << 27)) &
                    ((*(sptr) << 5) | (*(sptr + 1) >> 27)) &
                    ((*(sptr) << 15) | (*(sptr + 1) >> 17)) &
                    ((*(sptr) << 25) | (*(sptr + 1) >> 7));
        }
    }
}

static void
fdilate_2_73(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls5;
int32_t             wpls15;
int32_t             wpls25;

    wpls5 = 5 * wpls;
    wpls15 = 15 * wpls;
    wpls25 = 25 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls25)) |
                    (*(sptr + wpls15)) |
                    (*(sptr + wpls5)) |
                    (*(sptr - wpls5)) |
                    (*(sptr - wpls15)) |
                    (*(sptr - wpls25));
        }
    }
}

static void
ferode_2_73(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls5;
int32_t             wpls15;
int32_t             wpls25;

    wpls5 = 5 * wpls;
    wpls15 = 15 * wpls;
    wpls25 = 25 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls25)) &
                    (*(sptr - wpls15)) &
                    (*(sptr - wpls5)) &
                    (*(sptr + wpls5)) &
                    (*(sptr + wpls15)) &
                    (*(sptr + wpls25));
        }
    }
}

static void
fdilate_2_74(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) << 27) | (*(sptr + 1) >> 5)) |
                    ((*(sptr) << 18) | (*(sptr + 1) >> 14)) |
                    ((*(sptr) << 9) | (*(sptr + 1) >> 23)) |
                    (*sptr) |
                    ((*(sptr) >> 9) | (*(sptr - 1) << 23)) |
                    ((*(sptr) >> 18) | (*(sptr - 1) << 14)) |
                    ((*(sptr) >> 27) | (*(sptr - 1) << 5));
        }
    }
}

static void
ferode_2_74(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;

    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = ((*(sptr) >> 27) | (*(sptr - 1) << 5)) &
                    ((*(sptr) >> 18) | (*(sptr - 1) << 14)) &
                    ((*(sptr) >> 9) | (*(sptr - 1) << 23)) &
                    (*sptr) &
                    ((*(sptr) << 9) | (*(sptr + 1) >> 23)) &
                    ((*(sptr) << 18) | (*(sptr + 1) >> 14)) &
                    ((*(sptr) << 27) | (*(sptr + 1) >> 5));
        }
    }
}

static void
fdilate_2_75(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls9;
int32_t             wpls18;
int32_t             wpls27;

    wpls9 = 9 * wpls;
    wpls18 = 18 * wpls;
    wpls27 = 27 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr + wpls27)) |
                    (*(sptr + wpls18)) |
                    (*(sptr + wpls9)) |
                    (*sptr) |
                    (*(sptr - wpls9)) |
                    (*(sptr - wpls18)) |
                    (*(sptr - wpls27));
        }
    }
}

static void
ferode_2_75(uint32_t  *datad,
            int32_t    w,
            int32_t    h,
            int32_t    wpld,
            uint32_t  *datas,
            int32_t    wpls)
{
int32_t   i;
int32_t   j, pwpls;
uint32_t  *sptr, *dptr;
int32_t             wpls9;
int32_t             wpls18;
int32_t             wpls27;

    wpls9 = 9 * wpls;
    wpls18 = 18 * wpls;
    wpls27 = 27 * wpls;
    pwpls = (uint32_t)(w + 31) / 32;  /* proper wpl of src */

    for (i = 0; i < h; i++) {
        sptr = datas + i * wpls;
        dptr = datad + i * wpld;
        for (j = 0; j < pwpls; j++, sptr++, dptr++) {
            *dptr = (*(sptr - wpls27)) &
                    (*(sptr - wpls18)) &
                    (*(sptr - wpls9)) &
                    (*sptr) &
                    (*(sptr + wpls9)) &
                    (*(sptr + wpls18)) &
                    (*(sptr + wpls27));
        }
    }
}

