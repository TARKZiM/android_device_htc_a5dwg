/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <android-base/logging.h>
#include <android-base/properties.h>

#include "init_msm8926.h"
#include "vendor_init.h"

using android::base::GetProperty;

void gsm_properties(char const default_network[])
{
    property_override("ro.telephony.default_network", default_network);
    property_override("ro.ril.hsupa.category", "6");
    property_override("ro.ril.hsxpa", "4");
    property_override("ro.ril.disable.cpc", "1");
    property_override("ro.ril.enable.pre_r8fd", "1");
    property_override("ro.ril.enable.sdr", "1");
    property_override("ro.ril.enable.r8fd", "1");
    property_override("ro.ril.disable.fd.plmn.prefix", "23402,23410,23411,23420,23594,27202,27205");
}

void vendor_load_properties()
{

    std::string device;
    std::string bootmid = GetProperty("ro.boot.mid", "");
    std::string carrier = GetProperty("ro.boot.carrier", "");

    if (bootmid == "0P9C50000") {
        /* a5dwg (chinese) */
        property_override("ro.build.fingerprint", "htc/htccn_chs_ct/htc_a5dwg:4.4.2/KOT49H/377271.2:user/release-keys");
        property_override("ro.build.description", "2.06.1401.2 CL377271 release-keys");
        property_override("ro.product.model", "D816d");
        property_override("ro.product.device", "htc_a5dwg");
        property_override("ro.build.product", "htc_a5dwg");
        property_override("ro.telephony.default_network", "7");
        property_override("persist.radio.multisim.config", "dsds");
        property_override("ro.ril.enable.pre_r8fd", "1");
        property_override("ro.ril.enable.sdr", "0");
        property_override("ro.ril.enable.r8fd", "1");
        property_override("ro.ril.disable.fd.plmn.prefix", "23402,23410,23411,23420,27202");
        property_override("ro.ril.oem.ecclist", "110,112,119,120,911,999");
        property_override("ro.ril.set.mtusize", "1420");
    } else if (bootmid == "0P9C51000") {
        /* a5dwg (international) */
        gsm_properties("7");
        property_override("ro.build.fingerprint", "htc/htc_asia_india/htc_a5dwg:4.4.2/KOT49H/334435.1:user/release-keys");
        property_override("ro.build.description", "1.24.720.1 CL334435 release-keys");
        property_override("ro.product.model", "Desire 816 dual sim");
        property_override("ro.product.device", "htc_a5dwg");
        property_override("ro.build.product", "htc_a5dwg");
        property_override("persist.radio.multisim.config", "dsds");
        property_override("ro.ril.hsdpa.category", "10");
        property_override("ro.ril.air.enabled", "1");
    } else {
        /* a5dug */
        gsm_properties("0");
        property_override("ro.product.device", "htc_a5dug");
        property_override("ro.build.product", "htc_a5dug");
        property_override("persist.radio.multisim.config", "dsda");
        property_override("ro.ril.hsdpa.category", "24");
        property_override("ro.ril.disable.cpc", "1");
        property_override("ro.ril.enable.sdr", "0");
        if (carrier == "HTC-Russia") {
            /* russian */
            property_override("ro.build.fingerprint", "htc/htc_europe/htc_a5dug:4.4.2/KOT49H/372006.1:user/release-keys");
            property_override("ro.build.description", "2.06.1402.2 CL377269 release-keys");
            property_override("ro.product.model", "Desire 816 dual sim");
            property_override("ro.ril.enable.a53", "1");
        } else {
            /* chinese */
            property_override("ro.build.fingerprint", "htc/htccn_chs_cu/htc_a5dug:5.0.2/LRX22G/510432.1:user/release-keys");
            property_override("ro.build.description", "2.34.1402.1 CL510432 release-keyss");
            property_override("ro.product.model", "D816w");
        }
    }
      device = GetProperty("ro.product.device", "");
      LOG(ERROR) << "Found bootmid '" << bootmid.c_str() << "' setting build properties for '" << device.c_str() << "' device\n";
}
