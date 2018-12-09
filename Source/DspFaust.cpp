#define JUCE_DRIVER 1
/* ------------------------------------------------------------
name: "PatSynth"
Code generated with Faust 2.13.9 (https://faust.grame.fr)
Compilation options: -scal -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

/************************************************************************
 ************************************************************************
 FAUST API Architecture File
 Copyright (C) 2016 GRAME, Romain Michon, CCRMA - Stanford University
 Copyright (C) 2014-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------

 This is sample code. This file is provided as an example of minimal
 FAUST architecture file. Redistribution and use in source and binary
 forms, with or without modification, in part or in full are permitted.
 In particular you can create a derived work of this FAUST architecture
 and distribute that work under terms of your choice.

 This sample code is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 ************************************************************************
 ************************************************************************/

#include <cmath>
#include <cstring>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __misc__
#define __misc__

#include <algorithm>
#include <map>
#include <cstdlib>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __meta__
#define __meta__

struct Meta
{
    virtual void declare(const char* key, const char* value) = 0;
    virtual ~Meta() {};
};

#endif

using std::max;
using std::min;

struct XXXX_Meta : std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key] = value; }
};

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key] = value; }
};

static int lsr(int x, int n)	{ return int(((unsigned int)x) >> n); }

static int int2pow2(int x)		{ int r = 0; while ((1<<r) < x) r++; return r; }

static long lopt(char* argv[], const char* name, long def)
{
	int	i;
    for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return std::atoi(argv[i+1]);
	return def;
}

static bool isopt(char* argv[], const char* name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

static const char* lopts(char* argv[], const char* name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}

#endif

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __UI_H__
#define __UI_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust DSP User Interface
 * User Interface as expected by the buildUserInterface() method of a DSP.
 * This abstract class contains only the method that the Faust compiler can
 * generate to describe a DSP user interface.
 ******************************************************************************/

struct Soundfile;

class UI
{

    public:

        UI() {}

        virtual ~UI() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
};

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __JSONUIDecoder__
#define __JSONUIDecoder__

#include <vector>
#include <map>
#include <utility>
#include <cstdlib>
#include <sstream>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef SIMPLEPARSER_H
#define SIMPLEPARSER_H

// ---------------------------------------------------------------------
//                          Simple Parser
// A parser returns true if it was able to parse what it is
// supposed to parse and advance the pointer. Otherwise it returns false
// and the pointer is not advanced so that another parser can be tried.
// ---------------------------------------------------------------------

#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <ctype.h>

#ifndef _WIN32
# pragma GCC diagnostic ignored "-Wunused-function"
#endif

struct itemInfo {
    std::string type;
    std::string label;
    std::string url;
    std::string address;
    std::string index;
    std::string init;
    std::string min;
    std::string max;
    std::string step;
    std::vector<std::pair<std::string, std::string> > meta;
};

/*
// Menu {'low' : 440.0; 'mid' : 880.0; 'hi' : 1760.0}
static bool parseMenuList(const char*& p, std::vector<std::string>& names, std::vector<double>& values);
static bool parseMenuItem(const char*& p, std::string& name, double& value);

// Menu {'foo.wav'; 'bar.wav'}
static bool parseMenuList2(const char*& p, std::vector<std::string>& names, bool debug = false);
static bool parseMenuItem2(const char*& p, std::string& name);

static void skipBlank(const char*& p);
static bool parseChar(const char*& p, char x);
static bool parseWord(const char*& p, const char* w);
static bool parseString(const char*& p, char quote, std::string& s);
static bool parseSQString(const char*& p, std::string& s);
static bool parseDQString(const char*& p, std::string& s);
static bool parseDouble(const char*& p, double& x);
static bool parseList(const char*& p, std::vector<std::string>& items);
*/

// ---------------------------------------------------------------------
//                          Elementary parsers
// ---------------------------------------------------------------------

// Report a parsing error
static bool parseError(const char*& p, const char* errmsg)
{
    std::cerr << "Parse error : " << errmsg << " here : " << p << std::endl;
    return true;
}

/**
 * @brief skipBlank : advance pointer p to the first non blank character
 * @param p the string to parse, then the remaining string
 */
static void skipBlank(const char*& p)
{
    while (isspace(*p)) { p++; }
}

// Parse character x, but don't report error if fails
static bool tryChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief parseChar : parse a specific character x
 * @param p the string to parse, then the remaining string
 * @param x the character to recognize
 * @return true if x was found at the begin of p
 */
static bool parseChar(const char*& p, char x)
{
    skipBlank(p);
    if (x == *p) {
        p++;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief parseWord : parse a specific string w
 * @param p the string to parse, then the remaining string
 * @param w the string to recognize
 * @return true if string w was found at the begin of p
 */
static bool parseWord(const char*& p, const char* w)
{
    skipBlank(p);
    const char* saved = p;  // to restore position if we fail
    while ((*w == *p) && (*w)) {++w; ++p;}
    if (*w) {
        p = saved;
        return false;
    } else {
        return true;
    }
}

/**
 * @brief parseDouble : parse number [s]dddd[.dddd] and store the result in x
 * @param p the string to parse, then the remaining string
 * @param x the float number found if any
 * @return true if a float number was found at the begin of p
 */
static bool parseDouble(const char*& p, double& x)
{
    double sign = +1.0;    // sign of the number
    double ipart = 0;      // integral part of the number
    double dpart = 0;      // decimal part of the number before division
    double dcoef = 1.0;    // division factor for the decimal part
    
    bool valid = false;    // true if the number contains at least one digit
    skipBlank(p);
    const char* saved = p; // to restore position if we fail
    
    if (parseChar(p, '+')) {
        sign = 1.0;
    } else if (parseChar(p, '-')) {
        sign = -1.0;
    }
    while (isdigit(*p)) {
        valid = true;
        ipart = ipart*10 + (*p - '0');
        p++;
    }
    if (parseChar(p, '.')) {
        while (isdigit(*p)) {
            valid = true;
            dpart = dpart*10 + (*p - '0');
            dcoef *= 10.0;
            p++;
        }
    }
    if (valid)  {
        x = sign*(ipart + dpart/dcoef);
    } else {
        p = saved;
    }
    return valid;
}

/**
 * @brief parseString, parse an arbitrary quoted string q...q and store the result in s
 * @param p the string to parse, then the remaining string
 * @param quote the character used to quote the string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseString(const char*& p, char quote, std::string& s)
{
    std::string str;
    skipBlank(p);
    
    const char* saved = p;  // to restore position if we fail
    if (*p++ == quote) {
        while ((*p != 0) && (*p != quote)) {
            str += *p++;
        }
        if (*p++ == quote) {
            s = str;
            return true;
        }
    }
    p = saved;
    return false;
}

/**
 * @brief parseSQString, parse a single quoted string '...' and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseSQString(const char*& p, std::string& s)
{
    return parseString(p, '\'', s);
}

/**
 * @brief parseDQString, parse a double quoted string "..." and store the result in s
 * @param p the string to parse, then the remaining string
 * @param s the (unquoted) string found if any
 * @return true if a string was found at the begin of p
 */
static bool parseDQString(const char*& p, std::string& s)
{
    return parseString(p, '"', s);
}

// ---------------------------------------------------------------------
//
//                          IMPLEMENTATION
// 
// ---------------------------------------------------------------------

/**
 * @brief parseMenuItem, parse a menu item ...'low':440.0...
 * @param p the string to parse, then the remaining string
 * @param name the name found
 * @param value the value found
 * @return true if a nemu item was found
 */
static bool parseMenuItem(const char*& p, std::string& name, double& value)
{
    const char* saved = p;  // to restore position if we fail
    if (parseSQString(p, name) && parseChar(p, ':') && parseDouble(p, value)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

static bool parseMenuItem2(const char*& p, std::string& name)
{
    const char* saved = p;  // to restore position if we fail
    if (parseSQString(p, name)) {
        return true;
    } else {
        p = saved;
        return false;
    }
}

/**
 * @brief parseMenuList, parse a menu list {'low' : 440.0; 'mid' : 880.0; 'hi' : 1760.0}...
 * @param p the string to parse, then the remaining string
 * @param names the vector of names found
 * @param values the vector of values found
 * @return true if a menu list was found
 */
static bool parseMenuList(const char*& p, std::vector<std::string>& names, std::vector<double>& values)
{
    std::vector<std::string> tmpnames;
    std::vector<double> tmpvalues;
    const char* saved = p; // to restore position if we fail

    if (parseChar(p, '{')) {
        do {
            std::string n;
            double v;
            if (parseMenuItem(p, n, v)) {
                tmpnames.push_back(n);
                tmpvalues.push_back(v);
            } else {
                p = saved;
                return false;
            }
        } while (parseChar(p, ';'));
        if (parseChar(p, '}')) {
            // we suceeded
            names = tmpnames;
            values = tmpvalues;
            return true;
        }
    }
    p = saved;
    return false;
}

static bool parseMenuList2(const char*& p, std::vector<std::string>& names, bool debug)
{
    std::vector<std::string> tmpnames;
    const char* saved = p;  // to restore position if we fail
    
    if (parseChar(p, '{')) {
        do {
            std::string n;
            if (parseMenuItem2(p, n)) {
                tmpnames.push_back(n);
            } else {
                goto error;
            }
        } while (parseChar(p, ';'));
        if (parseChar(p, '}')) {
            // we suceeded
            names = tmpnames;
            return true;
        }
    }
    
error:
    if (debug) { std::cerr << "parseMenuList2 : (" << saved << ") is not a valid list !\n"; }
    p = saved;
    return false;
}

/// ---------------------------------------------------------------------
// Parse list of strings
/// ---------------------------------------------------------------------
static bool parseList(const char*& p, std::vector<std::string>& items)
{
    const char* saved = p;  // to restore position if we fail
    if (parseChar(p, '[')) {
        do {
            std::string item;
            if (!parseDQString(p, item)) {
                p = saved;
                return false;
            }
            items.push_back(item);
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        p = saved;
        return false;
    }
}

static bool parseMetaData(const char*& p, std::map<std::string, std::string>& metadatas)
{
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas[metaKey] = metaValue;
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        return false;
    }
}

static bool parseItemMetaData(const char*& p, std::vector<std::pair<std::string, std::string> >& metadatas)
{
    std::string metaKey, metaValue;
    if (parseChar(p, ':') && parseChar(p, '[')) {
        do { 
            if (parseChar(p, '{') && parseDQString(p, metaKey) && parseChar(p, ':') && parseDQString(p, metaValue) && parseChar(p, '}')) {
                metadatas.push_back(std::make_pair(metaKey, metaValue));
            }
        } while (tryChar(p, ','));
        return parseChar(p, ']');
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse metadatas of the interface:
// "name" : "...", "inputs" : "...", "outputs" : "...", ...
// and store the result as key/value
/// ---------------------------------------------------------------------
static bool parseGlobalMetaData(const char*& p, std::string& key, std::string& value, std::map<std::string, std::string>& metadatas, std::vector<std::string>& items)
{
    if (parseDQString(p, key)) {
        if (key == "meta") {
            return parseMetaData(p, metadatas);
        } else {
            return parseChar(p, ':') && (parseDQString(p, value) || parseList(p, items));
        }
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse gui:
// "type" : "...", "label" : "...", "address" : "...", ...
// and store the result in uiItems Vector
/// ---------------------------------------------------------------------
static bool parseUI(const char*& p, std::vector<itemInfo*>& uiItems, int& numItems)
{
    if (parseChar(p, '{')) {
   
        std::string label;
        std::string value;
        
        do {
            if (parseDQString(p, label)) {
                if (label == "type") {
                    if (uiItems.size() != 0) {
                        numItems++;
                    }
                    if (parseChar(p, ':') && parseDQString(p, value)) {   
                        itemInfo* item = new itemInfo;
                        item->type = value;
                        uiItems.push_back(item);
                    }
                }
                
                else if (label == "label") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->label = value;
                    }
                }
                
                else if (label == "url") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->url = value;
                    }
                }
                
                else if (label == "address") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->address = value;
                    }
                }
                
                else if (label == "index") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->index = value;
                    }
                }
                
                else if (label == "meta") {
                    itemInfo* item = uiItems[numItems];
                    if (!parseItemMetaData(p, item->meta)) {
                        return false;
                    }
                }
                
                else if (label == "init") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->init = value;
                    }
                }
                
                else if (label == "min") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->min = value;
                    }
                }
                
                else if (label == "max") {
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->max = value;
                    }
                }
                
                else if (label == "step"){
                    if (parseChar(p, ':') && parseDQString(p, value)) {
                        itemInfo* item = uiItems[numItems];
                        item->step = value;
                    }
                }
                
                else if (label == "items") {
                    if (parseChar(p, ':') && parseChar(p, '[')) {
                        do { 
                            if (!parseUI(p, uiItems, numItems)) {
                                return false;
                            }
                        } while (tryChar(p, ','));
                        if (parseChar(p, ']')) {
                            itemInfo* item = new itemInfo;
                            item->type = "close";
                            uiItems.push_back(item);
                            numItems++;
                        }
                    }
                }
            } else {
                return false;
            }
            
        } while (tryChar(p, ','));
        
        return parseChar(p, '}');
    } else {
        return false;
    }
}

// ---------------------------------------------------------------------
// Parse full JSON record describing a JSON/Faust interface :
// {"metadatas": "...", "ui": [{ "type": "...", "label": "...", "items": [...], "address": "...","init": "...", "min": "...", "max": "...","step": "..."}]}
//
// and store the result in map Metadatas and vector containing the items of the interface. Returns true if parsing was successfull.
/// ---------------------------------------------------------------------
static bool parseJson(const char*& p, std::map<std::string, std::string>& metadatas1, std::map<std::string, std::vector<std::string> >& metadatas2, std::vector<itemInfo*>& uiItems)
{
    parseChar(p, '{');
    
    do {
        std::string key;
        std::string value;
        std::vector<std::string> items;
        if (parseGlobalMetaData(p, key, value, metadatas1, items)) {
            if (key != "meta") {
                // keep "name", "inputs", "outputs" key/value pairs
                if (items.size() > 0) {
                    metadatas2[key] = items;
                    items.clear();
                } else {
                    metadatas1[key] = value;
                }
            }
        } else if (key == "ui") {
            int numItems = 0;
            parseChar(p, '[') && parseUI(p, uiItems, numItems);
        }
    } while (tryChar(p, ','));
    
    return parseChar(p, '}');
}

#endif // SIMPLEPARSER_H

#ifdef _WIN32
#include <windows.h>
#define snprintf _snprintf
#endif

static FAUSTFLOAT STR2REAL(const std::string& s) { return (std::strtod(s.c_str(), NULL)); }

//-------------------------------------------------------------------
//  Decode a dsp JSON description and implement 'buildUserInterface'
//-------------------------------------------------------------------

struct Soundfile;

typedef std::map<std::string, std::pair <int, FAUSTFLOAT*> > controlMap;

struct JSONUIDecoder {

    std::string fName;
    std::string fFileName;
    
    std::map<std::string, std::string> fMetadatas;
    std::vector<itemInfo*> fUiItems;     
    
    FAUSTFLOAT* fInControl;
    FAUSTFLOAT* fOutControl;
    Soundfile** fSoundfiles;
    
    std::string fJSON;
    
    int fNumInputs, fNumOutputs; 
    int fInputItems, fOutputItems, fSoundfileItems;
    
    std::string fVersion;
    std::string fCompileOptions;
    
    std::vector<std::string> fLibraryList;
    std::vector<std::string> fIncludePathnames;
    
    int fDSPSize;
    
    controlMap fPathInputTable;     // [path, <index, zone>]
    controlMap fPathOutputTable;    // [path, <index, zone>]

    bool isInput(const std::string& type) { return (type == "vslider" || type == "hslider" || type == "nentry" || type == "button" || type == "checkbox"); }
    bool isOutput(const std::string& type) { return (type == "hbargraph" || type == "vbargraph"); }
    bool isSoundfile(const std::string& type) { return (type == "soundfile"); }

    JSONUIDecoder(const std::string& json) 
    {
        fJSON = json;
        const char* p = fJSON.c_str();
        std::map<std::string, std::vector<std::string> > meta_datas;
        parseJson(p, fMetadatas, meta_datas, fUiItems);
        
        // fMetadatas will contain the "meta" section as well as <name : val>, <inputs : val>, <ouputs : val> pairs
        if (fMetadatas.find("name") != fMetadatas.end()) {
            fName = fMetadatas["name"];
            fMetadatas.erase("name");
        } else {
            fName = "";
        }
        
        if (fMetadatas.find("filename") != fMetadatas.end()) {
            fFileName = fMetadatas["filename"];
            fMetadatas.erase("filename");
        } else {
            fName = "";
        }
     
        if (fMetadatas.find("version") != fMetadatas.end()) {
            fVersion = fMetadatas["version"];
            fMetadatas.erase("version");
        } else {
            fVersion = "";
        }
        
        if (fMetadatas.find("compile_options") != fMetadatas.end()) {
            fCompileOptions = fMetadatas["compile_options"];
            fMetadatas.erase("compile_options");
        } else {
            fCompileOptions = "";
        }
        
        if (meta_datas.find("library_list") != meta_datas.end()) {
            fLibraryList = meta_datas["library_list"];
            meta_datas.erase("library_list");
        }
        
        if (meta_datas.find("include_pathnames") != meta_datas.end()) {
            fIncludePathnames = meta_datas["include_pathnames"];
            meta_datas.erase("include_pathnames");
        }
  
        if (fMetadatas.find("size") != fMetadatas.end()) {
            fDSPSize = std::atoi(fMetadatas["size"].c_str());
            fMetadatas.erase("size");
        } else {
            fDSPSize = -1;
        }
         
        if (fMetadatas.find("inputs") != fMetadatas.end()) {
            fNumInputs = std::atoi(fMetadatas["inputs"].c_str());
            fMetadatas.erase("inputs");
        } else {
            fNumInputs = -1;
        }
        
        if (fMetadatas.find("outputs") != fMetadatas.end()) {
            fNumOutputs = std::atoi(fMetadatas["outputs"].c_str());
            fMetadatas.erase("outputs");
        } else {
            fNumOutputs = -1;
        }
       
        fInputItems = 0;
        fOutputItems = 0;
        fSoundfileItems = 0;
        
        std::vector<itemInfo*>::iterator it;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            std::string type = (*it)->type;
            if (isInput(type)) {
                fInputItems++;
            } else if (isOutput(type)) {
                fOutputItems++;          
            } else if (isSoundfile(type)) {
                fSoundfileItems++;
            }
        }
        
        fInControl = new FAUSTFLOAT[fInputItems];
        fOutControl = new FAUSTFLOAT[fOutputItems];
        fSoundfiles = new Soundfile*[fSoundfileItems];
        
        int counterIn = 0;
        int counterOut = 0;
        
        // Prepare the fPathTable and init zone
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            std::string type = (*it)->type;
            // Meta data declaration for input items
            if (isInput(type)) {
                if ((*it)->address != "") {
                    fPathInputTable[(*it)->address] = std::make_pair(std::atoi((*it)->index.c_str()), &fInControl[counterIn]);
                }
                fInControl[counterIn] = STR2REAL((*it)->init);
                counterIn++;
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                if ((*it)->address != "") {
                    fPathOutputTable[(*it)->address] = std::make_pair(std::atoi((*it)->index.c_str()), &fOutControl[counterOut]);
                }
                fOutControl[counterOut] = FAUSTFLOAT(0);
                counterOut++;
            }
        }
    }
    
    virtual ~JSONUIDecoder() 
    {
        std::vector<itemInfo*>::iterator it;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            delete(*it);
        }
        delete [] fInControl;
        delete [] fOutControl;
        delete [] fSoundfiles;
    }
    
    void metadata(Meta* m)
    {
        std::map<std::string, std::string>::iterator it;
        for (it = fMetadatas.begin(); it != fMetadatas.end(); it++) {
            m->declare((*it).first.c_str(), (*it).second.c_str());
        }
    }
    
    void resetUserInterface()
    {
        std::vector<itemInfo*>::iterator it;
        int item = 0;
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            if (isInput((*it)->type)) {
                fInControl[item++] = STR2REAL((*it)->init);
            }
        }
    }
   
    void buildUserInterface(UI* ui)
    {
        // To be sure the floats are correctly encoded
        char* tmp_local = setlocale(LC_ALL, NULL);
        setlocale(LC_ALL, "C");

        int counterIn = 0;
        int counterOut = 0;
        int counterSound = 0;
        std::vector<itemInfo*>::iterator it;
        
        for (it = fUiItems.begin(); it != fUiItems.end(); it++) {
            
            std::string type = (*it)->type;
            
            FAUSTFLOAT init = STR2REAL((*it)->init);
            FAUSTFLOAT min = STR2REAL((*it)->min);
            FAUSTFLOAT max = STR2REAL((*it)->max);
            FAUSTFLOAT step = STR2REAL((*it)->step);
            
            // Meta data declaration for input items
            if (isInput(type)) {
                fInControl[counterIn] = init;
                for (size_t i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(&fInControl[counterIn], (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            // Meta data declaration for output items
            else if (isOutput(type)) {
                fOutControl[counterOut] = init;
                for (size_t i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(&fOutControl[counterOut], (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            // Meta data declaration for group opening or closing
            else {
                for (size_t i = 0; i < (*it)->meta.size(); i++) {
                    ui->declare(0, (*it)->meta[i].first.c_str(), (*it)->meta[i].second.c_str());
                }
            }
            
            if (type == "hgroup") {
                ui->openHorizontalBox((*it)->label.c_str());
            } else if (type == "vgroup") { 
                ui->openVerticalBox((*it)->label.c_str());
            } else if (type == "tgroup") {
                ui->openTabBox((*it)->label.c_str());
            } else if (type == "vslider") {
                ui->addVerticalSlider((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);
            } else if (type == "hslider") {
                ui->addHorizontalSlider((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);            
            } else if (type == "checkbox") {
                ui->addCheckButton((*it)->label.c_str(), &fInControl[counterIn]);
            } else if (type == "soundfile") {
                ui->addSoundfile((*it)->label.c_str(), (*it)->url.c_str(), &fSoundfiles[counterSound]);
            } else if (type == "hbargraph") {
                ui->addHorizontalBargraph((*it)->label.c_str(), &fOutControl[counterOut], min, max);
            } else if (type == "vbargraph") {
                ui->addVerticalBargraph((*it)->label.c_str(), &fOutControl[counterOut], min, max);
            } else if (type == "nentry") {
                ui->addNumEntry((*it)->label.c_str(), &fInControl[counterIn], init, min, max, step);
            } else if (type == "button") {
                ui->addButton((*it)->label.c_str(), &fInControl[counterIn]);
            } else if (type == "close") {
                ui->closeBox();
            }
            
            if (isInput(type)) {
                counterIn++;
            } else if (isOutput(type)) {
                counterOut++;
            } else if (isSoundfile(type)) {
                counterSound++;
            }
        }
        
        setlocale(LC_ALL, tmp_local);
    }
    
    bool hasCompileOption(const std::string& option)
    {
        std::istringstream iss(fCompileOptions);
        std::string token;
        while (std::getline(iss, token, ' ')) {
            if (token == option) return true;
        }
        return false;
    }
    
};

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp__
#define __dsp__

#include <string>
#include <vector>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class UI;
struct Meta;

/**
 * DSP memory manager.
 */

struct dsp_memory_manager {
    
    virtual ~dsp_memory_manager() {}
    
    virtual void* allocate(size_t size) = 0;
    virtual void destroy(void* ptr) = 0;
    
};

/**
* Signal processor definition.
*/

class dsp {

    public:

        dsp() {}
        virtual ~dsp() {}

        /* Return instance number of audio inputs */
        virtual int getNumInputs() = 0;
    
        /* Return instance number of audio outputs */
        virtual int getNumOutputs() = 0;
    
        /**
         * Trigger the ui_interface parameter with instance specific calls
         * to 'addBtton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Returns the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;
    
        /**
         * Global init, calls the following methods:
         * - static class 'classInit': static tables initialization
         * - 'instanceInit': constants and instance state initialization
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void init(int samplingRate) = 0;

        /**
         * Init instance state
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void instanceInit(int samplingRate) = 0;

        /**
         * Init instance constant state
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void instanceConstants(int samplingRate) = 0;
    
        /* Init default control parameters values */
        virtual void instanceResetUserInterface() = 0;
    
        /* Init instance state (delay lines...) */
        virtual void instanceClear() = 0;
 
        /**
         * Return a clone of the instance.
         *
         * @return a copy of the instance on success, otherwise a null pointer.
         */
        virtual dsp* clone() = 0;
    
        /**
         * Trigger the Meta* parameter with instance specific calls to 'declare' (key, value) metadata.
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * DSP instance computation, to be called with successive in/out audio buffers.
         *
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * DSP instance computation: alternative method to be used by subclasses.
         *
         * @param date_usec - the timestamp in microsec given by audio driver.
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

/**
 * Generic DSP decorator.
 */

class decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = 0):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int samplingRate) { fDSP->init(samplingRate); }
        virtual void instanceInit(int samplingRate) { fDSP->instanceInit(samplingRate); }
        virtual void instanceConstants(int samplingRate) { fDSP->instanceConstants(samplingRate); }
        virtual void instanceResetUserInterface() { fDSP->instanceResetUserInterface(); }
        virtual void instanceClear() { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { fDSP->metadata(m); }
        // Beware: subclasses usually have to overload the two 'compute' methods
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
    
};

/**
 * DSP factory class.
 */

class dsp_factory {
    
    protected:
    
        // So that to force sub-classes to use deleteDSPFactory(dsp_factory* factory);
        virtual ~dsp_factory() {}
    
    public:
    
        virtual std::string getName() = 0;
        virtual std::string getSHAKey() = 0;
        virtual std::string getDSPCode() = 0;
        virtual std::string getCompileOptions() = 0;
        virtual std::vector<std::string> getLibraryList() = 0;
        virtual std::vector<std::string> getIncludePathnames() = 0;
    
        virtual dsp* createDSPInstance() = 0;
    
        virtual void setMemoryManager(dsp_memory_manager* manager) = 0;
        virtual dsp_memory_manager* getMemoryManager() = 0;
    
};

/**
 * On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
 * flags to avoid costly denormals.
 */

#ifdef __SSE__
    #include <xmmintrin.h>
    #ifdef __SSE2__
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
    #else
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
    #endif
#else
    #define AVOIDDENORMALS
#endif

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp_adapter__
#define __dsp_adapter__

#include <string.h>
#include <iostream>

// Adapts a DSP for a different number of inputs/outputs

class dsp_adapter : public decorator_dsp {
    
    private:
        
        FAUSTFLOAT** fAdaptedInputs;
        FAUSTFLOAT** fAdaptedOutputs;
        int fHardwareInputs;
        int fHardwareOutputs;
        
        void adaptBuffers(FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            for (int i = 0; i < fHardwareInputs; i++) {
                fAdaptedInputs[i] = inputs[i];
            }
            for (int i = 0; i < fHardwareOutputs; i++) {
                fAdaptedOutputs[i] = outputs[i];
            }
        }
        
    public:
        
        dsp_adapter(dsp* dsp, int hardware_inputs, int hardware_outputs, int buffer_size):decorator_dsp(dsp)
        {
            fHardwareInputs = hardware_inputs;
            fHardwareOutputs = hardware_outputs;
             
            fAdaptedInputs = new FAUSTFLOAT*[dsp->getNumInputs()];
            for (int i = 0; i < dsp->getNumInputs() - fHardwareInputs; i++) {
                fAdaptedInputs[i + fHardwareInputs] = new FAUSTFLOAT[buffer_size];
                memset(fAdaptedInputs[i + fHardwareInputs], 0, sizeof(FAUSTFLOAT) * buffer_size);
            }
            
            fAdaptedOutputs = new FAUSTFLOAT*[dsp->getNumOutputs()];
            for (int i = 0; i < dsp->getNumOutputs() - fHardwareOutputs; i++) {
                fAdaptedOutputs[i + fHardwareOutputs] = new FAUSTFLOAT[buffer_size];
                memset(fAdaptedOutputs[i + fHardwareOutputs], 0, sizeof(FAUSTFLOAT) * buffer_size);
            }
        }
        
        virtual ~dsp_adapter()
        {
            for (int i = 0; i < fDSP->getNumInputs() - fHardwareInputs; i++) {
                delete [] fAdaptedInputs[i + fHardwareInputs];
            }
            delete [] fAdaptedInputs;
            
            for (int i = 0; i < fDSP->getNumOutputs() - fHardwareOutputs; i++) {
                delete [] fAdaptedOutputs[i + fHardwareOutputs];
            }
            delete [] fAdaptedOutputs;
        }
    
        virtual int getNumInputs() { return fHardwareInputs; }
        virtual int getNumOutputs() { return fHardwareOutputs; }
    
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            adaptBuffers(inputs, outputs);
            fDSP->compute(date_usec, count, fAdaptedInputs, fAdaptedOutputs);
        }
        
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            adaptBuffers(inputs, outputs);
            fDSP->compute(count, fAdaptedInputs, fAdaptedOutputs);
        }
};

// Adapts a DSP for a different sample size

template <typename TYPE_INT, typename TYPE_EXT>
class dsp_sample_adapter : public decorator_dsp {
    
    protected:
    
        TYPE_INT** fAdaptedInputs;
        TYPE_INT** fAdaptedOutputs;
    
        void adaptInputBuffers(int count, FAUSTFLOAT** inputs)
        {
            for (int chan = 0; chan < fDSP->getNumInputs(); chan++) {
                for (int frame = 0; frame < count; frame++) {
                    fAdaptedInputs[chan][frame] = TYPE_INT(reinterpret_cast<TYPE_EXT**>(inputs)[chan][frame]);
                }
            }
        }
    
        void adaptOutputsBuffers(int count, FAUSTFLOAT** outputs)
        {
            for (int chan = 0; chan < fDSP->getNumOutputs(); chan++) {
                for (int frame = 0; frame < count; frame++) {
                    reinterpret_cast<TYPE_EXT**>(outputs)[chan][frame] = TYPE_EXT(fAdaptedOutputs[chan][frame]);
                }
            }
        }
    
    public:
    
        dsp_sample_adapter(dsp* dsp):decorator_dsp(dsp)
        {
            fAdaptedInputs = new TYPE_INT*[dsp->getNumInputs()];
            for (int i = 0; i < dsp->getNumInputs(); i++) {
                fAdaptedInputs[i] = new TYPE_INT[4096];
            }
            
            fAdaptedOutputs = new TYPE_INT*[dsp->getNumOutputs()];
            for (int i = 0; i < dsp->getNumOutputs(); i++) {
                fAdaptedOutputs[i] = new TYPE_INT[4096];
            }
        }
    
        virtual ~dsp_sample_adapter()
        {
            for (int i = 0; i < fDSP->getNumInputs(); i++) {
                delete [] fAdaptedInputs[i];
            }
            delete [] fAdaptedInputs;
            
            for (int i = 0; i < fDSP->getNumOutputs(); i++) {
                delete [] fAdaptedOutputs[i];
            }
            delete [] fAdaptedOutputs;
        }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            adaptInputBuffers(count, inputs);
            // DSP base class uses FAUSTFLOAT** type, so reinterpret_cast has to be used even if the real DSP uses SAMPLE_TYPE
            fDSP->compute(count, reinterpret_cast<FAUSTFLOAT**>(fAdaptedInputs), reinterpret_cast<FAUSTFLOAT**>(fAdaptedOutputs));
            adaptOutputsBuffers(count, outputs);
        }
    
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            adaptInputBuffers(count, inputs);
            // DSP base class uses FAUSTFLOAT** type, so reinterpret_cast has to be used even if the real DSP uses SAMPLE_TYPE
            fDSP->compute(date_usec, count, reinterpret_cast<FAUSTFLOAT**>(fAdaptedInputs), reinterpret_cast<FAUSTFLOAT**>(fAdaptedOutputs));
            adaptOutputsBuffers(count, outputs);
       }
};

#endif

//**************************************************************
// Soundfile handling
//**************************************************************

// Must be done before <<includeclass>> otherwise the 'Soundfile' type is not known

#if SOUNDFILE
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __SoundUI_H__
#define __SoundUI_H__

#include <map>
#include <vector>
#include <string>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef Decorator_UI_H
#define Decorator_UI_H


//----------------------------------------------------------------
//  Generic UI empty implementation
//----------------------------------------------------------------

class GenericUI : public UI
{
    
    public:
        
        GenericUI() {}
        virtual ~GenericUI() {}
        
        // -- widget's layouts
        virtual void openTabBox(const char* label) {}
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* soundpath, Soundfile** sf_zone) {}
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) {}
    
};

//----------------------------------------------------------------
//  Generic UI decorator
//----------------------------------------------------------------

class DecoratorUI : public UI
{
    
    protected:
        
        UI* fUI;
        
    public:
        
        DecoratorUI(UI* ui = 0):fUI(ui) {}
        virtual ~DecoratorUI() { delete fUI; }
        
        // -- widget's layouts
        virtual void openTabBox(const char* label)          { fUI->openTabBox(label); }
        virtual void openHorizontalBox(const char* label)   { fUI->openHorizontalBox(label); }
        virtual void openVerticalBox(const char* label)     { fUI->openVerticalBox(label); }
        virtual void closeBox()                             { fUI->closeBox(); }
        
        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)         { fUI->addButton(label, zone); }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)    { fUI->addCheckButton(label, zone); }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addVerticalSlider(label, zone, init, min, max, step); }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addHorizontalSlider(label, zone, init, min, max, step); }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        { fUI->addNumEntry(label, zone, init, min, max, step); }
        
        // -- passive widgets
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addHorizontalBargraph(label, zone, min, max); }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        { fUI->addVerticalBargraph(label, zone, min, max); }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) { fUI->addSoundfile(label, filename, sf_zone); }
    
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) { fUI->declare(zone, key, val); }
    
};

#endif

#ifdef __APPLE__
#include <CoreFoundation/CFBundle.h>
#endif

// Always included otherwise -i mode later on will not always include it (with the conditional includes)
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.

 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __Soundfile__
#define __Soundfile__

#include <iostream>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#define BUFFER_SIZE 1024
#define SAMPLE_RATE 44100
#define MAX_CHAN 64
#define MAX_SOUNDFILE_PARTS 256

#ifdef _MSC_VER
#define PRE_PACKED_STRUCTURE __pragma(pack(push, 1))
#define POST_PACKED_STRUCTURE \
    ;                         \
    __pragma(pack(pop))
#else
#define PRE_PACKED_STRUCTURE
#define POST_PACKED_STRUCTURE __attribute__((__packed__))
#endif

/*
 The soundfile structure to be used by the DSP code. Soundfile has a MAX_SOUNDFILE_PARTS parts 
 (even a single soundfile or an empty soundfile). 
 fLength, fOffset and fSampleRate field are filled accordingly by repeating 
 the actual parts if needed.
 
 It has to be 'packed' to that the LLVM backend can correctly access it.

 Index computation:
    - p is the current part number [0..MAX_SOUNDFILE_PARTS-1] (must be proved by the type system)
    - i is the current position in the part. It will be constrained between [0..length]
    - idx(p,i) = fOffset[p] + max(0, min(i, fLength[p]));
*/

PRE_PACKED_STRUCTURE
struct Soundfile {
    FAUSTFLOAT** fBuffers;
    int fLength[MAX_SOUNDFILE_PARTS];      // length of each part
    int fSampleRate[MAX_SOUNDFILE_PARTS];  // sample rate of each part
    int fOffset[MAX_SOUNDFILE_PARTS];      // offset of each part in the global buffer
    int fChannels;                         // max number of channels of all concatenated files

    Soundfile()
    {
        fBuffers  = NULL;
        fChannels = -1;
    }

    ~Soundfile()
    {
        // Free the real channels only
        for (int chan = 0; chan < fChannels; chan++) {
            delete fBuffers[chan];
        }
        delete[] fBuffers;
    }

} POST_PACKED_STRUCTURE;

/*
 The generic soundfile reader.
 */

class SoundfileReader {
    
   protected:
    
    void emptyFile(Soundfile* soundfile, int part, int& offset, int max_chan)
    {
        soundfile->fLength[part] = BUFFER_SIZE;
        soundfile->fSampleRate[part] = SAMPLE_RATE;
        soundfile->fOffset[part] = offset;
        // Update offset
        offset += soundfile->fLength[part];
    }

    Soundfile* createSoundfile(int cur_chan, int length, int max_chan)
    {
        Soundfile* soundfile = new Soundfile();
        if (!soundfile) {
            throw std::bad_alloc();
        }
        
        soundfile->fBuffers = new FAUSTFLOAT*[max_chan];
        if (!soundfile->fBuffers) {
            throw std::bad_alloc();
        }
        
        for (int chan = 0; chan < cur_chan; chan++) {
            soundfile->fBuffers[chan] = new FAUSTFLOAT[length];
            if (!soundfile->fBuffers[chan]) {
                throw std::bad_alloc();
            }
            memset(soundfile->fBuffers[chan], 0, sizeof(FAUSTFLOAT) * length);
        }
        
        soundfile->fChannels = cur_chan;
        return soundfile;
    }

    void getBuffersOffset(Soundfile* soundfile, FAUSTFLOAT** buffers, int offset)
    {
        for (int chan = 0; chan < soundfile->fChannels; chan++) {
            buffers[chan] = &soundfile->fBuffers[chan][offset];
        }
    }
    
    // Check if a soundfile exists and return its real path_name
    std::string checkFile(const std::vector<std::string>& sound_directories, const std::string& file_name)
    {
        if (checkFile(file_name)) {
            return file_name;
        } else {
            for (int i = 0; i < sound_directories.size(); i++) {
                std::string path_name = sound_directories[i] + "/" + file_name;
                if (checkFile(path_name)) { return path_name; }
            }
            return "";
        }
    }

    // To be implemented by subclasses

    /**
     * Check the availability of a sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     *
     * @return true if the sound resource is available, false otherwise.
     */
    virtual bool checkFile(const std::string& path_name) = 0;

    /**
     * Get the channels and length values of the given sound resource.
     *
     * @param path_name - the name of the file, or sound resource identified this way
     * @param channels - the channels value to be filled with the sound resource number of channels
     * @param length - the length value to be filled with the sound resource length
     *
     */
    virtual void getParamsFile(const std::string& path_name, int& channels, int& length) = 0;

    /**
     * Read one sound resource and fill the 'soundfile' accordingly
     *
     * @param path_name - the name of the file, or sound resource identified this way
     * @param part - the part number to be filled in the soundfile
     * @param offset - the offset value to be incremented with the actual sound resource length in frames
     * @param max_chan - the maximum number of mono channels to fill
     *
     */
    virtual void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan) = 0;

  public:
    
    virtual ~SoundfileReader() {}

    Soundfile* createSoundfile(const std::vector<std::string>& path_name_list, int max_chan)
    {
        try {
            int cur_chan = 1; // At least one buffer
            int total_length = 0;
            
            // Compute total length and chan max of all files
            for (int i = 0; i < path_name_list.size(); i++) {
                int chan, length;
                if (path_name_list[i] == "__empty_sound__") {
                    length = BUFFER_SIZE;
                    chan = 1;
                } else {
                    getParamsFile(path_name_list[i], chan, length);
                }
                cur_chan = std::max<int>(cur_chan, chan);
                total_length += length;
            }
            
            // Complete with empty parts
            total_length += (MAX_SOUNDFILE_PARTS - path_name_list.size()) * BUFFER_SIZE;
            
            // Create the soundfile
            Soundfile* soundfile = createSoundfile(cur_chan, total_length, max_chan);
            
            // Init offset
            int offset = 0;
            
            // Read all files
            for (int i = 0; i < path_name_list.size(); i++) {
                if (path_name_list[i] == "__empty_sound__") {
                    emptyFile(soundfile, i, offset, max_chan);
                } else {
                    readFile(soundfile, path_name_list[i], i, offset, max_chan);
                }
            }
            
            // Complete with empty parts
            for (int i = path_name_list.size(); i < MAX_SOUNDFILE_PARTS; i++) {
                emptyFile(soundfile, i, offset, max_chan);
            }
            
            // Share the same buffers for all other channels so that we have max_chan channels available
            for (int chan = cur_chan; chan < max_chan; chan++) {
                soundfile->fBuffers[chan] = soundfile->fBuffers[chan % cur_chan];
            }
            
            return soundfile;
            
        } catch (...) {
            return NULL;
        }
    }

    // Check if all soundfiles exist and return their real path_name
    std::vector<std::string> checkFiles(const std::vector<std::string>& sound_directories,
                                        const std::vector<std::string>& file_name_list)
    {
        std::vector<std::string> path_name_list;
        for (int i = 0; i < file_name_list.size(); i++) {
            std::string path_name = checkFile(sound_directories, file_name_list[i]);
            // If 'path_name' is not found, it is replaced by an empty sound (= silence)
            path_name_list.push_back((path_name == "") ? "__empty_sound__" : path_name);
        }
        return path_name_list;
    }

};

#endif

#if defined(JUCE_32BIT) || defined(JUCE_64BIT)
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __JuceReader__
#define __JuceReader__

#include <assert.h>


struct JuceReader : public SoundfileReader {
    
    AudioFormatManager fFormatManager;
    
    JuceReader() { fFormatManager.registerBasicFormats(); }
    
    bool checkFile(const std::string& path_name)
    {
        File file(path_name);
        if (file.existsAsFile()) {
            return true;
        } else {
            std::cerr << "ERROR : cannot open '" << path_name << std::endl;
            return false;
        }
    }
    
    void getParamsFile(const std::string& path_name, int& channels, int& length)
    {
        ScopedPointer<AudioFormatReader> formatReader = fFormatManager.createReaderFor(File(path_name));
        assert(formatReader);
        channels = int(formatReader->numChannels);
        length = int(formatReader->lengthInSamples);
    }
    
    void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan)
    {
        ScopedPointer<AudioFormatReader> formatReader = fFormatManager.createReaderFor(File(path_name));
        
        int channels = std::min<int>(max_chan, int(formatReader->numChannels));
        
        soundfile->fLength[part] = int(formatReader->lengthInSamples);
        soundfile->fSampleRate[part] = int(formatReader->sampleRate);
        soundfile->fOffset[part] = offset;
        
        FAUSTFLOAT* buffers[soundfile->fChannels];
        getBuffersOffset(soundfile, buffers, offset);
        
        if (formatReader->read(reinterpret_cast<int *const *>(buffers), int(formatReader->numChannels), 0, int(formatReader->lengthInSamples), false)) {
            
            // Possibly concert samples
            if (!formatReader->usesFloatingPointData) {
                for (int chan = 0; chan < int(formatReader->numChannels); ++chan) {
                    FAUSTFLOAT* buffer = &soundfile->fBuffers[chan][soundfile->fOffset[part]];
                    FloatVectorOperations::convertFixedToFloat(buffer, reinterpret_cast<const int*>(buffer), 1.0f/0x7fffffff, int(formatReader->lengthInSamples));
                }
            }
            
        } else {
            std::cerr << "Error reading the file : " << path_name << std::endl;
        }
            
        // Update offset
        offset += soundfile->fLength[part];
    }
    
};

#endif
JuceReader reader;
#else
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2018 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __LibsndfileReader__
#define __LibsndfileReader__

#include <sndfile.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <fstream>


struct LibsndfileReader : public SoundfileReader {
	
    LibsndfileReader() {}
	
    typedef sf_count_t (* sample_read)(SNDFILE* sndfile, FAUSTFLOAT* ptr, sf_count_t frames);
	
    bool checkFile(const std::string& path_name)
    {
        SF_INFO snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name.c_str(), SFM_READ, &snd_info);
        if (snd_file) {
            sf_close(snd_file);
            return true;
        } else {
            std::cerr << "ERROR : cannot open '" << path_name << "' (" << sf_strerror(NULL) << ")" << std::endl;
            return false;
        }
    }
	
    // Open the file and returns its length and channels
    void getParamsFile(const std::string& path_name, int& channels, int& length)
    {
        SF_INFO	snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name.c_str(), SFM_READ, &snd_info);
        assert(snd_file);
        channels = int(snd_info.channels);
        length = int(snd_info.frames);
        sf_close(snd_file);
    }
	
    // Will be called to fill all parts from 0 to MAX_SOUNDFILE_PARTS-1
    void readFile(Soundfile* soundfile, const std::string& path_name, int part, int& offset, int max_chan)
    {
        // Open sndfile
        SF_INFO	snd_info;
        snd_info.format = 0;
        SNDFILE* snd_file = sf_open(path_name.c_str(), SFM_READ, &snd_info);
        assert(snd_file);
		
        int channels = std::min<int>(max_chan, snd_info.channels);
		
        soundfile->fLength[part] = int(snd_info.frames);
        soundfile->fSampleRate[part] = snd_info.samplerate;
        soundfile->fOffset[part] = offset;
		
        // Read and fill snd_info.channels number of channels
        sf_count_t nbf;
		FAUSTFLOAT* buffer = (FAUSTFLOAT*)alloca(BUFFER_SIZE * sizeof(FAUSTFLOAT) * snd_info.channels);
		sample_read reader;
		
        if (sizeof(FAUSTFLOAT) == 4) {
            reader = reinterpret_cast<sample_read>(sf_readf_float);
        } else {
            reader = reinterpret_cast<sample_read>(sf_readf_double);
        }
        do {
            nbf = reader(snd_file, buffer, BUFFER_SIZE);
            for (int sample = 0; sample < nbf; sample++) {
                for (int chan = 0; chan < channels; chan++) {
                    soundfile->fBuffers[chan][offset + sample] = buffer[sample * snd_info.channels + chan];
                }
            }
            // Update offset
            offset += nbf;
        } while (nbf == BUFFER_SIZE);
		
        sf_close(snd_file);
    }

};

#endif
LibsndfileReader reader;
#endif

// To be used by dsp code if no SoundUI is used
std::vector<std::string> path_name_list;
Soundfile* defaultsound = reader.createSoundfile(path_name_list, MAX_CHAN);

class SoundUI : public GenericUI
{
		
    private:
    
        std::vector<std::string> fSoundfileDir;             // The soundfile directories
        std::map<std::string, Soundfile*> fSoundfileMap;    // Map to share loaded soundfiles
    
     public:
            
        SoundUI(const std::string& sound_directory = "")
        {
            fSoundfileDir.push_back(sound_directory);
        }
    
        SoundUI(const std::vector<std::string>& sound_directories):fSoundfileDir(sound_directories)
        {}
    
        virtual ~SoundUI()
        {   
            // Delete all soundfiles
            std::map<std::string, Soundfile*>::iterator it;
            for (it = fSoundfileMap.begin(); it != fSoundfileMap.end(); it++) {
                delete (*it).second;
            }
        }

        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* url, Soundfile** sf_zone)
        {
            const char* saved_url = url; // 'url' is consumed by parseMenuList2
            std::vector<std::string> file_name_list;
            
            bool menu = parseMenuList2(url, file_name_list, true);
            // If not a list, we have as single file
            if (!menu) { file_name_list.push_back(saved_url); }
            
            // Parse the possible list
            if (fSoundfileMap.find(saved_url) == fSoundfileMap.end()) {
                // Check all files and get their complete path
                std::vector<std::string> path_name_list = reader.checkFiles(fSoundfileDir, file_name_list);
                // Read them and create the Soundfile
                Soundfile* sound_file = reader.createSoundfile(path_name_list, MAX_CHAN);
                if (sound_file) {
                    fSoundfileMap[saved_url] = sound_file;
                } else {
                    // If failure, use 'defaultsound'
                    std::cerr << "addSoundfile : soundfile for " << saved_url << " cannot be created !" << std::endl;
                    *sf_zone = defaultsound;
                    return;
                }
            }
            
            // Get the soundfile
            *sf_zone = fSoundfileMap[saved_url];
        }
    
        static std::string getBinaryPath(std::string folder = "")
        {
            std::string bundle_path_str;
        #ifdef __APPLE__
            CFURLRef bundle_ref = CFBundleCopyBundleURL(CFBundleGetMainBundle());
            if (bundle_ref) {
                UInt8 bundle_path[512];
                if (CFURLGetFileSystemRepresentation(bundle_ref, true, bundle_path, 512)) {
                    bundle_path_str = std::string((char*)bundle_path) + folder;
                }
            }
        #endif
        #ifdef ANDROID_DRIVER
            bundle_path_str = "/data/data/__CURRENT_ANDROID_PACKAGE__/files";
        #endif
            return bundle_path_str;
        }
        
        static std::string getBinaryPathFrom(const std::string& path)
        {
            std::string bundle_path_str;
        #ifdef __APPLE__
            CFBundleRef bundle = CFBundleGetBundleWithIdentifier(CFStringCreateWithCString(kCFAllocatorDefault, path.c_str(), CFStringGetSystemEncoding()));
            CFURLRef bundle_ref = CFBundleCopyBundleURL(bundle);
            if (bundle_ref) {
                UInt8 bundle_path[512];
                if (CFURLGetFileSystemRepresentation(bundle_ref, true, bundle_path, 512)) {
                    bundle_path_str = std::string((char*)bundle_path);
                }
            }
        #endif
        #ifdef ANDROID_DRIVER
            bundle_path_str = "/data/data/__CURRENT_ANDROID_PACKAGE__/files";
        #endif
            return bundle_path_str;
        }
};

#endif
#endif

//**************************************************************
// OSC configuration (hardcoded for now...)
//**************************************************************

#define OSC_IP_ADDRESS  "192.168.1.112"
#define OSC_IN_PORT     "5510"
#define OSC_OUT_PORT    "5511"

//**************************************************************
// Intrinsic
//**************************************************************


#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <math.h>


class mydspSIG0 {
	
  private:
	
	int iRec16[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
		
	}
	int getNumOutputsmydspSIG0() {
		return 1;
		
	}
	int getInputRatemydspSIG0(int channel) {
		int rate;
		switch (channel) {
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	int getOutputRatemydspSIG0(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 0;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	void instanceInitmydspSIG0(int samplingFreq) {
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			iRec16[l17] = 0;
			
		}
		
	}
	
	void fillmydspSIG0(int count, float* output) {
		for (int i = 0; (i < count); i = (i + 1)) {
			iRec16[0] = (iRec16[1] + 1);
			output[i] = std::sin((9.58738019e-05f * float((iRec16[0] + -1))));
			iRec16[1] = iRec16[0];
			
		}
		
	}
};

mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static float ftbl0mydspSIG0[65536];
static float mydsp_faustpower2_f(float value) {
	return (value * value);
	
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif
#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	int iVec0[2];
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	float fRec1[2];
	FAUSTFLOAT fHslider2;
	float fRec3[2];
	FAUSTFLOAT fHslider3;
	float fRec4[2];
	FAUSTFLOAT fButton0;
	float fRec6[2];
	int fSamplingFreq;
	float fConst0;
	FAUSTFLOAT fHslider4;
	float fRec7[2];
	FAUSTFLOAT fHslider5;
	float fRec8[2];
	float fVec1[2];
	float fRec5[2];
	float fConst1;
	FAUSTFLOAT fEntry0;
	float fConst2;
	FAUSTFLOAT fHslider6;
	float fRec10[2];
	FAUSTFLOAT fHslider7;
	float fRec11[2];
	FAUSTFLOAT fHslider8;
	float fRec13[2];
	FAUSTFLOAT fHslider9;
	float fRec14[2];
	float fVec2[2];
	float fRec12[2];
	FAUSTFLOAT fHslider10;
	float fRec15[2];
	FAUSTFLOAT fHslider11;
	float fRec18[2];
	float fRec17[2];
	float fVec3[2];
	float fRec9[2];
	float fVec4[2];
	int IOTA;
	float fVec5[4096];
	float fConst3;
	float fRec19[2];
	float fRec21[2];
	FAUSTFLOAT fHslider12;
	float fRec23[2];
	FAUSTFLOAT fHslider13;
	float fRec24[2];
	float fVec6[2];
	float fRec22[2];
	FAUSTFLOAT fEntry1;
	int iRec26[2];
	float fConst4;
	FAUSTFLOAT fHslider14;
	float fRec27[2];
	FAUSTFLOAT fHslider15;
	float fRec28[2];
	float fRec25[3];
	FAUSTFLOAT fHslider16;
	float fRec29[2];
	FAUSTFLOAT fHslider17;
	float fRec30[2];
	float fConst5;
	float fRec2[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("filename", "PatSynth");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "0.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("misceffects.lib/name", "Faust Math Library");
		m->declare("misceffects.lib/version", "2.0");
		m->declare("name", "PatSynth");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.0");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
		m->declare("spats.lib/name", "Faust Spatialization Library");
		m->declare("spats.lib/version", "0.0");
	}

	virtual int getNumInputs() {
		return 0;
		
	}
	virtual int getNumOutputs() {
		return 2;
		
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch (channel) {
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	static void classInit(int samplingFreq) {
		mydspSIG0* sig0 = newmydspSIG0();
		sig0->instanceInitmydspSIG0(samplingFreq);
		sig0->fillmydspSIG0(65536, ftbl0mydspSIG0);
		deletemydspSIG0(sig0);
		
	}
	
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSamplingFreq)));
		fConst1 = (1.0f / fConst0);
		fConst2 = (0.25f * fConst0);
		fConst3 = (0.5f * fConst0);
		fConst4 = (3.14159274f / fConst0);
		fConst5 = (6.28318548f / fConst0);
		
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.5f);
		fHslider2 = FAUSTFLOAT(0.0f);
		fHslider3 = FAUSTFLOAT(0.14999999999999999f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(0.001f);
		fHslider5 = FAUSTFLOAT(0.5f);
		fEntry0 = FAUSTFLOAT(0.0f);
		fHslider6 = FAUSTFLOAT(55.0f);
		fHslider7 = FAUSTFLOAT(100.0f);
		fHslider8 = FAUSTFLOAT(0.001f);
		fHslider9 = FAUSTFLOAT(0.10000000000000001f);
		fHslider10 = FAUSTFLOAT(0.0f);
		fHslider11 = FAUSTFLOAT(0.10000000000000001f);
		fHslider12 = FAUSTFLOAT(0.001f);
		fHslider13 = FAUSTFLOAT(0.20000000000000001f);
		fEntry1 = FAUSTFLOAT(1.0f);
		fHslider14 = FAUSTFLOAT(10000.0f);
		fHslider15 = FAUSTFLOAT(0.90000000000000002f);
		fHslider16 = FAUSTFLOAT(100.0f);
		fHslider17 = FAUSTFLOAT(0.0f);
		
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			iVec0[l0] = 0;
			
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec0[l1] = 0.0f;
			
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec1[l2] = 0.0f;
			
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0f;
			
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec4[l4] = 0.0f;
			
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec6[l5] = 0.0f;
			
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec7[l6] = 0.0f;
			
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec8[l7] = 0.0f;
			
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fVec1[l8] = 0.0f;
			
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec5[l9] = 0.0f;
			
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec10[l10] = 0.0f;
			
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec11[l11] = 0.0f;
			
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec13[l12] = 0.0f;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec14[l13] = 0.0f;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fVec2[l14] = 0.0f;
			
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec12[l15] = 0.0f;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec15[l16] = 0.0f;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec18[l18] = 0.0f;
			
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec17[l19] = 0.0f;
			
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fVec3[l20] = 0.0f;
			
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			fRec9[l21] = 0.0f;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fVec4[l22] = 0.0f;
			
		}
		IOTA = 0;
		for (int l23 = 0; (l23 < 4096); l23 = (l23 + 1)) {
			fVec5[l23] = 0.0f;
			
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec19[l24] = 0.0f;
			
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			fRec21[l25] = 0.0f;
			
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec23[l26] = 0.0f;
			
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec24[l27] = 0.0f;
			
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fVec6[l28] = 0.0f;
			
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			fRec22[l29] = 0.0f;
			
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			iRec26[l30] = 0;
			
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec27[l31] = 0.0f;
			
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec28[l32] = 0.0f;
			
		}
		for (int l33 = 0; (l33 < 3); l33 = (l33 + 1)) {
			fRec25[l33] = 0.0f;
			
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec29[l34] = 0.0f;
			
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec30[l35] = 0.0f;
			
		}
		for (int l36 = 0; (l36 < 3); l36 = (l36 + 1)) {
			fRec2[l36] = 0.0f;
			
		}
		
	}
	
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	virtual int getSampleRate() {
		return fSamplingFreq;
		
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("PatSynth");
		ui_interface->openHorizontalBox("PatSynth");
		ui_interface->openVerticalBox("master");
		ui_interface->declare(&fHslider3, "1", "");
		ui_interface->addHorizontalSlider("mix", &fHslider3, 0.150000006f, 0.0f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider0, "2", "");
		ui_interface->addHorizontalSlider("gain", &fHslider0, 1.0f, 0.0f, 2.0f, 0.00100000005f);
		ui_interface->declare(&fHslider2, "3", "");
		ui_interface->addHorizontalSlider("drive", &fHslider2, 0.0f, 0.0f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider16, "4", "");
		ui_interface->addHorizontalSlider("eq-freq", &fHslider16, 100.0f, 20.0f, 10000.0f, 0.00100000005f);
		ui_interface->declare(&fHslider17, "4", "");
		ui_interface->addHorizontalSlider("eq-gain", &fHslider17, 0.0f, -12.0f, 12.0f, 0.00100000005f);
		ui_interface->declare(&fHslider1, "5", "");
		ui_interface->addHorizontalSlider("pan", &fHslider1, 0.5f, 0.0f, 1.0f, 0.00100000005f);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("noise");
		ui_interface->declare(&fEntry1, "1", "");
		ui_interface->addNumEntry("filter-type", &fEntry1, 1.0f, 0.0f, 2.0f, 1.0f);
		ui_interface->declare(&fHslider14, "3", "");
		ui_interface->addHorizontalSlider("cutoff", &fHslider14, 10000.0f, 50.0f, 10000.0f, 0.00100000005f);
		ui_interface->declare(&fHslider15, "4", "");
		ui_interface->addHorizontalSlider("reso", &fHslider15, 0.899999976f, 0.899999976f, 10.0f, 0.00100000005f);
		ui_interface->declare(&fHslider12, "5", "");
		ui_interface->addHorizontalSlider("attack", &fHslider12, 0.00100000005f, 0.00100000005f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider13, "6", "");
		ui_interface->addHorizontalSlider("release", &fHslider13, 0.200000003f, 0.00100000005f, 1.0f, 0.00100000005f);
		ui_interface->closeBox();
		ui_interface->openVerticalBox("osc");
		ui_interface->declare(&fEntry0, "1", "");
		ui_interface->addNumEntry("wave", &fEntry0, 0.0f, 0.0f, 2.0f, 1.0f);
		ui_interface->declare(&fHslider6, "2", "");
		ui_interface->addHorizontalSlider("freq", &fHslider6, 55.0f, 20.0f, 2000.0f, 0.00100000005f);
		ui_interface->declare(&fHslider4, "3", "");
		ui_interface->addHorizontalSlider("attack", &fHslider4, 0.00100000005f, 0.00100000005f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider5, "4", "");
		ui_interface->addHorizontalSlider("release", &fHslider5, 0.5f, 0.00100000005f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider7, "5", "");
		ui_interface->addHorizontalSlider("pitch-env-amount", &fHslider7, 100.0f, 0.0f, 10000.0f, 0.00100000005f);
		ui_interface->declare(&fHslider8, "6", "");
		ui_interface->addHorizontalSlider("pitch-env-attack", &fHslider8, 0.00100000005f, 0.00100000005f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider9, "7", "");
		ui_interface->addHorizontalSlider("pitch-env-release", &fHslider9, 0.100000001f, 0.00100000005f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider11, "8", "");
		ui_interface->addHorizontalSlider("pitch-lfo-freq", &fHslider11, 0.100000001f, 0.100000001f, 40.0f, 0.00100000005f);
		ui_interface->declare(&fHslider10, "9", "");
		ui_interface->addHorizontalSlider("pitch-lfo-amount", &fHslider10, 0.0f, 0.0f, 10000.0f, 0.00100000005f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->addButton("gate", &fButton0);
		ui_interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = (0.00100000005f * float(fHslider0));
		float fSlow1 = (0.00100000005f * float(fHslider1));
		float fSlow2 = (0.00100000005f * float(fHslider2));
		float fSlow3 = (0.00100000005f * float(fHslider3));
		float fSlow4 = (0.00100000005f * float(fButton0));
		float fSlow5 = (0.00100000005f * float(fHslider4));
		float fSlow6 = (0.00100000005f * float(fHslider5));
		int iSlow7 = int(float(fEntry0));
		int iSlow8 = (iSlow7 == 0);
		int iSlow9 = (iSlow7 == 1);
		float fSlow10 = (0.00100000005f * float(fHslider6));
		float fSlow11 = (0.00100000005f * float(fHslider7));
		float fSlow12 = (0.00100000005f * float(fHslider8));
		float fSlow13 = (0.00100000005f * float(fHslider9));
		float fSlow14 = (0.00100000005f * float(fHslider10));
		float fSlow15 = (0.00100000005f * float(fHslider11));
		float fSlow16 = (0.00100000005f * float(fHslider12));
		float fSlow17 = (0.00100000005f * float(fHslider13));
		int iSlow18 = int(float(fEntry1));
		int iSlow19 = (iSlow18 == 0);
		int iSlow20 = (iSlow18 == 1);
		float fSlow21 = (0.00100000005f * float(fHslider14));
		float fSlow22 = (0.00100000005f * float(fHslider15));
		float fSlow23 = (0.00100000005f * float(fHslider16));
		float fSlow24 = (0.00100000005f * float(fHslider17));
		for (int i = 0; (i < count); i = (i + 1)) {
			iVec0[0] = 1;
			fRec0[0] = (fSlow0 + (0.999000013f * fRec0[1]));
			fRec1[0] = (fSlow1 + (0.999000013f * fRec1[1]));
			fRec3[0] = (fSlow2 + (0.999000013f * fRec3[1]));
			fRec4[0] = (fSlow3 + (0.999000013f * fRec4[1]));
			fRec6[0] = (fSlow4 + (0.999000013f * fRec6[1]));
			int iTemp0 = (((fRec6[0] - fRec6[1]) > 0.0f) > 0);
			fRec7[0] = (fSlow5 + (0.999000013f * fRec7[1]));
			fRec8[0] = (fSlow6 + (0.999000013f * fRec8[1]));
			float fTemp1 = (fRec7[0] + fRec8[0]);
			fVec1[0] = fTemp1;
			float fTemp2 = (fConst0 * fTemp1);
			fRec5[0] = (iTemp0?0.0f:std::min<float>(fTemp2, ((fRec5[1] + (fConst0 * (fTemp1 - fVec1[1]))) + 1.0f)));
			float fTemp3 = (fConst0 * fRec7[0]);
			int iTemp4 = (fRec5[0] < fTemp3);
			fRec10[0] = (fSlow10 + (0.999000013f * fRec10[1]));
			fRec11[0] = (fSlow11 + (0.999000013f * fRec11[1]));
			fRec13[0] = (fSlow12 + (0.999000013f * fRec13[1]));
			fRec14[0] = (fSlow13 + (0.999000013f * fRec14[1]));
			float fTemp5 = (fRec13[0] + fRec14[0]);
			fVec2[0] = fTemp5;
			float fTemp6 = (fConst0 * fTemp5);
			fRec12[0] = (iTemp0?0.0f:std::min<float>(fTemp6, ((fRec12[1] + (fConst0 * (fTemp5 - fVec2[1]))) + 1.0f)));
			float fTemp7 = (fConst0 * fRec13[0]);
			int iTemp8 = (fRec12[0] < fTemp7);
			fRec15[0] = (fSlow14 + (0.999000013f * fRec15[1]));
			fRec18[0] = (fSlow15 + (0.999000013f * fRec18[1]));
			float fTemp9 = (fRec17[1] + (fConst1 * fRec18[0]));
			fRec17[0] = (fTemp9 - std::floor(fTemp9));
			float fTemp10 = ((fRec10[0] + (fRec11[0] * (iTemp8?((fRec12[0] < 0.0f)?0.0f:(iTemp8?(fConst1 * (fRec12[0] / fRec13[0])):1.0f)):((fRec12[0] < fTemp6)?(((0.0f - (fRec12[0] - fTemp7)) / (0.0f - (fConst0 * (fRec13[0] - fTemp5)))) + 1.0f):0.0f)))) + (fRec15[0] * ftbl0mydspSIG0[int((65536.0f * fRec17[0]))]));
			float fTemp11 = std::max<float>(fTemp10, 23.4489498f);
			float fTemp12 = std::max<float>(20.0f, std::fabs(fTemp11));
			fVec3[0] = fTemp12;
			float fTemp13 = (fRec9[1] + (fConst1 * fVec3[1]));
			fRec9[0] = (fTemp13 - std::floor(fTemp13));
			float fTemp14 = mydsp_faustpower2_f(((2.0f * fRec9[0]) + -1.0f));
			fVec4[0] = fTemp14;
			float fTemp15 = ((float(iVec0[1]) * (fTemp14 - fVec4[1])) / fTemp12);
			fVec5[(IOTA & 4095)] = fTemp15;
			float fTemp16 = std::max<float>(0.0f, std::min<float>(2047.0f, (fConst3 / fTemp11)));
			int iTemp17 = int(fTemp16);
			float fTemp18 = std::floor(fTemp16);
			float fTemp19 = std::max<float>(1.00000001e-07f, std::fabs(fTemp10));
			float fTemp20 = (fRec19[1] + (fConst1 * fTemp19));
			float fTemp21 = (fTemp20 + -1.0f);
			int iTemp22 = (fTemp21 < 0.0f);
			fRec19[0] = (iTemp22?fTemp20:fTemp21);
			float fRec20 = (iTemp22?fTemp20:(fTemp20 + (fTemp21 * (1.0f - (fConst0 / fTemp19)))));
			float fTemp23 = (fRec21[1] + (fConst1 * fTemp10));
			fRec21[0] = (fTemp23 - std::floor(fTemp23));
			fRec23[0] = (fSlow16 + (0.999000013f * fRec23[1]));
			fRec24[0] = (fSlow17 + (0.999000013f * fRec24[1]));
			float fTemp24 = (fRec23[0] + fRec24[0]);
			fVec6[0] = fTemp24;
			float fTemp25 = (fConst0 * fTemp24);
			fRec22[0] = (iTemp0?0.0f:std::min<float>(fTemp25, ((fRec22[1] + (fConst0 * (fTemp24 - fVec6[1]))) + 1.0f)));
			float fTemp26 = (fConst0 * fRec23[0]);
			int iTemp27 = (fRec22[0] < fTemp26);
			iRec26[0] = ((1103515245 * iRec26[1]) + 12345);
			float fTemp28 = (4.65661287e-10f * float(iRec26[0]));
			fRec27[0] = (fSlow21 + (0.999000013f * fRec27[1]));
			float fTemp29 = std::tan((fConst4 * fRec27[0]));
			float fTemp30 = (1.0f / fTemp29);
			fRec28[0] = (fSlow22 + (0.999000013f * fRec28[1]));
			float fTemp31 = (1.0f / fRec28[0]);
			float fTemp32 = (((fTemp31 + fTemp30) / fTemp29) + 1.0f);
			fRec25[0] = (fTemp28 - (((fRec25[2] * (((fTemp30 - fTemp31) / fTemp29) + 1.0f)) + (2.0f * (fRec25[1] * (1.0f - (1.0f / mydsp_faustpower2_f(fTemp29)))))) / fTemp32));
			float fTemp33 = (fTemp29 * fTemp32);
			float fTemp34 = ((fRec25[2] + (fRec25[0] + (2.0f * fRec25[1]))) / fTemp32);
			float fTemp35 = std::max<float>(-1.0f, std::min<float>(1.0f, (std::pow(10.0f, (2.0f * fRec3[0])) * ((((1.0f - fRec4[0]) * (iTemp4?((fRec5[0] < 0.0f)?0.0f:(iTemp4?(fConst1 * (fRec5[0] / fRec7[0])):1.0f)):((fRec5[0] < fTemp2)?(((0.0f - (fRec5[0] - fTemp3)) / (0.0f - (fConst0 * (fRec7[0] - fTemp1)))) + 1.0f):0.0f))) * (iSlow8?ftbl0mydspSIG0[int((65536.0f * fRec21[0]))]:(iSlow9?((2.0f * fRec20) + -1.0f):(fConst2 * ((fTemp15 - (fVec5[((IOTA - iTemp17) & 4095)] * (fTemp18 + (1.0f - fTemp16)))) - ((fTemp16 - fTemp18) * fVec5[((IOTA - (iTemp17 + 1)) & 4095)])))))) + ((fRec4[0] * (iTemp27?((fRec22[0] < 0.0f)?0.0f:(iTemp27?(fConst1 * (fRec22[0] / fRec23[0])):1.0f)):((fRec22[0] < fTemp25)?(((0.0f - (fRec22[0] - fTemp26)) / (0.0f - (fConst0 * (fRec23[0] - fTemp24)))) + 1.0f):0.0f))) * (iSlow19?fTemp34:(iSlow20?(fTemp28 - fTemp34):((fRec25[0] / fTemp33) + (fRec25[2] * (0.0f - (1.0f / fTemp33)))))))))));
			fRec29[0] = (fSlow23 + (0.999000013f * fRec29[1]));
			float fTemp36 = std::tan((fConst4 * fRec29[0]));
			float fTemp37 = (1.0f / fTemp36);
			fRec30[0] = (fSlow24 + (0.999000013f * fRec30[1]));
			int iTemp38 = (fRec30[0] > 0.0f);
			float fTemp39 = std::sin((fConst5 * fRec29[0]));
			float fTemp40 = (fConst4 * ((fRec29[0] * std::pow(10.0f, (0.0500000007f * std::fabs(fRec30[0])))) / fTemp39));
			float fTemp41 = (fConst4 * (fRec29[0] / fTemp39));
			float fTemp42 = (iTemp38?fTemp41:fTemp40);
			float fTemp43 = (2.0f * (fRec2[1] * (1.0f - (1.0f / mydsp_faustpower2_f(fTemp36)))));
			float fTemp44 = (((fTemp37 + fTemp42) / fTemp36) + 1.0f);
			fRec2[0] = ((fTemp35 * (1.0f - (0.333333343f * mydsp_faustpower2_f(fTemp35)))) - (((fRec2[2] * (((fTemp37 - fTemp42) / fTemp36) + 1.0f)) + fTemp43) / fTemp44));
			float fTemp45 = (iTemp38?fTemp40:fTemp41);
			float fTemp46 = ((fTemp43 + (fRec2[0] * (((fTemp37 + fTemp45) / fTemp36) + 1.0f))) + (fRec2[2] * (((fTemp37 - fTemp45) / fTemp36) + 1.0f)));
			output0[i] = FAUSTFLOAT((((fRec0[0] * (1.0f - fRec1[0])) * fTemp46) / fTemp44));
			output1[i] = FAUSTFLOAT((((fRec0[0] * fRec1[0]) * fTemp46) / fTemp44));
			iVec0[1] = iVec0[0];
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec6[1] = fRec6[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			fVec1[1] = fVec1[0];
			fRec5[1] = fRec5[0];
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
			fVec2[1] = fVec2[0];
			fRec12[1] = fRec12[0];
			fRec15[1] = fRec15[0];
			fRec18[1] = fRec18[0];
			fRec17[1] = fRec17[0];
			fVec3[1] = fVec3[0];
			fRec9[1] = fRec9[0];
			fVec4[1] = fVec4[0];
			IOTA = (IOTA + 1);
			fRec19[1] = fRec19[0];
			fRec21[1] = fRec21[0];
			fRec23[1] = fRec23[0];
			fRec24[1] = fRec24[0];
			fVec6[1] = fVec6[0];
			fRec22[1] = fRec22[0];
			iRec26[1] = iRec26[0];
			fRec27[1] = fRec27[0];
			fRec28[1] = fRec28[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec29[1] = fRec29[0];
			fRec30[1] = fRec30[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			
		}
		
	}

	
};

//**************************************************************
// Polyphony
//**************************************************************

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2013 GRAME, Romain Michon, CCRMA - Stanford University
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __faust_poly_engine__
#define __faust_poly_engine__

#include <math.h>
#include <stdio.h>
#include <string.h>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __audio__
#define __audio__

class dsp;

typedef void (* shutdown_callback)(const char* message, void* arg);

typedef void (* compute_callback)(void* arg);

class audio {
    
    protected:
    
    public:
    
        audio() {}
        virtual ~audio() {}

        virtual bool init(const char* name, dsp* dsp) = 0;
        virtual bool start() = 0;
        virtual void stop() = 0;
        virtual void setShutdownCb(shutdown_callback cb, void* arg) {}
        virtual void setComputeCb(compute_callback cb, void* arg) {}

        virtual int getBufferSize() = 0;
        virtual int getSampleRate() = 0;

        virtual int getNumInputs() = 0;
        virtual int getNumOutputs() = 0;

        virtual float getCPULoad() { return 0.f; }
};
					
#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef FAUST_JSONUI_H
#define FAUST_JSONUI_H

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_PATHBUILDER_H
#define FAUST_PATHBUILDER_H

#include <vector>
#include <string>
#include <algorithm>

/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class PathBuilder
{

    protected:
    
        std::vector<std::string> fControlsLevel;
       
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            std::replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
};

#endif  // FAUST_PATHBUILDER_H

/*******************************************************************************
 * JSONUI : Faust User Interface
 * This class produce a complete JSON decription of the DSP instance.
 ******************************************************************************/

template <typename REAL>
class JSONUIAux : public PathBuilder, public Meta, public UI
{

    protected:
    
        std::stringstream fJSON;
        std::stringstream fUI;
        std::stringstream fMeta;
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        std::string fVersion;           // Compiler version
        std::string fCompileOptions;    // Compilation options
        std::vector<std::string> fLibraryList;
        std::vector<std::string> fIncludePathnames;
        std::string fName;
        std::string fFileName;
        std::string fExpandedCode;
        std::string fSHAKey;
        std::string fDSPSize;           // In bytes
        std::map<std::string, int> fPathTable;
    
        char fCloseUIPar;
        char fCloseMetaPar;
        int fTab;
    
        int fInputs, fOutputs;
         
        void tab(int n, std::ostream& fout)
        {
            fout << '\n';
            while (n-- > 0) {
                fout << '\t';
            }
        }
    
        void addMeta(int tab_val, bool quote = true)
        {
            if (fMetaAux.size() > 0) {
                tab(tab_val, fUI); fUI << "\"meta\": [";
                std::string sep = "";
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    fUI << sep;
                    tab(tab_val + 1, fUI); fUI << "{ \"" << fMetaAux[i].first << "\": \"" << fMetaAux[i].second << "\" }";
                    sep = ",";
                }
                tab(tab_val, fUI); fUI << ((quote) ? "],": "]");
                fMetaAux.clear();
            }
        }
    
        // Add escape (that is  '\') for internal strings
        std::string flatten(const std::string& src)
        {
            bool in_string = false;
            std::stringstream dst;
            for (size_t i = 0; i < src.size(); i++) {
                switch (src[i]) {
                    case '\n':
                    case '\t':
                        break;
                    case ' ':
                        if (in_string) dst << src[i];
                        break;
                    case '"':
                        dst << "\\" << '"';
                        in_string = !in_string;
                        break;
                    case '\\':
                        dst << '\\' << '\\';
                        break;
                    default:
                        dst << src[i];
                        break;
                }
            }
            return dst.str();
        }
    
        std::string getAddressIndex(const std::string& path)
        {
            if (fPathTable.find(path) != fPathTable.end()) {
                std::stringstream num; num << fPathTable[path];
                return num.str();
            } else {
                return "-1";
            }
        }
      
     public:
     
        JSONUIAux(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& compile_options,
                  const std::vector<std::string>& library_list,
                  const std::vector<std::string>& include_pathnames,
                  const std::string& size,
                  const std::map<std::string, int>& path_table)
        {
            init(name, filename, inputs, outputs, sha_key, dsp_code, version, compile_options, library_list, include_pathnames, size, path_table);
        }

        JSONUIAux(const std::string& name, const std::string& filename, int inputs, int outputs)
        {
            init(name, filename, inputs, outputs, "", "", "", "", std::vector<std::string>(), std::vector<std::string>(), "", std::map<std::string, int>());
        }

        JSONUIAux(int inputs, int outputs)
        {
            init("", "", inputs, outputs, "", "","", "", std::vector<std::string>(), std::vector<std::string>(), "", std::map<std::string, int>());
        }
        
        JSONUIAux()
        {
            init("", "", -1, -1, "", "", "", "", std::vector<std::string>(), std::vector<std::string>(), "", std::map<std::string, int>());
        }
 
        virtual ~JSONUIAux() {}
        
        void setInputs(int inputs) { fInputs = inputs; }
        void setOutputs(int outputs) { fOutputs = outputs; }
    
        // Init may be called multiple times so fMeta and fUI are reinitialized
        void init(const std::string& name,
                  const std::string& filename,
                  int inputs,
                  int outputs,
                  const std::string& sha_key,
                  const std::string& dsp_code,
                  const std::string& version,
                  const std::string& compile_options,
                  const std::vector<std::string>& library_list,
                  const std::vector<std::string>& include_pathnames,
                  const std::string& size,
                  const std::map<std::string, int>& path_table)
        {
            fTab = 1;
            
            // Start Meta generation
            fMeta.str("");
            tab(fTab, fMeta); fMeta << "\"meta\": [";
            fCloseMetaPar = ' ';
            
            // Start UI generation
            fUI.str("");
            tab(fTab, fUI); fUI << "\"ui\": [";
            fCloseUIPar = ' ';
            fTab += 1;
            
            fName = name;
            fFileName = filename;
            fInputs = inputs;
            fOutputs = outputs;
            fExpandedCode = dsp_code;
            fSHAKey = sha_key;
            fDSPSize = size;
            fPathTable = path_table;
            fVersion = version;
            fCompileOptions = compile_options;
            fLibraryList = library_list;
            fIncludePathnames = include_pathnames;
        }
   
        // -- widget's layouts
    
        virtual void openGenericGroup(const char* label, const char* name)
        {
            fControlsLevel.push_back(label);
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
            addMeta(fTab + 1);
            tab(fTab, fUI); fUI << "\"items\": [";
            fCloseUIPar = ' ';
            fTab += 1;
        }

        virtual void openTabBox(const char* label)
        {
            openGenericGroup(label, "tgroup");
        }
    
        virtual void openHorizontalBox(const char* label)
        {
            openGenericGroup(label, "hgroup");
        }
    
        virtual void openVerticalBox(const char* label)
        {
            openGenericGroup(label, "vgroup");
        }
    
        virtual void closeBox()
        {
            fControlsLevel.pop_back();
            fTab -= 1;
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        // -- active widgets
  
        virtual void addGenericButton(const char* label, const char* name)
        {
            std::string path = buildPath(label);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\",";
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << getAddressIndex(path) << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            } else {
                tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            }
            addMeta(fTab + 1, false);
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addButton(const char* label, REAL* zone)
        {
            addGenericButton(label, "button");
        }
    
        virtual void addCheckButton(const char* label, REAL* zone)
        {
            addGenericButton(label, "checkbox");
        }

        virtual void addGenericEntry(const char* label, const char* name, REAL init, REAL min, REAL max, REAL step)
        {
            std::string path = buildPath(label);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << getAddressIndex(path) << "\",";
            }
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"init\": \"" << init << "\",";
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\",";
            tab(fTab + 1, fUI); fUI << "\"step\": \"" << step << "\"";
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        virtual void addVerticalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "vslider", init, min, max, step);
        }
    
        virtual void addHorizontalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "hslider", init, min, max, step);
        }
    
        virtual void addNumEntry(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "nentry", init, min, max, step);
        }

        // -- passive widgets
    
        virtual void addGenericBargraph(const char* label, const char* name, REAL min, REAL max) 
        {
            std::string path = buildPath(label);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\",";
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << getAddressIndex(path) << "\",";
            }
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\"";
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addHorizontalBargraph(const char* label, REAL* zone, REAL min, REAL max) 
        {
            addGenericBargraph(label, "hbargraph", min, max);
        }
    
        virtual void addVerticalBargraph(const char* label, REAL* zone, REAL min, REAL max)
        {
            addGenericBargraph(label, "vbargraph", min, max);
        }
    
        virtual void addSoundfile(const char* label, const char* url, Soundfile** zone)
        {
            std::string path = buildPath(label);
            
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << "soundfile" << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"url\": \"" << url << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << path << "\"" << ((fPathTable.size() > 0) ? "," : "");
            if (fPathTable.size() > 0) {
                tab(fTab + 1, fUI); fUI << "\"index\": \"" << getAddressIndex(path) << "\"";
            }
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        // -- metadata declarations

        virtual void declare(REAL* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
    
        // Meta interface
        virtual void declare(const char* key, const char* value)
        {
            fMeta << fCloseMetaPar;
            // fName found in metadata
            if ((strcmp(key, "name") == 0) && (fName == "")) fName = value;
            // fFileName found in metadata
            if ((strcmp(key, "filename") == 0) && (fFileName == "")) fFileName = value;
            tab(fTab, fMeta); fMeta << "{ " << "\"" << key << "\"" << ": " << "\"" << value << "\" }";
            fCloseMetaPar = ',';
        }
    
        std::string JSON(bool flat = false)
        {
            fTab = 0;
            fJSON << "{";
            fTab += 1;
            tab(fTab, fJSON); fJSON << "\"name\": \"" << fName << "\",";
            tab(fTab, fJSON); fJSON << "\"filename\": \"" << fFileName << "\",";
            if (fVersion != "") { tab(fTab, fJSON); fJSON << "\"version\": \"" << fVersion << "\","; }
            if (fCompileOptions != "") { tab(fTab, fJSON); fJSON << "\"compile_options\": \"" <<  fCompileOptions << "\","; }
            if (fLibraryList.size() > 0) {
                tab(fTab, fJSON);
                fJSON << "\"library_list\": [";
                for (size_t i = 0; i < fLibraryList.size(); i++) {
                    fJSON << "\"" << fLibraryList[i] << "\"";
                    if (i < (fLibraryList.size() - 1)) fJSON << ",";
                }
                fJSON << "],";
            }
            if (fIncludePathnames.size() > 0) {
                tab(fTab, fJSON);
                fJSON << "\"include_pathnames\": [";
                for (size_t i = 0; i < fIncludePathnames.size(); i++) {
                    fJSON << "\"" << fIncludePathnames[i] << "\"";
                    if (i < (fIncludePathnames.size() - 1)) fJSON << ",";
                }
                fJSON << "],";
            }
            if (fDSPSize != "") { tab(fTab, fJSON); fJSON << "\"size\": \"" << fDSPSize << "\","; }
            if (fSHAKey != "") { tab(fTab, fJSON); fJSON << "\"sha_key\": \"" << fSHAKey << "\","; }
            if (fExpandedCode != "") { tab(fTab, fJSON); fJSON << "\"code\": \"" << fExpandedCode << "\","; }
            tab(fTab, fJSON); fJSON << "\"inputs\": \"" << fInputs << "\","; 
            tab(fTab, fJSON); fJSON << "\"outputs\": \"" << fOutputs << "\",";
            tab(fTab, fMeta); fMeta << "],";
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            if (fCloseMetaPar == ',') { // If "declare" has been called, fCloseMetaPar state is now ','
                fJSON << fMeta.str() << fUI.str();
            } else {
                fJSON << fUI.str();
            }
            tab(fTab, fJSON); fJSON << "}";
            return (flat) ? flatten(fJSON.str()) : fJSON.str();
        }
    
};

// Externally available class using FAUSTFLOAT

class JSONUI : public JSONUIAux<FAUSTFLOAT>
{
    public :
    
        JSONUI(const std::string& name,
               const std::string& filename,
               int inputs,
               int outputs,
               const std::string& sha_key,
               const std::string& dsp_code,
               const std::string& version,
               const std::string& compile_options,
               const std::vector<std::string>& library_list,
               const std::vector<std::string>& include_pathnames,
               const std::string& size,
               const std::map<std::string, int>& path_table):
        JSONUIAux<FAUSTFLOAT>(name, filename,
                              inputs, outputs,
                              sha_key, dsp_code,
                              version, compile_options,
                              library_list, include_pathnames,
                              size, path_table)
        {}
        
        JSONUI(const std::string& name, const std::string& filename, int inputs, int outputs):
        JSONUIAux<FAUSTFLOAT>(name, filename, inputs, outputs)
        {}
        
        JSONUI(int inputs, int outputs):JSONUIAux<FAUSTFLOAT>(inputs, outputs)
        {}
        
        JSONUI():JSONUIAux<FAUSTFLOAT>()
        {}
    
        virtual ~JSONUI() {}
    
};

#endif // FAUST_JSONUI_H
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef API_UI_H
#define API_UI_H

#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <map>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __ValueConverter__
#define __ValueConverter__

/***************************************************************************************
								ValueConverter.h
							    (GRAME, © 2015)

Set of conversion objects used to map user interface values (for example a gui slider
delivering values between 0 and 1) to faust values (for example a vslider between
20 and 20000) using a log scale.

-- Utilities

Range(lo,hi) : clip a value x between lo and hi
Interpolator(lo,hi,v1,v2) : Maps a value x between lo and hi to a value y between v1 and v2
Interpolator3pt(lo,mi,hi,v1,vm,v2) : Map values between lo mid hi to values between v1 vm v2

-- Value Converters

ValueConverter::ui2faust(x)
ValueConverter::faust2ui(x)

-- ValueConverters used for sliders depending of the scale

LinearValueConverter(umin, umax, fmin, fmax)
LogValueConverter(umin, umax, fmin, fmax)
ExpValueConverter(umin, umax, fmin, fmax)

-- ValueConverters used for accelerometers based on 3 points

AccUpConverter(amin, amid, amax, fmin, fmid, fmax)		-- curve 0
AccDownConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 1
AccUpDownConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 2
AccDownUpConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 3

-- lists of ZoneControl are used to implement accelerometers metadata for each axes

ZoneControl(zone, valueConverter) : a zone with an accelerometer data converter

-- ZoneReader are used to implement screencolor metadata

ZoneReader(zone, valueConverter) : a zone with a data converter

****************************************************************************************/

#include <float.h>
#include <algorithm>    // std::max
#include <cmath>
#include <vector>
#include <assert.h>

//--------------------------------------------------------------------------------------
// Interpolator(lo,hi,v1,v2)
// Maps a value x between lo and hi to a value y between v1 and v2
// y = v1 + (x-lo)/(hi-lo)*(v2-v1)
// y = v1 + (x-lo) * coef   		with coef = (v2-v1)/(hi-lo)
// y = v1 + x*coef - lo*coef
// y = v1 - lo*coef + x*coef
// y = offset + x*coef				with offset = v1 - lo*coef
//--------------------------------------------------------------------------------------
class Interpolator
{
    private:

        //--------------------------------------------------------------------------------------
        // Range(lo,hi) clip a value between lo and hi
        //--------------------------------------------------------------------------------------
        struct Range
        {
            double fLo;
            double fHi;

            Range(double x, double y) : fLo(std::min<double>(x,y)), fHi(std::max<double>(x,y)) {}
            double operator()(double x) { return (x<fLo) ? fLo : (x>fHi) ? fHi : x; }
        };


        Range fRange;
        double fCoef;
        double fOffset;

    public:

        Interpolator(double lo, double hi, double v1, double v2) : fRange(lo,hi)
        {
            if (hi != lo) {
                // regular case
                fCoef = (v2-v1)/(hi-lo);
                fOffset = v1 - lo*fCoef;
            } else {
                // degenerate case, avoids division by zero
                fCoef = 0;
                fOffset = (v1+v2)/2;
            }
        }
        double operator()(double v)
        {
            double x = fRange(v);
            return  fOffset + x*fCoef;
        }

        void getLowHigh(double& amin, double& amax)
        {
            amin = fRange.fLo;
            amax = fRange.fHi;
        }
};

//--------------------------------------------------------------------------------------
// Interpolator3pt(lo,mi,hi,v1,vm,v2)
// Map values between lo mid hi to values between v1 vm v2
//--------------------------------------------------------------------------------------
class Interpolator3pt
{

    private:

        Interpolator fSegment1;
        Interpolator fSegment2;
        double fMid;

    public:

        Interpolator3pt(double lo, double mi, double hi, double v1, double vm, double v2) :
            fSegment1(lo, mi, v1, vm),
            fSegment2(mi, hi, vm, v2),
            fMid(mi) {}
        double operator()(double x) { return  (x < fMid) ? fSegment1(x) : fSegment2(x); }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fSegment1.getLowHigh(amin, amid);
            fSegment2.getLowHigh(amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Abstract ValueConverter class. Converts values between UI and Faust representations
//--------------------------------------------------------------------------------------
class ValueConverter
{

    public:

        virtual ~ValueConverter() {}
        virtual double ui2faust(double x) = 0;
        virtual double faust2ui(double x) = 0;
};

//--------------------------------------------------------------------------------------
// Linear conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class LinearValueConverter : public ValueConverter
{

    private:

        Interpolator fUI2F;
        Interpolator fF2UI;

    public:

        LinearValueConverter(double umin, double umax, double fmin, double fmax) :
            fUI2F(umin,umax,fmin,fmax), fF2UI(fmin,fmax,umin,umax)
        {}

        LinearValueConverter() :
            fUI2F(0.,0.,0.,0.), fF2UI(0.,0.,0.,0.)
        {}
        virtual double ui2faust(double x) {	return fUI2F(x); }
        virtual double faust2ui(double x) {	return fF2UI(x); }

};

//--------------------------------------------------------------------------------------
// Logarithmic conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class LogValueConverter : public LinearValueConverter
{

    public:

        LogValueConverter(double umin, double umax, double fmin, double fmax) :
        LinearValueConverter(umin, umax, log(std::max<double>(DBL_MIN, fmin)), std::log(std::max<double>(DBL_MIN, fmax)))
        {}

        virtual double ui2faust(double x) 	{ return std::exp(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x)	{ return LinearValueConverter::faust2ui(std::log(std::max<double>(x, DBL_MIN))); }

};

//--------------------------------------------------------------------------------------
// Exponential conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class ExpValueConverter : public LinearValueConverter
{

    public:

        ExpValueConverter(double umin, double umax, double fmin, double fmax) :
            LinearValueConverter(umin, umax, exp(fmin), exp(fmax))
        {}

        virtual double ui2faust(double x) { return std::log(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x) { return LinearValueConverter::faust2ui(std::exp(x)); }

};

//--------------------------------------------------------------------------------------
// A converter than can be updated
//--------------------------------------------------------------------------------------

class UpdatableValueConverter : public ValueConverter {

    protected:

        bool fActive;

    public:

        UpdatableValueConverter():fActive(true)
        {}
        virtual ~UpdatableValueConverter()
        {}

        virtual void setMappingValues(double amin, double amid, double amax, double min, double init, double max) = 0;
        virtual void getMappingValues(double& amin, double& amid, double& amax) = 0;

        void setActive(bool on_off) { fActive = on_off; }
        bool getActive() { return fActive; }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up curve (curve 0)
//--------------------------------------------------------------------------------------
class AccUpConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt fA2F;
        Interpolator3pt fF2A;

    public:

        AccUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmid,fmax),
            fF2A(fmin,fmid,fmax,amin,amid,amax)
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmin,fmid,fmax);
            fF2A = Interpolator3pt(fmin,fmid,fmax,amin,amid,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down curve (curve 1)
//--------------------------------------------------------------------------------------
class AccDownConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator3pt	fF2A;

    public:

        AccDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmid,fmin),
            fF2A(fmin,fmid,fmax,amax,amid,amin)
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
             //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmax,fmid,fmin);
            fF2A = Interpolator3pt(fmin,fmid,fmax,amax,amid,amin);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up-Down curve (curve 2)
//--------------------------------------------------------------------------------------
class AccUpDownConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccUpDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmax,fmin),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotone function
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
             //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmin,fmax,fmin);
            fF2A = Interpolator(fmin,fmax,amin,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down-Up curve (curve 3)
//--------------------------------------------------------------------------------------
class AccDownUpConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccDownUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmin,fmax),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotone function
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmax,fmin,fmax);
            fF2A = Interpolator(fmin,fmax,amin,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Base class for ZoneControl
//--------------------------------------------------------------------------------------
class ZoneControl
{

    protected:

        FAUSTFLOAT*	fZone;

    public:

        ZoneControl(FAUSTFLOAT* zone) : fZone(zone) {}
        virtual ~ZoneControl() {}

        virtual void update(double v) {}

        virtual void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max) {}
        virtual void getMappingValues(double& amin, double& amid, double& amax) {}

        FAUSTFLOAT* getZone() { return fZone; }

        virtual void setActive(bool on_off) {}
        virtual bool getActive() { return false; }

        virtual int getCurve() { return -1; }

};

//--------------------------------------------------------------------------------------
//  Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class ConverterZoneControl : public ZoneControl
{

    private:

        ValueConverter* fValueConverter;

    public:

        ConverterZoneControl(FAUSTFLOAT* zone, ValueConverter* valueConverter) : ZoneControl(zone), fValueConverter(valueConverter) {}
        virtual ~ConverterZoneControl() { delete fValueConverter; } // Assuming fValueConverter is not kept elsewhere...

        void update(double v) { *fZone = fValueConverter->ui2faust(v); }

        ValueConverter* getConverter() { return fValueConverter; }

};

//--------------------------------------------------------------------------------------
// Association of a zone and a four value converter, each one for each possible curve.
// Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class CurveZoneControl : public ZoneControl
{

    private:

        std::vector<UpdatableValueConverter*> fValueConverters;
        int fCurve;

    public:

        CurveZoneControl(FAUSTFLOAT* zone, int curve, double amin, double amid, double amax, double min, double init, double max) : ZoneControl(zone), fCurve(0)
        {
            assert(curve >= 0 && curve <= 3);
            fValueConverters.push_back(new AccUpConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccUpDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownUpConverter(amin, amid, amax, min, init, max));
            fCurve = curve;
        }
        virtual ~CurveZoneControl()
        {
            std::vector<UpdatableValueConverter*>::iterator it;
            for (it = fValueConverters.begin(); it != fValueConverters.end(); it++) {
                delete(*it);
            }
        }
        void update(double v) { if (fValueConverters[fCurve]->getActive()) *fZone = fValueConverters[fCurve]->ui2faust(v); }

        void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max)
        {
            fValueConverters[curve]->setMappingValues(amin, amid, amax, min, init, max);
            fCurve = curve;
        }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fValueConverters[fCurve]->getMappingValues(amin, amid, amax);
        }

        void setActive(bool on_off)
        {
            std::vector<UpdatableValueConverter*>::iterator it;
            for (it = fValueConverters.begin(); it != fValueConverters.end(); it++) {
                (*it)->setActive(on_off);
            }
        }

        int getCurve() { return fCurve; }
};

class ZoneReader
{

    private:

        FAUSTFLOAT* fZone;
        Interpolator fInterpolator;

    public:

        ZoneReader(FAUSTFLOAT* zone, double lo, double hi) : fZone(zone), fInterpolator(lo, hi, 0, 255) {}

        virtual ~ZoneReader() {}

        int getValue()
        {
            if (fZone != 0) {
                return (int)fInterpolator(*fZone);
            } else {
                return 127;
            }
        }

};

#endif

class APIUI : public PathBuilder, public Meta, public UI
{
    public:
    
        enum ItemType { kButton = 0, kCheckButton, kVSlider, kHSlider, kNumEntry, kHBargraph, kVBargraph };
  
    protected:
    
        enum { kLin = 0, kLog = 1, kExp = 2 };
    
        int fNumParameters;
        std::vector<std::string> fPaths;
        std::vector<std::string> fLabels;
        std::map<std::string, int> fPathMap;
        std::map<std::string, int> fLabelMap;
        std::vector<ValueConverter*> fConversion;
        std::vector<FAUSTFLOAT*> fZone;
        std::vector<FAUSTFLOAT> fInit;
        std::vector<FAUSTFLOAT> fMin;
        std::vector<FAUSTFLOAT> fMax;
        std::vector<FAUSTFLOAT> fStep;
        std::vector<ItemType> fItemType;
        std::vector<std::map<std::string, std::string> > fMetaData;
        std::vector<ZoneControl*> fAcc[3];
        std::vector<ZoneControl*> fGyr[3];

        // Screen color control
        // "...[screencolor:red]..." etc.
        bool fHasScreenControl;      // true if control screen color metadata
        ZoneReader* fRedReader;
        ZoneReader* fGreenReader;
        ZoneReader* fBlueReader;

        // Current values controlled by metadata
        std::string fCurrentUnit;
        int fCurrentScale;
        std::string fCurrentAcc;
        std::string fCurrentGyr;
        std::string fCurrentColor;
        std::string fCurrentTooltip;
        std::map<std::string, std::string> fCurrentMetadata;
    
        // Add a generic parameter
        virtual void addParameter(const char* label,
                                FAUSTFLOAT* zone,
                                FAUSTFLOAT init,
                                FAUSTFLOAT min,
                                FAUSTFLOAT max,
                                FAUSTFLOAT step,
                                ItemType type)
        {
            std::string path = buildPath(label);
            fPathMap[path] = fLabelMap[label] = fNumParameters++;
            fPaths.push_back(path);
            fLabels.push_back(label);
            fZone.push_back(zone);
            fInit.push_back(init);
            fMin.push_back(min);
            fMax.push_back(max);
            fStep.push_back(step);
            fItemType.push_back(type);
            
            // handle scale metadata
            switch (fCurrentScale) {
                case kLin:
                    fConversion.push_back(new LinearValueConverter(0, 1, min, max));
                    break;
                case kLog:
                    fConversion.push_back(new LogValueConverter(0, 1, min, max));
                    break;
                case kExp: fConversion.push_back(new ExpValueConverter(0, 1, min, max));
                    break;
            }
            fCurrentScale = kLin;
            
            if (fCurrentAcc.size() > 0 && fCurrentGyr.size() > 0) {
                std::cerr << "warning : 'acc' and 'gyr' metadata used for the same " << label << " parameter !!\n";
            }

            // handle acc metadata "...[acc : <axe> <curve> <amin> <amid> <amax>]..."
            if (fCurrentAcc.size() > 0) {
                std::istringstream iss(fCurrentAcc);
                int axe, curve;
                double amin, amid, amax;
                iss >> axe >> curve >> amin >> amid >> amax;

                if ((0 <= axe) && (axe < 3) &&
                    (0 <= curve) && (curve < 4) &&
                    (amin < amax) && (amin <= amid) && (amid <= amax))
                {
                    fAcc[axe].push_back(new CurveZoneControl(zone, curve, amin, amid, amax, min, init, max));
                } else {
                    std::cerr << "incorrect acc metadata : " << fCurrentAcc << std::endl;
                }
                fCurrentAcc = "";
            }
       
            // handle gyr metadata "...[gyr : <axe> <curve> <amin> <amid> <amax>]..."
            if (fCurrentGyr.size() > 0) {
                std::istringstream iss(fCurrentGyr);
                int axe, curve;
                double amin, amid, amax;
                iss >> axe >> curve >> amin >> amid >> amax;

                if ((0 <= axe) && (axe < 3) &&
                    (0 <= curve) && (curve < 4) &&
                    (amin < amax) && (amin <= amid) && (amid <= amax))
                {
                    fGyr[axe].push_back(new CurveZoneControl(zone, curve, amin, amid, amax, min, init, max));
                } else {
                    std::cerr << "incorrect gyr metadata : " << fCurrentGyr << std::endl;
                }
                fCurrentGyr = "";
            }
        
            // handle screencolor metadata "...[screencolor:red|green|blue|white]..."
            if (fCurrentColor.size() > 0) {
                if ((fCurrentColor == "red") && (fRedReader == 0)) {
                    fRedReader = new ZoneReader(zone, min, max);
                    fHasScreenControl = true;
                } else if ((fCurrentColor == "green") && (fGreenReader == 0)) {
                    fGreenReader = new ZoneReader(zone, min, max);
                    fHasScreenControl = true;
                } else if ((fCurrentColor == "blue") && (fBlueReader == 0)) {
                    fBlueReader = new ZoneReader(zone, min, max);
                    fHasScreenControl = true;
                } else if ((fCurrentColor == "white") && (fRedReader == 0) && (fGreenReader == 0) && (fBlueReader == 0)) {
                    fRedReader = new ZoneReader(zone, min, max);
                    fGreenReader = new ZoneReader(zone, min, max);
                    fBlueReader = new ZoneReader(zone, min, max);
                    fHasScreenControl = true;
                } else {
                    std::cerr << "incorrect screencolor metadata : " << fCurrentColor << std::endl;
                }
            }
            fCurrentColor = "";
            
            fMetaData.push_back(fCurrentMetadata);
            fCurrentMetadata.clear();
        }

        int getZoneIndex(std::vector<ZoneControl*>* table, int p, int val)
        {
            FAUSTFLOAT* zone = fZone[p];
            for (size_t i = 0; i < table[val].size(); i++) {
                if (zone == table[val][i]->getZone()) return i;
            }
            return -1;
        }
    
        void setConverter(std::vector<ZoneControl*>* table, int p, int val, int curve, double amin, double amid, double amax)
        {
            int id1 = getZoneIndex(table, p, 0);
            int id2 = getZoneIndex(table, p, 1);
            int id3 = getZoneIndex(table, p, 2);
            
            // Deactivates everywhere..
            if (id1 != -1) table[0][id1]->setActive(false);
            if (id2 != -1) table[1][id2]->setActive(false);
            if (id3 != -1) table[2][id3]->setActive(false);
            
            if (val == -1) { // Means: no more mapping...
                // So stay all deactivated...
            } else {
                int id4 = getZoneIndex(table, p, val);
                if (id4 != -1) {
                    // Reactivate the one we edit...
                    table[val][id4]->setMappingValues(curve, amin, amid, amax, fMin[p], fInit[p], fMax[p]);
                    table[val][id4]->setActive(true);
                } else {
                    // Allocate a new CurveZoneControl which is 'active' by default
                    FAUSTFLOAT* zone = fZone[p];
                    table[val].push_back(new CurveZoneControl(zone, curve, amin, amid, amax, fMin[p], fInit[p], fMax[p]));
                }
            }
        }
    
        void getConverter(std::vector<ZoneControl*>* table, int p, int& val, int& curve, double& amin, double& amid, double& amax)
        {
            int id1 = getZoneIndex(table, p, 0);
            int id2 = getZoneIndex(table, p, 1);
            int id3 = getZoneIndex(table, p, 2);
            
            if (id1 != -1) {
                val = 0;
                curve = table[val][id1]->getCurve();
                table[val][id1]->getMappingValues(amin, amid, amax);
            } else if (id2 != -1) {
                val = 1;
                curve = table[val][id2]->getCurve();
                table[val][id2]->getMappingValues(amin, amid, amax);
            } else if (id3 != -1) {
                val = 2;
                curve = table[val][id3]->getCurve();
                table[val][id3]->getMappingValues(amin, amid, amax);
            } else {
                val = -1; // No mapping
                curve = 0;
                amin = -100.;
                amid = 0.;
                amax = 100.;
            }
        }

     public:
    
        enum Type { kAcc = 0, kGyr = 1, kNoType };
   
        APIUI() : fNumParameters(0), fHasScreenControl(false), fRedReader(0), fGreenReader(0), fBlueReader(0), fCurrentScale(kLin)
        {}

        virtual ~APIUI()
        {
            std::vector<ValueConverter*>::iterator it1;
            for (it1 = fConversion.begin(); it1 != fConversion.end(); it1++) {
                delete(*it1);
            }

            std::vector<ZoneControl*>::iterator it2;
            for (int i = 0; i < 3; i++) {
                for (it2 = fAcc[i].begin(); it2 != fAcc[i].end(); it2++) {
                    delete(*it2);
                }
                for (it2 = fGyr[i].begin(); it2 != fGyr[i].end(); it2++) {
                    delete(*it2);
                }
            }
            
            delete fRedReader;
            delete fGreenReader;
            delete fBlueReader;
        }
    
        // -- widget's layouts

        virtual void openTabBox(const char* label)          { fControlsLevel.push_back(label); }
        virtual void openHorizontalBox(const char* label)   { fControlsLevel.push_back(label); }
        virtual void openVerticalBox(const char* label)     { fControlsLevel.push_back(label); }
        virtual void closeBox()                             { fControlsLevel.pop_back(); }

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addParameter(label, zone, 0, 0, 1, 1, kButton);
        }

        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addParameter(label, zone, 0, 0, 1, 1, kCheckButton);
        }

        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addParameter(label, zone, init, min, max, step, kVSlider);
        }

        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addParameter(label, zone, init, min, max, step, kHSlider);
        }

        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addParameter(label, zone, init, min, max, step, kNumEntry);
        }

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addParameter(label, zone, min, min, max, (max-min)/1000.0, kHBargraph);
        }

        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addParameter(label, zone, min, min, max, (max-min)/1000.0, kVBargraph);
        }
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            // Keep matadata
            fCurrentMetadata[key] = val;
            
            if (strcmp(key, "scale") == 0) {
                if (strcmp(val, "log") == 0) {
                    fCurrentScale = kLog;
                } else if (strcmp(val, "exp") == 0) {
                    fCurrentScale = kExp;
                } else {
                    fCurrentScale = kLin;
                }
            } else if (strcmp(key, "unit") == 0) {
                fCurrentUnit = val;
            } else if (strcmp(key, "acc") == 0) {
                fCurrentAcc = val;
            } else if (strcmp(key, "gyr") == 0) {
                fCurrentGyr = val;
            } else if (strcmp(key, "screencolor") == 0) {
                fCurrentColor = val; // val = "red", "green", "blue" or "white"
            } else if (strcmp(key, "tooltip") == 0) {
                fCurrentTooltip = val;
            }
        }

        virtual void declare(const char* key, const char* val)
        {}

		//-------------------------------------------------------------------------------
		// Simple API part
		//-------------------------------------------------------------------------------
		int getParamsCount() { return fNumParameters; }
        int getParamIndex(const char* path)
        {
            if (fPathMap.find(path) != fPathMap.end()) {
                return fPathMap[path];
            } else if (fLabelMap.find(path) != fLabelMap.end()) {
                return fLabelMap[path];
            } else {
                return -1;
            }
        }
        const char* getParamAddress(int p) { return fPaths[p].c_str(); }
        const char* getParamLabel(int p) { return fLabels[p].c_str(); }
        std::map<const char*, const char*> getMetadata(int p)
        {
            std::map<const char*, const char*> res;
            std::map<std::string, std::string> metadata = fMetaData[p];
            std::map<std::string, std::string>::iterator it;
            for (it = metadata.begin(); it != metadata.end(); ++it) {
                res[(*it).first.c_str()] = (*it).second.c_str();
            }
            return res;
        }

        const char* getMetadata(int p, const char* key)
        {
            return (fMetaData[p].find(key) != fMetaData[p].end()) ? fMetaData[p][key].c_str() : "";
        }
        FAUSTFLOAT getParamMin(int p) { return fMin[p]; }
        FAUSTFLOAT getParamMax(int p) { return fMax[p]; }
        FAUSTFLOAT getParamStep(int p) { return fStep[p]; }
        FAUSTFLOAT getParamInit(int p) { return fInit[p]; }

        FAUSTFLOAT* getParamZone(int p) { return fZone[p]; }
        FAUSTFLOAT getParamValue(int p) { return *fZone[p]; }
        void setParamValue(int p, FAUSTFLOAT v) { *fZone[p] = v; }

        double getParamRatio(int p) { return fConversion[p]->faust2ui(*fZone[p]); }
        void setParamRatio(int p, double r) { *fZone[p] = fConversion[p]->ui2faust(r); }

        double value2ratio(int p, double r)	{ return fConversion[p]->faust2ui(r); }
        double ratio2value(int p, double r)	{ return fConversion[p]->ui2faust(r); }
    
        /**
         * Return the control type (kAcc, kGyr, or -1) for a given parameter
         *
         * @param p - the UI parameter index
         *
         * @return the type
         */
        Type getParamType(int p)
        {
            if (p >= 0) {
                if (getZoneIndex(fAcc, p, 0) != -1
                    || getZoneIndex(fAcc, p, 1) != -1
                    || getZoneIndex(fAcc, p, 2) != -1) {
                    return kAcc;
                } else if (getZoneIndex(fGyr, p, 0) != -1
                           || getZoneIndex(fGyr, p, 1) != -1
                           || getZoneIndex(fGyr, p, 2) != -1) {
                    return kGyr;
                }
            }
            return kNoType;
        }
    
        /**
         * Return the Item type (kButton = 0, kCheckButton, kVSlider, kHSlider, kNumEntry, kHBargraph, kVBargraph) for a given parameter
         *
         * @param p - the UI parameter index
         *
         * @return the Item type
         */
        ItemType getParamItemType(int p)
        {
            return fItemType[p];
        }
   
        /**
         * Set a new value coming from an accelerometer, propagate it to all relevant float* zones.
         *
         * @param acc - 0 for X accelerometer, 1 for Y accelerometer, 2 for Z accelerometer
         * @param value - the new value
         *
         */
        void propagateAcc(int acc, double value)
        {
            for (size_t i = 0; i < fAcc[acc].size(); i++) {
                fAcc[acc][i]->update(value);
            }
        }
    
        /**
         * Used to edit accelerometer curves and mapping. Set curve and related mapping for a given UI parameter.
         *
         * @param p - the UI parameter index
         * @param acc - 0 for X accelerometer, 1 for Y accelerometer, 2 for Z accelerometer (-1 means "no mapping")
         * @param curve - between 0 and 3
         * @param amin - mapping 'min' point
         * @param amid - mapping 'middle' point
         * @param amax - mapping 'max' point
         *
         */
        void setAccConverter(int p, int acc, int curve, double amin, double amid, double amax)
        {
            setConverter(fAcc, p, acc, curve, amin, amid, amax);
        }
    
        /**
         * Used to edit gyroscope curves and mapping. Set curve and related mapping for a given UI parameter.
         *
         * @param p - the UI parameter index
         * @param acc - 0 for X gyroscope, 1 for Y gyroscope, 2 for Z gyroscope (-1 means "no mapping")
         * @param curve - between 0 and 3
         * @param amin - mapping 'min' point
         * @param amid - mapping 'middle' point
         * @param amax - mapping 'max' point
         *
         */
        void setGyrConverter(int p, int gyr, int curve, double amin, double amid, double amax)
        {
             setConverter(fGyr, p, gyr, curve, amin, amid, amax);
        }
    
        /**
         * Used to edit accelerometer curves and mapping. Get curve and related mapping for a given UI parameter.
         *
         * @param p - the UI parameter index
         * @param acc - the acc value to be retrieved (-1 means "no mapping")
         * @param curve - the curve value to be retrieved
         * @param amin - the amin value to be retrieved
         * @param amid - the amid value to be retrieved
         * @param amax - the amax value to be retrieved
         *
         */
        void getAccConverter(int p, int& acc, int& curve, double& amin, double& amid, double& amax)
        {
            getConverter(fAcc, p, acc, curve, amin, amid, amax);
        }

        /**
         * Used to edit gyroscope curves and mapping. Get curve and related mapping for a given UI parameter.
         *
         * @param p - the UI parameter index
         * @param gyr - the gyr value to be retrieved (-1 means "no mapping")
         * @param curve - the curve value to be retrieved
         * @param amin - the amin value to be retrieved
         * @param amid - the amid value to be retrieved
         * @param amax - the amax value to be retrieved
         *
         */
        void getGyrConverter(int p, int& gyr, int& curve, double& amin, double& amid, double& amax)
        {
            getConverter(fGyr, p, gyr, curve, amin, amid, amax);
        }
    
        /**
         * Set a new value coming from an gyroscope, propagate it to all relevant float* zones.
         *
         * @param gyr - 0 for X gyroscope, 1 for Y gyroscope, 2 for Z gyroscope
         * @param value - the new value
         *
         */
        void propagateGyr(int gyr, double value)
        {
            for (size_t i = 0; i < fGyr[gyr].size(); i++) {
                fGyr[gyr][i]->update(value);
            }
        }
   
        // getScreenColor() : -1 means no screen color control (no screencolor metadata found)
        // otherwise return 0x00RRGGBB a ready to use color
        int getScreenColor()
        {
            if (fHasScreenControl) {
                int r = (fRedReader) ? fRedReader->getValue() : 0;
                int g = (fGreenReader) ? fGreenReader->getValue() : 0;
                int b = (fBlueReader) ? fBlueReader->getValue() : 0;
                return (r<<16) | (g<<8) | b;
            } else {
                return -1;
            }
        }

};

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_MIDIUI_H
#define FAUST_MIDIUI_H

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <cstdlib>
#include <cmath>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __GUI_H__
#define __GUI_H__

#include <list>
#include <map>
#include <vector>
#include <iostream>

#ifdef _WIN32
# pragma warning (disable: 4100)
#else
# pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

/*
  Copyright (C) 2000 Paul Davis
  Copyright (C) 2003 Rohan Drape
  Copyright (C) 2016 GRAME (renaming for internal use)

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

  ISO/POSIX C version of Paul Davis's lock free ringbuffer C++ code.
  This is safe for the case of one read thread and one write thread.
*/

#ifndef __ring_buffer__
#define __ring_buffer__

#include <stdlib.h>
#include <string.h>

#ifdef WIN32
#pragma warning (disable: 4334)
#endif

typedef struct {
    char *buf;
    size_t len;
}
ringbuffer_data_t;

typedef struct {
    char *buf;
    volatile size_t write_ptr;
    volatile size_t read_ptr;
    size_t	size;
    size_t	size_mask;
    int	mlocked;
}
ringbuffer_t;

static ringbuffer_t *ringbuffer_create(size_t sz);
static void ringbuffer_free(ringbuffer_t *rb);
static void ringbuffer_get_read_vector(const ringbuffer_t *rb,
                                         ringbuffer_data_t *vec);
static void ringbuffer_get_write_vector(const ringbuffer_t *rb,
                                          ringbuffer_data_t *vec);
static size_t ringbuffer_read(ringbuffer_t *rb, char *dest, size_t cnt);
static size_t ringbuffer_peek(ringbuffer_t *rb, char *dest, size_t cnt);
static void ringbuffer_read_advance(ringbuffer_t *rb, size_t cnt);
static size_t ringbuffer_read_space(const ringbuffer_t *rb);
static int ringbuffer_mlock(ringbuffer_t *rb);
static void ringbuffer_reset(ringbuffer_t *rb);
static void ringbuffer_reset_size (ringbuffer_t * rb, size_t sz);
static size_t ringbuffer_write(ringbuffer_t *rb, const char *src,
                                 size_t cnt);
static void ringbuffer_write_advance(ringbuffer_t *rb, size_t cnt);
static size_t ringbuffer_write_space(const ringbuffer_t *rb);

/* Create a new ringbuffer to hold at least `sz' bytes of data. The
   actual buffer size is rounded up to the next power of two. */

static ringbuffer_t *
ringbuffer_create (size_t sz)
{
	size_t power_of_two;
	ringbuffer_t *rb;

	if ((rb = (ringbuffer_t *) malloc (sizeof (ringbuffer_t))) == NULL) {
		return NULL;
	}

	for (power_of_two = 1u; 1u << power_of_two < sz; power_of_two++);

	rb->size = 1u << power_of_two;
	rb->size_mask = rb->size;
	rb->size_mask -= 1;
	rb->write_ptr = 0;
	rb->read_ptr = 0;
	if ((rb->buf = (char *) malloc (rb->size)) == NULL) {
		free (rb);
		return NULL;
	}
	rb->mlocked = 0;

	return rb;
}

/* Free all data associated with the ringbuffer `rb'. */

static void
ringbuffer_free (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (rb->mlocked) {
		munlock (rb->buf, rb->size);
	}
#endif /* USE_MLOCK */
	free (rb->buf);
	free (rb);
}

/* Lock the data block of `rb' using the system call 'mlock'.  */

static int
ringbuffer_mlock (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (mlock (rb->buf, rb->size)) {
		return -1;
	}
#endif /* USE_MLOCK */
	rb->mlocked = 1;
	return 0;
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

static void
ringbuffer_reset (ringbuffer_t * rb)
{
	rb->read_ptr = 0;
	rb->write_ptr = 0;
    memset(rb->buf, 0, rb->size);
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

static void
ringbuffer_reset_size (ringbuffer_t * rb, size_t sz)
{
    rb->size = sz;
    rb->size_mask = rb->size;
    rb->size_mask -= 1;
    rb->read_ptr = 0;
    rb->write_ptr = 0;
}

/* Return the number of bytes available for reading. This is the
   number of bytes in front of the read pointer and behind the write
   pointer.  */

static size_t
ringbuffer_read_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return w - r;
	} else {
		return (w - r + rb->size) & rb->size_mask;
	}
}

/* Return the number of bytes available for writing. This is the
   number of bytes in front of the write pointer and behind the read
   pointer.  */

static size_t
ringbuffer_write_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		return (r - w) - 1;
	} else {
		return rb->size - 1;
	}
}

/* The copying data reader. Copy at most `cnt' bytes from `rb' to
   `dest'.  Returns the actual number of bytes copied. */

static size_t
ringbuffer_read (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[rb->read_ptr]), n1);
	rb->read_ptr = (rb->read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[rb->read_ptr]), n2);
		rb->read_ptr = (rb->read_ptr + n2) & rb->size_mask;
	}

	return to_read;
}

/* The copying data reader w/o read pointer advance. Copy at most
   `cnt' bytes from `rb' to `dest'.  Returns the actual number of bytes
   copied. */

static size_t
ringbuffer_peek (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;
	size_t tmp_read_ptr;

	tmp_read_ptr = rb->read_ptr;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = tmp_read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - tmp_read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[tmp_read_ptr]), n1);
	tmp_read_ptr = (tmp_read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[tmp_read_ptr]), n2);
	}

	return to_read;
}

/* The copying data writer. Copy at most `cnt' bytes to `rb' from
   `src'.  Returns the actual number of bytes copied. */

static size_t
ringbuffer_write (ringbuffer_t * rb, const char *src, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_write;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_write_space (rb)) == 0) {
		return 0;
	}

	to_write = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->write_ptr + to_write;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->write_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_write;
		n2 = 0;
	}

	memcpy (&(rb->buf[rb->write_ptr]), src, n1);
	rb->write_ptr = (rb->write_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (&(rb->buf[rb->write_ptr]), src + n1, n2);
		rb->write_ptr = (rb->write_ptr + n2) & rb->size_mask;
	}

	return to_write;
}

/* Advance the read pointer `cnt' places. */

static void
ringbuffer_read_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->read_ptr + cnt) & rb->size_mask;
	rb->read_ptr = tmp;
}

/* Advance the write pointer `cnt' places. */

static void
ringbuffer_write_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->write_ptr + cnt) & rb->size_mask;
	rb->write_ptr = tmp;
}

/* The non-copying data reader. `vec' is an array of two places. Set
   the values at `vec' to hold the current readable data at `rb'. If
   the readable data is in one segment the second segment has zero
   length. */

static void
ringbuffer_get_read_vector (const ringbuffer_t * rb,
				 ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = w - r;
	} else {
		free_cnt = (w - r + rb->size) & rb->size_mask;
	}

	cnt2 = r + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = rb->size - r;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;

	} else {

		/* Single part vector: just the rest of the buffer */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

/* The non-copying data writer. `vec' is an array of two places. Set
   the values at `vec' to hold the current writeable data at `rb'. If
   the writeable data is in one segment the second segment has zero
   length. */

static void
ringbuffer_get_write_vector (const ringbuffer_t * rb,
				  ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		free_cnt = (r - w) - 1;
	} else {
		free_cnt = rb->size - 1;
	}

	cnt2 = w + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[w]);
		vec[0].len = rb->size - w;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;
	} else {
		vec[0].buf = &(rb->buf[w]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

#endif // __ring_buffer__

/*******************************************************************************
 * GUI : Abstract Graphic User Interface
 * Provides additional mechanisms to synchronize widgets and zones. Widgets
 * should both reflect the value of a zone and allow to change this value.
 ******************************************************************************/

class uiItem;
class GUI;
struct clist;

typedef void (*uiCallback)(FAUSTFLOAT val, void* data);

struct uiItemBase
{
    
    uiItemBase(GUI* ui, FAUSTFLOAT* zone) {}
    
    virtual ~uiItemBase()
    {}
    
    virtual void modifyZone(FAUSTFLOAT v) = 0;
    virtual double cache() = 0;
    virtual void reflectZone() = 0;
};


static void deleteClist(clist* cl);

struct clist : public std::list<uiItemBase*>
{
    
    virtual ~clist()
    {
        deleteClist(this);
    }
        
};

static void createUiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data);

typedef std::map<FAUSTFLOAT*, clist*> zmap;

typedef std::map<FAUSTFLOAT*, ringbuffer_t*> ztimedmap;

class GUI : public UI
{
		
    private:
     
        static std::list<GUI*> fGuiList;
        zmap fZoneMap;
        bool fStopped;
        
     public:
            
        GUI():fStopped(false)
        {	
            fGuiList.push_back(this);
        }
        
        virtual ~GUI() 
        {   
            // delete all items
            zmap::iterator it;
            for (it = fZoneMap.begin(); it != fZoneMap.end(); it++) {
                delete (*it).second;
            }
            // suppress 'this' in static fGuiList
            fGuiList.remove(this);
        }

        // -- registerZone(z,c) : zone management
        
        void registerZone(FAUSTFLOAT* z, uiItemBase* c)
        {
            if (fZoneMap.find(z) == fZoneMap.end()) fZoneMap[z] = new clist();
            fZoneMap[z]->push_back(c);
        }
 
        void updateAllZones()
        {
            for (zmap::iterator m = fZoneMap.begin(); m != fZoneMap.end(); m++) {
                FAUSTFLOAT* z = m->first;
                clist*	l = m->second;
                if (z) {
                    FAUSTFLOAT v = *z;
                    for (clist::iterator c = l->begin(); c != l->end(); c++) {
                        if ((*c)->cache() != v) (*c)->reflectZone();
                    }
                }
            }
        }
        
        void updateZone(FAUSTFLOAT* z)
        {
            FAUSTFLOAT v = *z;
            clist* l = fZoneMap[z];
            for (clist::iterator c = l->begin(); c != l->end(); c++) {
                if ((*c)->cache() != v) (*c)->reflectZone();
            }
        }
    
        static void updateAllGuis()
        {
            std::list<GUI*>::iterator g;
            for (g = fGuiList.begin(); g != fGuiList.end(); g++) {
                (*g)->updateAllZones();
            }
        }
    
        void addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data)
        {
            createUiCallbackItem(this, zone, foo, data);
        }

        virtual void show() {};	
        virtual bool run() { return false; };

        static void runAllGuis() {
            std::list<GUI*>::iterator g;
            for (g = fGuiList.begin(); g != fGuiList.end(); g++) {
                (*g)->run();
            }
        }
    
        virtual void stop() { fStopped = true; }
        bool stopped() { return fStopped; }
    
        // -- widget's layouts
        
        virtual void openTabBox(const char* label) {};
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
    
        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
    
        // Static global for timed zones, shared between all UI that will set timed values
        static ztimedmap gTimedZoneMap;

};

/**
 * User Interface Item: abstract definition
 */

template <typename REAL>
class uiTypedItem : public uiItemBase
{
    protected:
        
        GUI* fGUI;
        REAL* fZone;
        REAL fCache;
        
        uiTypedItem(GUI* ui, REAL* zone):uiItemBase(ui, static_cast<FAUSTFLOAT*>(zone)),
        fGUI(ui), fZone(zone), fCache(REAL(-123456.654321))
        {
            ui->registerZone(zone, this);
        }
        
    public:
        
        virtual ~uiTypedItem()
        {}
        
        void modifyZone(REAL v)
        {
            fCache = v;
            if (*fZone != v) {
                *fZone = v;
                fGUI->updateZone(fZone);
            }
        }
        
        double cache() { return fCache; }
    
};

class uiItem : public uiTypedItem<FAUSTFLOAT> {
    
    protected:
    
        uiItem(GUI* ui, FAUSTFLOAT* zone):uiTypedItem<FAUSTFLOAT>(ui, zone)
        {}

    public:

        virtual ~uiItem() 
        {}

        void modifyZone(FAUSTFLOAT v) 	
        { 
            fCache = v;
            if (*fZone != v) {
                *fZone = v;
                fGUI->updateZone(fZone);
            }
        }

};

/**
 * User Interface item owned (and so deleted) by external code
 */

class uiOwnedItem : public uiItem {
    
    protected:
    
        uiOwnedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
    
     public:
    
        virtual ~uiOwnedItem()
        {}
    
        virtual void reflectZone() {}
};

/**
 * Callback Item
 */

class uiCallbackItem : public uiItem {
    
    protected:
    
        uiCallback fCallback;
        void* fData;
    
    public:
    
        uiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data)
        : uiItem(ui, zone), fCallback(foo), fData(data) {}
        
        virtual void reflectZone() 
        {		
            FAUSTFLOAT v = *fZone;
            fCache = v; 
            fCallback(v, fData);	
        }
};

/**
 *  For timestamped control
 */

struct DatedControl {
    
    double fDate;
    FAUSTFLOAT fValue;
    
    DatedControl(double d = 0., FAUSTFLOAT v = FAUSTFLOAT(0)):fDate(d), fValue(v) {}
    
};

/**
 * Base class for timed items
 */

class uiTimedItem : public uiItem
{
    
    protected:
        
        bool fDelete;
        
    public:
        
        uiTimedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {
            if (GUI::gTimedZoneMap.find(fZone) == GUI::gTimedZoneMap.end()) {
                GUI::gTimedZoneMap[fZone] = ringbuffer_create(8192);
                fDelete = true;
            } else {
                fDelete = false;
            }
        }
        
        virtual ~uiTimedItem()
        {
            ztimedmap::iterator it;
            if (fDelete && ((it = GUI::gTimedZoneMap.find(fZone)) != GUI::gTimedZoneMap.end())) {
                ringbuffer_free((*it).second);
                GUI::gTimedZoneMap.erase(it);
            }
        }
        
        virtual void modifyZone(double date, FAUSTFLOAT v)
        {
            size_t res;
            DatedControl dated_val(date, v);
            if ((res = ringbuffer_write(GUI::gTimedZoneMap[fZone], (const char*)&dated_val, sizeof(DatedControl))) != sizeof(DatedControl)) {
                std::cerr << "ringbuffer_write error DatedControl" << std::endl;
            }
        }
    
};

/**
 * Allows to group a set of zones
 */

class uiGroupItem : public uiItem
{
    protected:
    
        std::vector<FAUSTFLOAT*> fZoneMap;

    public:
    
        uiGroupItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
        virtual ~uiGroupItem() 
        {}
        
        virtual void reflectZone() 
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            
            // Update all zones of the same group
            std::vector<FAUSTFLOAT*>::iterator it;
            for (it = fZoneMap.begin(); it != fZoneMap.end(); it++) {
                (*(*it)) = v;
            }
        }
        
        void addZone(FAUSTFLOAT* zone) { fZoneMap.push_back(zone); }

};

// Can not be defined as method in the classes

static void createUiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data)
{
    new uiCallbackItem(ui, zone, foo, data);
}

static void deleteClist(clist* cl)
{
    std::list<uiItemBase*>::iterator it;
    for (it = cl->begin(); it != cl->end(); it++) {
        uiOwnedItem* owned = dynamic_cast<uiOwnedItem*>(*it);
        // owned items are deleted by external code
        if (!owned) {
            delete (*it);
        }
    }
}

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __midi__
#define __midi__

#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>

class MapUI;

/*******************************************************************************
 * MIDI processor definition.
 *
 * MIDI input or output handling classes will implement this interface,
 * so the same method names (keyOn, ctrlChange...) will be used either
 * when decoding MIDI input or encoding MIDI output events.
 *******************************************************************************/

class midi {

    public:

        midi() {}
        virtual ~midi() {}

        // Additional time-stamped API for MIDI input
        virtual MapUI* keyOn(double, int channel, int pitch, int velocity)
        {
            return keyOn(channel, pitch, velocity);
        }
        
        virtual void keyOff(double, int channel, int pitch, int velocity = 127)
        {
            keyOff(channel, pitch, velocity);
        }
    
        virtual void keyPress(double, int channel, int pitch, int press)
        {
            keyPress(channel, pitch, press);
        }
        
        virtual void chanPress(double date, int channel, int press)
        {
            chanPress(channel, press);
        }
    
        virtual void pitchWheel(double, int channel, int wheel)
        {
            pitchWheel(channel, wheel);
        }
           
        virtual void ctrlChange(double, int channel, int ctrl, int value)
        {
            ctrlChange(channel, ctrl, value);
        }
    
        virtual void ctrlChange14bits(double, int channel, int ctrl, int value)
        {
            ctrlChange14bits(channel, ctrl, value);
        }

        virtual void progChange(double, int channel, int pgm)
        {
            progChange(channel, pgm);
        }
    
        virtual void sysEx(double, std::vector<unsigned char>& message)
        {
            sysEx(message);
        }

        // MIDI sync
        virtual void startSync(double date)  {}
        virtual void stopSync(double date)   {}
        virtual void clock(double date)  {}

        // Standard MIDI API
        virtual MapUI* keyOn(int channel, int pitch, int velocity)      { return 0; }
        virtual void keyOff(int channel, int pitch, int velocity)       {}
        virtual void keyPress(int channel, int pitch, int press)        {}
        virtual void chanPress(int channel, int press)                  {}
        virtual void ctrlChange(int channel, int ctrl, int value)       {}
        virtual void ctrlChange14bits(int channel, int ctrl, int value) {}
        virtual void pitchWheel(int channel, int wheel)                 {}
        virtual void progChange(int channel, int pgm)                   {}
        virtual void sysEx(std::vector<unsigned char>& message)         {}

        enum MidiStatus {

            // channel voice messages
            MIDI_NOTE_OFF = 0x80,
            MIDI_NOTE_ON = 0x90,
            MIDI_CONTROL_CHANGE = 0xB0,
            MIDI_PROGRAM_CHANGE = 0xC0,
            MIDI_PITCH_BEND = 0xE0,
            MIDI_AFTERTOUCH = 0xD0,         // aka channel pressure
            MIDI_POLY_AFTERTOUCH = 0xA0,    // aka key pressure
            MIDI_CLOCK = 0xF8,
            MIDI_START = 0xFA,
            MIDI_CONT = 0xFB,
            MIDI_STOP = 0xFC,
            MIDI_SYSEX_START = 0xF0,
            MIDI_SYSEX_STOP = 0xF7

        };

        enum MidiCtrl {

            ALL_NOTES_OFF = 123,
            ALL_SOUND_OFF = 120

        };
};

/****************************************************
 * Base class for MIDI input handling.
 *
 * Shared common code used for input handling:
 * - decoding Real-Time messages: handleSync
 * - decoding one data byte messages: handleData1
 * - decoding two data byte messages: handleData2
 ****************************************************/

class midi_handler : public midi {

    protected:

        std::vector<midi*> fMidiInputs;
        std::string fName;
    
        int range(int min, int max, int val) { return (val < min) ? min : ((val >= max) ? max : val); }
  
    public:

        midi_handler(const std::string& name = "MIDIHandler"):fName(name) {}
        virtual ~midi_handler() {}

        void addMidiIn(midi* midi_dsp) { if (midi_dsp) fMidiInputs.push_back(midi_dsp); }
        void removeMidiIn(midi* midi_dsp)
        {
            std::vector<midi*>::iterator it = std::find(fMidiInputs.begin(), fMidiInputs.end(), midi_dsp);
            if (it != fMidiInputs.end()) {
                fMidiInputs.erase(it);
            }
        }

        virtual bool startMidi() { return true; }
        virtual void stopMidi() {}
    
        void setName(const std::string& name) { fName = name; }
        std::string getName() { return fName; }
        
        void handleSync(double time, int type)
        {
            if (type == MIDI_CLOCK) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->clock(time);
                }
            } else if (type == MIDI_START) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->startSync(time);
                }
            } else if (type == MIDI_STOP) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->stopSync(time);
                }
            }
        }

        void handleData1(double time, int type, int channel, int data1)
        {
            if (type == MIDI_PROGRAM_CHANGE) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->progChange(time, channel, data1);
                }
            } else if (type == MIDI_AFTERTOUCH) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->chanPress(time, channel, data1);
                }
            }
        }

        void handleData2(double time, int type, int channel, int data1, int data2)
        {
            if (type == MIDI_NOTE_OFF || ((type == MIDI_NOTE_ON) && (data2 == 0))) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyOff(time, channel, data1, data2);
                }
            } else if (type == MIDI_NOTE_ON) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyOn(time, channel, data1, data2);
                }
            } else if (type == MIDI_CONTROL_CHANGE) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->ctrlChange(time, channel, data1, data2);
                }
            } else if (type == MIDI_PITCH_BEND) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->pitchWheel(time, channel, (data2 << 7) + data1);
                }
            } else if (type == MIDI_POLY_AFTERTOUCH) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyPress(time, channel, data1, data2);
                }
            }
        }
    
        void handleMessage(double time, int type, std::vector<unsigned char>& message)
        {
            if (type == MIDI_SYSEX_START) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->sysEx(time, message);
                }
            }
        }

};

//-------------------------------
// For timestamped MIDI messages
//-------------------------------

struct DatedMessage {
    
    double fDate;
    unsigned char fBuffer[3];
    size_t fSize;
    
    DatedMessage(double date, unsigned char* buffer, size_t size)
    :fDate(date), fSize(size)
    {
        assert(size <= 3);
        memcpy(fBuffer, buffer, size);
    }
    
    DatedMessage():fDate(0.0), fSize(0)
    {}
    
};

#endif // __midi__

#ifdef _MSC_VER
#define gsscanf sscanf_s
#else
#define gsscanf sscanf
#endif

/*****************************************************************************
* Helper code for MIDI meta and polyphonic 'nvoices' parsing
******************************************************************************/

struct MidiMeta : public Meta, public std::map<std::string, std::string>
{
    void declare(const char* key, const char* value)
    {
        (*this)[key] = value;
    }
    
    const std::string get(const char* key, const char* def)
    {
        if (this->find(key) != this->end()) {
            return (*this)[key];
        } else {
            return def;
        }
    }
    
    static void analyse(dsp* tmp_dsp, bool& midi_sync, int& nvoices)
    {
        JSONUI jsonui;
        tmp_dsp->buildUserInterface(&jsonui);
        std::string json = jsonui.JSON();
        midi_sync = ((json.find("midi") != std::string::npos) &&
                     ((json.find("start") != std::string::npos) ||
                      (json.find("stop") != std::string::npos) ||
                      (json.find("clock") != std::string::npos)));
    
    #if defined(NVOICES) && NVOICES!=NUM_VOICES
        nvoices = NVOICES;
    #else
        MidiMeta meta;
        tmp_dsp->metadata(&meta);
        std::string numVoices = meta.get("nvoices", "0");
        nvoices = std::atoi(numVoices.c_str());
        if (nvoices < 0) nvoices = 0;
    #endif
    }
};

/*******************************************************************************
 * MidiUI : Faust User Interface
 * This class decodes MIDI meta data and maps incoming MIDI messages to them.
 * Currently ctrl, keyon/keyoff, keypress, pgm, chanpress, pitchwheel/pitchbend
 * start/stop/clock meta data is handled.
 ******************************************************************************/

class uiMidi {
    
    protected:
        
        midi* fMidiOut;
        bool fInputCtrl;
        
    public:
        
        uiMidi(midi* midi_out, bool input):fMidiOut(midi_out), fInputCtrl(input)
        {}
        virtual ~uiMidi()
        {}
    
};

/*****************************************************************************
 * Base class for MIDI aware UI items
 ******************************************************************************/

class uiMidiItem : public uiMidi, public uiItem {
    
    public:
        
        uiMidiItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidi(midi_out, input), uiItem(ui, zone)
        {}
        virtual ~uiMidiItem()
        {}
    
        virtual void reflectZone() {}
    
};

/*****************************************************************************
 * Base class for MIDI aware UI items with timestamp support
 ******************************************************************************/

class uiMidiTimedItem : public uiMidi, public uiTimedItem {
    
    public:
        
        uiMidiTimedItem(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidi(midi_out, input), uiTimedItem(ui, zone)
        {}
        virtual ~uiMidiTimedItem()
        {}
    
        virtual void reflectZone() {}
    
};

//-------------
// MIDI sync
//-------------

class uiMidiStart : public uiMidiTimedItem
{
  
    public:
    
        uiMidiStart(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStart()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->startSync(0);
            }
        }
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(v));
            }
        }
        
};

class uiMidiStop : public uiMidiTimedItem
{
  
    public:
    
        uiMidiStop(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiStop()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(1)) {
                fMidiOut->stopSync(0);
            }
        }
    void modifyZone(double date, FAUSTFLOAT v)
    {
        if (fInputCtrl) {
            uiItem::modifyZone(FAUSTFLOAT(v));
        }
    }
};

class uiMidiClock : public uiMidiTimedItem
{

    private:
        
        bool fState;
  
    public:
    
        uiMidiClock(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiTimedItem(midi_out, ui, zone, input), fState(false)
        {}
        virtual ~uiMidiClock()
        {}
    
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->clock(0);
        }
    
        void modifyZone(double date, FAUSTFLOAT v)
        {
            if (fInputCtrl) {
                fState = !fState;
                //uiMidiTimedItem::modifyZone(date, FAUSTFLOAT(fState));
                uiItem::modifyZone(FAUSTFLOAT(fState));//uiMidiTimedItem
            }
        }

};

//----------------------
// Standard MIDI events
//----------------------

class uiMidiProgChange : public uiMidiItem
{
    
    private:
        
        int fPgm;
  
    public:
    
        uiMidiProgChange(midi* midi_out, int pgm, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fPgm(pgm)
        {}
        virtual ~uiMidiProgChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->progChange(0, fPgm);
            }
        }
        
};

class uiMidiChanPress : public uiMidiItem
{
    private:
        
        int fPress;
  
    public:
    
        uiMidiChanPress(midi* midi_out, int press, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fPress(press)
        {}
        virtual ~uiMidiChanPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            if (v != FAUSTFLOAT(0)) {
                fMidiOut->chanPress(0, fPress);
            }
        }
        
};

class uiMidiCtrlChange : public uiMidiItem
{
    private:
    
        int fCtrl;
        LinearValueConverter fConverter;
 
    public:
    
        uiMidiCtrlChange(midi* midi_out, int ctrl, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fCtrl(ctrl), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiCtrlChange()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->ctrlChange(0, fCtrl, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
 
};

class uiMidiPitchWheel : public uiMidiItem
{

    private:
    	
		// currently, the range is of pitchwheel if fixed (-2/2 semitones)
        FAUSTFLOAT wheel2bend(float v)
        {
            return std::pow(2.0,(v/16383.0*4-2)/12);
        }

        int bend2wheel(float v)
        {
            return (int)((12*std::log(v)/std::log(2.0)+2)/4*16383);
        }
 
    public:
    
        uiMidiPitchWheel(midi* midi_out, GUI* ui, FAUSTFLOAT* zone, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input)
        {}
        virtual ~uiMidiPitchWheel()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->pitchWheel(0, bend2wheel(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(wheel2bend(v));
            }
        }
 
};

class uiMidiKeyOn : public uiMidiItem
{

    private:
        
        int fKeyOn;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyOn(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKeyOn(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyOn()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyOn(0, fKeyOn, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};

class uiMidiKeyOff : public uiMidiItem
{

    private:
        
        int fKeyOff;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyOff(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKeyOff(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyOff()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyOff(0, fKeyOff, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};


class uiMidiKeyPress : public uiMidiItem
{

    private:
    
        int fKey;
        LinearValueConverter fConverter;
  
    public:
    
        uiMidiKeyPress(midi* midi_out, int key, GUI* ui, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
            :uiMidiItem(midi_out, ui, zone, input), fKey(key), fConverter(0., 127., double(min), double(max))
        {}
        virtual ~uiMidiKeyPress()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fMidiOut->keyPress(0, fKey, fConverter.faust2ui(v));
        }
        
        void modifyZone(int v) 	
        { 
            if (fInputCtrl) {
                uiItem::modifyZone(FAUSTFLOAT(fConverter.ui2faust(v)));
            }
        }
        
};

class MapUI;

/******************************************************************************************
 * MidiUI : Faust User Interface
 * This class decodes MIDI metadata and maps incoming MIDI messages to them.
 * Currently ctrl, keyon/keyoff, keypress, pgm, chanpress, pitchwheel/pitchbend
 * start/stop/clock meta data are handled.
 *
 * Maps associating MIDI event ID (like each ctrl number) with all MIDI aware UI items
 * are defined and progressively filled when decoding MIDI related metadata.
 * MIDI aware UI items are used in both directions:
 *  - modifying their internal state when receving MIDI input events
 *  - sending their internal state as MIDI output events
 *******************************************************************************************/

class MidiUI : public GUI, public midi
{

    protected:
    
        std::map <int, std::vector<uiMidiCtrlChange*> > fCtrlChangeTable;
        std::map <int, std::vector<uiMidiProgChange*> > fProgChangeTable;
        std::map <int, std::vector<uiMidiChanPress*> >  fChanPressTable;
        std::map <int, std::vector<uiMidiKeyOn*> >      fKeyOnTable;
        std::map <int, std::vector<uiMidiKeyOff*> >     fKeyOffTable;
        std::map <int, std::vector<uiMidiKeyOn*> >      fKeyTable;
        std::map <int, std::vector<uiMidiKeyPress*> >   fKeyPressTable;
        std::vector<uiMidiPitchWheel*>                  fPitchWheelTable;
        
        std::vector<uiMidiStart*>   fStartTable;
        std::vector<uiMidiStop*>    fStopTable;
        std::vector<uiMidiClock*>   fClockTable;
        
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        
        midi_handler* fMidiHandler;
        bool fDelete;
    
        void addGenericZone(FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max, bool input = true)
        {
            if (fMetaAux.size() > 0) {
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    unsigned num;
                    if (fMetaAux[i].first == "midi") {
                        if (gsscanf(fMetaAux[i].second.c_str(), "ctrl %u", &num) == 1) {
                            fCtrlChangeTable[num].push_back(new uiMidiCtrlChange(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyon %u", &num) == 1) {
                            fKeyOnTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keyoff %u", &num) == 1) {
                            fKeyOffTable[num].push_back(new uiMidiKeyOff(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "key %u", &num) == 1) {
                            fKeyTable[num].push_back(new uiMidiKeyOn(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "keypress %u", &num) == 1) {
                            fKeyPressTable[num].push_back(new uiMidiKeyPress(fMidiHandler, num, this, zone, min, max, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "pgm %u", &num) == 1) {
                            fProgChangeTable[num].push_back(new uiMidiProgChange(fMidiHandler, num, this, zone, input));
                        } else if (gsscanf(fMetaAux[i].second.c_str(), "chanpress %u", &num) == 1) {
                            fChanPressTable[num].push_back(new uiMidiChanPress(fMidiHandler, num, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "pitchwheel") == 0 
                            || strcmp(fMetaAux[i].second.c_str(), "pitchbend") == 0) {
                            fPitchWheelTable.push_back(new uiMidiPitchWheel(fMidiHandler, this, zone, input));
                        // MIDI sync
                        } else if (strcmp(fMetaAux[i].second.c_str(), "start") == 0) {
                            fStartTable.push_back(new uiMidiStart(fMidiHandler, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "stop") == 0) {
                            fStopTable.push_back(new uiMidiStop(fMidiHandler, this, zone, input));
                        } else if (strcmp(fMetaAux[i].second.c_str(), "clock") == 0) {
                            fClockTable.push_back(new uiMidiClock(fMidiHandler, this, zone, input));
                        }
                    }
                }
            }
            fMetaAux.clear();
        }

    public:
    
        MidiUI():fMidiHandler(NULL), fDelete(false)
        {}

        MidiUI(midi_handler* midi_handler, bool delete_handler = false)
        {
            fMidiHandler = midi_handler;
            fMidiHandler->addMidiIn(this);
            fDelete = delete_handler;
        }
 
        virtual ~MidiUI() 
        { 
            fMidiHandler->removeMidiIn(this);
            if (fDelete) delete fMidiHandler;
        }
        
        bool run() { return fMidiHandler->startMidi(); }
        void stop() { fMidiHandler->stopMidi(); }
        
        void addMidiIn(midi* midi_dsp) { fMidiHandler->addMidiIn(midi_dsp); }
        void removeMidiIn(midi* midi_dsp) { fMidiHandler->removeMidiIn(midi_dsp); }
      
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addGenericZone(zone, FAUSTFLOAT(0), FAUSTFLOAT(1));
        }
        
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addGenericZone(zone, min, max);
        }

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
        {
            addGenericZone(zone, min, max, false);
        }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addGenericZone(zone, min, max, false);
        }

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
        
        // -- MIDI API 
        
        MapUI* keyOn(double date, int channel, int note, int velocity)
        {
            if (fKeyOnTable.find(note) != fKeyOnTable.end()) {
                for (unsigned int i = 0; i < fKeyOnTable[note].size(); i++) {
                    fKeyOnTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
            // If note is in fKeyTable, handle it as a keyOn
            if (fKeyTable.find(note) != fKeyTable.end()) {
                for (unsigned int i = 0; i < fKeyTable[note].size(); i++) {
                    fKeyTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
            return 0;
        }
        
        void keyOff(double date, int channel, int note, int velocity)
        {
            if (fKeyOffTable.find(note) != fKeyOffTable.end()) {
                for (unsigned int i = 0; i < fKeyOffTable[note].size(); i++) {
                    fKeyOffTable[note][i]->modifyZone(FAUSTFLOAT(velocity));
                }
            }
            // If note is in fKeyTable, handle it as a keyOff with a 0 velocity
            if (fKeyTable.find(note) != fKeyTable.end()) {
                for (unsigned int i = 0; i < fKeyTable[note].size(); i++) {
                    fKeyTable[note][i]->modifyZone(0);
                }
            }
        }
           
        void ctrlChange(double date, int channel, int ctrl, int value)
        {
            if (fCtrlChangeTable.find(ctrl) != fCtrlChangeTable.end()) {
                for (unsigned int i = 0; i < fCtrlChangeTable[ctrl].size(); i++) {
                    fCtrlChangeTable[ctrl][i]->modifyZone(FAUSTFLOAT(value));
                }
            } 
        }
        
        void progChange(double date, int channel, int pgm)
        {
            if (fProgChangeTable.find(pgm) != fProgChangeTable.end()) {
                for (unsigned int i = 0; i < fProgChangeTable[pgm].size(); i++) {
                    fProgChangeTable[pgm][i]->modifyZone(FAUSTFLOAT(1));
                }
            } 
        }
        
        void pitchWheel(double date, int channel, int wheel) 
        {
            for (unsigned int i = 0; i < fPitchWheelTable.size(); i++) {
                fPitchWheelTable[i]->modifyZone(FAUSTFLOAT(wheel));
            }
        }
        
        void keyPress(double date, int channel, int pitch, int press) 
        {
            if (fKeyPressTable.find(pitch) != fKeyPressTable.end()) {
                for (unsigned int i = 0; i < fKeyPressTable[pitch].size(); i++) {
                    fKeyPressTable[pitch][i]->modifyZone(FAUSTFLOAT(press));
                }
            } 
        }
        
        void chanPress(double date, int channel, int press)
        {
            if (fChanPressTable.find(press) != fChanPressTable.end()) {
                for (unsigned int i = 0; i < fChanPressTable[press].size(); i++) {
                    fChanPressTable[press][i]->modifyZone(FAUSTFLOAT(1));
                }
            } 
        }
        
        void ctrlChange14bits(double date, int channel, int ctrl, int value) {}
        
        // MIDI sync
        
        void startSync(double date)
        {
            for (unsigned int i = 0; i < fStartTable.size(); i++) {
                fStartTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
        
        void stopSync(double date)
        {
            for (unsigned int i = 0; i < fStopTable.size(); i++) {
                fStopTable[i]->modifyZone(date, FAUSTFLOAT(0));
            }
        }
        
        void clock(double date)
        {
            for (unsigned int i = 0; i < fClockTable.size(); i++) {
                fClockTable[i]->modifyZone(date, FAUSTFLOAT(1));
            }
        }
};

#endif // FAUST_MIDIUI_H
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __poly_dsp__
#define __poly_dsp__

#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <ostream>
#include <sstream>
#include <vector>
#include <limits.h>
#include <float.h>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp_combiner__
#define __dsp_combiner__

#include <string.h>
#include <assert.h>


// Combine two DSP in sequence

class dsp_sequencer : public dsp {
    
    private:
        
        dsp* fDSP1;
        dsp* fDSP2;
        FAUSTFLOAT** fSeqBuffer;
         
    public:
        
        dsp_sequencer(dsp* dsp1, dsp* dsp2, int buffer_size = 4096)
            :fDSP1(dsp1), fDSP2(dsp2)
        {
            assert(fDSP1->getNumOutputs() == fDSP2->getNumInputs());
            fSeqBuffer = new FAUSTFLOAT*[fDSP1->getNumOutputs()];
            for (int i = 0; i < fDSP1->getNumOutputs(); i++) {
                fSeqBuffer[i] = new FAUSTFLOAT[buffer_size];
            }
        }
        
        virtual ~dsp_sequencer()
        {
            for (int i = 0; i < fDSP1->getNumOutputs(); i++) {
               delete [] fSeqBuffer[i];
            }
            
            delete [] fSeqBuffer;
            delete fDSP1;
            delete fDSP2;
        }
               
        virtual int getNumInputs() { return fDSP1->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP2->getNumOutputs(); }
    
        virtual void buildUserInterface(UI* ui_interface)
        {
            ui_interface->openTabBox("Sequencer");
            ui_interface->openVerticalBox("DSP1");
            fDSP1->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->openVerticalBox("DSP2");
            fDSP2->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->closeBox();
        }
        
        virtual int getSampleRate()
        {
            return fDSP1->getSampleRate();
        }
    
        virtual void init(int samplingRate)
        {
            fDSP1->init(samplingRate);
            fDSP2->init(samplingRate);
        }
    
        virtual void instanceInit(int samplingRate)
        {
            fDSP1->instanceInit(samplingRate);
            fDSP2->instanceInit(samplingRate);
        }
    
        virtual void instanceConstants(int samplingRate)
        {
            fDSP1->instanceConstants(samplingRate);
            fDSP2->instanceConstants(samplingRate);
        }
    
        virtual void instanceResetUserInterface()
        {
            fDSP1->instanceResetUserInterface();
            fDSP2->instanceResetUserInterface();
        }
    
        virtual void instanceClear()
        {
            fDSP1->instanceClear();
            fDSP2->instanceClear();
        }
        
        virtual dsp* clone()
        {
            return new dsp_sequencer(fDSP1->clone(), fDSP2->clone());
        }
    
        virtual void metadata(Meta* m)
        {
            fDSP1->metadata(m);
            fDSP2->metadata(m);
        }
 
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, fSeqBuffer);
            fDSP2->compute(count, fSeqBuffer, outputs);
        }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

// Combine two DSP in parallel

class dsp_parallelizer : public dsp {
    
    private:
        
        dsp* fDSP1;
        dsp* fDSP2;
    
        FAUSTFLOAT** fInputsDSP2;
        FAUSTFLOAT** fOutputsDSP2;
    
    public:
        
        dsp_parallelizer(dsp* dsp1, dsp* dsp2, int buffer_size = 4096)
            :fDSP1(dsp1), fDSP2(dsp2)
        {
            fInputsDSP2 = new FAUSTFLOAT*[fDSP2->getNumInputs()];
            fOutputsDSP2 = new FAUSTFLOAT*[fDSP2->getNumOutputs()];
        }
        
        virtual ~dsp_parallelizer()
        {
            delete fDSP1;
            delete fDSP2;
            delete [] fInputsDSP2;
            delete [] fOutputsDSP2;
        }
               
        virtual int getNumInputs() { return fDSP1->getNumInputs() + fDSP2->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP1->getNumOutputs() + fDSP2->getNumOutputs(); }
    
        virtual void buildUserInterface(UI* ui_interface)
        {
            ui_interface->openTabBox("Parallelizer");
            ui_interface->openVerticalBox("DSP1");
            fDSP1->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->openVerticalBox("DSP2");
            fDSP2->buildUserInterface(ui_interface);
            ui_interface->closeBox();
            ui_interface->closeBox();
        }
        
        virtual int getSampleRate()
        {
            return fDSP1->getSampleRate();
        }
    
        virtual void init(int samplingRate)
        {
            fDSP1->init(samplingRate);
            fDSP2->init(samplingRate);
        }
    
        virtual void instanceInit(int samplingRate)
        {
            fDSP1->instanceInit(samplingRate);
            fDSP2->instanceInit(samplingRate);
        }
    
        virtual void instanceConstants(int samplingRate)
        {
            fDSP1->instanceConstants(samplingRate);
            fDSP2->instanceConstants(samplingRate);
        }
        
        virtual void instanceResetUserInterface()
        {
            fDSP1->instanceResetUserInterface();
            fDSP2->instanceResetUserInterface();
        }

        virtual void instanceClear()
        {
            fDSP1->instanceClear();
            fDSP2->instanceClear();
        }
        
        virtual dsp* clone()
        {
            return new dsp_parallelizer(fDSP1->clone(), fDSP2->clone());
        }

        virtual void metadata(Meta* m)
        {
            fDSP1->metadata(m);
            fDSP2->metadata(m);
        }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            fDSP1->compute(count, inputs, outputs);
            
            // Shift inputs/outputs channels for fDSP2
            for (int chan = 0; chan < fDSP2->getNumInputs(); chan++) {
                fInputsDSP2[chan] = inputs[fDSP1->getNumInputs() + chan];
            }
            for (int chan = 0; chan < fDSP2->getNumOutputs(); chan++) {
                fOutputsDSP2[chan] = outputs[fDSP1->getNumOutputs() + chan];
            }
            
            fDSP2->compute(count, fInputsDSP2, fOutputsDSP2);
        }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
};

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#include <vector>
#include <map>
#include <string>


/*******************************************************************************
 * MapUI : Faust User Interface
 * This class creates a map of complete hierarchical path and zones for each UI items.
 ******************************************************************************/

class MapUI : public UI, public PathBuilder
{
    
    protected:
    
        // Complete path map
        std::map<std::string, FAUSTFLOAT*> fPathZoneMap;
    
        // Label zone map
        std::map<std::string, FAUSTFLOAT*> fLabelZoneMap;
    
    public:
        
        MapUI() {};
        virtual ~MapUI() {};
        
        // -- widget's layouts
        void openTabBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
        }
        
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
        
        // -- metadata declarations
        void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
        
        // set/get
        void setParamValue(const std::string& path, FAUSTFLOAT value)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                *fPathZoneMap[path] = value;
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                *fLabelZoneMap[path] = value;
            }
        }
        
        FAUSTFLOAT getParamValue(const std::string& path)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                return *fPathZoneMap[path];
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                return *fLabelZoneMap[path];
            } else {
                return FAUSTFLOAT(0);
            }
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getMap() { return fPathZoneMap; }
        
        int getParamsCount() { return int(fPathZoneMap.size()); }
        
        std::string getParamAddress(int index)
        { 
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            while (index-- > 0 && it++ != fPathZoneMap.end()) {}
            return (*it).first;
        }
    
        std::string getParamAddress(FAUSTFLOAT* zone)
        {
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            do {
                if ((*it).second == zone) return (*it).first;
            }
            while (it++ != fPathZoneMap.end());
            return "";
        }
};

#endif // FAUST_MAPUI_H
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __proxy_dsp__
#define __proxy_dsp__

#include <vector>
#include <map>


//----------------------------------------------------------------
//  Proxy dsp definition created from the DSP JSON description
//  This class allows a 'proxy' dsp to control a real dsp 
//  possibly running somewhere else.
//----------------------------------------------------------------

class proxy_dsp : public dsp {

    private:
    
        int fSamplingFreq;
        JSONUIDecoder* fDecoder;
        
    public:
    
        proxy_dsp(const std::string& json)
        {
            fDecoder = new JSONUIDecoder(json);
            fSamplingFreq = -1;
        }
          
        proxy_dsp(dsp* dsp)
        {
            JSONUI builder(dsp->getNumInputs(), dsp->getNumOutputs());
            dsp->metadata(&builder);
            dsp->buildUserInterface(&builder);
            fSamplingFreq = dsp->getSampleRate();
            fDecoder = new JSONUIDecoder(builder.JSON());
        }
      
        virtual ~proxy_dsp()
        {
            delete fDecoder;
        }
       
        virtual int getNumInputs() 	{ return fDecoder->fNumInputs; }
        virtual int getNumOutputs() { return fDecoder->fNumOutputs; }
        
        virtual void buildUserInterface(UI* ui) { fDecoder->buildUserInterface(ui); }
        
        // To possibly implement in a concrete proxy dsp 
        virtual void init(int samplingFreq)
        {
            instanceInit(samplingFreq);
        }
        virtual void instanceInit(int samplingFreq)
        {
            instanceConstants(samplingFreq);
            instanceResetUserInterface();
            instanceClear();
        }
        virtual void instanceConstants(int samplingRate) { fSamplingFreq = samplingRate; }
        virtual void instanceResetUserInterface() { fDecoder->resetUserInterface(); }
        virtual void instanceClear() {}
    
        virtual int getSampleRate() { return fSamplingFreq; }
    
        virtual proxy_dsp* clone() { return new proxy_dsp(fDecoder->fJSON); }
        virtual void metadata(Meta* m) { fDecoder->metadata(m); }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {}
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {} 
        
};

#endif

#define kActiveVoice      0
#define kFreeVoice        -1
#define kReleaseVoice     -2
#define kNoVoice          -3

#define VOICE_STOP_LEVEL  0.0005    // -70 db
#define MIX_BUFFER_SIZE   4096

// endsWith(<str>,<end>) : returns true if <str> ends with <end>

static bool endsWith(std::string const& str, std::string const& end)
{
    size_t l1 = str.length();
    size_t l2 = end.length();
    return (l1 >= l2) && (0 == str.compare(l1 - l2, l2, end));
}

static double midiToFreq(double note)
{
    return 440.0 * std::pow(2.0, (note-69.0)/12.0);
}

/**
 * Allows to control zones in a grouped manner.
 */

class GroupUI : public GUI, public PathBuilder
{

    private:

        std::map<std::string, uiGroupItem*> fLabelZoneMap;

        void insertMap(std::string label, FAUSTFLOAT* zone)
        {
            if (!endsWith(label, "/gate")
                && !endsWith(label, "/freq")
                && !endsWith(label, "/gain")) {

                // Groups all controller except 'freq', 'gate', and 'gain'
                if (fLabelZoneMap.find(label) != fLabelZoneMap.end()) {
                    fLabelZoneMap[label]->addZone(zone);
                } else {
                    fLabelZoneMap[label] = new uiGroupItem(this, zone);
                }
            }
        }

        uiCallbackItem* fPanic;

    public:

        GroupUI(FAUSTFLOAT* zone, uiCallback cb, void* arg)
        {
            fPanic = new uiCallbackItem(this, zone, cb, arg);
        }
    
        virtual ~GroupUI()
        {
            // 'fPanic' is kept and deleted in GUI, so do not delete here
        }

        // -- widget's layouts
        void openTabBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
        }

        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            insertMap(buildPath(label), zone);
        }

        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            insertMap(buildPath(label), zone);
        }

};

/**
 * One voice of polyphony.
 */

struct dsp_voice : public MapUI, public decorator_dsp {

    int fNote;                          // Playing note actual pitch
    int fDate;                          // KeyOn date
    bool fTrigger;                      // True if stolen note and need for envelop trigger
    FAUSTFLOAT fLevel;                  // Last audio block level
    std::vector<std::string> fGatePath; // Paths of 'gate' control
    std::vector<std::string> fGainPath; // Paths of 'gain' control
    std::vector<std::string> fFreqPath; // Paths of 'freq' control
    FAUSTFLOAT** fInputsSlice;
    FAUSTFLOAT** fOutputsSlice;
 
    dsp_voice(dsp* dsp):decorator_dsp(dsp)
    {
        dsp->buildUserInterface(this);
        fNote = kFreeVoice;
        fLevel = FAUSTFLOAT(0);
        fDate = 0;
        fTrigger = false;
        extractPaths(fGatePath, fFreqPath, fGainPath);
        fInputsSlice = new FAUSTFLOAT*[dsp->getNumInputs()];
        fOutputsSlice = new FAUSTFLOAT*[dsp->getNumOutputs()];
    }
    virtual ~dsp_voice()
    {
        delete [] fInputsSlice;
        delete [] fOutputsSlice;
    }

    void extractPaths(std::vector<std::string>& gate, std::vector<std::string>& freq, std::vector<std::string>& gain)
    {
        // Keep gain, freq and gate labels
        std::map<std::string, FAUSTFLOAT*>::iterator it;
        for (it = getMap().begin(); it != getMap().end(); it++) {
            std::string path = (*it).first;
            if (endsWith(path, "/gate")) {
                gate.push_back(path);
            } else if (endsWith(path, "/freq")) {
                freq.push_back(path);
            } else if (endsWith(path, "/gain")) {
                gain.push_back(path);
            }
        }
    }

    // MIDI velocity [0..127]
    void keyOn(int pitch, int velocity, bool trigger)
    {
        keyOn(pitch, float(velocity)/127.f, trigger);
    }

    // Normalized MIDI velocity [0..1]
    void keyOn(int pitch, float velocity, bool trigger)
    {
        for (size_t i = 0; i < fFreqPath.size(); i++) {
            setParamValue(fFreqPath[i], midiToFreq(pitch));
        }
        for (size_t i = 0; i < fGainPath.size(); i++) {
            setParamValue(fGainPath[i], velocity);
        }
        fNote = pitch;
        fTrigger = trigger;
    }

    void keyOff(bool hard = false)
    {
        // Be sure the voice is not triggered
        fTrigger = false;
        
        // No use of velocity for now...
        for (size_t i = 0; i < fGatePath.size(); i++) {
            setParamValue(fGatePath[i], FAUSTFLOAT(0));
        }
        
        if (hard) {
            // Immediately stop voice
            fNote = kFreeVoice;
        } else {
            // Release voice
            fNote = kReleaseVoice;
        }
    }

    void play(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        if (fTrigger) {
            // New note, so trigger it
            trigger(count, inputs, outputs);
        } else {
            // Compute the voice
            compute(count, inputs, outputs);
        }
    }

    void trigger(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        for (size_t i = 0; i < fGatePath.size(); i++) {
            setParamValue(fGatePath[i], FAUSTFLOAT(0));
        }
        computeSlice(0, 1, inputs, outputs);
        for (size_t i = 0; i < fGatePath.size(); i++) {
            setParamValue(fGatePath[i], FAUSTFLOAT(1));
        }
        computeSlice(1, count - 1, inputs, outputs);
        fTrigger = false;
    }

    void computeSlice(int offset, int slice, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
    {
        if (slice > 0) {
            for (int chan = 0; chan < getNumInputs(); chan++) {
                fInputsSlice[chan] = &(inputs[chan][offset]);
            }
            for (int chan = 0; chan < getNumOutputs(); chan++) {
                fOutputsSlice[chan] = &(outputs[chan][offset]);
            }
            compute(slice, fInputsSlice, fOutputsSlice);
        }
    }

};

/**
 * A group of voices.
 */

struct dsp_voice_group {

    GroupUI fGroups;

    std::vector<dsp_voice*> fVoiceTable; // Individual voices
    dsp* fVoiceGroup;                    // Voices group to be used for GUI grouped control

    FAUSTFLOAT fPanic;

    bool fVoiceControl;
    bool fGroupControl;

    dsp_voice_group(uiCallback cb, void* arg, bool control, bool group)
        :fGroups(&fPanic, cb, arg),
        fVoiceGroup(0), fPanic(FAUSTFLOAT(0)),
        fVoiceControl(control), fGroupControl(group)
    {}

    virtual ~dsp_voice_group()
    {
        for (size_t i = 0; i < fVoiceTable.size(); i++) {
            delete fVoiceTable[i];
        }
        delete fVoiceGroup;
    }

    void addVoice(dsp_voice* voice)
    {
        fVoiceTable.push_back(voice);
    }

    void clearVoices()
    {
        fVoiceTable.clear();
    }

    void init()
    {
        // Groups all uiItem for a given path
        fVoiceGroup = new proxy_dsp(fVoiceTable[0]);
        fVoiceGroup->buildUserInterface(&fGroups);
        for (size_t i = 0; i < fVoiceTable.size(); i++) {
            fVoiceTable[i]->buildUserInterface(&fGroups);
        }
    }

    void buildUserInterface(UI* ui_interface)
    {
        if (fVoiceTable.size() > 1) {
            ui_interface->openTabBox("Polyphonic");

            // Grouped voices UI
            ui_interface->openVerticalBox("Voices");
            ui_interface->addButton("Panic", &fPanic);
            fVoiceGroup->buildUserInterface(ui_interface);
            ui_interface->closeBox();

            // If not grouped, also add individual voices UI
            if (!fGroupControl) {
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    char buffer[32];
                    snprintf(buffer, 32, ((fVoiceTable.size() < 8) ? "Voice%ld" : "V%ld"), long(i+1));
                    ui_interface->openHorizontalBox(buffer);
                    fVoiceTable[i]->buildUserInterface(ui_interface);
                    ui_interface->closeBox();
                }
            }

            ui_interface->closeBox();
        } else {
            fVoiceTable[0]->buildUserInterface(ui_interface);
        }
    }

};

/**
 * Base class for MIDI controllable DSP.
 */

class dsp_poly : public decorator_dsp, public midi {

    public:
    
        dsp_poly(dsp* dsp):decorator_dsp(dsp)
        {}
    
        virtual ~dsp_poly() {}
    
        // Group API
        virtual void setGroup(bool group) = 0;
        virtual bool getGroup() = 0;

};

/**
 * Polyphonic DSP: groups a set of DSP to be played together or triggered by MIDI.
 *
 * All voices are preallocated by cloning the single DSP voice given at creation time.
 * Dynamic voice allocation is done in 'getFreeVoice'
 */

class mydsp_poly : public dsp_voice_group, public dsp_poly {

    private:

        FAUSTFLOAT** fMixBuffer;
        int fDate;

        FAUSTFLOAT mixVoice(int count, FAUSTFLOAT** outputBuffer, FAUSTFLOAT** mixBuffer)
        {
            FAUSTFLOAT level = 0;
            for (int i = 0; i < getNumOutputs(); i++) {
                FAUSTFLOAT* mixChannel = mixBuffer[i];
                FAUSTFLOAT* outChannel = outputBuffer[i];
                for (int j = 0; j < count; j++) {
                    level = std::max<FAUSTFLOAT>(level, (FAUSTFLOAT)fabs(outChannel[j]));
                    mixChannel[j] += outChannel[j];
                }
            }
            return level;
        }

        void clearOutput(int count, FAUSTFLOAT** mixBuffer)
        {
            for (int i = 0; i < getNumOutputs(); i++) {
                memset(mixBuffer[i], 0, count * sizeof(FAUSTFLOAT));
            }
        }
    
        int getPlayingVoice(int pitch)
        {
            int voice_playing = kNoVoice;
            int oldest_date_playing = INT_MAX;
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fNote == pitch) {
                    // Keeps oldest playing voice
                    if (fVoiceTable[i]->fDate < oldest_date_playing) {
                        oldest_date_playing = fVoiceTable[i]->fDate;
                        voice_playing = int(i);
                    }
                }
            }
            
            return voice_playing;
        }
    
        // Always returns a voice
        int getFreeVoice()
        {
            int voice = kNoVoice;
            
            // Looks for the first available voice
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                if (fVoiceTable[i]->fNote == kFreeVoice) {
                    voice = int(i);
                    goto result;
                }
            }

            {
                // Otherwise steal one
                int voice_release = kNoVoice;
                int voice_playing = kNoVoice;
                
                int oldest_date_release = INT_MAX;
                int oldest_date_playing = INT_MAX;

                // Scan all voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    if (fVoiceTable[i]->fNote == kReleaseVoice) {
                        // Keeps oldest release voice
                        if (fVoiceTable[i]->fDate < oldest_date_release) {
                            oldest_date_release = fVoiceTable[i]->fDate;
                            voice_release = int(i);
                        }
                    } else {
                        // Otherwise keeps oldest playing voice
                        if (fVoiceTable[i]->fDate < oldest_date_playing) {
                            oldest_date_playing = fVoiceTable[i]->fDate;
                            voice_playing = int(i);
                        }
                    }
                }
            
                // Then decide which one to steal
                if (oldest_date_release != INT_MAX) {
                    std::cout << "Steal release voice : voice_date " << fVoiceTable[voice_release]->fDate << " cur_date = " << fDate << " voice = " << voice_release << std::endl;
                    voice = voice_release;
                    goto result;
                } else if (oldest_date_playing != INT_MAX) {
                    std::cout << "Steal playing voice : voice_date " << fVoiceTable[voice_playing]->fDate << " cur_date = " << fDate << " voice = " << voice_playing << std::endl;
                    voice = voice_playing;
                    goto result;
                } else {
                    assert(false);
                    return kNoVoice;
                }
            }
            
        result:
            fVoiceTable[voice]->fDate = fDate++;
            fVoiceTable[voice]->fTrigger = true;    // So that envelop is always re-initialized
            fVoiceTable[voice]->fNote = kActiveVoice;
            return voice;
        }

        static void panic(FAUSTFLOAT val, void* arg)
        {
            if (val == FAUSTFLOAT(1)) {
                static_cast<mydsp_poly*>(arg)->allNotesOff(true);
            }
        }

        bool checkPolyphony()
        {
            if (fVoiceTable.size() > 0) {
                return true;
            } else {
                std::cout << "DSP is not polyphonic...\n";
                return false;
            }
        }

    public:
    
        /**
         * Constructor.
         *
         * @param dsp - the dsp to be used for one voice. Beware: mydsp_poly will use and finally delete the pointer.
         * @param nvoices - number of polyphony voices
         * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
         *                If false all voices are always running.
         * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
         *                a given control on all voices, assuming GUI::updateAllGuis() is called.
         *                If false, all voices can be individually controlled.
         *                setGroup/getGroup methods can be used to set/get the group state.
         *
         */
        mydsp_poly(dsp* dsp,
                   int nvoices,
                   bool control = false,
                   bool group = true)
        : dsp_voice_group(panic, this, control, group), dsp_poly(dsp)
        {
            fDate = 0;

            // Create voices
            for (int i = 0; i < nvoices; i++) {
                addVoice(new dsp_voice(dsp->clone()));
            }

            // Init audio output buffers
            fMixBuffer = new FAUSTFLOAT*[getNumOutputs()];
            for (int i = 0; i < getNumOutputs(); i++) {
                fMixBuffer[i] = new FAUSTFLOAT[MIX_BUFFER_SIZE];
            }

            dsp_voice_group::init();
        }

        virtual ~mydsp_poly()
        {
            for (int i = 0; i < getNumOutputs(); i++) {
                delete[] fMixBuffer[i];
            }
            delete[] fMixBuffer;
        }

        // DSP API
    
        void buildUserInterface(UI* ui_interface)
        {
            dsp_voice_group::buildUserInterface(ui_interface);
        }

        void init(int samplingRate)
        {
            decorator_dsp::init(samplingRate);
            fVoiceGroup->init(samplingRate);
            fPanic = FAUSTFLOAT(0);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->init(samplingRate);
            }
        }
    
        void instanceInit(int samplingFreq)
        {
            instanceConstants(samplingFreq);
            instanceResetUserInterface();
            instanceClear();
        }

        void instanceConstants(int samplingRate)
        {
            decorator_dsp::instanceConstants(samplingRate);
            fVoiceGroup->instanceConstants(samplingRate);
            
            // Init voices
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceConstants(samplingRate);
            }
        }

        void instanceResetUserInterface()
        {
            decorator_dsp::instanceResetUserInterface();
            fVoiceGroup->instanceResetUserInterface();
            fPanic = FAUSTFLOAT(0);
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceResetUserInterface();
            }
        }

        void instanceClear()
        {
            decorator_dsp::instanceClear();
            fVoiceGroup->instanceClear();
            
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->instanceClear();
            }
        }

        virtual mydsp_poly* clone()
        {
            return new mydsp_poly(fDSP->clone(), int(fVoiceTable.size()), fVoiceControl, fGroupControl);
        }

        void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            assert(count <= MIX_BUFFER_SIZE);

            // First clear the outputs
            clearOutput(count, outputs);

            if (fVoiceControl) {
                // Mix all playing voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    dsp_voice* voice = fVoiceTable[i];
                    if (voice->fNote != kFreeVoice) {
                        voice->play(count, inputs, fMixBuffer);
                        // Mix it in result
                        voice->fLevel = mixVoice(count, fMixBuffer, outputs);
                        // Check the level to possibly set the voice in kFreeVoice again
                        if ((voice->fLevel < VOICE_STOP_LEVEL) && (voice->fNote == kReleaseVoice)) {
                            voice->fNote = kFreeVoice;
                        }
                    }
                }
            } else {
                // Mix all voices
                for (size_t i = 0; i < fVoiceTable.size(); i++) {
                    fVoiceTable[i]->compute(count, inputs, fMixBuffer);
                    mixVoice(count, fMixBuffer, outputs);
                }
            }
        }

        void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            compute(count, inputs, outputs);
        }
    
        // Terminate all active voices, gently or immediately (depending of 'hard' value)
        void allNotesOff(bool hard = false)
        {
            for (size_t i = 0; i < fVoiceTable.size(); i++) {
                fVoiceTable[i]->keyOff(hard);
            }
        }

        // Additional polyphonic API
        MapUI* newVoice()
        {
            return fVoiceTable[getFreeVoice()];
        }

        void deleteVoice(MapUI* voice)
        {
            std::vector<dsp_voice*>::iterator it = find(fVoiceTable.begin(), fVoiceTable.end(), reinterpret_cast<dsp_voice*>(voice));
            if (it != fVoiceTable.end()) {
                (*it)->keyOff();
            } else {
                std::cout << "Voice not found\n";
            }
        }
    
        void setGroup(bool group) { fGroupControl = group; }
        bool getGroup() { return fGroupControl; }

        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            if (checkPolyphony()) {
                int voice = getFreeVoice();
                fVoiceTable[voice]->keyOn(pitch, velocity, true);
                return fVoiceTable[voice];
            } else {
                return 0;
            }
        }

        void keyOff(int channel, int pitch, int velocity = 127)
        {
            if (checkPolyphony()) {
                int voice = getPlayingVoice(pitch);
                if (voice != kNoVoice) {
                    fVoiceTable[voice]->keyOff();
                } else {
                    std::cout << "Playing pitch = " << pitch << " not found\n";
                }
            }
        }

        void pitchWheel(int channel, int wheel)
        {}

        void ctrlChange(int channel, int ctrl, int value)
        {
            if (ctrl == ALL_NOTES_OFF || ctrl == ALL_SOUND_OFF) {
                allNotesOff();
            }
        }

        void progChange(int channel, int pgm)
        {}

        void keyPress(int channel, int pitch, int press)
        {}

        void chanPress(int channel, int press)
        {}

        void ctrlChange14bits(int channel, int ctrl, int value)
        {}

};

static std::string pathToContent(const std::string& path)
{
    std::ifstream file(path.c_str(), std::ifstream::binary);
    
    file.seekg(0, file.end);
    int size = int(file.tellg());
    file.seekg(0, file.beg);
    
    // And allocate buffer to that a single line can be read...
    char* buffer = new char[size + 1];
    file.read(buffer, size);
    
    // Terminate the string
    buffer[size] = 0;
    std::string result = buffer;
    file.close();
    delete [] buffer;
    return result;
}

/**
 * Polyphonic DSP with an integrated effect. fPolyDSP will respond to MIDI messages.
 */
class dsp_poly_effect : public dsp_poly {
    
    private:
        
        dsp_poly* fPolyDSP;
        
    public:
        
        dsp_poly_effect(dsp_poly* dsp1, dsp* dsp2)
        :dsp_poly(dsp2), fPolyDSP(dsp1)
        {}
        
        virtual ~dsp_poly_effect()
        {
            // dsp_poly_effect is also a decorator_dsp, which will free fPolyDSP
        }
        
        // MIDI API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            return fPolyDSP->keyOn(channel, pitch, velocity);
        }
        void keyOff(int channel, int pitch, int velocity)
        {
            fPolyDSP->keyOff(channel, pitch, velocity);
        }
        void keyPress(int channel, int pitch, int press)
        {
            fPolyDSP->keyPress(channel, pitch, press);
        }
        void chanPress(int channel, int press)
        {
            fPolyDSP->chanPress(channel, press);
        }
        void ctrlChange(int channel, int ctrl, int value)
        {
            fPolyDSP->ctrlChange(channel, ctrl, value);
        }
        void ctrlChange14bits(int channel, int ctrl, int value)
        {
            fPolyDSP->ctrlChange14bits(channel, ctrl, value);
        }
        void pitchWheel(int channel, int wheel)
        {
            fPolyDSP->pitchWheel(channel, wheel);
        }
        void progChange(int channel, int pgm)
        {
            fPolyDSP->progChange(channel, pgm);
        }
        
        // Group API
        void setGroup(bool group)
        {
            fPolyDSP->setGroup(group);
        }
        bool getGroup()
        {
            return fPolyDSP->getGroup();
        }
};

/**
 * Polyphonic DSP factory class. Helper code to support polyphonic DSP source with an integrated effect.
 */

struct dsp_poly_factory : public dsp_factory {
    
    dsp_factory* fProcessFactory;
    dsp_factory* fEffectFactory;
    
    std::string getEffectCode(const std::string& dsp_content)
    {
        std::stringstream effect_code;
        effect_code << "adapt(1,1) = _; adapt(2,2) = _,_; adapt(1,2) = _ <: _,_; adapt(2,1) = _,_ :> _;";
        effect_code << "adaptor(F,G) = adapt(outputs(F),inputs(G)); dsp_code = environment{ " << dsp_content << " };";
        effect_code << "process = adaptor(dsp_code.process, dsp_code.effect) : dsp_code.effect;";
        return effect_code.str();
    }

    dsp_poly_factory(dsp_factory* process_factory = NULL,
                     dsp_factory* effect_factory = NULL):
    fProcessFactory(process_factory)
    ,fEffectFactory(effect_factory)
    {}
    
    virtual ~dsp_poly_factory()
    {}
    
    virtual std::string getName() { return fProcessFactory->getName(); }
    virtual std::string getSHAKey() { return fProcessFactory->getSHAKey(); }
    virtual std::string getDSPCode() { return fProcessFactory->getDSPCode(); }
    virtual std::string getCompileOptions() { return fProcessFactory->getCompileOptions(); }
    virtual std::vector<std::string> getLibraryList() { return fProcessFactory->getLibraryList(); }
    virtual std::vector<std::string> getIncludePathnames() { return fProcessFactory->getIncludePathnames(); }
    
    virtual void setMemoryManager(dsp_memory_manager* manager)
    {
        fProcessFactory->setMemoryManager(manager);
        if (fEffectFactory) {
            fEffectFactory->setMemoryManager(manager);
        }
    }
    virtual dsp_memory_manager* getMemoryManager() { return fProcessFactory->getMemoryManager(); }
    
    /* Create a new polyphonic DSP instance with global effect, to be deleted with C++ 'delete'
     *
     * @param nvoices - number of polyphony voices
     * @param control - whether voices will be dynamically allocated and controlled (typically by a MIDI controler).
     *                If false all voices are always running.
     * @param group - if true, voices are not individually accessible, a global "Voices" tab will automatically dispatch
     *                a given control on all voices, assuming GUI::updateAllGuis() is called.
     *                If false, all voices can be individually controlled.
     */
    dsp_poly* createPolyDSPInstance(int nvoices, bool control, bool group)
    {
        dsp_poly* dsp_poly = new mydsp_poly(fProcessFactory->createDSPInstance(), nvoices, control, group);
        if (fEffectFactory) {
            // the 'dsp_poly' object has to be controlled with MIDI, so kept separated from new dsp_sequencer(...) object
            return new dsp_poly_effect(dsp_poly, new dsp_sequencer(dsp_poly, fEffectFactory->createDSPInstance()));
        } else {
            return new dsp_poly_effect(dsp_poly, dsp_poly);
        }
    }
    
    /* Create a new DSP instance, to be deleted with C++ 'delete' */
    dsp* createDSPInstance()
    {
        return fProcessFactory->createDSPInstance();
    }
    
};

#endif // __poly_dsp__
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2013 GRAME, Romain Michon, CCRMA - Stanford University
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __faust_engine__
#define __faust_engine__

#ifdef __cplusplus
extern "C" {
#endif

    void* create(int, int); // To be implemented
    void destroy(void*);

    bool start(void*);
    void stop(void*);
    
    bool isRunning(void*);

    unsigned long keyOn(void*, int, int);
    int keyOff(void*, int);
    
    void propagateMidi(void*, int, double, int, int, int, int);

    const char* getJSONUI(void*);
    const char* getJSONMeta(void*);

    int getParamsCount(void*);

    void setParamValue(void*, const char*, float);
    float getParamValue(void*, const char*);
    
    void setParamIdValue(void*, int, float);
    float getParamIdValue(void*, int);

    void setVoiceParamValue(void*, const char*, unsigned long, float);
    float getVoiceParamValue(void*, const char*, unsigned long);

    const char* getParamAddress(void*, int);

    void propagateAcc(void*, int, float);
    void setAccConverter(void*, int, int, int, float, float, float);

    void propagateGyr(void*, int, float);
    void setGyrConverter(void*, int, int, int, float, float, float);

    float getCPULoad(void*);
    int getScreenColor(void*);

#ifdef __cplusplus
}
#endif

#endif // __faust_engine__

//**************************************************************
// Mono or polyphonic audio DSP engine
//**************************************************************

using namespace std;

class FaustPolyEngine {
        
    protected:

        mydsp_poly* fPolyDSP;     // the polyphonic Faust object
        dsp* fFinalDSP;           // the "final" dsp object submitted to the audio driver
    
        APIUI fAPIUI;             // the UI description

        string fJSONUI;
        string fJSONMeta;
        bool fRunning;
        audio* fDriver;
    
        midi_handler fMidiHandler;
        MidiUI fMidiUI;
    
        void init(dsp* mono_dsp, audio* driver, midi_handler* midi)
        {
            bool midi_sync = false;
            int nvoices = 0;
            fRunning = false;
            
            MidiMeta::analyse(mono_dsp, midi_sync, nvoices);
            
            // Getting the UI JSON
            JSONUI jsonui1(mono_dsp->getNumInputs(), mono_dsp->getNumOutputs());
            mono_dsp->buildUserInterface(&jsonui1);
            fJSONUI = jsonui1.JSON();
            
            // Getting the metadata JSON
            JSONUI jsonui1M(mono_dsp->getNumInputs(), mono_dsp->getNumOutputs());
            mono_dsp->metadata(&jsonui1M);
            fJSONMeta = jsonui1M.JSON();
            
            if (fJSONUI.find("keyboard") != std::string::npos
                || fJSONUI.find("poly") != std::string::npos
                || nvoices > 0) {
                
                fPolyDSP = new mydsp_poly(mono_dsp, nvoices, true);
                fMidiHandler.addMidiIn(fPolyDSP);
                if (midi) midi->addMidiIn(fPolyDSP);
                
            #if POLY2
                fFinalDSP = new dsp_sequencer(fPolyDSP, new effect());
            #else
                fFinalDSP = fPolyDSP;
            #endif
                
                // Update JSONs with Poly version
                JSONUI jsonui2(mono_dsp->getNumInputs(), mono_dsp->getNumOutputs());
                fFinalDSP->buildUserInterface(&jsonui2);
                fJSONUI = jsonui2.JSON();
                JSONUI jsonui2M(mono_dsp->getNumInputs(), mono_dsp->getNumOutputs());
                fFinalDSP->metadata(&jsonui2M);
                fJSONMeta = jsonui2M.JSON();
                
            } else {
                fPolyDSP = NULL;
                fFinalDSP = mono_dsp;
            }
            
            fFinalDSP->buildUserInterface(&fMidiUI);
            fFinalDSP->buildUserInterface(&fAPIUI);
            
            // Retrieving DSP object name
            struct MyMeta : public Meta
            {
                string fName;
                void declare(const char* key, const char* value)
                {
                    if (strcmp(key, "name") == 0) fName = value;
                }
                MyMeta():fName("Dummy"){}
            };
      
            MyMeta meta;
            fFinalDSP->metadata(&meta);
            if (midi) midi->setName(meta.fName);
            
            // If driver cannot be initialized, start will fail later on...
            if (!driver->init(meta.fName.c_str(), fFinalDSP)) {
                delete driver;
                fDriver = NULL;
            } else {
                fDriver = driver;
            }
        }
    
    public:
    
        FaustPolyEngine(dsp* mono_dsp, audio* driver = NULL, midi_handler* midi = NULL):fMidiUI(&fMidiHandler)
        {
            init(((mono_dsp) ? mono_dsp : new mydsp()), driver, midi);
        }
    
        virtual ~FaustPolyEngine()
        {
            delete fDriver;
            delete fFinalDSP;
        }

        /*
         * start()
         * Begins the processing and return true if the connection
         * with the audio device was successful and false if not.
         */
        bool start()
        {
            if (!fRunning) {
                fRunning = (fDriver) ? fDriver->start() : false;
            }
            return fRunning;
        }
    
        /*
         * isRunning()
         * Returns true if the DSP frames are being computed and
         * false if not.
         */
        bool isRunning() 
        {
            return fRunning;
        }

        /*
         * stop()
         * Stops the processing, closes the audio engine.
         */
        void stop()
        {
            if (fRunning) {
                fRunning = false;
                fDriver->stop();
            }
        }
    
        void setGroup(bool group) { if (fPolyDSP) fPolyDSP->setGroup(group); }
        bool getGroup() { return (fPolyDSP) ? fPolyDSP->getGroup() : false; }
    
        /*
         * keyOn(pitch, velocity)
         * Instantiates a new polyphonic voice where velocity
         * and pitch are MIDI numbers (0-127). keyOn can only
         * be used if the [style:poly] metadata is used in the
         * Faust code. keyOn will return 0 if the object is not
         * polyphonic and the allocated voice otherwise.
         */
        MapUI* keyOn(int pitch, int velocity)
        {
            if (fPolyDSP) {
                return fPolyDSP->keyOn(0, pitch, velocity); // MapUI* passed to Java as an integer
            } else {
                return 0;
            }
        }

        /*
         * keyOff(pitch)
         * De-instantiates a polyphonic voice where pitch is the
         * MIDI number of the note (0-127). keyOff can only be
         * used if the [style:poly] metadata is used in the Faust
         * code. keyOn will return 0 if the object is not polyphonic
         * and 1 otherwise.
         */
        int keyOff(int pitch, int velocity = 127)
        {
            if (fPolyDSP) {
                fPolyDSP->keyOff(0, pitch, velocity);
                return 1;
            } else {
                return 0;
            }
        }

        /*
         * newVoice()
         * Instantiate a new voice and returns the corresponding mapUI.
         */
        MapUI* newVoice()
        {
            if (fPolyDSP) {
                return fPolyDSP->newVoice();
            } else {
                return 0;
            }
        }

        /*
         * deleteVoice(MapUI* voice)
         * Delete a voice based on its MapUI*.
         */
        int deleteVoice(MapUI* voice)
        {
            if (fPolyDSP) {
                fPolyDSP->deleteVoice(voice);
                return 1;
            } else {
                return 0;
            }
        }

        /*
         * deleteVoice(unsigned long voice)
         * Delete a voice based on its MapUI* casted as a unsigned long.
         */
        int deleteVoice(unsigned long voice)
        {
            return deleteVoice(reinterpret_cast<MapUI*>(voice));
        }
        
        /*
         * allNotesOff()
         * Gently terminates all the active voices.
         */
        void allNotesOff()
        {
            if (fPolyDSP) {
                fPolyDSP->allNotesOff();
            }
        }
    
        /*
         * Propagate MIDI data to the Faust object.
         */
        void propagateMidi(int count, double time, int type, int channel, int data1, int data2)
        {
            if (count == 3) fMidiHandler.handleData2(time, type, channel, data1, data2);
            else if (count == 2) fMidiHandler.handleData1(time, type, channel, data1);
            else if (count == 1) fMidiHandler.handleSync(time, type);
            GUI::updateAllGuis();
        }
    
        /*
         * getJSONUI()
         * Returns a string containing a JSON description of the
         * UI of the Faust object.
         */
        const char* getJSONUI()
        {
            return fJSONUI.c_str();
        }
        
        /*
         * getJSONMeta()
         * Returns a string containing a JSON description of the
         * metadata of the Faust object.
         */
        const char* getJSONMeta()
        {
            return fJSONMeta.c_str();
        }
    
        /*
         * buildUserInterface(ui)
         * Calls the polyphonic or monophonic buildUserInterface with the ui parameter.
         */
        void buildUserInterface(UI* ui_interface)
        {
            fFinalDSP->buildUserInterface(ui_interface);
        }

        /*
         * getParamsCount()
         * Returns the number of control parameters of the Faust object.
         */
        int getParamsCount()
        {
            return fAPIUI.getParamsCount();
        }
    
        /*
         * setParamValue(address, value)
         * Sets the value of the parameter associated with address.
         */
        void setParamValue(const char* address, float value)
        {
            int id = (address) ? fAPIUI.getParamIndex(address) : -1;
            if (id >= 0) {
                fAPIUI.setParamValue(id, value);
                // In POLY mode, update all voices
                GUI::updateAllGuis();
            }
        }

        /*
         * getParamValue(address)
         * Takes the address of a parameter and returns its current
         * value.
         */
        float getParamValue(const char* address)
        {
            int id = (address) ? fAPIUI.getParamIndex(address) : -1;
            return (id >= 0) ? fAPIUI.getParamValue(id) : 0.f;
        }
    
        /*
         * setParamValue(id, value)
         * Sets the value of the parameter associated with id.
         */
        void setParamValue(int id, float value)
        {
            fAPIUI.setParamValue(id, value);
            // In POLY mode, update all voices
            GUI::updateAllGuis();
        }
        
        /*
         * getParamValue(id)
         * Takes the id of a parameter and returns its current
         * value.
         */
        float getParamValue(int id)
        {
            return fAPIUI.getParamValue(id);
        }

        /*
         * setVoiceParamValue(address, voice, value)
         * Sets the value of the parameter associated with address for
         * the voice. setVoiceParamValue can only be
         * used if the [style:poly] metadata is used in the Faust code.
         */
        void setVoiceParamValue(const char* address, unsigned long voice, float value)
        {
            reinterpret_cast<MapUI*>(voice)->setParamValue(address, value);
        }

        /*
         * setVoiceParamValue(id, voice, value)
         * Sets the value of the parameter associated with the id for
         * the voice. setVoiceParamValue can only be
         * used if the [style:poly] metadata is used in the Faust code.
         */
        void setVoiceParamValue(int id, unsigned long voice, float value)
        {
            reinterpret_cast<MapUI*>(voice)->setParamValue(reinterpret_cast<MapUI*>(voice)->getParamAddress(id), value);
        }
    
        /*
         * getVoiceParamValue(address, voice)
         * Gets the parameter value associated with address for the voice.
         * getVoiceParamValue can only be used if the [style:poly] metadata
         * is used in the Faust code.
         */
        float getVoiceParamValue(const char* address, unsigned long voice)
        {
            return reinterpret_cast<MapUI*>(voice)->getParamValue(address);
        }

        /*
         * getVoiceParamValue(id, voice)
         * Gets the parameter value associated with the id for the voice.
         * getVoiceParamValue can only be used if the [style:poly] metadata
         * is used in the Faust code.
         */
        float getVoiceParamValue(int id, unsigned long voice)
        {
            return reinterpret_cast<MapUI*>(voice)->getParamValue(reinterpret_cast<MapUI*>(voice)->getParamAddress(id));
        }
    
        /*
         * getParamAddress(id)
         * Returns the address of a parameter in function of its "id".
         */
        const char* getParamAddress(int id)
        {
            return fAPIUI.getParamAddress(id);
        }

        /*
         * getVoiceParamAddress(id, voice)
         * Returns the address of a parameter for a specific voice 
         * in function of its "id".
         */
        const char* getVoiceParamAddress(int id, unsigned long voice)
        {
            return reinterpret_cast<MapUI*>(voice)->getParamAddress(id).c_str();
        }
        
        /*
         * getParamMin(address)
         * Returns the minimum value of a parameter.
         */
        float getParamMin(const char* address)
        {
            int id = (address) ? fAPIUI.getParamIndex(address) : -1;
            return (id >= 0) ? fAPIUI.getParamMin(id) : 0.f;
        }
    
        /*
         * getParamMin(id)
         * Returns the minimum value of a parameter.
         */
        float getParamMin(int id)
        {
            return fAPIUI.getParamMin(id);
        }
    
        /*
         * getParamMax(address)
         * Returns the maximum value of a parameter.
         */
        float getParamMax(const char* address)
        {
            int id = (address) ? fAPIUI.getParamIndex(address) : -1;
            return (id >= 0) ? fAPIUI.getParamMax(id) : 0.f;
        }
    
        /*
         * getParamMax(id)
         * Returns the maximum value of a parameter.
         */
        float getParamMax(int id)
        {
            return fAPIUI.getParamMax(id);
        }
    
        /*
         * getParamInit(address)
         * Returns the default value of a parameter.
         */
        float getParamInit(const char* address)
        {
            int id = (address) ? fAPIUI.getParamIndex(address) : -1;
            return (id >= 0) ? fAPIUI.getParamInit(id) : 0.f;
        }
    
        /*
         * getParamInit(id)
         * Returns the default value of a parameter.
         */
        float getParamInit(int id)
        {
            return fAPIUI.getParamInit(id);
        }
    
        /*
         * getMetadata(address, key)
         * Returns the metadata of a parameter.
         */
        const char* getMetadata(const char* address, const char* key)
        {
            int id = (address) ? fAPIUI.getParamIndex(address) : -1;
            return (id >= 0) ? fAPIUI.getMetadata(id, key) : "";
        }
    
        /*
         * getMetadata(id, key)
         * Returns the metadata of a parameter.
         */
        const char* getMetadata(int id, const char* key)
        {
            return fAPIUI.getMetadata(id, key);
        }

        /*
         * propagateAcc(int acc, float v)
         * Propage accelerometer value to the curve conversion layer.
         */
        void propagateAcc(int acc, float v)
        {
            fAPIUI.propagateAcc(acc, v);
            GUI::updateAllGuis();
        }

        /*
         * setAccConverter(int p, int acc, int curve, float amin, float amid, float amax)
         * Change accelerometer curve mapping.
         */
        void setAccConverter(int p, int acc, int curve, float amin, float amid, float amax)
        {
           fAPIUI.setAccConverter(p, acc, curve, amin, amid, amax);
        }

        /*
         * propagateGyr(int gyr, float v)
         * Propage gyroscope value to the curve conversion layer.
         */
        void propagateGyr(int gyr, float v)
        {
            fAPIUI.propagateGyr(gyr, v);
            GUI::updateAllGuis();
        }

        /*
         * setGyrConverter(int p, int acc, int curve, float amin, float amid, float amax)
         * Change gyroscope curve mapping.
         */
        void setGyrConverter(int p, int gyr, int curve, float amin, float amid, float amax)
        {
            fAPIUI.setGyrConverter(p, gyr, curve, amin, amid, amax);
        }
    
        /*
         * getCPULoad()
         * Return DSP CPU load.
         */
        float getCPULoad() { return (fDriver) ? fDriver->getCPULoad() : 0.f; }

        /*
         * getScreenColor() -> c:int
         * Get the requested screen color c :
         * c <  0 : no screen color requested (keep regular UI)
         * c >= 0 : requested color (no UI but a colored screen)
         */
        int getScreenColor()
        {
            return fAPIUI.getScreenColor();
        }

};

// Public C API

#ifdef __cplusplus
extern "C" {
#endif
    
    void destroy(void* dsp) { delete reinterpret_cast<FaustPolyEngine*>(dsp); }

    bool start(void* dsp) { return reinterpret_cast<FaustPolyEngine*>(dsp)->start(); }
    void stop(void* dsp) { reinterpret_cast<FaustPolyEngine*>(dsp)->stop(); }
    
    bool isRunning(void* dsp) { return reinterpret_cast<FaustPolyEngine*>(dsp)->isRunning(); }

    unsigned long keyOn(void* dsp, int pitch, int velocity) { return (unsigned long)reinterpret_cast<FaustPolyEngine*>(dsp)->keyOn(pitch, velocity); }
    int keyOff(void* dsp, int pitch) { return reinterpret_cast<FaustPolyEngine*>(dsp)->keyOff(pitch); }
    
    void propagateMidi(void* dsp, int count, double time, int type, int channel, int data1, int data2)
    {
        reinterpret_cast<FaustPolyEngine*>(dsp)->propagateMidi(count, time, type, channel, data1, data2);
    }

    const char* getJSONUI(void* dsp) { return reinterpret_cast<FaustPolyEngine*>(dsp)->getJSONUI(); }
    const char* getJSONMeta(void* dsp) { return reinterpret_cast<FaustPolyEngine*>(dsp)->getJSONMeta(); }

    int getParamsCount(void* dsp) { return reinterpret_cast<FaustPolyEngine*>(dsp)->getParamsCount(); }
    
    void setParamValue(void* dsp, const char* address, float value) { reinterpret_cast<FaustPolyEngine*>(dsp)->setParamValue(address, value); }
    float getParamValue(void* dsp, const char* address) { return reinterpret_cast<FaustPolyEngine*>(dsp)->getParamValue(address); }
   
    void setParamIdValue(void* dsp, int id, float value) { reinterpret_cast<FaustPolyEngine*>(dsp)->setParamValue(id, value); }
    float getParamIdValue(void* dsp, int id) { return reinterpret_cast<FaustPolyEngine*>(dsp)->getParamValue(id); }
    
    void setVoiceParamValue(void* dsp, const char* address, unsigned long voice, float value)
    {
        reinterpret_cast<FaustPolyEngine*>(dsp)->setVoiceParamValue(address, voice, value);
    }
    float getVoiceParamValue(void* dsp, const char* address, unsigned long voice) { return reinterpret_cast<FaustPolyEngine*>(dsp)->getVoiceParamValue(address, voice); }
    
    const char* getParamAddress(void* dsp, int id) { return reinterpret_cast<FaustPolyEngine*>(dsp)->getParamAddress(id); }

    void propagateAcc(void* dsp, int acc, float v)  { reinterpret_cast<FaustPolyEngine*>(dsp)->propagateAcc(acc, v); }
    void setAccConverter(void* dsp, int p, int acc, int curve, float amin, float amid, float amax)
    {
        reinterpret_cast<FaustPolyEngine*>(dsp)->setAccConverter(p, acc, curve, amin, amid, amax);
    }
    void propagateGyr(void* dsp, int acc, float v)  { reinterpret_cast<FaustPolyEngine*>(dsp)->propagateGyr(acc, v); }
    void setGyrConverter(void* dsp, int p, int gyr, int curve, float amin, float amid, float amax)
    {
        reinterpret_cast<FaustPolyEngine*>(dsp)->setGyrConverter(p, gyr, curve, amin, amid, amax);
    }

    float getCPULoad(void* dsp) { return reinterpret_cast<FaustPolyEngine*>(dsp)->getCPULoad(); }
    int getScreenColor(void* dsp) { return reinterpret_cast<FaustPolyEngine*>(dsp)->getScreenColor(); }
    
#ifdef __cplusplus
}
#endif

#endif // __faust_poly_engine__

//**************************************************************
// Audio driver
//**************************************************************

#if COREAUDIO_DRIVER
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __coreaudio_dsp__
#define __coreaudio_dsp__

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <sys/time.h>

#include <AudioToolbox/AudioConverter.h>
#include <CoreAudio/CoreAudio.h>
#include <AudioUnit/AudioUnit.h>
#include <CoreServices/CoreServices.h>


/******************************************************************************
*******************************************************************************

							COREAUDIO INTERNAL INTERFACE

*******************************************************************************
*******************************************************************************/

#define OPEN_ERR -1
#define CLOSE_ERR -1
#define NO_ERR 0

#define WAIT_NOTIFICATION_COUNTER 60

typedef	UInt8	CAAudioHardwareDeviceSectionID;
#define	kAudioDeviceSectionInput	((CAAudioHardwareDeviceSectionID)0x01)
#define	kAudioDeviceSectionOutput	((CAAudioHardwareDeviceSectionID)0x00)
#define	kAudioDeviceSectionGlobal	((CAAudioHardwareDeviceSectionID)0x00)
#define	kAudioDeviceSectionWildcard	((CAAudioHardwareDeviceSectionID)0xFF)

class TCoreAudioRenderer;
typedef TCoreAudioRenderer* TCoreAudioRendererPtr;

static void PrintStreamDesc(AudioStreamBasicDescription *inDesc)
{
    printf("- - - - - - - - - - - - - - - - - - - -\n");
    printf("  Sample Rate:%f\n", inDesc->mSampleRate);
    printf("  Format ID:%.*s\n", (int)sizeof(inDesc->mFormatID), (char*)&inDesc->mFormatID);
    printf("  Format Flags:%lX\n", (unsigned long)inDesc->mFormatFlags);
    printf("  Bytes per Packet:%ld\n", (long)inDesc->mBytesPerPacket);
    printf("  Frames per Packet:%ld\n", (long)inDesc->mFramesPerPacket);
    printf("  Bytes per Frame:%ld\n", (long)inDesc->mBytesPerFrame);
    printf("  Channels per Frame:%ld\n", (long)inDesc->mChannelsPerFrame);
    printf("  Bits per Channel:%ld\n", (long)inDesc->mBitsPerChannel);
    printf("- - - - - - - - - - - - - - - - - - - -\n");
}

static void printError(OSStatus err)
{
    switch (err) {
        case kAudioHardwareNoError:
            printf("error code : kAudioHardwareNoError\n");
            break;
		case kAudioConverterErr_FormatNotSupported:
            printf("error code : kAudioConverterErr_FormatNotSupported\n");
            break;
        case kAudioConverterErr_OperationNotSupported:
            printf("error code : kAudioConverterErr_OperationNotSupported\n");
            break;
        case kAudioConverterErr_PropertyNotSupported:
            printf("error code : kAudioConverterErr_PropertyNotSupported\n");
            break;
        case kAudioConverterErr_InvalidInputSize:
            printf("error code : kAudioConverterErr_InvalidInputSize\n");
            break;
        case kAudioConverterErr_InvalidOutputSize:
            printf("error code : kAudioConverterErr_InvalidOutputSize\n");
            break;
        case kAudioConverterErr_UnspecifiedError:
            printf("error code : kAudioConverterErr_UnspecifiedError\n");
            break;
        case kAudioConverterErr_BadPropertySizeError:
            printf("error code : kAudioConverterErr_BadPropertySizeError\n");
            break;
        case kAudioConverterErr_RequiresPacketDescriptionsError:
            printf("error code : kAudioConverterErr_RequiresPacketDescriptionsError\n");
            break;
        case kAudioConverterErr_InputSampleRateOutOfRange:
            printf("error code : kAudioConverterErr_InputSampleRateOutOfRange\n");
            break;
        case kAudioConverterErr_OutputSampleRateOutOfRange:
            printf("error code : kAudioConverterErr_OutputSampleRateOutOfRange\n");
            break;
		case kAudioHardwareNotRunningError:
            printf("error code : kAudioHardwareNotRunningError\n");
            break;
        case kAudioHardwareUnknownPropertyError:
            printf("error code : kAudioHardwareUnknownPropertyError\n");
            break;
        case kAudioHardwareIllegalOperationError:
            printf("error code : kAudioHardwareIllegalOperationError\n");
            break;
        case kAudioHardwareBadDeviceError:
            printf("error code : kAudioHardwareBadDeviceError\n");
            break;
        case kAudioHardwareBadStreamError:
            printf("error code : kAudioHardwareBadStreamError\n");
            break;
        case kAudioDeviceUnsupportedFormatError:
            printf("error code : kAudioDeviceUnsupportedFormatError\n");
            break;
        case kAudioDevicePermissionsError:
            printf("error code : kAudioDevicePermissionsError\n");
            break;
        default:
            printf("error code : err = %d\n", err);
            break;
    }
}

static Float64 GetNominalSampleRate(AudioDeviceID inDevice) 
{
    Float64 sampleRate = 0;
    UInt32 outSize =  sizeof(Float64);
    OSStatus err = AudioDeviceGetProperty(inDevice, 0, kAudioDeviceSectionGlobal, kAudioDevicePropertyNominalSampleRate, &outSize, &sampleRate);
    if (err != noErr) {
        printf("Cannot get current sample rate\n");
        printError(err);
        return -1;
    } else {
        return sampleRate;
    }
}

static CFStringRef GetDeviceName(AudioDeviceID id)
{
    UInt32 size = sizeof(CFStringRef);
    CFStringRef UIname;
    OSStatus err = AudioDeviceGetProperty(id, 0, false, kAudioDevicePropertyDeviceUID, &size, &UIname);
    return (err == noErr) ? UIname : NULL;
}

static bool CheckAvailableDeviceName(const char* device_name, AudioDeviceID* device_id, int len = -1)
{
    UInt32 size;
    Boolean isWritable;
    int i, deviceNum;
    OSStatus err;

    err = AudioHardwareGetPropertyInfo(kAudioHardwarePropertyDevices, &size, &isWritable);
    if (err != noErr) {
        return false;
    }

    deviceNum = size / sizeof(AudioDeviceID);
    AudioDeviceID devices[deviceNum];
 
    err = AudioHardwareGetProperty(kAudioHardwarePropertyDevices, &size, devices);
    if (err != noErr) {
        return false;
    }

    for (i = 0; i < deviceNum; i++) {
        char device_name_aux[256];
    
        size = 256;
        err = AudioDeviceGetProperty(devices[i], 0, false, kAudioDevicePropertyDeviceName, &size, device_name_aux);
        if (err != noErr) {
            return false;
        }
 
        if (strncmp(device_name_aux, device_name, (len == -1) ? strlen(device_name) : len) == 0) {
            *device_id = devices[i];
            return true;
        }
    }

    return false;
}

class TCoreAudioRenderer
{
    
    protected:
    
        AudioDeviceID fAggregateDeviceID;
        AudioObjectID fAggregatePluginID;    // Used for aggregate device
     
        int fDevNumInChans;
        int fDevNumOutChans;
        
        int fPhysicalInputs;
        int fPhysicalOutputs;
        
        float** fInChannel;
        float** fOutChannel;

        int fBufferSize;
        int fSampleRate;
    
        bool fIsInJackDevice;
        bool fIsOutJackDevice;
        
        dsp* fDSP;

        AudioBufferList* fInputData;
        AudioDeviceID fDeviceID;
        AudioUnit fAUHAL;
        bool fState;
    
        compute_callback fControlCb;
        void* fControlCbArg;

        OSStatus GetDefaultDeviceAndSampleRate(int inChan, int outChan, int& sample_rate, AudioDeviceID* device)
        {
            
            UInt32 theSize = sizeof(UInt32);
            AudioDeviceID inDefault;
            AudioDeviceID outDefault;
            OSStatus res;
            
            if ((res = AudioHardwareGetProperty(kAudioHardwarePropertyDefaultInputDevice,
                                                &theSize, &inDefault)) != noErr) {
                return res;
            }
            
            if ((res = AudioHardwareGetProperty(kAudioHardwarePropertyDefaultOutputDevice,
                                                &theSize, &outDefault)) != noErr) {
                return res;
            }
            
            /*
            // TODO
            if (inDefault == 0) {
                printf("Error default input device is 0, will take 'Built-in'...\n");
                if (CheckAvailableDeviceName("Built-in Microphone", &inDefault) 
                    || CheckAvailableDeviceName("Built-in Line", &inDefault)) {
                    printf("GetDefaultInputDevice : output = %ld\n", inDefault);
                } else {
                    printf("Cannot find any input device to use...");
                    return -1;
                }
            }
            
            if (outDefault == 0) {
                printf("Error default ouput device is 0, will take 'Built-in'...\n");
                if (CheckAvailableDeviceName("Built-in Output", &outDefault)) {
                    printf("GetDefaultOutputDevice : output = %ld\n", outDefault);
                } else {
                    printf("Cannot find any output device to use...\n");
                    return -1;
                }
            }  
            */          
            
            //printf("GetDefaultDevice : input = %d output = %d\n", inDefault, outDefault);
            
            // Duplex mode
            if (inChan > 0 && outChan > 0) {
                // Get the device only if default input and output are the same
                if (inDefault == outDefault) {
                    *device = inDefault;
                    goto end;
                } else {
                    if (CreateAggregateDevice(inDefault, outDefault, sample_rate) != noErr) {
                        return kAudioHardwareBadDeviceError;
                    }
                    //printf("fAggregateDeviceID %d\n", fAggregateDeviceID);
                    *device = fAggregateDeviceID;
                    goto end;
                }
            } else if (inChan > 0) {
                *device = inDefault;
                goto end;
            } else if (outChan > 0) {
                *device = outDefault;
                goto end;
            } else {
                return kAudioHardwareBadDeviceError;
            }
            
        end:   
            
            if (sample_rate == -1) {
                // Possible take the current sample rate
                sample_rate = int(GetNominalSampleRate(*device));
            } else {
                // Otherwise force the one we want...
                SetupSampleRateAux(*device, sample_rate);
            }
            //printf("samplerate %d\n", sample_rate);
            fSampleRate = sample_rate;
            return noErr;
        }

        OSStatus CreateAggregateDevice(AudioDeviceID captureDeviceID, AudioDeviceID playbackDeviceID, int& sample_rate)
        {
            OSStatus err = noErr;
            AudioObjectID sub_device[32];
            UInt32 outSize = sizeof(sub_device);
            
            //printf("CreateAggregateDevice : input device %d\n", captureDeviceID);
            
            err = AudioDeviceGetProperty(captureDeviceID, 0, kAudioDeviceSectionGlobal, kAudioAggregateDevicePropertyActiveSubDeviceList, &outSize, sub_device);
            std::vector<AudioDeviceID> captureDeviceIDArray;
            
            if (err != noErr) {
                //printf("Input device does not have subdevices\n");
                captureDeviceIDArray.push_back(captureDeviceID);
            } else {
                int num_devices = outSize / sizeof(AudioObjectID);
                //printf("Input device has %d subdevices\n", num_devices);
                for (int i = 0; i < num_devices; i++) {
                    //printf("Input sub_device %d\n", sub_device[i]);
                    captureDeviceIDArray.push_back(sub_device[i]);
                }
            }
            
            outSize = sizeof(sub_device);
            err = AudioDeviceGetProperty(playbackDeviceID, 0, kAudioDeviceSectionGlobal, kAudioAggregateDevicePropertyActiveSubDeviceList, &outSize, sub_device);
            std::vector<AudioDeviceID> playbackDeviceIDArray;
            
            if (err != noErr) {
                //printf("Output device does not have subdevices\n");
                playbackDeviceIDArray.push_back(playbackDeviceID);
            } else {
                int num_devices = outSize / sizeof(AudioObjectID);
                //printf("Output device has %d subdevices\n", num_devices);
                for (int i = 0; i < num_devices; i++) {
                    //printf("Output sub_device %d\n", sub_device[i]);
                    playbackDeviceIDArray.push_back(sub_device[i]);
                }
            }
            
            return CreateAggregateDeviceAux(captureDeviceIDArray, playbackDeviceIDArray, sample_rate);
        }
        
        OSStatus CreateAggregateDeviceAux(std::vector<AudioDeviceID> captureDeviceID, std::vector<AudioDeviceID> playbackDeviceID, int& sample_rate)
        {
            OSStatus osErr = noErr;
            UInt32 outSize;
            Boolean outWritable;
            bool fClockDriftCompensate = true;
            
            // Prepare sub-devices for clock drift compensation
            // Workaround for bug in the HAL : until 10.6.2
            AudioObjectPropertyAddress theAddressOwned = { kAudioObjectPropertyOwnedObjects, kAudioObjectPropertyScopeGlobal, kAudioObjectPropertyElementMaster };
            AudioObjectPropertyAddress theAddressDrift = { kAudioSubDevicePropertyDriftCompensation, kAudioObjectPropertyScopeGlobal, kAudioObjectPropertyElementMaster };
            UInt32 theQualifierDataSize = sizeof(AudioObjectID);
            AudioClassID inClass = kAudioSubDeviceClassID;
            void* theQualifierData = &inClass;
            UInt32 subDevicesNum = 0;
            
            //---------------------------------------------------------------------------
            // Setup SR of both devices otherwise creating AD may fail...
            //---------------------------------------------------------------------------
            UInt32 keptclockdomain = 0;
            UInt32 clockdomain = 0;
            outSize = sizeof(UInt32);
            bool need_clock_drift_compensation = false;
            
            for (UInt32 i = 0; i < captureDeviceID.size(); i++) {
                if (SetupSampleRateAux(captureDeviceID[i], sample_rate) < 0) {
                    printf("TCoreAudioRenderer::CreateAggregateDeviceAux : cannot set SR of input device\n");
                } else  {
                    // Check clock domain
                    osErr = AudioDeviceGetProperty(captureDeviceID[i], 0, kAudioDeviceSectionGlobal, kAudioDevicePropertyClockDomain, &outSize, &clockdomain);
                    if (osErr != 0) {
                        printf("TCoreAudioRenderer::CreateAggregateDeviceAux : kAudioDevicePropertyClockDomain error\n");
                        printError(osErr);
                    } else {
                        keptclockdomain = (keptclockdomain == 0) ? clockdomain : keptclockdomain;
                        //printf("TCoreAudioRenderer::CreateAggregateDevice : input clockdomain = %d\n", clockdomain);
                        if (clockdomain != 0 && clockdomain != keptclockdomain) {
                            //printf("TCoreAudioRenderer::CreateAggregateDevice : devices do not share the same clock!! clock drift compensation would be needed...\n");
                            need_clock_drift_compensation = true;
                        }
                    }
                }
            }
            
            for (UInt32 i = 0; i < playbackDeviceID.size(); i++) {
                if (SetupSampleRateAux(playbackDeviceID[i], sample_rate) < 0) {
                    printf("TCoreAudioRenderer::CreateAggregateDeviceAux : cannot set SR of output device\n");
                } else {
                    // Check clock domain
                    osErr = AudioDeviceGetProperty(playbackDeviceID[i], 0, kAudioDeviceSectionGlobal, kAudioDevicePropertyClockDomain, &outSize, &clockdomain);
                    if (osErr != 0) {
                        printf("TCoreAudioRenderer::CreateAggregateDeviceAux : kAudioDevicePropertyClockDomain error\n");
                        printError(osErr);
                    } else {
                        keptclockdomain = (keptclockdomain == 0) ? clockdomain : keptclockdomain;
                        //printf("TCoreAudioRenderer::CreateAggregateDevice : output clockdomain = %d", clockdomain);
                        if (clockdomain != 0 && clockdomain != keptclockdomain) {
                            //printf("TCoreAudioRenderer::CreateAggregateDevice : devices do not share the same clock!! clock drift compensation would be needed...\n");
                            need_clock_drift_compensation = true;
                        }
                    }
                }
            }
            
            // If no valid clock domain was found, then assume we have to compensate...
            if (keptclockdomain == 0) {
                need_clock_drift_compensation = true;
            }
            
            //---------------------------------------------------------------------------
            // Start to create a new aggregate by getting the base audio hardware plugin
            //---------------------------------------------------------------------------
            
            char device_name[256];
            for (UInt32 i = 0; i < captureDeviceID.size(); i++) {
                GetDeviceNameFromID(captureDeviceID[i], device_name);
                //printf("Separated input = '%s' \n", device_name);
            }
            
            for (UInt32 i = 0; i < playbackDeviceID.size(); i++) {
                GetDeviceNameFromID(playbackDeviceID[i], device_name);
                //printf("Separated output = '%s' \n", device_name);
            }
            
            osErr = AudioHardwareGetPropertyInfo(kAudioHardwarePropertyPlugInForBundleID, &outSize, &outWritable);
            if (osErr != noErr) {
                printf("TCoreAudioRenderer::CreateAggregateDeviceAux : AudioHardwareGetPropertyInfo kAudioHardwarePropertyPlugInForBundleID error\n");
                printError(osErr);
                return osErr;
            }
            
            AudioValueTranslation pluginAVT;
            CFStringRef inBundleRef = CFSTR("com.apple.audio.CoreAudio");
            
            pluginAVT.mInputData = &inBundleRef;
            pluginAVT.mInputDataSize = sizeof(inBundleRef);
            pluginAVT.mOutputData = &fAggregatePluginID;
            pluginAVT.mOutputDataSize = sizeof(fAggregatePluginID);
            
            osErr = AudioHardwareGetProperty(kAudioHardwarePropertyPlugInForBundleID, &outSize, &pluginAVT);
            if (osErr != noErr) {
                printf("TCoreAudioRenderer::CreateAggregateDeviceAux : AudioHardwareGetProperty kAudioHardwarePropertyPlugInForBundleID error\n");
                printError(osErr);
                return osErr;
            }
            
            //-------------------------------------------------
            // Create a CFDictionary for our aggregate device
            //-------------------------------------------------
            
            CFMutableDictionaryRef aggDeviceDict = CFDictionaryCreateMutable(NULL, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
            
            char buffer1[64];
            char buffer2[64];
            
            // generate "random" name
            struct timeval fTv1;
            struct timezone tz;
            gettimeofday(&fTv1, &tz);
            
            sprintf(buffer1, "com.grame.%d", fTv1.tv_sec + fTv1.tv_usec);
            sprintf(buffer2, "%d", fTv1.tv_sec + fTv1.tv_usec);
            
            CFStringRef AggregateDeviceNameRef = CFStringCreateWithCString(kCFAllocatorDefault, buffer1, CFStringGetSystemEncoding());
            CFStringRef AggregateDeviceUIDRef = CFStringCreateWithCString(kCFAllocatorDefault, buffer2, CFStringGetSystemEncoding());
            
            // add the name of the device to the dictionary
            CFDictionaryAddValue(aggDeviceDict, CFSTR(kAudioAggregateDeviceNameKey), AggregateDeviceNameRef);
            
            // add our choice of UID for the aggregate device to the dictionary
            CFDictionaryAddValue(aggDeviceDict, CFSTR(kAudioAggregateDeviceUIDKey), AggregateDeviceUIDRef);
            
            // add a "private aggregate key" to the dictionary
            int value = 1;
            CFNumberRef AggregateDeviceNumberRef = CFNumberCreate(NULL, kCFNumberIntType, &value);
            
            SInt32 system;
            Gestalt(gestaltSystemVersion, &system);
            
            //printf("TCoreAudioRenderer::CreateAggregateDevice : system version = %x limit = %x\n", system, 0x00001054);
            
            // Starting with 10.5.4 systems, the AD can be internal... (better)
            if (system < 0x00001054) {
                //printf("TCoreAudioRenderer::CreateAggregateDevice : public aggregate device....\n");
            } else {
                //printf("TCoreAudioRenderer::CreateAggregateDevice : private aggregate device....\n");
                CFDictionaryAddValue(aggDeviceDict, CFSTR(kAudioAggregateDeviceIsPrivateKey), AggregateDeviceNumberRef);
            }
            
            // Prepare sub-devices for clock drift compensation
            CFMutableArrayRef subDevicesArrayClock = NULL;
            
            /*
             if (fClockDriftCompensate) {
                 if (need_clock_drift_compensation) {
                     jack_info("Clock drift compensation activated...");
                     subDevicesArrayClock = CFArrayCreateMutable(NULL, 0, &kCFTypeArrayCallBacks);
                     
                     for (UInt32 i = 0; i < captureDeviceID.size(); i++) {
                         CFStringRef UID = GetDeviceName(captureDeviceID[i]);
                         if (UID) {
                         CFMutableDictionaryRef subdeviceAggDeviceDict = CFDictionaryCreateMutable(NULL, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
                         CFDictionaryAddValue(subdeviceAggDeviceDict, CFSTR(kAudioSubDeviceUIDKey), UID);
                         CFDictionaryAddValue(subdeviceAggDeviceDict, CFSTR(kAudioSubDeviceDriftCompensationKey), AggregateDeviceNumberRef);
                         //CFRelease(UID);
                         CFArrayAppendValue(subDevicesArrayClock, subdeviceAggDeviceDict);
                     }
                 }
                 
                 for (UInt32 i = 0; i < playbackDeviceID.size(); i++) {
                     CFStringRef UID = GetDeviceName(playbackDeviceID[i]);
                     if (UID) {
                         CFMutableDictionaryRef subdeviceAggDeviceDict = CFDictionaryCreateMutable(NULL, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
                         CFDictionaryAddValue(subdeviceAggDeviceDict, CFSTR(kAudioSubDeviceUIDKey), UID);
                         CFDictionaryAddValue(subdeviceAggDeviceDict, CFSTR(kAudioSubDeviceDriftCompensationKey), AggregateDeviceNumberRef);
                         //CFRelease(UID);
                         CFArrayAppendValue(subDevicesArrayClock, subdeviceAggDeviceDict);
                     }
                 }
                     
                     // add sub-device clock array for the aggregate device to the dictionary
                     CFDictionaryAddValue(aggDeviceDict, CFSTR(kAudioAggregateDeviceSubDeviceListKey), subDevicesArrayClock);
                     } else {
                     jack_info("Clock drift compensation was asked but is not needed (devices use the same clock domain)");
                 }
            }
            */
            
            //-------------------------------------------------
            // Create a CFMutableArray for our sub-device list
            //-------------------------------------------------
            
            // we need to append the UID for each device to a CFMutableArray, so create one here
            CFMutableArrayRef subDevicesArray = CFArrayCreateMutable(NULL, 0, &kCFTypeArrayCallBacks);
            
            std::vector<CFStringRef> captureDeviceUID;
            for (UInt32 i = 0; i < captureDeviceID.size(); i++) {
                CFStringRef ref = GetDeviceName(captureDeviceID[i]);
                if (ref == NULL) {
                    return -1;
                }
                captureDeviceUID.push_back(ref);
                // input sub-devices in this example, so append the sub-device's UID to the CFArray
                CFArrayAppendValue(subDevicesArray, ref);
            }
            
            std::vector<CFStringRef> playbackDeviceUID;
            for (UInt32 i = 0; i < playbackDeviceID.size(); i++) {
                CFStringRef ref = GetDeviceName(playbackDeviceID[i]);
                if (ref == NULL) {
                    return -1;
                }
                playbackDeviceUID.push_back(ref);
                // output sub-devices in this example, so append the sub-device's UID to the CFArray
                CFArrayAppendValue(subDevicesArray, ref);
            }
            
            //-----------------------------------------------------------------------
            // Feed the dictionary to the plugin, to create a blank aggregate device
            //-----------------------------------------------------------------------
            
            AudioObjectPropertyAddress pluginAOPA;
            pluginAOPA.mSelector = kAudioPlugInCreateAggregateDevice;
            pluginAOPA.mScope = kAudioObjectPropertyScopeGlobal;
            pluginAOPA.mElement = kAudioObjectPropertyElementMaster;
            UInt32 outDataSize;
            
            osErr = AudioObjectGetPropertyDataSize(fAggregatePluginID, &pluginAOPA, 0, NULL, &outDataSize);
            if (osErr != noErr) {
                printf("TCoreAudioRenderer::CreateAggregateDeviceAux : AudioObjectGetPropertyDataSize error\n");
                printError(osErr);
                goto error;
            }
            
            osErr = AudioObjectGetPropertyData(fAggregatePluginID, &pluginAOPA, sizeof(aggDeviceDict), &aggDeviceDict, &outDataSize, &fAggregateDeviceID);
            if (osErr != noErr) {
                printf("TCoreAudioRenderer::CreateAggregateDeviceAux : AudioObjectGetPropertyData error\n");
                printError(osErr);
                goto error;
            }
            
            // pause for a bit to make sure that everything completed correctly
            // this is to work around a bug in the HAL where a new aggregate device seems to disappear briefly after it is created
            CFRunLoopRunInMode(kCFRunLoopDefaultMode, 0.1, false);
            
            //-------------------------
            // Set the sub-device list
            //-------------------------
            
            pluginAOPA.mSelector = kAudioAggregateDevicePropertyFullSubDeviceList;
            pluginAOPA.mScope = kAudioObjectPropertyScopeGlobal;
            pluginAOPA.mElement = kAudioObjectPropertyElementMaster;
            outDataSize = sizeof(CFMutableArrayRef);
            osErr = AudioObjectSetPropertyData(fAggregateDeviceID, &pluginAOPA, 0, NULL, outDataSize, &subDevicesArray);
            if (osErr != noErr) {
                printf("TCoreAudioRenderer::CreateAggregateDeviceAux : AudioObjectSetPropertyData for sub-device list error\n");
                printError(osErr);
                goto error;
            }
            
            // pause again to give the changes time to take effect
            CFRunLoopRunInMode(kCFRunLoopDefaultMode, 0.1, false);
            
            //-----------------------
            // Set the master device
            //-----------------------
            
            // set the master device manually (this is the device which will act as the master clock for the aggregate device)
            // pass in the UID of the device you want to use
            pluginAOPA.mSelector = kAudioAggregateDevicePropertyMasterSubDevice;
            pluginAOPA.mScope = kAudioObjectPropertyScopeGlobal;
            pluginAOPA.mElement = kAudioObjectPropertyElementMaster;
            outDataSize = sizeof(CFStringRef);
            osErr = AudioObjectSetPropertyData(fAggregateDeviceID, &pluginAOPA, 0, NULL, outDataSize, &playbackDeviceUID[0]);  // First playback is master...
            if (osErr != noErr) {
                printf("TCoreAudioRenderer::CreateAggregateDeviceAux : AudioObjectSetPropertyData for master device error\n");
                printError(osErr);
                goto error;
            }
            
            // pause again to give the changes time to take effect
            CFRunLoopRunInMode(kCFRunLoopDefaultMode, 0.1, false);
            
            // Prepare sub-devices for clock drift compensation
            // Workaround for bug in the HAL : until 10.6.2
            
            if (fClockDriftCompensate) {
                if (need_clock_drift_compensation) {
                    //printf("Clock drift compensation activated...\n");
                    
                    // Get the property data size
                    osErr = AudioObjectGetPropertyDataSize(fAggregateDeviceID, &theAddressOwned, theQualifierDataSize, theQualifierData, &outSize);
                    if (osErr != noErr) {
                        printf("TCoreAudioRenderer::CreateAggregateDeviceAux kAudioObjectPropertyOwnedObjects error\n");
                        printError(osErr);
                    }
                    
                    //	Calculate the number of object IDs
                    subDevicesNum = outSize / sizeof(AudioObjectID);
                    //printf("TCoreAudioRenderer::CreateAggregateDevice clock drift compensation, number of sub-devices = %d\n", subDevicesNum);
                    AudioObjectID subDevices[subDevicesNum];
                    outSize = sizeof(subDevices);
                    
                    osErr = AudioObjectGetPropertyData(fAggregateDeviceID, &theAddressOwned, theQualifierDataSize, theQualifierData, &outSize, subDevices);
                    if (osErr != noErr) {
                        printf("TCoreAudioRenderer::CreateAggregateDeviceAux kAudioObjectPropertyOwnedObjects error\n");
                        printError(osErr);
                    }
                    
                    // Set kAudioSubDevicePropertyDriftCompensation property...
                    for (UInt32 index = 0; index < subDevicesNum; ++index) {
                        UInt32 theDriftCompensationValue = 1;
                        osErr = AudioObjectSetPropertyData(subDevices[index], &theAddressDrift, 0, NULL, sizeof(UInt32), &theDriftCompensationValue);
                        if (osErr != noErr) {
                            printf("TCoreAudioRenderer::CreateAggregateDeviceAux kAudioSubDevicePropertyDriftCompensation error\n");
                            printError(osErr);
                        }
                    }
                } else {
                    //printf("Clock drift compensation was asked but is not needed (devices use the same clock domain)\n");
                }
            }
            
            // pause again to give the changes time to take effect
            CFRunLoopRunInMode(kCFRunLoopDefaultMode, 0.1, false);
            
            //----------
            // Clean up
            //----------
            
            // release the private AD key
            CFRelease(AggregateDeviceNumberRef);
            
            // release the CF objects we have created - we don't need them any more
            CFRelease(aggDeviceDict);
            CFRelease(subDevicesArray);
            
            if (subDevicesArrayClock)
                CFRelease(subDevicesArrayClock);
            
            // release the device UID
            for (UInt32 i = 0; i < captureDeviceUID.size(); i++) {
                CFRelease(captureDeviceUID[i]);
            }
            
            for (UInt32 i = 0; i < playbackDeviceUID.size(); i++) {
                CFRelease(playbackDeviceUID[i]);
            }
            
            //printf("New aggregate device %d\n", fAggregateDeviceID);
            return noErr;
            
        error:
            DestroyAggregateDevice();
            return -1;
        }

        void DestroyAggregateDevice()
        {   
            if (fAggregateDeviceID > 0) {
                OSStatus osErr = noErr;
                AudioObjectPropertyAddress pluginAOPA;
                pluginAOPA.mSelector = kAudioPlugInDestroyAggregateDevice;
                pluginAOPA.mScope = kAudioObjectPropertyScopeGlobal;
                pluginAOPA.mElement = kAudioObjectPropertyElementMaster;
                UInt32 outDataSize;
                if (fAggregatePluginID > 0)   {
                    osErr = AudioObjectGetPropertyDataSize(fAggregatePluginID, &pluginAOPA, 0, NULL, &outDataSize);
                    if (osErr != noErr) {
                        //printf("TCoreAudioRenderer::DestroyAggregateDevice : AudioObjectGetPropertyDataSize error\n");
                        //printError(osErr);
                    }
                    osErr = AudioObjectGetPropertyData(fAggregatePluginID, &pluginAOPA, 0, NULL, &outDataSize, &fAggregateDeviceID);
                    if (osErr != noErr) {
                        //printf("TCoreAudioRenderer::DestroyAggregateDevice : AudioObjectGetPropertyData error\n");
                        //printError(osErr);
                    }
                }
            }
        }

        OSStatus GetDeviceNameFromID(AudioDeviceID id, char* name)
        {
            UInt32 size = 256;
            return AudioDeviceGetProperty(id, 0, false, kAudioDevicePropertyDeviceName, &size, name);
        }
        
        int SetupBufferSize(int buffer_size)
        {
            // Setting buffer size
            OSStatus err = noErr;
            UInt32 current_buffer_size = buffer_size;
            UInt32 outSize; 
            AudioValueRange buffer_size_range;
            
            outSize = sizeof(AudioValueRange);
            err = AudioDeviceGetProperty(fDeviceID, 0, true, kAudioDevicePropertyBufferFrameSizeRange, &outSize, &buffer_size_range);
            if (err != noErr) {
                printf("Cannot get buffer size range\n");
                printError(err);
                return -1;
            } else {
                //printf("SetupBufferSize : buffer size range min = %ld max = %ld\n", (int)buffer_size_range.mMinimum, (int)buffer_size_range.mMaximum);
            }
            
            outSize = sizeof(UInt32);
            err = AudioDeviceGetProperty(fDeviceID, 0, kAudioDeviceSectionGlobal, kAudioDevicePropertyBufferFrameSize, &outSize, &current_buffer_size);
            if (err != noErr) {
                printf("Cannot get buffer size\n");
                printError(err);
                return -1;
            } else {
                //printf("SetupBufferSize : current buffer size %ld\n", current_buffer_size);
            }

            // If needed, set new buffer size
            if (buffer_size != current_buffer_size && buffer_size >= (int)buffer_size_range.mMinimum && buffer_size <= (int)buffer_size_range.mMaximum) {
                current_buffer_size = buffer_size;

                // To get BS change notification
                err = AudioDeviceAddPropertyListener(fDeviceID, 0, true, kAudioDevicePropertyBufferFrameSize, BSNotificationCallback, this);
                if (err != noErr) {
                    printf("Error calling AudioDeviceAddPropertyListener with kAudioDevicePropertyBufferFrameSize\n");
                    printError(err);
                    return -1;
                }

                // Waiting for BS change notification
                int count = 0;
                fState = false;

                err = AudioDeviceSetProperty(fDeviceID, NULL, 0, kAudioDeviceSectionGlobal, kAudioDevicePropertyBufferFrameSize, outSize, &current_buffer_size);
                if (err != noErr) {
                    printf("SetupBufferSize : cannot set buffer size = %ld\n", current_buffer_size);
                    printError(err);
                    goto error;
                }

                while (!fState && count++ < WAIT_NOTIFICATION_COUNTER) {
                    usleep(100000);
                    //printf("SetupBufferSize : wait count = %d\n", count);
                }

                if (count >= WAIT_NOTIFICATION_COUNTER) {
                    printf("Did not get buffer size notification...\n");
                    goto error;
                }

                // Check new buffer size
                outSize = sizeof(UInt32);
                err = AudioDeviceGetProperty(fDeviceID, 0, kAudioDeviceSectionGlobal, kAudioDevicePropertyBufferFrameSize, &outSize, &current_buffer_size);
                if (err != noErr) {
                    printf("Cannot get current buffer size\n");
                    printError(err);
                } else {
                    //printf("SetupBufferSize : checked buffer size = %ld\n", current_buffer_size);
                }

                // Remove BS change notification
                AudioDeviceRemovePropertyListener(fDeviceID, 0, true, kAudioDevicePropertyBufferFrameSize, BSNotificationCallback);
            } else {
                //printf("Keep current buffer size = %ld\n", current_buffer_size);
            }
            
            fBufferSize = current_buffer_size;
            return 0;

        error:

            // Remove BS change notification
            AudioDeviceRemovePropertyListener(fDeviceID, 0, true, kAudioDevicePropertyBufferFrameSize, BSNotificationCallback);
            return -1;
        }
        
        static OSStatus BSNotificationCallback(AudioDeviceID inDevice,
                                                         UInt32 inChannel,
                                                         Boolean isInput,
                                                         AudioDevicePropertyID inPropertyID,
                                                         void* inClientData)
        {
            TCoreAudioRenderer* driver = (TCoreAudioRenderer*)inClientData;
        
            switch (inPropertyID) {

                case kAudioDevicePropertyBufferFrameSize: {
                    //printf("BSNotificationCallback kAudioDevicePropertyBufferFrameSize\n");
                    // Check new buffer size
                    UInt32 current_buffer_size;
                    UInt32 outSize = sizeof(UInt32);
                    OSStatus err = AudioDeviceGetProperty(inDevice, 0, kAudioDeviceSectionGlobal, kAudioDevicePropertyBufferFrameSize, &outSize, &current_buffer_size);
                    if (err != noErr) {
                        printf("Cannot get current buffer size\n");
                        printError(err);
                    } else {
                        //printf("BSNotificationCallback : checked current buffer size = %d\n", current_buffer_size);
                    }
                    driver->fState = true;
                    break;
                }
            }

            return noErr;
        }

        int SetupSampleRateAux(AudioDeviceID inDevice, int& sample_rate)
        {
            OSStatus err = noErr;
            UInt32 outSize = sizeof(Float64);
            Float64 sampleRate = GetNominalSampleRate(inDevice);
            
            if (sample_rate != -1 && sample_rate != (int)sampleRate) {
                sampleRate = (Float64)sample_rate;
                
                // To get SR change notification
                err = AudioDeviceAddPropertyListener(inDevice, 0, true, kAudioDevicePropertyNominalSampleRate, SRNotificationCallback, this);
                if (err != noErr) {
                    printf("Error calling AudioDeviceAddPropertyListener with kAudioDevicePropertyNominalSampleRate\n");
                    printError(err);
                    return -1;
                }
                err = AudioDeviceSetProperty(inDevice, NULL, 0, kAudioDeviceSectionGlobal, kAudioDevicePropertyNominalSampleRate, outSize, &sampleRate);
                if (err != noErr) {
                    printf("Cannot set sample rate = %d\n", sample_rate);
                    printError(err);
                    return -1;
                }
                
                // Waiting for SR change notification
                int count = 0;
                while (!fState && count++ < WAIT_NOTIFICATION_COUNTER) {
                    usleep(100000);
                    //printf("Wait count = %d\n", count);
                }
                
                // Check new sample rate
                outSize = sizeof(Float64);
                err = AudioDeviceGetProperty(inDevice, 0, kAudioDeviceSectionGlobal, kAudioDevicePropertyNominalSampleRate, &outSize, &sampleRate);
                if (err != noErr) {
                    printf("Cannot get current sample rate\n");
                    printError(err);
                } else {
                    //printf("Checked sample rate = %f\n", sampleRate);
                }
                
                // Remove SR change notification
                AudioDeviceRemovePropertyListener(inDevice, 0, true, kAudioDevicePropertyNominalSampleRate, SRNotificationCallback);
            }
            
            sample_rate = int(sampleRate);
            return 0;
        }   

        static OSStatus Render(void *inRefCon,
                           AudioUnitRenderActionFlags *ioActionFlags,
                           const AudioTimeStamp *inTimeStamp,
                           UInt32 inBusNumber,
                           UInt32 inNumberFrames,
                           AudioBufferList *ioData)
        {
            return static_cast<TCoreAudioRendererPtr>(inRefCon)->Render(ioActionFlags, inTimeStamp, inNumberFrames, ioData);
        }

        static OSStatus SRNotificationCallback(AudioDeviceID inDevice,
                                            UInt32 inChannel,
                                            Boolean	isInput,
                                            AudioDevicePropertyID inPropertyID,
                                               void* inClientData)
        {
            TCoreAudioRenderer* driver = (TCoreAudioRenderer*)inClientData;
            
            switch (inPropertyID) {
                    
                case kAudioDevicePropertyNominalSampleRate: {
                    //printf("SRNotificationCallback kAudioDevicePropertyNominalSampleRate\n");
                    driver->fState = true;
                    // Check new sample rate
                    Float64 sampleRate;
                    UInt32 outSize = sizeof(Float64);
                    OSStatus err = AudioDeviceGetProperty(inDevice, 0, kAudioDeviceSectionGlobal, kAudioDevicePropertyNominalSampleRate, &outSize, &sampleRate);
                    if (err != noErr) {
                        printf("Cannot get current sample rate\n");
                        printError(err);
                    } else {
                        //printf("SRNotificationCallback : checked sample rate = %f\n", sampleRate);
                    }
                    break;
                }
            }
            
            return noErr;
        }

        virtual OSStatus Render(AudioUnitRenderActionFlags *ioActionFlags,
                            const AudioTimeStamp *inTimeStamp,
                            UInt32 inNumberFrames,
                            AudioBufferList *ioData)
        {
            OSStatus err = noErr;
            if (fDevNumInChans > 0) {
                err = AudioUnitRender(fAUHAL, ioActionFlags, inTimeStamp, 1, inNumberFrames, fInputData);
            }
            if (err == noErr) {
                for (int i = 0; i < fDevNumInChans; i++) {
                    fInChannel[i] = (float*)fInputData->mBuffers[i].mData;
                }
                for (int i = 0; i < fDevNumOutChans; i++) {
                    fOutChannel[i] = (float*)ioData->mBuffers[i].mData;
                }
                fDSP->compute(double(AudioConvertHostTimeToNanos(inTimeStamp->mHostTime))/1000., inNumberFrames, fInChannel, fOutChannel);
                if (fControlCb) {
                    fControlCb(fControlCbArg);
                }
            } else {
                printf("AudioUnitRender error... %x\n", fInputData);
                printError(err);
            }
            return err;
        }
        
    public:
    
        TCoreAudioRenderer()
            :fAggregateDeviceID(-1),fAggregatePluginID(-1),
            fDevNumInChans(0),fDevNumOutChans(0),
            fPhysicalInputs(0), fPhysicalOutputs(0),
            fInChannel(0),fOutChannel(0),
            fBufferSize(0),fSampleRate(0),
            fIsInJackDevice(false),
            fIsOutJackDevice(false),
            fDSP(0),
            fInputData(0),
            fDeviceID(0),fAUHAL(0),
            fState(false),
            fControlCb(NULL),
            fControlCbArg(NULL)
        {}

        virtual ~TCoreAudioRenderer()
        {}
        
        int GetBufferSize() {return fBufferSize;}
        int GetSampleRate() {return fSampleRate;}
    
        void setComputeCb(compute_callback cb, void* arg)
        {
            fControlCb = cb;
            fControlCbArg = arg;
        }

        static OSStatus RestartProc(AudioObjectID objectID, UInt32 numberAddresses,
                                   const AudioObjectPropertyAddress inAddresses[],
                                   void *clientData) 
        {
            /*
            TCoreAudioRenderer* renderer = (TCoreAudioRenderer*)clientData;
            AudioDeviceID defaultDevice;
            UInt32 theSize = sizeof(UInt32);
            OSStatus res;
            char device_name[256];
            
            // Test if new device is "JackRouter"
            if (inAddresses[0].mSelector == kAudioHardwarePropertyDefaultInputDevice) {
                
                if ((res = AudioHardwareGetProperty(kAudioHardwarePropertyDefaultInputDevice,
                                                    &theSize, &defaultDevice)) == noErr) {
                    renderer->GetDeviceNameFromID(defaultDevice, device_name);
                    renderer->fIsInJackDevice = strcmp(device_name, "JackRouter") == 0;
                }
                
            } else  if (inAddresses[0].mSelector == kAudioHardwarePropertyDefaultOutputDevice) {
                
                if ((res = AudioHardwareGetProperty(kAudioHardwarePropertyDefaultOutputDevice,
                                                    &theSize, &defaultDevice)) == noErr) {
                    renderer->GetDeviceNameFromID(defaultDevice, device_name);
                    renderer->fIsOutJackDevice = strcmp(device_name, "JackRouter") == 0;
                }
                
            }
            
            // Switch only of input and output are "JackRouter"
            if (renderer->fIsInJackDevice && renderer->fIsOutJackDevice || !renderer->fIsInJackDevice && !renderer->fIsOutJackDevice) {
                renderer->Stop();
                renderer->Close();
                int sampleRate = -1; // Use the current sample rate
                int bufferSize = (renderer->fBufferSize > 0) ? renderer->fBufferSize : 512; // Use default if needed
                renderer->OpenDefault(renderer->fDSP, renderer->fDevNumInChans, renderer->fDevNumOutChans, bufferSize, sampleRate);
                renderer->Start();
            }
            */
            return 0;
        }
    
        int OpenDefault(dsp* DSP, int inChan, int outChan, int bufferSize, int& sampleRate)
        {
            fDevNumInChans = 0;
            fDevNumOutChans = 0;
            fInChannel = 0;
            fOutChannel = 0;
            fBufferSize = 0;
            fSampleRate = 0;
            fDSP = 0;
            fInputData = 0;
            fDeviceID = 0; 
            fAUHAL = 0;
            fState = false;
            return OpenDefault(inChan, outChan, bufferSize, sampleRate);
        }
    
        int OpenDefault(int inChan, int outChan, int buffer_size, int& sample_rate)
        {
            OSStatus err;
            UInt32 outSize;
            UInt32 enableIO;
            Boolean isWritable;
            AudioStreamBasicDescription srcFormat, dstFormat, sampleRate;
            
            fDevNumInChans = inChan;
            fDevNumOutChans = outChan;
            
            fInChannel = new float*[fDevNumInChans];
            fOutChannel = new float*[fDevNumOutChans];
            
            //printf("OpenDefault inChan = %ld outChan = %ld bufferSize = %ld sample_rate = %ld\n", inChan, outChan, bufferSize, sample_rate);
            
            SInt32 major;
            SInt32 minor;
            Gestalt(gestaltSystemVersionMajor, &major);
            Gestalt(gestaltSystemVersionMinor, &minor);
            
            // Starting with 10.6 systems, the HAL notification thread is created internally
            if (major == 10 && minor >= 6) {
                CFRunLoopRef theRunLoop = NULL;
                AudioObjectPropertyAddress theAddress = { kAudioHardwarePropertyRunLoop, kAudioObjectPropertyScopeGlobal, kAudioObjectPropertyElementMaster };
                OSStatus osErr = AudioObjectSetPropertyData (kAudioObjectSystemObject, &theAddress, 0, NULL, sizeof(CFRunLoopRef), &theRunLoop);
                if (osErr != noErr) {
                    printf("TCoreAudioRenderer::Open kAudioHardwarePropertyRunLoop error\n");
                    printError(osErr);
                }
            }
             
            if (GetDefaultDeviceAndSampleRate(inChan, outChan, sample_rate, &fDeviceID) != noErr) {
                printf("Cannot open default device\n");
                return OPEN_ERR;
            }
             
            // Setting buffer size
            if (SetupBufferSize(buffer_size) < 0) {
                return OPEN_ERR;
            }
            
            // fBufferSize now has the real value, either 'bufferSize' (if could be changed) or driver current one
            
            // AUHAL
        
        #ifdef MAC_OS_X_VERSION_10_5
            ComponentDescription cd = {kAudioUnitType_Output, kAudioUnitSubType_HALOutput, kAudioUnitManufacturer_Apple, 0, 0};
            Component HALOutput = FindNextComponent(NULL, &cd);
            err = OpenAComponent(HALOutput, &fAUHAL);
            if (err != noErr) {
                printf("Error calling OpenAComponent\n");
                printError(err);
                goto error;
            }
        #else 
            AudioComponentDescription cd = {kAudioUnitType_Output, kAudioUnitSubType_HALOutput, kAudioUnitManufacturer_Apple, 0, 0};
            AudioComponent HALOutput = AudioComponentFindNext(NULL, &cd);
            err = AudioComponentInstanceNew(HALOutput, &fAUHAL);
            if (err != noErr) {
                printf("Error calling AudioComponentInstanceNew\n");
                printError(err);
                goto error;
            }
        #endif
            
            err = AudioUnitInitialize(fAUHAL);
            if (err != noErr) {
                printf("Cannot initialize AUHAL unit\n");
                printError(err);
                goto error;
            }
            
            if (inChan > 0) {
                enableIO = 1;
                //printf("OpenAUHAL : setup AUHAL input on\n");
            } else {
                enableIO = 0;
                //printf("OpenAUHAL : setup AUHAL input off\n");
            }
            
            err = AudioUnitSetProperty(fAUHAL, kAudioOutputUnitProperty_EnableIO, kAudioUnitScope_Input, 1, &enableIO, sizeof(enableIO));
            if (err != noErr) {
                printf("Error calling AudioUnitSetProperty - kAudioOutputUnitProperty_EnableIO, kAudioUnitScope_Input\n");
                printError(err);
                goto error;
            }
                
            if (outChan > 0) {
                enableIO = 1;
                //printf("OpenAUHAL : setup AUHAL output on\n");
            } else {
                enableIO = 0;
                //printf("OpenAUHAL : setup AUHAL output off\n");
            }
            
            err = AudioUnitSetProperty(fAUHAL, kAudioOutputUnitProperty_EnableIO, kAudioUnitScope_Output, 0, &enableIO, sizeof(enableIO));
            if (err != noErr) {
                printf("Error calling AudioUnitSetProperty - kAudioOutputUnitProperty_EnableIO, kAudioUnitScope_Output\n");
                printError(err);
                goto error;
            }
            
            AudioDeviceID currAudioDeviceID;
            outSize = sizeof(AudioDeviceID);
            err = AudioUnitGetProperty(fAUHAL, kAudioOutputUnitProperty_CurrentDevice, kAudioUnitScope_Global, 0, &currAudioDeviceID, &outSize);
            if (err != noErr) {
                printf("Error calling AudioUnitGetProperty - kAudioOutputUnitProperty_CurrentDevice\n");
                printError(err);
                goto error;
            } else {
                //printf("AudioUnitGetPropertyCurrentDevice = %d\n", currAudioDeviceID);
            }
        
            // Setup up choosen device, in both input and output cases
            err = AudioUnitSetProperty(fAUHAL, kAudioOutputUnitProperty_CurrentDevice, kAudioUnitScope_Global, 0, &fDeviceID, sizeof(AudioDeviceID));
            if (err != noErr) {
                printf("Error calling AudioUnitSetProperty - kAudioOutputUnitProperty_CurrentDevice\n");
                printError(err);
                goto error;
            }
            
            if (inChan > 0) {
                err = AudioUnitSetProperty(fAUHAL, kAudioUnitProperty_MaximumFramesPerSlice, kAudioUnitScope_Global, 1, (UInt32*)&fBufferSize, sizeof(UInt32));
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_MaximumFramesPerSlice\n");
                    printError(err);
                    goto error;
                }
            }
            
            if (outChan > 0) {
                err = AudioUnitSetProperty(fAUHAL, kAudioUnitProperty_MaximumFramesPerSlice, kAudioUnitScope_Global, 0, (UInt32*)&fBufferSize, sizeof(UInt32));
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_MaximumFramesPerSlice\n");
                    printError(err);
                    goto error;
                }
            }
            
            err = AudioUnitGetPropertyInfo(fAUHAL, kAudioOutputUnitProperty_ChannelMap, kAudioUnitScope_Input, 1, &outSize, &isWritable);
            if (err != noErr) {
                //printf("Error calling AudioUnitGetPropertyInfo - kAudioOutputUnitProperty_ChannelMap 1\n");
                //printError(err);
            } else {
                fPhysicalInputs = (err == noErr) ? outSize / sizeof(SInt32) : 0;
                //printf("fPhysicalInputs = %ld\n", fPhysicalInputs);
            }
                    
            err = AudioUnitGetPropertyInfo(fAUHAL, kAudioOutputUnitProperty_ChannelMap, kAudioUnitScope_Output, 0, &outSize, &isWritable);
            if (err != noErr) {
                //printf("Error calling AudioUnitGetPropertyInfo - kAudioOutputUnitProperty_ChannelMap 0\n");
                //printError(err);
            } else {
                fPhysicalOutputs = (err == noErr) ? outSize / sizeof(SInt32) : 0;
                //printf("fPhysicalOutputs = %ld\n", fPhysicalOutputs);
            }
            
            /*
             Just ignore this case : seems to work without any further change...
             
             if (outChan > fPhysicalOutputs) {
                printf("This device hasn't required output channels\n");
                goto error;
             }
             if (inChan > fPhysicalInputs) {
                printf("This device hasn't required input channels\n");
                goto error;
             }
             */
            
            if (inChan < fPhysicalInputs) {
                SInt32 chanArr[fPhysicalInputs];
                for (int i = 0; i < fPhysicalInputs; i++) {
                    chanArr[i] = -1;
                }
                for (int i = 0; i < inChan; i++) {
                    chanArr[i] = i;
                }
                AudioUnitSetProperty(fAUHAL, kAudioOutputUnitProperty_ChannelMap , kAudioUnitScope_Input, 1, chanArr, sizeof(SInt32) * fPhysicalInputs);
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioOutputUnitProperty_ChannelMap 1\n");
                    printError(err);
                }
            }
            
            if (outChan < fPhysicalOutputs) {
                SInt32 chanArr[fPhysicalOutputs];
                for (int i = 0;	i < fPhysicalOutputs; i++) {
                    chanArr[i] = -1;
                }
                for (int i = 0; i < outChan; i++) {
                    chanArr[i] = i;
                }
                err = AudioUnitSetProperty(fAUHAL, kAudioOutputUnitProperty_ChannelMap, kAudioUnitScope_Output, 0, chanArr, sizeof(SInt32) * fPhysicalOutputs);
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioOutputUnitProperty_ChannelMap 0\n");
                    printError(err);
                }
            }
            
            if (inChan > 0) {
                outSize = sizeof(AudioStreamBasicDescription);
                err = AudioUnitGetProperty(fAUHAL, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Output, 1, &srcFormat, &outSize);
                if (err != noErr) {
                    printf("Error calling AudioUnitGetProperty - kAudioUnitProperty_StreamFormat kAudioUnitScope_Output\n");
                    printError(err);
                }
                //PrintStreamDesc(&srcFormat);
                
                srcFormat.mSampleRate = sample_rate;
                srcFormat.mFormatID = kAudioFormatLinearPCM;
                srcFormat.mFormatFlags = kAudioFormatFlagsNativeFloatPacked | kLinearPCMFormatFlagIsNonInterleaved;
                srcFormat.mBytesPerPacket = sizeof(float);
                srcFormat.mFramesPerPacket = 1;
                srcFormat.mBytesPerFrame = sizeof(float);
                srcFormat.mChannelsPerFrame = inChan;
                srcFormat.mBitsPerChannel = 32;
                
                //PrintStreamDesc(&srcFormat);
                
                err = AudioUnitSetProperty(fAUHAL, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Output, 1, &srcFormat, sizeof(AudioStreamBasicDescription));
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_StreamFormat kAudioUnitScope_Output\n");
                    printError(err);
                }
            }
            
            if (outChan > 0) {
                outSize = sizeof(AudioStreamBasicDescription);
                err = AudioUnitGetProperty(fAUHAL, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Input, 0, &dstFormat, &outSize);
                if (err != noErr) {
                    printf("Error calling AudioUnitGetProperty - kAudioUnitProperty_StreamFormat kAudioUnitScope_Output\n");
                    printError(err);
                }
                //PrintStreamDesc(&dstFormat);
                
                dstFormat.mSampleRate = sample_rate;
                dstFormat.mFormatID = kAudioFormatLinearPCM;
                dstFormat.mFormatFlags = kAudioFormatFlagsNativeFloatPacked | kLinearPCMFormatFlagIsNonInterleaved;
                dstFormat.mBytesPerPacket = sizeof(float);
                dstFormat.mFramesPerPacket = 1;
                dstFormat.mBytesPerFrame = sizeof(float);
                dstFormat.mChannelsPerFrame = outChan;
                dstFormat.mBitsPerChannel = 32;
                
                //PrintStreamDesc(&dstFormat);
                
                err = AudioUnitSetProperty(fAUHAL, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Input, 0, &dstFormat, sizeof(AudioStreamBasicDescription));
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_StreamFormat kAudioUnitScope_Output\n");
                    printError(err);
                }
            }
            
            if (inChan > 0 && outChan == 0) {
                AURenderCallbackStruct output;
                output.inputProc = Render;
                output.inputProcRefCon = this;
                err = AudioUnitSetProperty(fAUHAL, kAudioOutputUnitProperty_SetInputCallback, kAudioUnitScope_Global, 0, &output, sizeof(output));
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_SetRenderCallback 1\n");
                    printError(err);
                    goto error;
                }
            } else {
                AURenderCallbackStruct output;
                output.inputProc = Render;
                output.inputProcRefCon = this;
                err = AudioUnitSetProperty(fAUHAL, kAudioUnitProperty_SetRenderCallback, kAudioUnitScope_Input, 0, &output, sizeof(output));
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_SetRenderCallback 0\n");
                    printError(err);
                    goto error;
                }
            }
            
            if (inChan > 0) {
                fInputData = (AudioBufferList*)malloc(sizeof(UInt32) + inChan * sizeof(AudioBuffer));
                assert(fInputData);
                fInputData->mNumberBuffers = inChan;
                
                // Prepare buffers
                for (int i = 0; i < inChan; i++) {
                    fInputData->mBuffers[i].mNumberChannels = 1;
                    fInputData->mBuffers[i].mData = malloc(fBufferSize * sizeof(float));
                    assert(fInputData->mBuffers[i].mData),
                    fInputData->mBuffers[i].mDataByteSize = fBufferSize * sizeof(float);
                }
            }
            
            AudioObjectPropertyAddress property_address;
            property_address.mScope = kAudioObjectPropertyScopeGlobal;
            property_address.mElement = kAudioObjectPropertyElementMaster;
            
            property_address.mSelector = kAudioHardwarePropertyDefaultInputDevice;
            if (AudioObjectAddPropertyListener(kAudioObjectSystemObject, &property_address, RestartProc, this)) {
                printf("AudioObjectAddPropertyListener() failed\n");
                return OPEN_ERR;
            } else {
                //printf("AudioObjectAddPropertyListener() OK\n");
            }
            
            property_address.mSelector = kAudioHardwarePropertyDefaultOutputDevice;
            if (AudioObjectAddPropertyListener(kAudioObjectSystemObject, &property_address, RestartProc, this)) {
                printf("AudioObjectAddPropertyListener() failed\n");
                return OPEN_ERR;
            } else {
                //printf("AudioObjectAddPropertyListener() OK\n");
            }
             
            return NO_ERR;
            
        error:
            AudioUnitUninitialize(fAUHAL);
            CloseComponent(fAUHAL);
            fAUHAL = 0;
            return OPEN_ERR;
        }
        
        int Close()
        {
            if (!fAUHAL) {
                return CLOSE_ERR;
            }
            
            for (int i = 0; i < fDevNumInChans; i++) {
                free(fInputData->mBuffers[i].mData);
            }
            if (fInputData) {
                free(fInputData);
            }
            AudioUnitUninitialize(fAUHAL);
            CloseComponent(fAUHAL);
            fAUHAL = NULL;
            
            DestroyAggregateDevice();
            
            delete[] fInChannel;
            delete[] fOutChannel;
            
            AudioObjectPropertyAddress property_address;
            property_address.mScope = kAudioObjectPropertyScopeGlobal;
            property_address.mElement = kAudioObjectPropertyElementMaster;
            
            property_address.mSelector = kAudioHardwarePropertyDefaultInputDevice;
            AudioObjectRemovePropertyListener(kAudioObjectSystemObject, &property_address, RestartProc, this);
            
            property_address.mSelector = kAudioHardwarePropertyDefaultOutputDevice;
            AudioObjectRemovePropertyListener(kAudioObjectSystemObject, &property_address, RestartProc, this);
            
            return NO_ERR;
        }

        int Start()
        {
            if (!fAUHAL) {
                return OPEN_ERR;
            }
            
            OSStatus err = AudioOutputUnitStart(fAUHAL);
            
            if (err != noErr) {
                printf("Error while opening device : device open error \n");
                return OPEN_ERR;
            } else {
                return NO_ERR;
            }
        }
        
        int Stop()
        {
            if (!fAUHAL) {
                return OPEN_ERR;
            }
            
            OSStatus err = AudioOutputUnitStop(fAUHAL);
            
            if (err != noErr) {
                printf("Error while closing device : device close error \n");
                return OPEN_ERR;
            } else {
                return NO_ERR;
            }
        }
    
        void setDsp(dsp* DSP)
        {
            fDSP = DSP;
        }
        
        int GetNumInputs() { return fPhysicalInputs; }
        int GetNumOutputs() { return fPhysicalOutputs; }

};

/******************************************************************************
*******************************************************************************

							CORE AUDIO INTERFACE

*******************************************************************************
*******************************************************************************/
class coreaudio : public audio {

    protected:
        
        TCoreAudioRenderer fAudioDevice;
        int fSampleRate, fBufferSize;

    public:
      
        coreaudio(int srate, int bsize) : fSampleRate(srate), fBufferSize(bsize) {}
            coreaudio(int bsize) : fSampleRate(-1), fBufferSize(bsize) {}
        virtual ~coreaudio() { fAudioDevice.Close(); }

        virtual bool init(const char* /*name*/, dsp* DSP) 
        {
            if (fAudioDevice.OpenDefault(DSP, DSP->getNumInputs(), DSP->getNumOutputs(), fBufferSize, fSampleRate) < 0) {
                printf("Cannot open CoreAudio device\n");
                return false;
            }
            fAudioDevice.setDsp(DSP);
            // If -1 was given, fSampleRate will be changed by OpenDefault
            DSP->init(fSampleRate);
            return true;
        }

        virtual bool start() 
        {
            if (fAudioDevice.Start() < 0) {
                printf("Cannot start CoreAudio device\n");
                return false;
            }
            return true;
        }
    
        virtual void stop()
        {
            fAudioDevice.Stop();
        }
    
        virtual void setComputeCb(compute_callback cb, void* arg)
        {
            fAudioDevice.setComputeCb(cb, arg);
        }
 
        virtual int getBufferSize() { return fAudioDevice.GetBufferSize(); }
        virtual int getSampleRate() { return fAudioDevice.GetSampleRate(); }
        
        virtual int getNumInputs() { return fAudioDevice.GetNumInputs(); }
        virtual int getNumOutputs() { return fAudioDevice.GetNumOutputs(); }

};

#endif

/********************END ARCHITECTURE SECTION (part 2/2)****************/


#elif IOS_DRIVER
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.

 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/


#ifndef __coreaudio_ios_dsp__
#define __coreaudio_ios_dsp__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <errno.h>
#include <time.h>


#include <AudioToolbox/AudioConverter.h>
#include <AudioToolbox/AudioServices.h>
#include <AudioUnit/AudioUnit.h>

using namespace std;

/******************************************************************************
*******************************************************************************

							COREAUDIO INTERFACE

*******************************************************************************
*******************************************************************************/

#define OPEN_ERR -1
#define NO_ERR 0

class TiPhoneCoreAudioRenderer
{

    protected:

        AudioUnit fAUHAL;

        int	fDevNumInChans;
        int	fDevNumOutChans;

        int fHWNumInChans;
        int fHWNumOutChans;

        compute_callback fControlCb;
        void* fControlCbArg;
  
        dsp* fDSP;

        AudioBufferList* fCAInputData;

        static void PrintStreamDesc(AudioStreamBasicDescription *inDesc)
        {
            printf("- - - - - - - - - - - - - - - - - - - -\n");
            printf("  Sample Rate:%f\n", inDesc->mSampleRate);
            printf("  Format ID:%.*s\n", (int) sizeof(inDesc->mFormatID), (char*)&inDesc->mFormatID);
            printf("  Format Flags:%lX\n", inDesc->mFormatFlags);
            printf("  Bytes per Packet:%ld\n", inDesc->mBytesPerPacket);
            printf("  Frames per Packet:%ld\n", inDesc->mFramesPerPacket);
            printf("  Bytes per Frame:%ld\n", inDesc->mBytesPerFrame);
            printf("  Channels per Frame:%ld\n", inDesc->mChannelsPerFrame);
            printf("  Bits per Channel:%ld\n", inDesc->mBitsPerChannel);
            printf("- - - - - - - - - - - - - - - - - - - -\n");
        }

        static void printError(OSStatus err)
        {
            switch (err) {
                case kAudioConverterErr_FormatNotSupported:
                    printf("error code : kAudioConverterErr_FormatNotSupported\n");
                    break;
                case kAudioConverterErr_OperationNotSupported:
                    printf("error code : kAudioConverterErr_OperationNotSupported\n");
                    break;
                case kAudioConverterErr_PropertyNotSupported:
                    printf("error code : kAudioConverterErr_PropertyNotSupported\n");
                    break;
                case kAudioConverterErr_InvalidInputSize:
                    printf("error code : kAudioConverterErr_InvalidInputSize\n");
                    break;
                case kAudioConverterErr_InvalidOutputSize:
                    printf("error code : kAudioConverterErr_InvalidOutputSize\n");
                    break;
                case kAudioConverterErr_UnspecifiedError:
                    printf("error code : kAudioConverterErr_UnspecifiedError\n");
                    break;
                case kAudioConverterErr_BadPropertySizeError:
                    printf("error code : kAudioConverterErr_BadPropertySizeError\n");
                    break;
                case kAudioConverterErr_RequiresPacketDescriptionsError:
                    printf("error code : kAudioConverterErr_RequiresPacketDescriptionsError\n");
                    break;
                case kAudioConverterErr_InputSampleRateOutOfRange:
                    printf("error code : kAudioConverterErr_InputSampleRateOutOfRange\n");
                    break;
                case kAudioConverterErr_OutputSampleRateOutOfRange:
                    printf("error code : kAudioConverterErr_OutputSampleRateOutOfRange\n");
                    break;
                default:
                    printf("error code : unknown\n");
                    break;
            }
        }

        static OSStatus Render(void *inRefCon,AudioUnitRenderActionFlags *ioActionFlags,
                               const AudioTimeStamp *inTimeStamp,
                               UInt32,
                               UInt32 inNumberFrames,
                               AudioBufferList *ioData)
        {
            return static_cast<TiPhoneCoreAudioRenderer*>(inRefCon)->Render(ioActionFlags, inTimeStamp, inNumberFrames, ioData);
        }

        OSStatus Render(AudioUnitRenderActionFlags *ioActionFlags,
                        const AudioTimeStamp *inTimeStamp,
                        UInt32 inNumberFrames,
                        AudioBufferList *ioData)
        {
            OSStatus err = noErr;

            if (fDevNumInChans > 0) {
                err = AudioUnitRender(fAUHAL, ioActionFlags, inTimeStamp, 1, inNumberFrames, fCAInputData);
            }

            if (err == noErr) {
                float* fInChannel[fDevNumInChans];
                float* fOutChannel[fDevNumOutChans];

                for (int chan = 0; chan < fDevNumInChans; chan++) {
                    fInChannel[chan] = (float*)fCAInputData->mBuffers[chan].mData;
                }

                for (int chan = 0; chan < fDevNumOutChans; chan++) {
                    fOutChannel[chan] = (float*)ioData->mBuffers[chan].mData;
                }

                fDSP->compute((int)inNumberFrames, fInChannel, fOutChannel);
                
                if (fControlCb) {
                    fControlCb(fControlCbArg);
                }
            }
            return err;
        }

        static void InterruptionListener(void *inClientData, UInt32 inInterruption)
        {
            TiPhoneCoreAudioRenderer *obj = (TiPhoneCoreAudioRenderer*)inClientData;
            printf("Session interrupted! --- %s ---", (inInterruption == kAudioSessionBeginInterruption) ? "Begin Interruption" : "End Interruption");

            if (inInterruption == kAudioSessionEndInterruption) {
                // Make sure we are again the active session
                AudioSessionSetActive(true);
                obj->SetupMixing();
                AudioOutputUnitStart(obj->fAUHAL);
            }

            if (inInterruption == kAudioSessionBeginInterruption) {
                AudioOutputUnitStop(obj->fAUHAL);
            }
        }
    
        int SetupMixing()
        {
            OSStatus err;

            /*
            01/07/2014 : cause iRig to fail, so deactivated for now...
            CFStringRef route;
            UInt32 routesize = sizeof(route);
            OSStatus err  = AudioSessionGetProperty(kAudioSessionProperty_AudioRoute, &routesize, &route);
            if (err == noErr) {
                if (CFStringCompare(route, CFSTR("ReceiverAndMicrophone"), 0) == kCFCompareEqualTo || CFStringCompare(route,CFSTR("Receiver"), 0) == kCFCompareEqualTo) {
                    // Re-route audio to the speaker (not the receiver, which no music app will ever want)
                    printf("Rerouting audio to speaker\n");
                    UInt32 newRoute = kAudioSessionOverrideAudioRoute_Speaker;
                    AudioSessionSetProperty(kAudioSessionProperty_OverrideAudioRoute, sizeof(newRoute), &newRoute);
                }
             }
            */

            UInt32 allowMixing = true;
            err = AudioSessionSetProperty(kAudioSessionProperty_OverrideCategoryMixWithOthers, sizeof(allowMixing), &allowMixing);
            if (err != noErr) {
                printf("Could not set audio session mixing\n");
                printError(err);
                return -1;
            } else {
                return 0;
            }
        }

        static void AudioSessionPropertyListener(void* inClientData, AudioSessionPropertyID inID, UInt32 inDataSize, const void* inData)
        {
            TiPhoneCoreAudioRenderer *obj = (TiPhoneCoreAudioRenderer*)inData;
            switch (inID) {
                case kAudioSessionProperty_ServerDied: {
                    printf("kAudioSessionProperty_ServerDied\n");
                    break;
                }
                case kAudioSessionProperty_AudioRouteChange: {
                    printf("kAudioSessionProperty_AudioRouteChange\n");
                    obj->SetupMixing();
                    break;
                }
                case kAudioSessionProperty_AudioInputAvailable: {
                    printf("kAudioSessionProperty_AudioInputAvailable\n");
                    obj->SetupMixing();
                    break;
                }
            }
        }

        static int SetAudioCategory(int input, int output)
        {
            // Set the audioCategory the way Faust DSP wants
            UInt32 audioCategory;
            if ((input > 0) && (output > 0)) {
                audioCategory = kAudioSessionCategory_PlayAndRecord;
                printf("AudioCategory kAudioSessionCategory_PlayAndRecord\n");
            } else if (input > 0) {
                audioCategory = kAudioSessionCategory_RecordAudio;
                printf("AudioCategory kAudioSessionCategory_RecordAudio\n");
            } else  if (output > 0) {
                audioCategory = kAudioSessionCategory_MediaPlayback;
                printf("AudioCategory kAudioSessionCategory_MediaPlayback\n");
            }

            OSStatus err = AudioSessionSetProperty(kAudioSessionProperty_AudioCategory, sizeof(audioCategory), &audioCategory);
            if (err != noErr) {
                printf("Couldn't set audio category\n");
                printError(err);
                return OPEN_ERR;
            }

            // 09/07/2015 : https://developer.apple.com/library/ios/qa/qa1754/_index.html
            if (audioCategory == kAudioSessionCategory_PlayAndRecord) {
                
                // 21/09/2017 Compatible with bluetooth devices. Deactivate bluetooth micro which run at 16khz, use internal micro instead.
                /*
                UInt32 overrideAudioRoute = 1;
                err = AudioSessionSetProperty(kAudioSessionProperty_OverrideCategoryDefaultToSpeaker, sizeof(UInt32), &overrideAudioRoute);
                if (err != noErr) {
                    printf("Error setting kAudioSessionProperty_OverrideCategoryDefaultToSpeaker\n");
                    printError(err);
                }

                UInt32 allowBluetoothInput = 1;
                err = AudioSessionSetProperty(kAudioSessionProperty_OverrideCategoryEnableBluetoothInput, sizeof(UInt32), &allowBluetoothInput);
                if (err != noErr) {
                    printf("Error setting kAudioSessionProperty_OverrideCategoryEnableBluetoothInput\n");
                    printError(err);
                }
                */
                
                // On devices with more than one built-in microphone, the microphone closest to the video camera is used.
                UInt32 allowInternalInput = kAudioSessionMode_VideoRecording;
                err = AudioSessionSetProperty(kAudioSessionProperty_Mode, sizeof(UInt32), &allowInternalInput);
                if (err != noErr) {
                    printf("Error setting kAudioSessionMode_VideoRecording\n");
                    printError(err);
                }

            }

        #if NOAGC
            // If input is used, disable AGC
            if (audioCategory == kAudioSessionCategory_RecordAudio || audioCategory == kAudioSessionCategory_PlayAndRecord) {

                UInt32 sessionMode = kAudioSessionMode_Measurement;
                err = AudioSessionSetProperty(kAudioSessionProperty_Mode, sizeof(sessionMode), &sessionMode);
                if (err != noErr) {
                    printf("Error setting kAudioSessionMode_Measurement\n");
                    printError(err);
                }

                UInt32 availableGain;
                UInt32 outSize = sizeof(availableGain);
                err = AudioSessionGetProperty(kAudioSessionProperty_InputGainAvailable, &outSize, &availableGain);
                if (err != noErr) {
                    printf("Error getting kAudioSessionProperty_InputGainAvailable\n");
                    printError(err);
                } else {
                    Float32 gain;
                    printf("Getting kAudioSessionProperty_InputGainAvailable OK\n");
                    outSize = sizeof(Float32);
                    AudioSessionGetProperty(kAudioSessionProperty_InputGainScalar, &outSize, &gain);
                    printf("Getting kAudioSessionProperty_InputGainScalar :  %f\n", gain);
                    gain = 1.0f;
                    err = AudioSessionSetProperty(kAudioSessionProperty_InputGainScalar, sizeof(Float32), &gain);
                    if (err != noErr) {
                        printf("Error setting kAudioSessionProperty_InputGainScalar\n");
                        printError(err);
                    } else {
                        printf("Setting kAudioSessionProperty_InputGainAvailable to 1.0 OK\n");
                    }
                }
            }
        #endif

            return NO_ERR;
        }

        int SetParameters(int bufferSize, int samplerate)
        {
            OSStatus err;
            UInt32 outSize;
            UInt32 enableIO;
            AudioStreamBasicDescription srcFormat, dstFormat;

            printf("SetParameters fDevNumInChans = %d fDevNumOutChans = %d bufferSize = %d samplerate = %d\n", fDevNumInChans, fDevNumOutChans, bufferSize, samplerate);

            err = AudioSessionSetActive(true);
            if (err != noErr) {
                printf("Couldn't set audio session active\n");
                printError(err);
                return OPEN_ERR;
            }

            AudioSessionAddPropertyListener(kAudioSessionProperty_AudioRouteChange, AudioSessionPropertyListener, this);
            AudioSessionAddPropertyListener(kAudioSessionProperty_AudioInputAvailable, AudioSessionPropertyListener, this);
            AudioSessionAddPropertyListener(kAudioSessionProperty_ServerDied, AudioSessionPropertyListener, this);

            if (SetAudioCategory(fDevNumInChans, fDevNumOutChans) != NO_ERR) {
                return OPEN_ERR;
            }

            // Scan Hardware
            outSize = sizeof(fHWNumInChans);
            err = AudioSessionGetProperty(kAudioSessionProperty_CurrentHardwareInputNumberChannels, &outSize, &fHWNumInChans);
            if (err != noErr) {
                fHWNumInChans = 0;
                printf("Couldn't get hw input channels\n");
                printError(err);
            } else {
                printf("Get hw input channels %d\n", fHWNumInChans);
            }

            outSize = sizeof(fHWNumOutChans);
            err = AudioSessionGetProperty(kAudioSessionProperty_CurrentHardwareOutputNumberChannels, &outSize, &fHWNumOutChans);
            if (err != noErr) {
                fHWNumOutChans = 0;
                printf("Couldn't get hw output channels\n");
                printError(err);
            } else {
                printf("Get hw output channels %d\n", fHWNumOutChans);
            }
            /*
            // Possibly reset the audioCategory the way hardware allows
            // 21/09/2017 cause problem when use bluetooth, deactive for now
            if (SetAudioCategory(fHWNumInChans, fHWNumOutChans) != NO_ERR) {
                return OPEN_ERR;
            }
            */
            if (SetupMixing() < 0) {
                return OPEN_ERR;
            }

            Float64 hwSampleRate;
            outSize = sizeof(hwSampleRate);
            err = AudioSessionGetProperty(kAudioSessionProperty_CurrentHardwareSampleRate, &outSize, &hwSampleRate);
            if (err != noErr) {
                printf("Couldn't get hw sample rate\n");
                printError(err);
                return OPEN_ERR;
            } else {
                printf("Get hw sample rate %f\n", hwSampleRate);
            }

            Float32 hwBufferSize;
            outSize = sizeof(hwBufferSize);
            err = AudioSessionGetProperty(kAudioSessionProperty_CurrentHardwareIOBufferDuration, &outSize, &hwBufferSize);
            if (err != noErr) {
                printf("Couldn't get hw buffer duration\n");
                printError(err);
                return OPEN_ERR;
            } else {
                printf("Get hw buffer duration %f\n", hwBufferSize);
            }

            Float32 preferredPeriodDuration = float(bufferSize) / float(samplerate);
            printf("preferredPeriodDuration %f \n", preferredPeriodDuration);

            err = AudioSessionSetProperty(kAudioSessionProperty_PreferredHardwareIOBufferDuration, sizeof(preferredPeriodDuration), &preferredPeriodDuration);
            if (err != noErr) {
                printf("Couldn't set i/o buffer duration\n");
                printError(err);
                return OPEN_ERR;
            }

            Float32 actualPeriodDuration;
            outSize = sizeof(actualPeriodDuration);
            err = AudioSessionGetProperty(kAudioSessionProperty_PreferredHardwareIOBufferDuration, &outSize, &actualPeriodDuration);
            if (err != noErr) {
                printf("Couldn't get hw buffer duration\n");
                printError(err);
                return OPEN_ERR;
            }

            printf("preferredPeriodDuration %f actualPeriodDuration %f\n", preferredPeriodDuration, actualPeriodDuration);
            if (preferredPeriodDuration != actualPeriodDuration) {
                printf("Couldn't set hw buffer duration\n");
                return OPEN_ERR;
            }

            Float64 preferredSamplerate = float(samplerate);
            err = AudioSessionSetProperty(kAudioSessionProperty_PreferredHardwareSampleRate, sizeof(preferredSamplerate), &preferredSamplerate);
            if (err != noErr) {
                printf("Couldn't set i/o sample rate\n");
                printError(err);
                return OPEN_ERR;
            }

            Float32 inputLatency;
            outSize = sizeof(inputLatency);
            err = AudioSessionGetProperty(kAudioSessionProperty_CurrentHardwareInputLatency, &outSize, &inputLatency);
            if (err != noErr) {
                printf("Couldn't get inputLatency\n");
                printError(err);
            } else {
                printf("inputLatency in sec : %f\n", inputLatency);
            }

            Float32 outputLatency;
            outSize = sizeof(outputLatency);
            err = AudioSessionGetProperty(kAudioSessionProperty_CurrentHardwareOutputLatency, &outSize, &outputLatency);
            if (err != noErr) {
                printf("Couldn't get outputLatency\n");
                printError(err);
            } else {
                printf("outputLatency in sec : %f\n", outputLatency);
            }

            // AUHAL
            AudioComponentDescription cd = {kAudioUnitType_Output, kAudioUnitSubType_RemoteIO, kAudioUnitManufacturer_Apple, 0, 0};
            AudioComponent HALOutput = AudioComponentFindNext(NULL, &cd);

            err = AudioComponentInstanceNew(HALOutput, &fAUHAL);
            if (err != noErr) {
                printf("Error calling OpenAComponent\n");
                printError(err);
                goto error;
            }

            enableIO = 1;
            err = AudioUnitSetProperty(fAUHAL, kAudioOutputUnitProperty_EnableIO, kAudioUnitScope_Output, 0, &enableIO, sizeof(enableIO));
            if (err != noErr) {
                printf("Error calling AudioUnitSetProperty - kAudioOutputUnitProperty_EnableIO, kAudioUnitScope_Output\n");
                printError(err);
                goto error;
            }

            enableIO = 1;
            err = AudioUnitSetProperty(fAUHAL, kAudioOutputUnitProperty_EnableIO, kAudioUnitScope_Input, 1, &enableIO, sizeof(enableIO));
            if (err != noErr) {
                printf("Error calling AudioUnitSetProperty - kAudioOutputUnitProperty_EnableIO, kAudioUnitScope_Input\n");
                printError(err);
                goto error;
            }

            UInt32 maxFPS;
            outSize = sizeof(maxFPS);
            err = AudioUnitGetProperty(fAUHAL, kAudioUnitProperty_MaximumFramesPerSlice, kAudioUnitScope_Global, 0, &maxFPS, &outSize);
            if (err != noErr) {
                printf("Couldn't get kAudioUnitProperty_MaximumFramesPerSlice\n");
                printError(err);
                goto error;
            } else {
                printf("Get kAudioUnitProperty_MaximumFramesPerSlice %d\n", (unsigned int)maxFPS);
            }

            err = AudioUnitSetProperty(fAUHAL, kAudioUnitProperty_MaximumFramesPerSlice, kAudioUnitScope_Global, 1, (UInt32*)&bufferSize, sizeof(UInt32));
            if (err != noErr) {
                printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_MaximumFramesPerSlice\n");
                printError(err);
                goto error;
            }

            err = AudioUnitSetProperty(fAUHAL, kAudioUnitProperty_MaximumFramesPerSlice, kAudioUnitScope_Global, 0, (UInt32*)&bufferSize, sizeof(UInt32));
            if (err != noErr) {
                printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_MaximumFramesPerSlice\n");
                printError(err);
                goto error;
            }

            err = AudioUnitInitialize(fAUHAL);
            if (err != noErr) {
                printf("Cannot initialize AUHAL unit\n");
                printError(err);
                goto error;
            }

            // Setting format
            if (fDevNumInChans > 0) {
                outSize = sizeof(AudioStreamBasicDescription);
                err = AudioUnitGetProperty(fAUHAL, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Output, 1, &srcFormat, &outSize);
                if (err != noErr) {
                    printf("Error calling AudioUnitGetProperty - kAudioUnitProperty_StreamFormat kAudioUnitScope_Output\n");
                    printError(err);
                }
                PrintStreamDesc(&srcFormat);

                srcFormat.mFormatID = kAudioFormatLinearPCM;
                srcFormat.mFormatFlags = kAudioFormatFlagsNativeFloatPacked | kLinearPCMFormatFlagIsNonInterleaved;
                srcFormat.mBytesPerPacket = sizeof(AudioUnitSampleType);
                srcFormat.mFramesPerPacket = 1;
                srcFormat.mBytesPerFrame = sizeof(AudioUnitSampleType);
                srcFormat.mChannelsPerFrame = fDevNumInChans;
                srcFormat.mBitsPerChannel = 32;

                PrintStreamDesc(&srcFormat);

                err = AudioUnitSetProperty(fAUHAL, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Output, 1, &srcFormat, sizeof(AudioStreamBasicDescription));
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_StreamFormat kAudioUnitScope_Output\n");
                    printError(err);
                }
            }

            if (fDevNumOutChans > 0) {
                outSize = sizeof(AudioStreamBasicDescription);
                err = AudioUnitGetProperty(fAUHAL, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Input, 0, &dstFormat, &outSize);
                if (err != noErr) {
                    printf("Error calling AudioUnitGetProperty - kAudioUnitProperty_StreamFormat kAudioUnitScope_Input\n");
                    printError(err);
                }
                PrintStreamDesc(&dstFormat);

                dstFormat.mFormatID = kAudioFormatLinearPCM;
                dstFormat.mFormatFlags = kAudioFormatFlagsNativeFloatPacked | kLinearPCMFormatFlagIsNonInterleaved;
                dstFormat.mBytesPerPacket = sizeof(AudioUnitSampleType);
                dstFormat.mFramesPerPacket = 1;
                dstFormat.mBytesPerFrame = sizeof(AudioUnitSampleType);
                dstFormat.mChannelsPerFrame = fDevNumOutChans;
                dstFormat.mBitsPerChannel = 32;

                PrintStreamDesc(&dstFormat);

                err = AudioUnitSetProperty(fAUHAL, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Input, 0, &dstFormat, sizeof(AudioStreamBasicDescription));
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_StreamFormat kAudioUnitScope_Input\n");
                    printError(err);
                }
            }

            if (fDevNumInChans > 0 && fDevNumOutChans == 0) {
                AURenderCallbackStruct output;
                output.inputProc = Render;
                output.inputProcRefCon = this;
                err = AudioUnitSetProperty(fAUHAL, kAudioOutputUnitProperty_SetInputCallback, kAudioUnitScope_Global, 0, &output, sizeof(output));
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_SetRenderCallback 1\n");
                    printError(err);
                    goto error;
                }
            } else {
                AURenderCallbackStruct output;
                output.inputProc = Render;
                output.inputProcRefCon = this;
                err = AudioUnitSetProperty(fAUHAL, kAudioUnitProperty_SetRenderCallback, kAudioUnitScope_Input, 0, &output, sizeof(output));
                if (err != noErr) {
                    printf("Error calling AudioUnitSetProperty - kAudioUnitProperty_SetRenderCallback 0\n");
                    printError(err);
                    goto error;
                }
            }

            // Possibly prepare input buffers
            if (fDevNumInChans > 0) {
                fCAInputData = (AudioBufferList*)malloc(sizeof(float) + fDevNumInChans * sizeof(AudioBuffer));
                fCAInputData->mNumberBuffers = fDevNumInChans;
                for (int i = 0; i < fDevNumInChans; i++) {
                    fCAInputData->mBuffers[i].mNumberChannels = 1;
                    fCAInputData->mBuffers[i].mDataByteSize = bufferSize * sizeof(float);
                    fCAInputData->mBuffers[i].mData = malloc(bufferSize * sizeof(float));
                }
            }

            return NO_ERR;

        error:
            AudioUnitUninitialize(fAUHAL);
            AudioComponentInstanceDispose(fAUHAL);
            return OPEN_ERR;
        }

    public:

        TiPhoneCoreAudioRenderer()
            :fAUHAL(0), fDevNumInChans(0), fDevNumOutChans(0),
            fHWNumInChans(0), fHWNumOutChans(0),
            fDSP(0), fCAInputData(NULL), fControlCb(NULL), fControlCbArg(NULL)
        {}

        virtual ~TiPhoneCoreAudioRenderer()
        {
            if (fCAInputData) {
                for (int i = 0; i < fDevNumInChans; i++) {
                    free(fCAInputData->mBuffers[i].mData);
                }
                free(fCAInputData);
            }
        }
    
        void setComputeCb(compute_callback cb, void* arg)
        {
            fControlCb = cb;
            fControlCbArg = arg;
        }
 
        int Open(dsp* dsp, int inChan, int outChan, int buffersize, int samplerate)
        {
            fDSP = dsp;
            fDevNumInChans = inChan;
            fDevNumOutChans = outChan;
      
            // Initialize and configure the audio session
            OSStatus err = AudioSessionInitialize(NULL, NULL, InterruptionListener, this);
            if (err != noErr && err != kAudioSessionAlreadyInitialized) {
                printf("Couldn't initialize audio session\n");
                printError(err);
                return OPEN_ERR;
            }

            if (SetParameters(buffersize, samplerate) < 0) {
                printf("Cannot set parameters to CoreAudio device\n");
                return OPEN_ERR;
            }

            return NO_ERR;
        }

        int Close()
        {
            AudioUnitUninitialize(fAUHAL);
            AudioComponentInstanceDispose(fAUHAL);
            return NO_ERR;
        }

        int Start()
        {
            AudioSessionSetActive(true);

            if (AudioOutputUnitStart(fAUHAL) != noErr) {
                printf("Error while opening device : device open error\n");
                return OPEN_ERR;
            } else {
                return NO_ERR;
            }
        }

        int Stop()
        {
            AudioSessionSetActive(false);

            if (AudioOutputUnitStop(fAUHAL) != noErr) {
                printf("Error while closing device : device close error\n");
                return OPEN_ERR;
            } else {
                return NO_ERR;
            }
        }

        int GetNumInputs() { return fHWNumInChans; }
        int GetNumOutputs() { return fHWNumOutChans; }

};

/******************************************************************************
 *******************************************************************************

                                CORE AUDIO INTERFACE

 *******************************************************************************
 *******************************************************************************/

class iosaudio : public audio {
    
    protected:

        TiPhoneCoreAudioRenderer fAudioDevice;
        int fSampleRate, fBufferSize;
  
    public:

        iosaudio(int srate, int bsize)
        :fSampleRate(srate), fBufferSize(bsize)
        {}

        virtual ~iosaudio() { fAudioDevice.Close(); }
    
        virtual void setComputeCb(compute_callback cb, void* arg)
        {
            fAudioDevice.setComputeCb(cb, arg);
        }

        virtual bool init(const char* /*name*/, dsp* DSP)
        {
            DSP->init(fSampleRate);
            if (fAudioDevice.Open(DSP, DSP->getNumInputs(), DSP->getNumOutputs(), fBufferSize, fSampleRate) < 0) {
                printf("Cannot open iOS audio device\n");
                return false;
            }
            return true;
        }

        virtual bool start()
        {
            if (fAudioDevice.Start() < 0) {
                printf("Cannot start iOS audio device\n");
                return false;
            }
            return true;
        }

        virtual void stop()
        {
            fAudioDevice.Stop();
        }

        virtual int getBufferSize() { return fBufferSize; }
        virtual int getSampleRate() { return fSampleRate; }

        virtual int getNumInputs() { return fAudioDevice.GetNumInputs(); }
        virtual int getNumOutputs() { return fAudioDevice.GetNumOutputs(); }

};

#endif

/********************END ARCHITECTURE SECTION (part 2/2)****************/
#elif ANDROID_DRIVER
    #include <android/log.h>
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __android_dsp__
#define __android_dsp__

#include <android/log.h>
#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>
#include <time.h>


#define CONV16BIT 32767.f
#define CONVMYFLT (1.f/32767.f)

#define NUM_INPUTS 2
#define NUM_OUTPUTS 2
#define CPU_TABLE_SIZE 16

static const char *res_str(SLresult result)
{
    switch(result)
    {
        case SL_RESULT_SUCCESS: return "Success";
        case SL_RESULT_PRECONDITIONS_VIOLATED: return "Preconditions violated";
        case SL_RESULT_PARAMETER_INVALID: return "Parameter invalid";
        case SL_RESULT_MEMORY_FAILURE: return "Memory failure";
        case SL_RESULT_RESOURCE_ERROR: return "Resource error";
        case SL_RESULT_RESOURCE_LOST: return "Resource lost";
        case SL_RESULT_IO_ERROR: return "I/O error";
        case SL_RESULT_BUFFER_INSUFFICIENT: return "Buffer insufficient";
        case SL_RESULT_CONTENT_CORRUPTED: return "Content corrupted";
        case SL_RESULT_CONTENT_UNSUPPORTED: return "Content unsupported";
        case SL_RESULT_CONTENT_NOT_FOUND: return "Content not found";
        case SL_RESULT_PERMISSION_DENIED: return "Permission denied";
        case SL_RESULT_FEATURE_UNSUPPORTED: return "Feature unsupported";
        case SL_RESULT_INTERNAL_ERROR: return "Internal error";
        case SL_RESULT_UNKNOWN_ERROR: return "Unknown error";
        case SL_RESULT_OPERATION_ABORTED: return "Operation aborted";
        case SL_RESULT_CONTROL_LOST: return "Control lost";
#ifdef SL_RESULT_READONLY
        case SL_RESULT_READONLY: return "ReadOnly";
#endif
#ifdef SL_RESULT_ENGINEOPTION_UNSUPPORTED
        case SL_RESULT_ENGINEOPTION_UNSUPPORTED: return "Engine option unsupported";
#endif
#ifdef SL_RESULT_SOURCE_SINK_INCOMPATIBLE
        case SL_RESULT_SOURCE_SINK_INCOMPATIBLE: return "Source/Sink incompatible";
#endif
    }
    return "Unknown error code";
}

struct CircularBuffer {
    
    short* fBuffer;
    int fReadIndex;
    int fWriteIndex;
    int fSize;
    int fChan;
    
    CircularBuffer(int frames, int chan)
    {
        fBuffer = new short[frames * chan];
        memset(fBuffer, 0, sizeof(short) * frames * chan);
        fSize = frames;
        fChan = chan;
        fReadIndex = 0;
        fWriteIndex = frames/2; // Set write index in the middle
    }
    
    ~CircularBuffer()
    {
        delete [] fBuffer;
    }
    
    short* getWritePtr() { return &fBuffer[fWriteIndex * fChan]; }
    short* getReadPtr() { return &fBuffer[fReadIndex * fChan]; }
    
    void moveWritePtr(int frames)
    {
        //__android_log_print(ANDROID_LOG_ERROR, "Faust", "moveWritePtr %x fWriteIndex = %ld", this, fWriteIndex);
        fWriteIndex = (fWriteIndex + frames) % fSize;
    }
    void moveReadPtr(int frames)
    {
        //__android_log_print(ANDROID_LOG_ERROR, "Faust", "moveReadPtr %x fReadIndex = %ld", this,  fReadIndex);
        fReadIndex = (fReadIndex + frames) % fSize;
    }
    
};

//http://stackoverflow.com/questions/17188761/how-to-obtain-computation-time-in-ndk

class androidaudio : public audio {
    
    protected:
    
        dsp* fDSP;
        
        int	fNumInChans;
        int	fNumOutChans;
        
        unsigned int fSampleRate;
        unsigned int fBufferSize;
    
        int64_t fCPUTable[CPU_TABLE_SIZE];
        int fCPUTableIndex;
    
        float** fInputs;
        float** fOutputs;
    
        CircularBuffer fOpenSLInputs;
        CircularBuffer fOpenSLOutputs;
    
        SLObjectItf fOpenSLEngine, fOutputMix, fInputBufferQueue, fOutputBufferQueue;
        SLAndroidSimpleBufferQueueItf fOutputBufferQueueInterface, fInputBufferQueueInterface;
    
        SLRecordItf fRecordInterface;
        SLPlayItf fPlayInterface;
    
        compute_callback fControlCb;
        void* fControlCbArg;
    
        int64_t getTimeUsec() 
        {
            struct timespec now;
            clock_gettime(CLOCK_MONOTONIC, &now);
            return ((int64_t) now.tv_sec * 1000000000LL + now.tv_nsec)/1000;
        }
    
        void processAudio()
        {
            int64_t t1 = getTimeUsec();
       
            // Converting short input to float
            if (fNumInChans > 0) {
                short* input = fOpenSLInputs.getReadPtr();
                for (int chan = 0; chan < NUM_INPUTS; chan++) {
                    for (int i  = 0; i < fBufferSize; i++) {
                        fInputs[chan][i] = float(input[i * NUM_INPUTS + chan] * CONVMYFLT);
                    }
                }
                fOpenSLInputs.moveReadPtr(fBufferSize);
            }
            
            // Compute DSP
            fDSP->compute(fBufferSize, fInputs, fOutputs);
            
            if (fControlCb) {
                fControlCb(fControlCbArg);
            }
            
            // Converting float to short output
            if (fNumOutChans > 0) {
                short* output = fOpenSLOutputs.getWritePtr();
                for (int chan = 0; chan < NUM_OUTPUTS; chan++) {
                    for (int i = 0; i < fBufferSize; i++) {
                        output[i * NUM_OUTPUTS + chan] = short(min(1.f, max(-1.f, fOutputs[chan][i])) * CONV16BIT);
                    }
                }
                fOpenSLOutputs.moveWritePtr(fBufferSize);
            }
            
            int64_t t2 = getTimeUsec();
            fCPUTable[(fCPUTableIndex++)&(CPU_TABLE_SIZE-1)] = t2 - t1;
        }
    
        static void inputCallback(SLAndroidSimpleBufferQueueItf caller, void* arg)
        {
            androidaudio* obj = (androidaudio*)arg;
            obj->inputCallback(caller);
        }
    
        void inputCallback(SLAndroidSimpleBufferQueueItf caller)
        {
            SLresult result = (*caller)->Enqueue(caller, fOpenSLInputs.getWritePtr(), fBufferSize * sizeof(short) * NUM_INPUTS);
            fOpenSLInputs.moveWritePtr(fBufferSize);
            if (result != SL_RESULT_SUCCESS) {
                __android_log_print(ANDROID_LOG_ERROR, "Faust", "inputCallback Enqueue error = %s", res_str(result));
            }
        }
    
        static void outputCallback(SLAndroidSimpleBufferQueueItf caller, void* arg)
        {
            androidaudio* obj = (androidaudio*)arg;
            obj->outputCallback(caller);
        }
    
        void outputCallback(SLAndroidSimpleBufferQueueItf caller)
        {
            // Output callback drives DSP computation
            processAudio();
            
            SLresult result = (*caller)->Enqueue(caller, fOpenSLOutputs.getReadPtr(), fBufferSize * sizeof(short) * NUM_OUTPUTS);
            fOpenSLOutputs.moveReadPtr(fBufferSize);
            if (result != SL_RESULT_SUCCESS) {
                __android_log_print(ANDROID_LOG_ERROR, "Faust", "outputCallback Enqueue error = %s", res_str(result));
            }
        }
          
    public:
    
        androidaudio(long srate, long bsize)
        : fDSP(0), fSampleRate(srate),
        fBufferSize(bsize), fCPUTableIndex(0), fNumInChans(0), fNumOutChans(0),
        fOpenSLEngine(0), fOutputMix(0), fInputBufferQueue(0), fOutputBufferQueue(0),
        fOpenSLInputs(bsize * 4, NUM_INPUTS), fOpenSLOutputs(bsize * 4, NUM_OUTPUTS),
        fControlCb(NULL), fControlCbArg(NULL)
        {
            __android_log_print(ANDROID_LOG_ERROR, "Faust", "Constructor");
            
            // Allocating memory for input channels.
            fInputs = new float*[NUM_INPUTS];
            for (int i = 0; i < NUM_INPUTS; i++) {
                fInputs[i] = new float[fBufferSize];
                memset(fInputs[i], 0, fBufferSize * sizeof(float));
            }
    
            // Allocating memory for output channels.
            fOutputs = new float*[NUM_OUTPUTS];
            for (int i = 0; i < NUM_OUTPUTS; i++) {
                fOutputs[i] = new float[fBufferSize];
                memset(fOutputs[i], 0, fBufferSize * sizeof(float));
            }
        }

        virtual ~androidaudio()
        {
            __android_log_print(ANDROID_LOG_ERROR, "Faust", "Destructor");
            
            if (fInputBufferQueue) {
                (*fInputBufferQueue)->Destroy(fInputBufferQueue);
                fInputBufferQueue = NULL;
            }
            
            if (fOutputBufferQueue) {
                (*fOutputBufferQueue)->Destroy(fOutputBufferQueue);
                fOutputBufferQueue = NULL;
            }
            
            if (fOutputMix) {
                (*fOutputMix)->Destroy(fOutputMix);
                fOutputMix = NULL;
            }
             
            if (fOpenSLEngine) {
                (*fOpenSLEngine)->Destroy(fOpenSLEngine);
                fOpenSLEngine = NULL;
            }
            
            for (int i = 0; i < NUM_INPUTS; i++) {
                delete [] fInputs[i];
            }
            delete [] fInputs;
           
            for (int i = 0; i < NUM_OUTPUTS; i++) {
                delete [] fOutputs[i];
            }
            delete [] fOutputs;
        }
    
        // DSP CPU load in percentage of the buffer size duration
        float getCPULoad()
        {
            float sum = 0.f;
            for (int i = 0; i < CPU_TABLE_SIZE; i++) {
                sum += fCPUTable[i];
            }
            return (sum/float(CPU_TABLE_SIZE))/(10000.f*float(fBufferSize)/float(fSampleRate));
        }
    
        virtual bool init(const char* name, dsp* DSP)
        {
            __android_log_print(ANDROID_LOG_ERROR, "Faust", "init");
            
            fDSP = DSP;
            fNumInChans = fDSP->getNumInputs();
            fNumOutChans = fDSP->getNumOutputs();
            fDSP->init(fSampleRate);
            
            static const SLboolean requireds[2] = { SL_BOOLEAN_TRUE, SL_BOOLEAN_TRUE };
            SLresult result;
            SLuint32 sr;
            
            switch (fSampleRate) {
                    
                case 8000:
                    sr = SL_SAMPLINGRATE_8;
                    break;
                case 11025:
                    sr = SL_SAMPLINGRATE_11_025;
                    break;
                case 16000:
                    sr = SL_SAMPLINGRATE_16;
                    break;
                case 22050:
                    sr = SL_SAMPLINGRATE_22_05;
                    break;
                case 24000:
                    sr = SL_SAMPLINGRATE_24;
                    break;
                case 32000:
                    sr = SL_SAMPLINGRATE_32;
                    break;
                case 44100:
                    sr = SL_SAMPLINGRATE_44_1;
                    break;
                case 48000:
                    sr = SL_SAMPLINGRATE_48;
                    break;
                case 64000:
                    sr = SL_SAMPLINGRATE_64;
                    break;
                case 88200:
                    sr = SL_SAMPLINGRATE_88_2;
                    break;
                case 96000:
                    sr = SL_SAMPLINGRATE_96;
                    break;
                case 192000:
                    sr = SL_SAMPLINGRATE_192;
                    break;
                default:
                    return false;
            }
          
            // Create the OpenSL ES engine.
            result = slCreateEngine(&fOpenSLEngine, 0, NULL, 0, NULL, NULL);
            if (result != SL_RESULT_SUCCESS) {
                __android_log_print(ANDROID_LOG_ERROR, "Faust", "slCreateEngine/fOpenSLEngine error = %s", res_str(result));
                return false;
            }
            
            result = (*fOpenSLEngine)->Realize(fOpenSLEngine, SL_BOOLEAN_FALSE);
            if (result != SL_RESULT_SUCCESS) {
                __android_log_print(ANDROID_LOG_ERROR, "Faust", "Realize/fOpenSLEngine error = %s", res_str(result));
                return false;
            }
            
            SLEngineItf openSLEngineInterface = NULL;
            result = (*fOpenSLEngine)->GetInterface(fOpenSLEngine, SL_IID_ENGINE, &openSLEngineInterface);
            if (result != SL_RESULT_SUCCESS) {
                __android_log_print(ANDROID_LOG_ERROR, "Faust", "GetInterface/fOpenSLEngine error = %s", res_str(result));
                return false;
            }
            
            // Create the output mix.
            result = (*openSLEngineInterface)->CreateOutputMix(openSLEngineInterface, &fOutputMix, 0, NULL, NULL);
            if (result != SL_RESULT_SUCCESS) {
                __android_log_print(ANDROID_LOG_ERROR, "Faust", "CreateOutputMix/openSLEngineInterface error = %s", res_str(result));
                return false;
            }
            
            result = (*fOutputMix)->Realize(fOutputMix, SL_BOOLEAN_FALSE);
            if (result != SL_RESULT_SUCCESS) {
                __android_log_print(ANDROID_LOG_ERROR, "Faust", "Realize/fOutputMix error = %s", res_str(result));
                return false;
            }
        
            SLDataLocator_OutputMix outputMixLocator = { SL_DATALOCATOR_OUTPUTMIX, fOutputMix };
            
            if (fNumInChans > 0) {
                // Create the input buffer queue.
                SLDataLocator_IODevice deviceInputLocator = { SL_DATALOCATOR_IODEVICE, SL_IODEVICE_AUDIOINPUT, SL_DEFAULTDEVICEID_AUDIOINPUT, NULL };
                SLDataSource inputSource = { &deviceInputLocator, NULL };
                SLDataLocator_AndroidSimpleBufferQueue inputLocator = { SL_DATALOCATOR_ANDROIDSIMPLEBUFFERQUEUE, 1 };
                SLDataFormat_PCM inputFormat = { SL_DATAFORMAT_PCM, 2, sr, SL_PCMSAMPLEFORMAT_FIXED_16, SL_PCMSAMPLEFORMAT_FIXED_16, SL_SPEAKER_FRONT_LEFT | SL_SPEAKER_FRONT_RIGHT, SL_BYTEORDER_LITTLEENDIAN };
                SLDataSink inputSink = { &inputLocator, &inputFormat };
                const SLInterfaceID inputInterfaces[2] = { SL_IID_ANDROIDSIMPLEBUFFERQUEUE, SL_IID_ANDROIDCONFIGURATION };
                
                result = (*openSLEngineInterface)->CreateAudioRecorder(openSLEngineInterface, &fInputBufferQueue, &inputSource, &inputSink, 2, inputInterfaces, requireds);
                if (result != SL_RESULT_SUCCESS) {
                    __android_log_print(ANDROID_LOG_ERROR, "Faust", "CreateAudioRecorder/openSLEngineInterface error = %s", res_str(result));
                    return false;
                }
                
            #if DISABLE_AGC
                SLAndroidConfigurationItf configObject;
                result = (*fInputBufferQueue)->GetInterface(fInputBufferQueue, SL_IID_ANDROIDCONFIGURATION, &configObject);
                if (result == SL_RESULT_SUCCESS) {
                    //SLuint32 mode = SL_ANDROID_RECORDING_PRESET_GENERIC;
                    SLuint32 mode = SL_ANDROID_RECORDING_PRESET_VOICE_RECOGNITION;
                    result = (*configObject)->SetConfiguration(configObject, SL_ANDROID_KEY_RECORDING_PRESET, &mode, sizeof(mode));
                    if (result != SL_RESULT_SUCCESS) {
                       __android_log_print(ANDROID_LOG_ERROR, "Faust", "SetConfiguration SL_ANDROID_KEY_RECORDING_PRESET error = %s", res_str(result));
                    }
                } else {
                    __android_log_print(ANDROID_LOG_ERROR, "Faust", "GetInterface SL_IID_ANDROIDCONFIGURATION error = %s", res_str(result));
                }
            #endif
                
                result = (*fInputBufferQueue)->Realize(fInputBufferQueue, SL_BOOLEAN_FALSE);
                if (result != SL_RESULT_SUCCESS) {
                    __android_log_print(ANDROID_LOG_ERROR, "Faust", "Realize/fInputBufferQueue error = %s", res_str(result));
                    return false;
                }
            }
            
            if (fNumOutChans > 0) {
                // Create the output buffer queue.
                SLDataLocator_AndroidSimpleBufferQueue outputLocator = { SL_DATALOCATOR_ANDROIDSIMPLEBUFFERQUEUE, 1 };
                SLDataFormat_PCM outputFormat = { SL_DATAFORMAT_PCM, 2, sr, SL_PCMSAMPLEFORMAT_FIXED_16, SL_PCMSAMPLEFORMAT_FIXED_16, SL_SPEAKER_FRONT_LEFT | SL_SPEAKER_FRONT_RIGHT, SL_BYTEORDER_LITTLEENDIAN };
                SLDataSource outputSource = { &outputLocator, &outputFormat };
                const SLInterfaceID outputInterfaces[1] = { SL_IID_BUFFERQUEUE };
                SLDataSink outputSink = { &outputMixLocator, NULL };
                
                result = (*openSLEngineInterface)->CreateAudioPlayer(openSLEngineInterface, &fOutputBufferQueue, &outputSource, &outputSink, 1, outputInterfaces, requireds);
                if (result != SL_RESULT_SUCCESS) {
                    __android_log_print(ANDROID_LOG_ERROR, "Faust", "CreateAudioPlayer/openSLEngineInterface error  = %s", res_str(result));
                    return false;
                }
                
                result = (*fOutputBufferQueue)->Realize(fOutputBufferQueue, SL_BOOLEAN_FALSE);
                if (result != SL_RESULT_SUCCESS) {
                    __android_log_print(ANDROID_LOG_ERROR, "Faust", "Realize/fOutputBufferQueue error = %s", res_str(result));
                    return false;
                }
            }
            
            if (fNumInChans > 0) { // Initialize
                
                result = (*fInputBufferQueue)->GetInterface(fInputBufferQueue, SL_IID_ANDROIDSIMPLEBUFFERQUEUE, &fInputBufferQueueInterface);
                if (result != SL_RESULT_SUCCESS) {
                    __android_log_print(ANDROID_LOG_ERROR, "Faust", "GetInterface/fInputBufferQueue error = %s", res_str(result));
                    return false;
                }
                
                result = (*fInputBufferQueueInterface)->RegisterCallback(fInputBufferQueueInterface, inputCallback, this);
                if (result != SL_RESULT_SUCCESS) {
                    __android_log_print(ANDROID_LOG_ERROR, "Faust", "RegisterCallback/fInputBufferQueueInterface error = %s", res_str(result));
                    return false;
                }
                
                result = (*fInputBufferQueue)->GetInterface(fInputBufferQueue, SL_IID_RECORD, &fRecordInterface);
                if (result != SL_RESULT_SUCCESS) {
                    __android_log_print(ANDROID_LOG_ERROR, "Faust", "GetInterface/fInputBufferQueue error = %s", res_str(result));
                    return false;
                }
                
                result = (*fInputBufferQueueInterface)->Enqueue(fInputBufferQueueInterface,
                                                                fOpenSLInputs.getWritePtr(),
                                                                fBufferSize * sizeof(short) * NUM_INPUTS);
                fOpenSLInputs.moveWritePtr(fBufferSize);
                if (result != SL_RESULT_SUCCESS) {
                    __android_log_print(ANDROID_LOG_ERROR, "Faust", "Enqueue/fInputBufferQueueInterface error = %s", res_str(result));
                    return false;
                }
                
                result = (*fRecordInterface)->SetRecordState(fRecordInterface, SL_RECORDSTATE_STOPPED);
                if (result != SL_RESULT_SUCCESS) {
                    __android_log_print(ANDROID_LOG_ERROR, "Faust", "SetRecordState/fRecordInterface error = %s", res_str(result));
                }
            }
            
            if (fNumOutChans > 0) { // Initialize
              
                result = (*fOutputBufferQueue)->GetInterface(fOutputBufferQueue, SL_IID_BUFFERQUEUE, &fOutputBufferQueueInterface);
                if (result != SL_RESULT_SUCCESS) {
                    __android_log_print(ANDROID_LOG_ERROR, "Faust", "GetInterface/fOutputBufferQueue error = %s", res_str(result));
                    return false;
                }
                
                result = (*fOutputBufferQueueInterface)->RegisterCallback(fOutputBufferQueueInterface, outputCallback, this);
                if (result != SL_RESULT_SUCCESS) {
                    __android_log_print(ANDROID_LOG_ERROR, "Faust", "RegisterCallback/fOutputBufferQueueInterface error = %s", res_str(result));
                    return false;
                }
                
                result = (*fOutputBufferQueue)->GetInterface(fOutputBufferQueue, SL_IID_PLAY, &fPlayInterface);
                if (result != SL_RESULT_SUCCESS) {
                    __android_log_print(ANDROID_LOG_ERROR, "Faust", "GetInterface/fOutputBufferQueue error = %s", res_str(result));
                    return false;
                }
                
                result = (*fOutputBufferQueueInterface)->Enqueue(fOutputBufferQueueInterface,
                                                                 fOpenSLOutputs.getReadPtr(),
                                                                 fBufferSize * sizeof(short) * NUM_OUTPUTS);
                fOpenSLOutputs.moveReadPtr(fBufferSize);
                if (result != SL_RESULT_SUCCESS) {
                    __android_log_print(ANDROID_LOG_ERROR, "Faust", "Enqueue/fOutputBufferQueueInterface error = %s", res_str(result));
                    return false;
                }
                
                result = (*fPlayInterface)->SetPlayState(fPlayInterface, SL_PLAYSTATE_STOPPED);
                if (result != SL_RESULT_SUCCESS) {
                    __android_log_print(ANDROID_LOG_ERROR, "Faust", "SetPlayState/fPlayInterface error = %s", res_str(result));
                }
            }
            
            return true;
        }
    
        virtual bool start()
        {
            __android_log_print(ANDROID_LOG_ERROR, "Faust", "start");
            SLresult result;
            
            if (fNumInChans > 0) {
                // start the inout buffer queue.
                result = (*fRecordInterface)->SetRecordState(fRecordInterface, SL_RECORDSTATE_RECORDING);
                if (result != SL_RESULT_SUCCESS) {
                    __android_log_print(ANDROID_LOG_ERROR, "Faust", "SetRecordState/fRecordInterface error = %s", res_str(result));
                }
            }
            
            if (fNumOutChans > 0) {
                // start the output buffer queue.
                result = (*fPlayInterface)->SetPlayState(fPlayInterface, SL_PLAYSTATE_PLAYING);
                if (result != SL_RESULT_SUCCESS) {
                    __android_log_print(ANDROID_LOG_ERROR, "Faust", "SetPlayState/fPlayInterface error = %s", res_str(result));
                }
            }
            
            return true;
        }
        
        virtual void stop()
        {
            __android_log_print(ANDROID_LOG_ERROR, "Faust", "stop");
            SLresult result;
            
            if (fNumInChans > 0) {
                result = (*fRecordInterface)->SetRecordState(fRecordInterface, SL_RECORDSTATE_PAUSED);
                if (result != SL_RESULT_SUCCESS) {
                    __android_log_print(ANDROID_LOG_ERROR, "Faust", "SetRecordState/fRecordInterface error = %s", res_str(result));
                }
            }
            
            if (fNumOutChans > 0) {
                result = (*fPlayInterface)->SetPlayState(fPlayInterface, SL_PLAYSTATE_PAUSED);
                if (result != SL_RESULT_SUCCESS) {
                    __android_log_print(ANDROID_LOG_ERROR, "Faust", "SetPlayState/fPlayInterface error = %s", res_str(result));
                }
            }
        }
    
        void setComputeCb(compute_callback cb, void* arg)
        {
            fControlCb = cb;
            fControlCbArg = arg;
        }
    
        virtual int getBufferSize()
        {
            return fBufferSize;
        }
        
        virtual int getSampleRate()
        {
            return fSampleRate;
        }
        
        virtual int getNumInputs()
        {
            return fNumInChans;
        }
        
        virtual int getNumOutputs()
        {
            return fNumOutChans;
        }
    
};

#endif 
#elif ALSA_DRIVER
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __alsa_dsp__
#define __alsa_dsp__

#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <pwd.h>
#include <limits.h>

#include <alsa/asoundlib.h>

/**
DEFAULT ALSA PARAMETERS CONTROLLED BY ENVIRONMENT VARIABLES

Some default parameters of Faust's ALSA applications are controlled by the following environment variables :

    FAUST2ALSA_DEVICE   = "hw:0"
    FAUST2ALSA_FREQUENCY= 44100
    FAUST2ALSA_BUFFER   = 512
    FAUST2ALSA_PERIODS  = 2
*/

// handle 32/64 bits int size issues

#ifdef __x86_64__

#define uint32	unsigned int
#define uint64	unsigned long int

#define int32	int
#define int64	long int

#else

#define uint32	unsigned int
#define uint64	unsigned long long int

#define int32	int
#define int64	long long int
#endif

// check 32/64 bits issues are correctly handled

#define check_error(err) if (err) { printf("%s:%d, alsa error %d : %s\n", __FILE__, __LINE__, err, snd_strerror(err)); exit(1); }
#define check_error_msg(err,msg) if (err) { fprintf(stderr, "%s:%d, %s : %s(%d)\n", __FILE__, __LINE__, msg, snd_strerror(err), err); exit(1); }
#define display_error_msg(err,msg) if (err) { fprintf(stderr, "%s:%d, %s : %s(%d)\n", __FILE__, __LINE__, msg, snd_strerror(err), err); }

/**
 * Used to set the priority and scheduling of the audi#include <sys/types.h>
       #include <pwd.h>
o thread
 */
static bool setRealtimePriority ()
{
    struct passwd*          pw;
    int                     err;
    uid_t                   uid;
    struct sched_param      param;

    uid = getuid ();
    pw = getpwnam ("root");
    err = setuid (pw->pw_uid);
	if (err==0) {
    	param.sched_priority = 50; /* 0 to 99  */
    	err = sched_setscheduler(0, SCHED_RR, &param);
    	err = setuid (uid);
	}
    return (err != -1);
}

/******************************************************************************
*******************************************************************************

								AUDIO INTERFACE

*******************************************************************************
*******************************************************************************/

enum { kRead = 1, kWrite = 2, kReadWrite = 3 };

/**
 * A convenient class to pass parameters to AudioInterface
 */
struct AudioParam
{
 	const char*		fCardName;
	unsigned int	fFrequency;
	unsigned int	fBuffering;
	unsigned int	fPeriods;

	unsigned int	fSoftInputs;
	unsigned int	fSoftOutputs;

 	AudioParam() :
		fCardName("hw:0"),
		fFrequency(44100),
		fBuffering(512),
		fPeriods(2),
		fSoftInputs(2),
		fSoftOutputs(2)
	{}

	AudioParam&	cardName(const char* n)	{ fCardName = n; 		return *this; }
	AudioParam&	frequency(int f)		{ fFrequency = f; 		return *this; }
	AudioParam&	buffering(int fpb)		{ fBuffering = fpb; 	return *this; }
	AudioParam&	periods(int p)			{ fPeriods = p; 		return *this; }
	AudioParam&	inputs(int n)			{ fSoftInputs = n; 		return *this; }
	AudioParam&	outputs(int n)			{ fSoftOutputs = n; 	return *this; }
};

/**
 * An ALSA audio interface
 */
struct AudioInterface : public AudioParam
{

    snd_pcm_t*				fOutputDevice;
	snd_pcm_t*				fInputDevice;
	snd_pcm_hw_params_t* 	fInputParams;
	snd_pcm_hw_params_t* 	fOutputParams;

	snd_pcm_format_t 		fSampleFormat;
	snd_pcm_access_t 		fSampleAccess;

	unsigned int			fCardInputs;
	unsigned int			fCardOutputs;

	unsigned int			fChanInputs;
	unsigned int			fChanOutputs;

	bool					fDuplexMode;

	// interleaved mode audiocard buffers
	void*		fInputCardBuffer;
	void*		fOutputCardBuffer;

	// non interleaved mode audiocard buffers
	void*		fInputCardChannels[256];
	void*		fOutputCardChannels[256];

	// non interleaved mod, floating point software buffers
	float*		fInputSoftChannels[256];
	float*		fOutputSoftChannels[256];

	const char*	cardName()				{ return fCardName;  	}
 	int			frequency()				{ return fFrequency; 	}
	int			buffering()				{ return fBuffering;  	}
	int			periods()				{ return fPeriods;  	}

	float**		inputSoftChannels()		{ return fInputSoftChannels;	}
	float**		outputSoftChannels()	{ return fOutputSoftChannels;	}

	bool		duplexMode()			{ return fDuplexMode; }

	AudioInterface(const AudioParam& ap = AudioParam()) : AudioParam(ap)
	{

		fInputDevice 			= 0;
		fOutputDevice 			= 0;
		fInputParams			= 0;
		fOutputParams			= 0;
	}

	/**
	 * Open the audio interface
	 */
	void open()
	{
		int err;

		// try to open output device, quit if fail to open output device
		err = snd_pcm_open(&fOutputDevice, fCardName, SND_PCM_STREAM_PLAYBACK, 0); check_error(err)

		// setup output device parameters
		err = snd_pcm_hw_params_malloc(&fOutputParams); check_error(err)
		setAudioParams(fOutputDevice, fOutputParams);

		fCardOutputs = fSoftOutputs;
		snd_pcm_hw_params_set_channels_near(fOutputDevice, fOutputParams, &fCardOutputs);
		err = snd_pcm_hw_params(fOutputDevice, fOutputParams ); check_error(err);

		// allocate alsa output buffers
		if (fSampleAccess == SND_PCM_ACCESS_RW_INTERLEAVED) {
			fOutputCardBuffer = calloc(interleavedBufferSize(fOutputParams), 1);
		} else {
			for (unsigned int i = 0; i < fCardOutputs; i++) {
				fOutputCardChannels[i] = calloc(noninterleavedBufferSize(fOutputParams), 1);
			}
        }

		// check for duplex mode (if we need and have an input device)
		if (fSoftInputs == 0) {
			fDuplexMode = false;
			fCardInputs = 0;
		} else {
			// try to open input device
			err = snd_pcm_open( &fInputDevice,  fCardName, SND_PCM_STREAM_CAPTURE, 0 );
			if (err == 0) {
				fDuplexMode = true;
			} else {
				printf("Warning : no input device");
				fDuplexMode = false;
				fCardInputs = 0;
			}
		}

		if (fDuplexMode) {

			// we have and need an input device
			// set the number of physical inputs close to what we need
			err = snd_pcm_hw_params_malloc(&fInputParams); check_error(err);
			setAudioParams(fInputDevice, fInputParams);
			fCardInputs = fSoftInputs;
			snd_pcm_hw_params_set_channels_near(fInputDevice, fInputParams, &fCardInputs);
            err = snd_pcm_hw_params(fInputDevice, fInputParams); check_error(err);

			// allocation of alsa buffers
			if (fSampleAccess == SND_PCM_ACCESS_RW_INTERLEAVED) {
				fInputCardBuffer = calloc(interleavedBufferSize(fInputParams), 1);
			} else {
				for (unsigned int i = 0; i < fCardInputs; i++) {
					fInputCardChannels[i] = calloc(noninterleavedBufferSize(fInputParams), 1);
				}
			}
        }

		printf("inputs : %u, outputs : %u\n", fCardInputs, fCardOutputs);

		// allocation of floating point buffers needed by the dsp code

		fChanInputs = max(fSoftInputs, fCardInputs);		assert (fChanInputs < 256);
		fChanOutputs = max(fSoftOutputs, fCardOutputs);		assert (fChanOutputs < 256);

		for (unsigned int i = 0; i < fChanInputs; i++) {
			fInputSoftChannels[i] = (float*)calloc(fBuffering, sizeof(float));
			for (unsigned int j = 0; j < fBuffering; j++) {
				fInputSoftChannels[i][j] = 0.0;
			}
		}

		for (unsigned int i = 0; i < fChanOutputs; i++) {
			fOutputSoftChannels[i] = (float*)calloc(fBuffering, sizeof(float));
			for (unsigned int j = 0; j < fBuffering; j++) {
				fOutputSoftChannels[i][j] = 0.0;
			}
		}
	}

	void setAudioParams(snd_pcm_t* stream, snd_pcm_hw_params_t* params)
	{
		int	err;

		// set params record with initial values
		err = snd_pcm_hw_params_any(stream, params);
		check_error_msg(err, "unable to init parameters")

		// set alsa access mode (and fSampleAccess field) either to non interleaved or interleaved

		err = snd_pcm_hw_params_set_access(stream, params, SND_PCM_ACCESS_RW_NONINTERLEAVED);
		if (err) {
			err = snd_pcm_hw_params_set_access(stream, params, SND_PCM_ACCESS_RW_INTERLEAVED);
			check_error_msg(err, "unable to set access mode neither to non-interleaved or to interleaved");
		}
		snd_pcm_hw_params_get_access(params, &fSampleAccess);

		// search for 32-bits or 16-bits format
		err = snd_pcm_hw_params_set_format(stream, params, SND_PCM_FORMAT_S32);
		if (err) {
			err = snd_pcm_hw_params_set_format(stream, params, SND_PCM_FORMAT_S16);
		 	check_error_msg(err, "unable to set format to either 32-bits or 16-bits");
		}
		snd_pcm_hw_params_get_format(params, &fSampleFormat);
		// set sample frequency
		snd_pcm_hw_params_set_rate_near (stream, params, &fFrequency, 0);

		// set period and period size (buffering)
		err = snd_pcm_hw_params_set_period_size(stream, params, fBuffering, 0);
		check_error_msg(err, "period size not available");

		err = snd_pcm_hw_params_set_periods(stream, params, fPeriods, 0);
		check_error_msg(err, "number of periods not available");
	}

	ssize_t interleavedBufferSize (snd_pcm_hw_params_t* params)
	{
		_snd_pcm_format 	format;  	snd_pcm_hw_params_get_format(params, &format);
		snd_pcm_uframes_t 	psize;		snd_pcm_hw_params_get_period_size(params, &psize, NULL);
		unsigned int 		channels; 	snd_pcm_hw_params_get_channels(params, &channels);
		ssize_t bsize = snd_pcm_format_size(format, psize * channels);
		return bsize;
	}

	ssize_t noninterleavedBufferSize (snd_pcm_hw_params_t* params)
	{
		_snd_pcm_format 	format;  	snd_pcm_hw_params_get_format(params, &format);
		snd_pcm_uframes_t 	psize;		snd_pcm_hw_params_get_period_size(params, &psize, NULL);
		ssize_t bsize = snd_pcm_format_size(format, psize);
		return bsize;
	}

	void close()
	{}

	/**
	 * Read audio samples from the audio card. Convert samples to floats and take
	 * care of interleaved buffers
	 */
	void read()
	{
        if (fSampleAccess == SND_PCM_ACCESS_RW_INTERLEAVED) {

			int count = snd_pcm_readi(fInputDevice, fInputCardBuffer, fBuffering);
			if (count < 0) {
				 //display_error_msg(count, "reading samples");
				 snd_pcm_prepare(fInputDevice);
				 //check_error_msg(err, "preparing input stream");
			}

			if (fSampleFormat == SND_PCM_FORMAT_S16) {
				short* buffer16b = (short*)fInputCardBuffer;
				for (unsigned int s = 0; s < fBuffering; s++) {
					for (unsigned int c = 0; c < fCardInputs; c++) {
						fInputSoftChannels[c][s] = float(buffer16b[c + s*fCardInputs])*(1.0/float(SHRT_MAX));
					}
				}
			} else if (fSampleFormat == SND_PCM_FORMAT_S32) {
				int32* buffer32b = (int32*)fInputCardBuffer;
				for (unsigned int s = 0; s < fBuffering; s++) {
					for (unsigned int c = 0; c < fCardInputs; c++) {
						fInputSoftChannels[c][s] = float(buffer32b[c + s*fCardInputs])*(1.0/float(INT_MAX));
					}
				}
			} else {
				printf("unrecognized input sample format : %u\n", fSampleFormat);
				exit(1);
			}

		} else if (fSampleAccess == SND_PCM_ACCESS_RW_NONINTERLEAVED) {

			int count = snd_pcm_readn(fInputDevice, fInputCardChannels, fBuffering);
			if (count < 0) {
				 //display_error_msg(count, "reading samples");
				 snd_pcm_prepare(fInputDevice);
				 //check_error_msg(err, "preparing input stream");
			}

			if (fSampleFormat == SND_PCM_FORMAT_S16) {
				for (unsigned int c = 0; c < fCardInputs; c++) {
					short* chan16b = (short*)fInputCardChannels[c];
					for (unsigned int s = 0; s < fBuffering; s++) {
						fInputSoftChannels[c][s] = float(chan16b[s])*(1.0/float(SHRT_MAX));
					}
				}
			} else if (fSampleFormat == SND_PCM_FORMAT_S32) {
				for (unsigned int c = 0; c < fCardInputs; c++) {
					int32* chan32b = (int32*)fInputCardChannels[c];
					for (unsigned int s = 0; s < fBuffering; s++) {
						fInputSoftChannels[c][s] = float(chan32b[s])*(1.0/float(INT_MAX));
					}
				}
			} else {
				printf("unrecognized input sample format : %u\n", fSampleFormat);
				exit(1);
			}

		} else {
			check_error_msg(-10000, "unknown access mode");
		}
    }

	/**
	 * write the output soft channels to the audio card. Convert sample
	 * format and interleaves buffers when needed
	 */
	void write()
	{
		recovery :

		if (fSampleAccess == SND_PCM_ACCESS_RW_INTERLEAVED) {

			if (fSampleFormat == SND_PCM_FORMAT_S16) {
				short* buffer16b = (short*)fOutputCardBuffer;
				for (unsigned int f = 0; f < fBuffering; f++) {
					for (unsigned int c = 0; c < fCardOutputs; c++) {
						float x = fOutputSoftChannels[c][f];
						buffer16b[c + f*fCardOutputs] = short(max(min(x,1.0f),-1.0f) * float(SHRT_MAX)) ;
					}
				}

			} else if (fSampleFormat == SND_PCM_FORMAT_S32)  {
				int32* buffer32b = (int32*)fOutputCardBuffer;
				for (unsigned int f = 0; f < fBuffering; f++) {
					for (unsigned int c = 0; c < fCardOutputs; c++) {
						float x = fOutputSoftChannels[c][f];
						buffer32b[c + f*fCardOutputs] = int(max(min(x,1.0f),-1.0f) * float(INT_MAX));
					}
				}
			} else {
				printf("unrecognized output sample format : %u\n", fSampleFormat);
				exit(1);
			}

			int count = snd_pcm_writei(fOutputDevice, fOutputCardBuffer, fBuffering);
			if (count<0) {
				//display_error_msg(count, "w3");
				snd_pcm_prepare(fOutputDevice);
				//check_error_msg(err, "preparing output stream");
				goto recovery;
			}


		} else if (fSampleAccess == SND_PCM_ACCESS_RW_NONINTERLEAVED) {

			if (fSampleFormat == SND_PCM_FORMAT_S16) {

				for (unsigned int c = 0; c < fCardOutputs; c++) {
					short* chan16b = (short*) fOutputCardChannels[c];
					for (unsigned int f = 0; f < fBuffering; f++) {
						float x = fOutputSoftChannels[c][f];
						chan16b[f] = short(max(min(x,1.0f),-1.0f) * float(SHRT_MAX));
					}
				}

			} else if (fSampleFormat == SND_PCM_FORMAT_S32) {

				for (unsigned int c = 0; c < fCardOutputs; c++) {
					int32* chan32b = (int32*) fOutputCardChannels[c];
					for (unsigned int f = 0; f < fBuffering; f++) {
						float x = fOutputSoftChannels[c][f];
						chan32b[f] = int(max(min(x,1.0f),-1.0f) * float(INT_MAX));
					}
				}

			} else {
				printf("unrecognized output sample format : %u\n", fSampleFormat);
				exit(1);
			}

			int count = snd_pcm_writen(fOutputDevice, fOutputCardChannels, fBuffering);
			if (count<0) {
				//display_error_msg(count, "w3");
				snd_pcm_prepare(fOutputDevice);
				//check_error_msg(err, "preparing output stream");
				goto recovery;
			}

		} else {
			check_error_msg(-10000, "unknown access mode");
		}
	}

	/**
	 *  print short information on the audio device
	 */
	void shortinfo()
	{
		int						err;
		snd_ctl_card_info_t*	card_info;
    	snd_ctl_t*				ctl_handle;
		err = snd_ctl_open(&ctl_handle, fCardName, 0); check_error(err);
		snd_ctl_card_info_alloca (&card_info);
		err = snd_ctl_card_info(ctl_handle, card_info);	check_error(err);
		printf("%s|%d|%d|%d|%d|%s\n",
				snd_ctl_card_info_get_driver(card_info),
				fCardInputs, fCardOutputs,
				fFrequency, fBuffering,
				snd_pcm_format_name((_snd_pcm_format)fSampleFormat));
	}

	/**
	 *  print more detailled information on the audio device
	 */
	void longinfo()
	{
		int						err;
		snd_ctl_card_info_t*	card_info;
    	snd_ctl_t*				ctl_handle;

		printf("Audio Interface Description :\n");
		printf("Sampling Frequency : %d, Sample Format : %s, buffering : %d\n",
				fFrequency, snd_pcm_format_name((_snd_pcm_format)fSampleFormat), fBuffering);
		printf("Software inputs : %2d, Software outputs : %2d\n", fSoftInputs, fSoftOutputs);
		printf("Hardware inputs : %2d, Hardware outputs : %2d\n", fCardInputs, fCardOutputs);
		printf("Channel inputs  : %2d, Channel outputs  : %2d\n", fChanInputs, fChanOutputs);

		// affichage des infos de la carte
		err = snd_ctl_open (&ctl_handle, fCardName, 0); check_error(err);
		snd_ctl_card_info_alloca (&card_info);
		err = snd_ctl_card_info(ctl_handle, card_info); check_error(err);
		printCardInfo(card_info);

		// affichage des infos liees aux streams d'entree-sortie
		if (fSoftInputs > 0)	printHWParams(fInputParams);
		if (fSoftOutputs > 0)	printHWParams(fOutputParams);
	}

	void printCardInfo(snd_ctl_card_info_t*	ci)
	{
		printf("Card info (address : %p)\n", ci);
		printf("\tID         = %s\n", snd_ctl_card_info_get_id(ci));
		printf("\tDriver     = %s\n", snd_ctl_card_info_get_driver(ci));
		printf("\tName       = %s\n", snd_ctl_card_info_get_name(ci));
		printf("\tLongName   = %s\n", snd_ctl_card_info_get_longname(ci));
		printf("\tMixerName  = %s\n", snd_ctl_card_info_get_mixername(ci));
		printf("\tComponents = %s\n", snd_ctl_card_info_get_components(ci));
		printf("--------------\n");
	}

	void printHWParams( snd_pcm_hw_params_t* params )
	{
		printf("HW Params info (address : %p)\n", params);
#if 0
		printf("\tChannels    = %d\n", snd_pcm_hw_params_get_channels(params));
		printf("\tFormat      = %s\n", snd_pcm_format_name((_snd_pcm_format)snd_pcm_hw_params_get_format(params)));
		printf("\tAccess      = %s\n", snd_pcm_access_name((_snd_pcm_access)snd_pcm_hw_params_get_access(params)));
		printf("\tRate        = %d\n", snd_pcm_hw_params_get_rate(params, NULL));
		printf("\tPeriods     = %d\n", snd_pcm_hw_params_get_periods(params, NULL));
		printf("\tPeriod size = %d\n", (int)snd_pcm_hw_params_get_period_size(params, NULL));
		printf("\tPeriod time = %d\n", snd_pcm_hw_params_get_period_time(params, NULL));
		printf("\tBuffer size = %d\n", (int)snd_pcm_hw_params_get_buffer_size(params));
		printf("\tBuffer time = %d\n", snd_pcm_hw_params_get_buffer_time(params, NULL));
#endif
		printf("--------------\n");
	}
    
    int getNumInputs() { return fCardInputs; }
    int getNumOutputs() { return fCardOutputs; }

};

// lopt : Scan Command Line long int Arguments
long lopt(int argc, char *argv[], const char* longname, const char* shortname, long def)
{
	for (int i=2; i<argc; i++)
		if (strcmp(argv[i-1], shortname) == 0 || strcmp(argv[i-1], longname) == 0)
			return atoi(argv[i]);
	return def;
}

// sopt : Scan Command Line string Arguments
const char* sopt(int argc, char *argv[], const char* longname, const char* shortname, const char* def)
{
	for (int i=2; i<argc; i++)
		if (strcmp(argv[i-1], shortname) == 0 || strcmp(argv[i-1], longname) == 0)
			return argv[i];
	return def;
}

// fopt : Scan Command Line flag option (without argument), return true if the flag
bool fopt(int argc, char *argv[], const char* longname, const char* shortname)
{
	for (int i=1; i<argc; i++)
		if (strcmp(argv[i], shortname) == 0 || strcmp(argv[i], longname) == 0)
			return true;
	return false;
}

/**
 * Return the value of an environment variable or defval if undefined.
 */
static int getDefaultEnv(const char* name, int defval)
{
    const char* str = getenv(name);
    if (str) {
        return atoi(str);
    } else {
        return defval;
    }
}

/**
 * Return the value of an environment variable or defval if undefined.
 */
static const char* getDefaultEnv(const char* name, const char* defval)
{
    const char* str = getenv(name);
    if (str) {
        return str;
    } else {
        return defval;
    }
}

/******************************************************************************
*******************************************************************************

							   ALSA audio interface

*******************************************************************************
*******************************************************************************/
static void* __run(void* ptr);

class alsaaudio : public audio
{
	AudioInterface*	fAudio;
	dsp* 			fDSP;
	pthread_t 		fAudioThread;
	bool 			fRunning;

 public:

    alsaaudio(int argc, char *argv[], dsp* DSP) : fDSP(DSP), fRunning(false)
    {
        fAudio = new AudioInterface(AudioParam().cardName(sopt(argc, argv, "--device", "-d", getDefaultEnv("FAUST2ALSA_DEVICE", "hw:0")))
            .frequency(lopt(argc, argv, "--frequency", "-f", getDefaultEnv("FAUST2ALSA_FREQUENCY", 44100)))
            .buffering(lopt(argc, argv, "--buffer", "-b", getDefaultEnv("FAUST2ALSA_BUFFER", 512)))
            .periods(lopt(argc, argv, "--periods", "-p", getDefaultEnv("FAUST2ALSA_PERIODS", 2)))
            .inputs(DSP->getNumInputs())
            .outputs(DSP->getNumOutputs()));
    }
    
    alsaaudio(int srate, int bsize) : fDSP(0), fRunning(false)
    {
        fAudio = new AudioInterface(AudioParam().cardName("hw:0")
                                    .frequency(srate)
                                    .buffering(bsize)
                                    .periods(2));
    }

	virtual ~alsaaudio() { stop(); delete fAudio; }

	virtual bool init(const char* /*name*/, dsp* DSP)
    {
        fDSP = DSP;
        fAudio->inputs(DSP->getNumInputs());
        fAudio->outputs(DSP->getNumOutputs());
		fAudio->open();
	    DSP->init(fAudio->frequency());
 		return true;
	}

    virtual bool start()
    {
        fRunning = true;
        if (pthread_create(&fAudioThread, 0, __run, this)) {
            fRunning = false;
        }
        return fRunning;
    }

    virtual void stop()
    {
        if (fRunning) {
            fRunning = false;
            pthread_join(fAudioThread, 0);
        }
    }
    
    virtual int getBufferSize() { return fAudio->buffering(); }
    virtual int getSampleRate() { return fAudio->frequency(); }

	virtual void run()
    {
		bool rt = setRealtimePriority();
		printf(rt ? "RT : ":"NRT: "); fAudio->shortinfo();
        AVOIDDENORMALS;
		if (fAudio->duplexMode()) {
            fAudio->write();
			fAudio->write();
			while (fRunning) {
				fAudio->read();
				fDSP->compute(fAudio->buffering(), fAudio->inputSoftChannels(), fAudio->outputSoftChannels());
				fAudio->write();
			}
        } else {
            fAudio->write();
			while (fRunning) {
				fDSP->compute(fAudio->buffering(), fAudio->inputSoftChannels(), fAudio->outputSoftChannels());
				fAudio->write();
			}
		}
	}
    
    virtual int getNumInputs() { return fAudio->getNumInputs(); }
    virtual int getNumOutputs() { return fAudio->getNumOutputs(); }

};

void* __run (void* ptr)
{
	alsaaudio * alsa = (alsaaudio*)ptr;
	alsa->run();
	return 0;
}

#endif

/********************END ARCHITECTURE SECTION (part 2/2)****************/

#elif JACK_DRIVER
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __jack_dsp__
#define __jack_dsp__

#include <stdio.h>
#include <cstdlib>
#include <list>
#include <vector>
#include <string.h>
#include <jack/jack.h>
#include <jack/midiport.h>
#ifdef JACK_IOS
#include <jack/custom.h>
#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __jack_midi__
#define __jack_midi__

#include <iostream>
#include <cstdlib>

#include <jack/midiport.h>

class MapUI;

//-----------------------------------------------
// MIDI input/output handling using JACK library
//-----------------------------------------------

class jack_midi_handler : public midi_handler {
    
    
    protected:

        ringbuffer_t* fOutBuffer;

        void writeMessage(double date, unsigned char* buffer, size_t size)
        {
            size_t res;
            DatedMessage dated_message(date, buffer, size);
            if ((res = ringbuffer_write(fOutBuffer, (const char*)&dated_message, sizeof(DatedMessage))) != sizeof(DatedMessage)) {
                std::cerr << "ringbuffer_write error DatedMessage" << std::endl;
            }
        }

        void processMidiInBuffer(void* port_buf_in)
        {
            for (size_t i = 0; i < jack_midi_get_event_count(port_buf_in); ++i) {
                jack_midi_event_t event;
                if (jack_midi_event_get(&event, port_buf_in, i) == 0) {

                    size_t nBytes = event.size;
                    int type = (int)event.buffer[0] & 0xf0;
                    int channel = (int)event.buffer[0] & 0x0f;
                    double time = event.time; // Timestamp in frames

                    // MIDI sync
                    if (nBytes == 1) {
                        handleSync(time, (int)event.buffer[0]);
                    } else if (nBytes == 2) {
                        handleData1(time, type, channel, (int)event.buffer[1]);
                    } else if (nBytes == 3) {
                        handleData2(time, type, channel, (int)event.buffer[1], (int)event.buffer[2]);
                    } else {
                        std::vector<unsigned char> message(event.buffer, event.buffer + event.size);
                        handleMessage(time, type, message);
                    }
                }
            }
        }

        void processMidiOutBuffer(void* port_buf_out_aux, bool reset = false)
        {
            // MIDI output
            unsigned char* port_buf_out = (unsigned char*)port_buf_out_aux;
            if (reset) {
                jack_midi_reset_buffer(port_buf_out);
            } else {
                jack_midi_clear_buffer(port_buf_out);
            }
           
            // Write each message one by one
            DatedMessage dated_message;
            while (ringbuffer_read(fOutBuffer, (char*)&dated_message, sizeof(DatedMessage)) == sizeof(DatedMessage)) {
                jack_midi_data_t* data = jack_midi_event_reserve(port_buf_out, dated_message.fDate, dated_message.fSize);
                if (data) {
                    memcpy(data, dated_message.fBuffer, dated_message.fSize);
                } else {
                    std::cerr << "jack_midi_event_reserve error" << std::endl;
                }
            }
        }

    public:

        jack_midi_handler(const std::string& name = "JACKHandler")
            :midi_handler(name)
        {
            fOutBuffer = ringbuffer_create(8192);
        }
        virtual ~jack_midi_handler()
        {
            ringbuffer_free(fOutBuffer);
        }

        // MIDI output API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            unsigned char buffer[3]
                = { static_cast<unsigned char>(MIDI_NOTE_ON + channel),
                    static_cast<unsigned char>(pitch),
                    static_cast<unsigned char>(velocity) };
            writeMessage(0, buffer, 3);
            return 0;
        }

        void keyOff(int channel, int pitch, int velocity)
        {
            unsigned char buffer[3]
                = { static_cast<unsigned char>(MIDI_NOTE_OFF + channel),
                    static_cast<unsigned char>(pitch),
                    static_cast<unsigned char>(velocity) };
            writeMessage(0, buffer, 3);
        }

        void ctrlChange(int channel, int ctrl, int val)
        {
            unsigned char buffer[3]
                = { static_cast<unsigned char>(MIDI_CONTROL_CHANGE + channel),
                    static_cast<unsigned char>(ctrl),
                    static_cast<unsigned char>(val) };
            writeMessage(0, buffer, 3);
        }

        void chanPress(int channel, int press)
        {
            unsigned char buffer[2]
                = { static_cast<unsigned char>(MIDI_AFTERTOUCH + channel),
                    static_cast<unsigned char>(press) };
            writeMessage(0, buffer, 2);
        }

        void progChange(int channel, int pgm)
        {
            unsigned char buffer[2]
                = { static_cast<unsigned char>(MIDI_PROGRAM_CHANGE + channel),
                    static_cast<unsigned char>(pgm) };
            writeMessage(0, buffer, 2);
        }

        void keyPress(int channel, int pitch, int press)
        {
            unsigned char buffer[3]
                = { static_cast<unsigned char>(MIDI_POLY_AFTERTOUCH + channel),
                    static_cast<unsigned char>(pitch),
                    static_cast<unsigned char>(press) };
            writeMessage(0, buffer, 3);
        }

        void pitchWheel(int channel, int wheel)
        {
            unsigned char buffer[3]
                = { static_cast<unsigned char>(MIDI_PITCH_BEND + channel),
                    static_cast<unsigned char>(wheel & 0x7F),
                    static_cast<unsigned char>((wheel >> 7) & 0x7F) };
            writeMessage(0, buffer, 3);
        }

        void ctrlChange14bits(int channel, int ctrl, int value) {}

        void startSync(double date)
        {
            unsigned char buffer[1] = { MIDI_START };
            writeMessage(date, buffer, 1);
        }
  
        void stopSync(double date)
        {
            unsigned char buffer[1] = { MIDI_STOP };
            writeMessage(date, buffer, 1);
        }

        void clock(double date)
        {
            unsigned char buffer[1] = { MIDI_CLOCK };
            writeMessage(date, buffer, 1);
        }
    
        void sysEx(double date, std::vector<unsigned char>& message)
        {
            writeMessage(date, message.data(), (int)message.size());
        }

};

#endif

#if defined(_WIN32) && !defined(__MINGW32__)
#define snprintf _snprintf_s
#endif

/******************************************************************************
*******************************************************************************

							JACK AUDIO INTERFACE

*******************************************************************************
*******************************************************************************/

class jackaudio : public audio {

    protected:

        dsp*			fDSP;               // FAUST DSP
        jack_client_t*	fClient;            // JACK client

        std::vector<jack_port_t*>	fInputPorts;        // JACK input ports
        std::vector<jack_port_t*>	fOutputPorts;       // JACK output ports

        std::vector<char*> fPhysicalInputs;
        std::vector<char*> fPhysicalOutputs;
    
        compute_callback fControlCb;
        void* fControlCbArg;

        shutdown_callback fShutdown;        // Shutdown callback to be called by libjack
        void*           fShutdownArg;       // Shutdown callback data
        void*           fIconData;          // iOS specific
        int             fIconSize;          // iOS specific
        bool            fAutoConnect;       // autoconnect with system in/out ports

        std::list<std::pair<std::string, std::string> > fConnections;		// Connections list

        static int _jack_srate(jack_nframes_t nframes, void* arg)
        {
            fprintf(stdout, "The sample rate is now %u/sec\n", nframes);
            return 0;
        }

        static void _jack_shutdown(void* arg)
        {}

        static void _jack_info_shutdown(jack_status_t code, const char* reason, void* arg)
        {
            fprintf(stderr, "%s\n", reason);
            static_cast<jackaudio*>(arg)->shutdown(reason);
        }

        static int _jack_process(jack_nframes_t nframes, void* arg)
        {
            return static_cast<jackaudio*>(arg)->process(nframes);
        }

        static int _jack_buffersize(jack_nframes_t nframes, void* arg)
        {
            fprintf(stdout, "The buffer size is now %u/sec\n", nframes);
            return 0;
        }

        #ifdef _OPENMP
        static void* _jack_thread(void* arg)
        {
            jackaudio* audio = (jackaudio*)arg;
            audio->process_thread();
            return 0;
        }
        #endif

        void shutdown(const char* message)
        {
            fClient = NULL;

            if (fShutdown) {
                fShutdown(message, fShutdownArg);
            } else {
                exit(1); // By default
            }
        }

        // Save client connections
        virtual bool saveConnections()
        {
            if (fClient) {
                fConnections.clear();

                for (size_t i = 0; i < fInputPorts.size(); i++) {
                    const char** connected_port = jack_port_get_all_connections(fClient, fInputPorts[i]);
                    if (connected_port != NULL) {
                        for (int port = 0; connected_port[port]; port++) {
                            fConnections.push_back(std::make_pair(connected_port[port], jack_port_name(fInputPorts[i])));
                            // printf("INPUT %s ==> %s\n", connected_port[port], jack_port_name(fInputPorts[i]));
                        }
                        jack_free(connected_port);
                    }
                }

                for (size_t i = 0; i < fOutputPorts.size(); i++) {
                    const char** connected_port = jack_port_get_all_connections(fClient, fOutputPorts[i]);
                    if (connected_port != NULL) {
                        for (int port = 0; connected_port[port]; port++) {
                            fConnections.push_back(std::make_pair(jack_port_name(fOutputPorts[i]), connected_port[port]));
                            // printf("OUTPUT %s ==> %s\n", jack_port_name(fOutputPorts[i]), connected_port[port]);
                        }
                        jack_free(connected_port);
                    }
                }
                return true;
            } else {
                fprintf(stdout, "Client no more running...\n");
                return false;
            }
        }

        // Load client connections
        void loadConnections()
        {
            std::list<std::pair<std::string, std::string> >::const_iterator it;
            for (it = fConnections.begin(); it != fConnections.end(); it++) {
                std::pair<std::string, std::string> connection = *it;
                jack_connect(fClient, connection.first.c_str(), connection.second.c_str());
            }
        }

    #ifdef _OPENMP
        void process_thread()
        {
            jack_nframes_t nframes;
            while (1) {
                nframes = jack_cycle_wait(fClient);
                process(nframes);
                jack_cycle_signal(fClient, 0);
            }
        }
    #endif

        // JACK callbacks
        virtual int	process(jack_nframes_t nframes)
        {
            AVOIDDENORMALS;

            // Retrieve JACK inputs/output audio buffers
            float** fInChannel = (float**)alloca(fInputPorts.size() * sizeof(float*));
            for (size_t i = 0; i < fInputPorts.size(); i++) {
                fInChannel[i] = (float*)jack_port_get_buffer(fInputPorts[i], nframes);
            }

            float** fOutChannel = (float**)alloca(fOutputPorts.size() * sizeof(float*));
            for (size_t i = 0; i < fOutputPorts.size(); i++) {
                fOutChannel[i] = (float*)jack_port_get_buffer(fOutputPorts[i], nframes);
            }

            fDSP->compute(nframes, reinterpret_cast<FAUSTFLOAT**>(fInChannel), reinterpret_cast<FAUSTFLOAT**>(fOutChannel));
            
            if (fControlCb) {
                fControlCb(fControlCbArg);
            }
            return 0;
        }
 
    public:

        jackaudio(const void* icon_data = 0, size_t icon_size = 0, bool auto_connect = true)
            : fDSP(0), fClient(0), fShutdown(0), fShutdownArg(0), fAutoConnect(auto_connect), fControlCb(NULL), fControlCbArg(NULL)
        {
            if (icon_data) {
                fIconData = malloc(icon_size);
                fIconSize = icon_size;
                memcpy(fIconData, icon_data, icon_size);
            } else {
                fIconData = NULL;
                fIconSize = 0;
            }
        }

        virtual ~jackaudio()
        {
            if (fClient) {
                stop();

                for (size_t i = 0; i < fInputPorts.size(); i++) {
                    jack_port_unregister(fClient, fInputPorts[i]);
                }
                for (size_t i = 0; i < fOutputPorts.size(); i++) {
                    jack_port_unregister(fClient, fOutputPorts[i]);
                }
                jack_client_close(fClient);

                if (fIconData) {
                    free(fIconData);
                }
            }
        }

        virtual bool init(const char* name, dsp* dsp)
        {
            if (initAux(name)) {
                if (dsp) { setDsp(dsp); }
                return true;
            } else {
                return false;
            }
        }

        bool initAux(const char* name)
        {
            if ((fClient = jack_client_open(name, JackNullOption, NULL)) == 0) {
                fprintf(stderr, "JACK server not running ?\n");
                return false;
            }
        #ifdef JACK_IOS
            jack_custom_publish_data(fClient, "icon.png", fIconData, fIconSize);
        #endif

        #ifdef _OPENMP
            jack_set_process_thread(fClient, _jack_thread, this);
        #else
            jack_set_process_callback(fClient, _jack_process, this);
        #endif

            jack_set_sample_rate_callback(fClient, _jack_srate, this);
            jack_set_buffer_size_callback(fClient, _jack_buffersize, this);
            jack_on_info_shutdown(fClient, _jack_info_shutdown, this);

            // Get Physical inputs
            int inputs = 0;
            char** physicalInPorts = (char**)jack_get_ports(fClient, NULL, JACK_DEFAULT_AUDIO_TYPE, JackPortIsPhysical|JackPortIsOutput);
            if (physicalInPorts != NULL) {
                while (physicalInPorts[inputs]) {
                    fPhysicalInputs.push_back(physicalInPorts[inputs]);
                    printf("physical input %s\n", physicalInPorts[inputs]);
                    inputs++;
                }
                jack_free(physicalInPorts);
            }

            // Get Physical outputs
            int outputs = 0;
            char** physicalOutPorts = (char**)jack_get_ports(fClient, NULL, JACK_DEFAULT_AUDIO_TYPE, JackPortIsPhysical|JackPortIsInput);
            if (physicalOutPorts != NULL) {
                while (physicalOutPorts[outputs]) {
                    fPhysicalOutputs.push_back(physicalOutPorts[outputs]);
                    printf("physical output %s\n", physicalOutPorts[outputs]);
                    outputs++;
                }
                jack_free(physicalOutPorts);
            }

            return true;
        }

        virtual bool start()
        {
            if (jack_activate(fClient)) {
                fprintf(stderr, "Cannot activate client\n");
                return false;
            }

            if (fConnections.size() > 0) {
                loadConnections();
            } else if (fAutoConnect) {
                defaultConnections();
            }

            return true;
        }

        virtual void stop()
        {
            if (fClient) {
                saveConnections();
                jack_deactivate(fClient);
            }
        }

        virtual void setShutdownCb(shutdown_callback cb, void* arg)
        {
            fShutdown = cb;
            fShutdownArg = arg;
        }
    
        void setComputeCb(compute_callback cb, void* arg)
        {
            fControlCb = cb;
            fControlCbArg = arg;
        }

        virtual int getBufferSize() { return jack_get_buffer_size(fClient); }
        virtual int getSampleRate() { return jack_get_sample_rate(fClient); }

        virtual int getNumInputs()
        {
            return fPhysicalInputs.size();
        }

        virtual int getNumOutputs()
        {
            return fPhysicalOutputs.size();
        }

        // Additional public API

        jack_client_t* getClient() { return fClient; }

        // Connect to physical inputs/outputs
        void defaultConnections()
        {
            // To avoid feedback at launch time, don't connect hardware inputs
            /*
            for (int i = 0; i < fInputPorts.size() && i < fPhysicalOutputs.size(); i++) {
                jack_connect(fClient, fPhysicalInputs[i], jack_port_name(fInputPorts[i]));
            }
            */
            for (size_t i = 0; i < fOutputPorts.size() && i < fPhysicalInputs.size(); i++) {
                jack_connect(fClient, jack_port_name(fOutputPorts[i]), fPhysicalOutputs[i]);
            }
        }

        virtual void setDsp(dsp* dsp)
        {
            // Warning: possible memory leak here... 
            fDSP = (sizeof(FAUSTFLOAT) == 8) ? (new dsp_sample_adapter<double, float>(dsp)) : dsp;

            for (int i = 0; i < fDSP->getNumInputs(); i++) {
                char buf[256];
                snprintf(buf, 256, "in_%d", i);
                fInputPorts.push_back(jack_port_register(fClient, buf, JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0));
            }
            for (int i = 0; i < fDSP->getNumOutputs(); i++) {
                char buf[256];
                snprintf(buf, 256, "out_%d", i);
                fOutputPorts.push_back(jack_port_register(fClient, buf, JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0));
            }

            fDSP->init(jack_get_sample_rate(fClient));
        }

        void connect(jackaudio* driver, int src, int dst, bool reverse)
        {
            if (driver) {
                // Connection between drivers
                jack_port_t* src_port = getOutputPort(src);
                jack_port_t* dst_port = driver->getInputPort(src);
                if (src_port && dst_port) {
                    jack_connect(fClient, jack_port_name(src_port), jack_port_name(dst_port));
                }
            } else if (reverse) {
                // Connection to physical input
                if ((size_t)src > fPhysicalInputs.size()) return;
                jack_port_t* dst_port = getInputPort(dst);
                if (dst_port) {
                    jack_connect(fClient, fPhysicalInputs[src], jack_port_name(dst_port));
                }
            } else {
                // Connection to physical output
                if ((size_t)dst > fPhysicalOutputs.size()) return;
                jack_port_t* src_port = getOutputPort(src);
                if (src_port) {
                    jack_connect(fClient, jack_port_name(src_port), fPhysicalOutputs[dst]);
                }
            }
        }

        void disconnect(jackaudio* driver, int src, int dst, bool reverse)
        {
            if (driver) {
                // Connection between drivers
                jack_port_t* src_port = getOutputPort(src);
                jack_port_t* dst_port = driver->getInputPort(src);
                if (src_port && dst_port) {
                    jack_disconnect(fClient, jack_port_name(src_port), jack_port_name(dst_port));
                }
            } else if (reverse) {
                // Connection to physical input
                if ((size_t)src > fPhysicalInputs.size()) return;
                jack_port_t* dst_port = getInputPort(dst);
                if (dst_port) {
                    jack_disconnect(fClient, fPhysicalInputs[src], jack_port_name(dst_port));
                }
            } else {
                // Connection to physical output
                if ((size_t)dst > fPhysicalOutputs.size()) return;
                jack_port_t* src_port = getOutputPort(src);
                if (src_port) {
                    jack_disconnect(fClient, jack_port_name(src_port), fPhysicalOutputs[dst]);
                }
            }
        }

        bool isConnected(jackaudio* driver, int src, int dst, bool reverse)
        {
            if (driver) {
                // Connection between drivers
                jack_port_t* src_port = getOutputPort(src);
                jack_port_t* dst_port = driver->getInputPort(src);
                if (src_port && dst_port) {
                    return jack_port_connected_to(src_port, jack_port_name(dst_port));
                } else {
                    return false;
                }
            } else if (reverse) {
                // Connection to physical input
                if ((size_t)src > fPhysicalInputs.size()) return false;
                jack_port_t* dst_port = getInputPort(dst);
                if (dst_port) {
                    return jack_port_connected_to(dst_port, fPhysicalInputs[src]);
                } else {
                    return false;
                }
            } else {
                // Connection to physical output
                if ((size_t)dst > fPhysicalOutputs.size()) return false;
                jack_port_t* src_port = getOutputPort(src);
                if (src_port) {
                    return jack_port_connected_to(src_port, fPhysicalOutputs[dst]);
                } else {
                    return false;
                }
            }
        }

        jack_port_t* getInputPort(int port)  { return (port >= 0 && port < (int)fInputPorts.size()) ? fInputPorts[port] : 0; }
        jack_port_t* getOutputPort(int port) { return (port >= 0 && port < (int)fOutputPorts.size()) ? fOutputPorts[port] : 0; }

};

// Add JACK MIDI

class jackaudio_midi : public jackaudio, public jack_midi_handler {

    protected:

        jack_port_t* fInputMidiPort;       // JACK input MIDI port
        jack_port_t* fOutputMidiPort;      // JACK output MIDI port

        virtual bool saveConnections()
        {
            if (jackaudio::saveConnections()) { // Audio connections can be saved, so try MIDI
                
                if (fInputMidiPort) {
                    const char** connected_port = jack_port_get_all_connections(fClient, fInputMidiPort);
                    if (connected_port != NULL) {
                        for (int port = 0; connected_port[port]; port++) {
                            fConnections.push_back(std::make_pair(connected_port[port], jack_port_name(fInputMidiPort)));
                            // printf("INPUT %s ==> %s\n", connected_port[port], jack_port_name(fInputPorts[i]));
                        }
                        jack_free(connected_port);
                    }
                }

                if (fOutputMidiPort) {
                    const char** connected_port = jack_port_get_all_connections(fClient, fOutputMidiPort);
                    if (connected_port != NULL) {
                        for (int port = 0; connected_port[port]; port++) {
                            fConnections.push_back(std::make_pair(jack_port_name(fOutputMidiPort), connected_port[port]));
                            // printf("OUTPUT %s ==> %s\n", jack_port_name(fOutputPorts[i]), connected_port[port]);
                        }
                        jack_free(connected_port);
                    }
                }
                return true;
                
            } else {
                return false;
            }
        }

        virtual void processMidiIn(jack_nframes_t nframes)
        {
            // MIDI input
            if (fInputMidiPort) {
                processMidiInBuffer(jack_port_get_buffer(fInputMidiPort, nframes));
            }
        }

        virtual void processAudio(jack_nframes_t nframes)
        {
            // Audio
            AVOIDDENORMALS;

            // Retrieve JACK inputs/output audio buffers
            float** fInChannel = (float**)alloca(fInputPorts.size() * sizeof(float*));
            for (size_t i = 0; i < fInputPorts.size(); i++) {
                fInChannel[i] = (float*)jack_port_get_buffer(fInputPorts[i], nframes);
            }

            float** fOutChannel = (float**)alloca(fOutputPorts.size() * sizeof(float*));
            for (size_t i = 0; i < fOutputPorts.size(); i++) {
                fOutChannel[i] = (float*)jack_port_get_buffer(fOutputPorts[i], nframes);
            }

            // By convention timestamp of -1 means 'no timestamp conversion' : events already have a timestamp espressed in frames
            fDSP->compute(-1, nframes, reinterpret_cast<FAUSTFLOAT**>(fInChannel), reinterpret_cast<FAUSTFLOAT**>(fOutChannel));
        }

        virtual void processMidiOut(jack_nframes_t nframes)
        {
            // MIDI output
            if (fOutputMidiPort) {
                processMidiOutBuffer(jack_port_get_buffer(fOutputMidiPort, nframes));
            }
        }

        virtual int process(jack_nframes_t nframes)
        {
            // MIDI in
            processMidiIn(nframes);

            // Audio
            processAudio(nframes);

            // MIDI out
            processMidiOut(nframes);
            return 0;
        }

    public:

        jackaudio_midi(const void* icon_data = 0, size_t icon_size = 0, bool auto_connect = true)
            :jackaudio(icon_data, icon_size, auto_connect), jack_midi_handler("JACKMidi"),
            fInputMidiPort(0), fOutputMidiPort(0)
        {}

        virtual ~jackaudio_midi()
        {
            if (fClient) {
                if (fInputMidiPort) { jack_port_unregister(fClient, fInputMidiPort); }
                if (fOutputMidiPort) { jack_port_unregister(fClient, fOutputMidiPort); }
            }
        }
    
        virtual bool init(const char* name, dsp* dsp)
        {
            if (jackaudio::initAux(name)) {
                if (dsp) { setDsp(dsp); }
                fInputMidiPort = jack_port_register(fClient, "midi_in_1", JACK_DEFAULT_MIDI_TYPE, JackPortIsInput, 0);
                fOutputMidiPort = jack_port_register(fClient, "midi_out_1", JACK_DEFAULT_MIDI_TYPE, JackPortIsOutput, 0);
                return true;
            } else {
                return false;
            }
        }

        virtual bool start()
        {
            return jackaudio::start();
        }

        virtual void stop()
        {
            jackaudio::stop();
        }

};

#endif
#elif PORTAUDIO_DRIVER
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __portaudio_dsp__
#define __portaudio_dsp__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <portaudio.h>


static bool pa_error(int err)
{
    if (err != paNoError) {
        printf("PortAudio error: %s\n", Pa_GetErrorText(err));
        return true;
    } else {
        return false;
    }
}

/******************************************************************************
 *******************************************************************************
 
 PORT AUDIO INTERFACE
 
 *******************************************************************************
 *******************************************************************************/

class portaudio : public audio {
    
    protected:
        
        dsp* fDsp;
        PaStream* fAudioStream;
        long fSampleRate;
        long fBufferSize;
        PaStreamParameters fInputParameters;
        PaStreamParameters fOutputParameters;
        
        //----------------------------------------------------------------------------
        // 	Number of physical input and output channels of the PA device
        //----------------------------------------------------------------------------
        int	fDevNumInChans;
        int	fDevNumOutChans;
        
        static int audioCallback(const void* ibuf, void* obuf, unsigned long frames, const PaStreamCallbackTimeInfo* time, PaStreamCallbackFlags, void* drv)
        {
            return static_cast<portaudio*>(drv)->processAudio(time->currentTime, 
                                                            (float**)ibuf, 
                                                            static_cast<float**>(obuf), 
                                                            frames);
        }
        
        virtual int processAudio(PaTime current_time, float** ibuf, float** obuf, unsigned long frames) 
        {
            // Cleanup hardware outputs that are not used by DSP
            for (int i = fDsp->getNumOutputs(); i < fDevNumOutChans; i++) {
                memset(obuf[i], 0, sizeof(FAUSTFLOAT) * fBufferSize);
            }
            
            // Process samples
            fDsp->compute(current_time * 1000000., frames, ibuf, obuf);
            return paContinue;
        }
        
    public:
        
        portaudio(long srate, long bsize) : 
                fDsp(0), fAudioStream(0),
                fSampleRate(srate), fBufferSize(bsize), 
                fDevNumInChans(0), fDevNumOutChans(0) {}
                
        virtual ~portaudio() 
        {   
            if (fAudioStream) {
                pa_error(Pa_StopStream(fAudioStream));
                pa_error(Pa_CloseStream(fAudioStream));
                fAudioStream = 0;
            }
            // Note that Pa_Initialize handled multiple times calls and 
            // must be matched with a corresponding call to Pa_Terminate
            Pa_Terminate();
        }
        
        virtual bool init(const char* name, dsp* DSP)
        {
            if (init(name, DSP->getNumInputs(), DSP->getNumOutputs())) {
                setDsp(DSP);
                return true;
            } else {
                return false;
            }
        }
        
        bool init(const char* /*name*/, int numInputs, int numOutputs)
        {         
            // Note that Pa_Initialize handled multiple times calls and 
            // must be matched with a corresponding call to Pa_Terminate
            if (pa_error(Pa_Initialize())) {
                return false;
            }
            
            const PaDeviceInfo*	idev = Pa_GetDeviceInfo(Pa_GetDefaultInputDevice());
            const PaDeviceInfo*	odev = Pa_GetDeviceInfo(Pa_GetDefaultOutputDevice());
            
            printf("DEVICE = %p || %p\n", idev, odev);
            
            //In case there is no audio device, the function fails
            
            if (idev == NULL) {
                fDevNumInChans = 0;
            } else {
                fDevNumInChans = idev->maxInputChannels;
                fInputParameters.device = Pa_GetDefaultInputDevice();
                fInputParameters.sampleFormat = paFloat32 | paNonInterleaved;
                fInputParameters.channelCount = fDevNumInChans;
                fInputParameters.hostApiSpecificStreamInfo = 0;
            }
            
            if (odev == NULL) {
                fDevNumOutChans = 0;
            } else{
                fDevNumOutChans = odev->maxOutputChannels;
                fOutputParameters.device = Pa_GetDefaultOutputDevice();
                fOutputParameters.sampleFormat = paFloat32 | paNonInterleaved;;
                fOutputParameters.channelCount = fDevNumOutChans;
                fOutputParameters.hostApiSpecificStreamInfo = 0;
            }
            
            // A DSP that has only outputs or only inputs forces the presence of an output or input device
            if (numInputs == 0 && numOutputs != 0 && fDevNumOutChans == 0) {
                printf("Devices not adapted to DSP\n");
                return false;
            }
            
            if (numInputs != 0 && numOutputs == 0 && fDevNumInChans == 0) {
                printf("Devices not adapted to DSP\n");
                return false;
            }
            
            // If no device exists : the function fails
            PaError err;
            if ((err = Pa_IsFormatSupported(((fDevNumInChans > 0) ? &fInputParameters : 0),
                                            ((fDevNumOutChans > 0) ? &fOutputParameters : 0), fSampleRate)) != 0) {
                printf("stream format is not supported err = %d\n", err);
                return false;
            }
            
            if (pa_error(Pa_OpenStream(&fAudioStream, ((fDevNumInChans > 0) ? &fInputParameters : 0),
                                       ((fDevNumOutChans > 0) ? &fOutputParameters : 0), 
                                       fSampleRate, fBufferSize, paNoFlag, audioCallback, this))) {
                return false;
            }    
            
            return true;
        }
        
        void setDsp(dsp* DSP)
        {
            fDsp = DSP;
            if (fDsp->getNumInputs() > fDevNumInChans || fDsp->getNumOutputs() > fDevNumOutChans) {
                printf("DSP has %d inputs and %d outputs, physical inputs = %d physical outputs = %d \n", 
                       fDsp->getNumInputs(), fDsp->getNumOutputs(), 
                       fDevNumInChans, fDevNumOutChans);
                fDsp = new dsp_adapter(fDsp, fDevNumInChans, fDevNumOutChans, fBufferSize);
            }
            
            fDsp->init(fSampleRate);
        }
        
        virtual bool start() 
        {
            if (pa_error(Pa_StartStream(fAudioStream))) {
                return false;
            } else {
                return true;
            }
        }
        
        virtual void stop() 
        {
            if (fAudioStream) {
                pa_error(Pa_StopStream(fAudioStream));
            }
        }
        
        virtual int getBufferSize() 
        { 
            return fBufferSize; 
        }
        
        virtual int getSampleRate()
        { 
            return fSampleRate; 
        }
        
        virtual int getNumInputs()
        {
            return fDevNumInChans;
        }
        
        virtual int getNumOutputs()
        {
            return fDevNumOutChans;
        }
};

#endif
#elif RTAUDIO_DRIVER
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __rtaudio_dsp__
#define __rtaudio_dsp__

#include <stdio.h>
#include <assert.h>
#include <RtAudio.h>
#include <stdlib.h>


#define FORMAT RTAUDIO_FLOAT32

/******************************************************************************
 *******************************************************************************
 
 RTAUDIO INTERFACE
 
 *******************************************************************************
 *******************************************************************************/

class rtaudio : public audio {
    
    protected:
        
        dsp* fDsp;
        RtAudio fAudioDAC;
        unsigned int fSampleRate;
        unsigned int fBufferSize;
         
        //----------------------------------------------------------------------------
        // 	number of physical input and output channels of the PA device
        //----------------------------------------------------------------------------
        int	fDevNumInChans;
        int	fDevNumOutChans;
        
        virtual int processAudio(double streamTime, void* inbuf, void* outbuf, unsigned long frames) 
        {
            float* inputs[fDsp->getNumInputs()];
            float* outputs[fDsp->getNumOutputs()];
            
            for (int i = 0; i < fDsp->getNumInputs(); i++) {
                inputs[i] = &(static_cast<float*>(inbuf))[i * frames];
            }
            for (int i = 0; i < fDsp->getNumOutputs(); i++) {
                outputs[i] = &(static_cast<float*>(outbuf))[i * frames];
            }

            // process samples
            fDsp->compute(streamTime * 1000000., frames, inputs, outputs);
            return 0;
        }
    
        static int audioCallback(void* outputBuffer, void* inputBuffer, 
                                unsigned int nBufferFrames,
                                double streamTime, RtAudioStreamStatus status, 
                                void* drv)
        {
            return static_cast<rtaudio*>(drv)->processAudio(streamTime, inputBuffer, outputBuffer, nBufferFrames);
        }
      
    public:
        
        rtaudio(int srate, int bsize) : fDsp(0),
                fSampleRate(srate), fBufferSize(bsize), 
                fDevNumInChans(0), fDevNumOutChans(0) {}
            
        virtual ~rtaudio() 
        {   
            try {
                fAudioDAC.stopStream();
                fAudioDAC.closeStream();
            } catch (RtAudioError& e) {
                std::cout << '\n' << e.getMessage() << '\n' << std::endl;
            }
        }
        
        virtual bool init(const char* name, dsp* DSP)
        {
            if (init(name, DSP->getNumInputs(), DSP->getNumOutputs())) {
                setDsp(DSP);
                return true;
            } else {
                return false;
            }
        }
        
        bool init(const char* /*name*/, int numInputs, int numOutputs)
        {           
            if (fAudioDAC.getDeviceCount() < 1) {
                std::cout << "No audio devices found!\n";
                return false;
            }
            
            RtAudio::DeviceInfo info_in = fAudioDAC.getDeviceInfo(fAudioDAC.getDefaultInputDevice());
            RtAudio::DeviceInfo info_out = fAudioDAC.getDeviceInfo(fAudioDAC.getDefaultOutputDevice());
            RtAudio::StreamParameters iParams, oParams;
            
            iParams.deviceId = fAudioDAC.getDefaultInputDevice();
            fDevNumInChans = info_in.inputChannels;
            iParams.nChannels = fDevNumInChans;
            iParams.firstChannel = 0;
            
            oParams.deviceId = fAudioDAC.getDefaultOutputDevice();
            fDevNumOutChans = info_out.outputChannels;
            oParams.nChannels = fDevNumOutChans;
            oParams.firstChannel = 0;
            
            RtAudio::StreamOptions options;
            options.flags |= RTAUDIO_NONINTERLEAVED;
         
            try {
                fAudioDAC.openStream(((numOutputs > 0) ? &oParams : NULL), 
                    ((numInputs > 0) ? &iParams : NULL), FORMAT, 
                    fSampleRate, &fBufferSize, audioCallback, this, &options);
            } catch (RtAudioError& e) {
                std::cout << '\n' << e.getMessage() << '\n' << std::endl;
                return false;
            }
               
            return true;
        }
        
        void setDsp(dsp* DSP)
        {
            fDsp = DSP;
            
            if (fDsp->getNumInputs() > fDevNumInChans || fDsp->getNumOutputs() > fDevNumOutChans) {
                printf("DSP has %d inputs and %d outputs, physical inputs = %d physical outputs = %d \n", 
                       fDsp->getNumInputs(), fDsp->getNumOutputs(), 
                       fDevNumInChans, fDevNumOutChans);
                fDsp = new dsp_adapter(fDsp, fDevNumInChans, fDevNumOutChans, fBufferSize);
            }
            
            fDsp->init(fSampleRate);
        }
        
        virtual bool start() 
        {
            try {
                fAudioDAC.startStream();
            } catch (RtAudioError& e) {
                std::cout << '\n' << e.getMessage() << '\n' << std::endl;
                return false;
            }
            return true;
        }
        
        virtual void stop() 
        {
            try {
                fAudioDAC.stopStream();
            } catch (RtAudioError& e) {
                std::cout << '\n' << e.getMessage() << '\n' << std::endl;
            }
        }
        
        virtual int getBufferSize() 
        { 
            return fBufferSize; 
        }
        
        virtual int getSampleRate()
        { 
            return fSampleRate; 
        }
        
        virtual int getNumInputs()
        {
            return fDevNumInChans;
        }
        
        virtual int getNumOutputs()
        {
            return fDevNumOutChans;
        }
};

#endif
#elif OPEN_FRAMEWORK_DRIVER
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __openframework__
#define __openframework__

#include "ofSoundStream.h"
#include "ofBaseTypes.h"


class ofaudio : public audio, public ofBaseSoundInput, public ofBaseSoundOutput {
    
    private:
    
        ofSoundStream fStream;
        float* fInBuffer;
        float** fNIInputs;
        float** fNIOutputs;
        int fSampleRate;
        int fBufferSize;
        dsp* fDSP;
    
    public:
    
        ofaudio(int srate, int bsize):fInBuffer(nullptr), fSampleRate(srate), fBufferSize(bsize) {}
        virtual ~ofaudio()
        {
            fStream.stop();
            fStream.close();
            
            for (int i = 0; i < fDSP->getNumInputs(); i++) {
                delete [] fNIInputs[i];
            }
            delete [] fNIInputs;
            
            for (int i = 0; i < fDSP->getNumOutputs(); i++) {
                delete [] fNIOutputs[i];
            }
            delete [] fNIOutputs;
        }
    
        void audioIn(float* input, int bufferSize, int nChannels)
        {
            // Keep the input buffer to be used in 'audioOut' for the same audio cycle
            fInBuffer = input;
        }
    
        void audioOut(float* output, int bufferSize, int nChannels)
        {
            // Deinterleave input (= fInBuffer)
            for (int chan = 0; chan < fDSP->getNumInputs(); chan++) {
                for (int frame = 0; frame < bufferSize; frame++) {
                    fNIInputs[chan][frame] = fInBuffer[chan + frame * fDSP->getNumInputs()];
                }
            }
            
            fDSP->compute(bufferSize, fNIInputs, fNIOutputs);
            
            // Interleave output
            for (int chan = 0; chan < fDSP->getNumOutputs(); chan++) {
                for (int frame = 0; frame < bufferSize; frame++) {
                    output[chan + frame * fDSP->getNumOutputs()] = fNIOutputs[chan][frame];
                }
            }
        }

        bool init(const char* name, dsp* dsp)
        {
            fDSP = dsp;
            
            //fStream.printDeviceList();
            
            fNIInputs = new float*[fDSP->getNumInputs()];
            for (int i = 0; i < fDSP->getNumInputs(); i++) {
                fNIInputs[i] = new float[4046];
            }
            fNIOutputs = new float*[fDSP->getNumOutputs()];
            for (int i = 0; i < fDSP->getNumOutputs(); i++) {
                fNIOutputs[i] = new float[4046];
            }
            
            if (fDSP->getNumInputs() > 0) {
                fStream.setInput(this);
            }
            if (fDSP->getNumOutputs() > 0) {
                fStream.setOutput(this);
            }
            
            fDSP->init(fSampleRate);
            return true;
        }
    
        bool start()
        {
            // 'setup' also starts the stream...
            return fStream.setup(fDSP->getNumOutputs(), fDSP->getNumInputs(), fSampleRate, fBufferSize, 1);
        }
    
        void stop()
        {
            fStream.stop();
        }
    
        void setShutdownCb(shutdown_callback cb, void* arg) {}

        int getBufferSize()
        {
            return fStream.getBufferSize();
        }
    
        int getSampleRate()
        {
            return fStream.getSampleRate();
        }

        int getNumInputs() { return fStream.getNumInputChannels(); }
        int getNumOutputs() { return fStream.getNumOutputChannels(); }

        float getCPULoad() { return 0.f; }
};
					
#endif
#elif JUCE_DRIVER
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __juce_dsp__
#define __juce_dsp__

#include "../JuceLibraryCode/JuceHeader.h"


class juceaudio : public audio, private AudioAppComponent {
    
    private:
        
        dsp* fDSP;
    
        void prepareToPlay(int, double) override
        {
            const BigInteger activeInputChannels = deviceManager.getCurrentAudioDevice()->getActiveInputChannels();
            const BigInteger activeOutputChannels = deviceManager.getCurrentAudioDevice()->getActiveOutputChannels();
            const int maxInputChannels = activeInputChannels.getHighestBit() + 1;
            const int maxOutputChannels = activeOutputChannels.getHighestBit() + 1;
            
            // Possibly adapt DSP...
            if (fDSP->getNumInputs() > maxInputChannels || fDSP->getNumOutputs() > maxOutputChannels) {
                fDSP = new dsp_adapter(fDSP, maxInputChannels, maxOutputChannels, 4096);
            }
            
            fDSP->init(int(deviceManager.getCurrentAudioDevice()->getCurrentSampleRate()));
        }
        
        void releaseResources() override
        {}
        
        void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) override
        {
            AVOIDDENORMALS;
            
            const float** inputs = (const float**)alloca(fDSP->getNumInputs() * sizeof(float));
            for (int i = 0; i < fDSP->getNumInputs(); i++) {
                inputs[i] = bufferToFill.buffer->getReadPointer(i, bufferToFill.startSample);
            }
            
            float** outputs = (float**)alloca(fDSP->getNumOutputs() * sizeof(float));
            for (int i = 0; i < fDSP->getNumOutputs(); i++) {
                outputs[i] = bufferToFill.buffer->getWritePointer(i, bufferToFill.startSample);
            }
            
            // MIDI timestamp is expressed in frames
            fDSP->compute(-1, bufferToFill.numSamples, (float**)inputs, outputs);
        }
    
    public:
    
        juceaudio() {}
        virtual ~juceaudio()
        {
            shutdownAudio();
        }
        
        bool init(const char* name, dsp* dsp) override
        {
            fDSP = dsp;
            return true;
        }
        
        bool start() override
        {
            setAudioChannels (fDSP->getNumInputs(), fDSP->getNumOutputs());
            prepareToPlay(0, 0); // Unused samplerate and buffersize, taken from deviceManager
            return true;
        }
        
        void stop() override
        {
            shutdownAudio();
        }
        
        int getBufferSize() override
        {
            return int(deviceManager.getCurrentAudioDevice()->getCurrentBufferSizeSamples());
        }
        
        int getSampleRate() override
        {
            return int(deviceManager.getCurrentAudioDevice()->getCurrentSampleRate());
        }
        
        int getNumInputs() override { return deviceManager.getCurrentAudioDevice()->getActiveInputChannels().toInteger(); }
        int getNumOutputs() override { return deviceManager.getCurrentAudioDevice()->getActiveOutputChannels().toInteger(); }
        
        float getCPULoad() override { return float(deviceManager.getCpuUsage()); }
};

#endif
#elif DUMMY_DRIVER
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dummy_audio__
#define __dummy_audio__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <iomanip>

#ifdef USE_PTHREAD
#include <pthread.h>
#else
#include <thread>
#endif
			

#define BUFFER_TO_RENDER 10

class dummyaudio : public audio {

    private:

        dsp* fDSP;

        long fSampleRate;
        long fBufferSize;
    
        FAUSTFLOAT** fInChannel;
        FAUSTFLOAT** fOutChannel;
    
        int fNumInputs;
        int fNumOutputs;
    
        bool fRunning;

        int fRender;
        int fCount;
        int fSample;
        bool fManager;
    
#ifdef USE_PTHREAD
        pthread_t fAudioThread;
        static void* run(void* ptr)
        {
            dummyaudio* audio = (dummyaudio*)ptr;
            audio->process();
            return 0;
        }
#else
		static void run(dummyaudio* audio)
		{
			audio->process();
		}
		std::thread* fAudioThread = 0;
#endif
    
        void process()
        {
            while (fRunning && (--fRender > 0)) {
                if (fSample > 0) { std::cout << "Render one buffer\n"; }
                render();
            }
            fRunning = false;
        }

    public:

        dummyaudio(int sr, int bs, int count = BUFFER_TO_RENDER, int sample = -1, bool manager = false)
            :fSampleRate(sr), fBufferSize(bs),
            fInChannel(0), fOutChannel(0),
            fRender(0), fCount(count),
            fSample(sample), fManager(manager)
        {}
    
        dummyaudio(int count = BUFFER_TO_RENDER)
            :fSampleRate(48000), fBufferSize(512),
            fInChannel(0), fOutChannel(0),
            fRender(0), fCount(count),
            fSample(512), fManager(false)
        {}
    
        virtual ~dummyaudio()
        {
            for (int i = 0; i < fNumInputs; i++) {
                delete[] fInChannel[i];
            }
            for (int i = 0; i < fNumOutputs; i++) {
               delete[] fOutChannel[i];
            }
            
            delete [] fInChannel;
            delete [] fOutChannel;
        }

        virtual bool init(const char* name, dsp* dsp)
        {
            fDSP = dsp;
            
            // To be used in destructor
            fNumInputs = fDSP->getNumInputs();
            fNumOutputs = fDSP->getNumOutputs();
            
            if (fManager) {
                // classInit is called elsewhere with a custom memory manager
                fDSP->instanceInit(fSampleRate);
            } else {
                fDSP->init(fSampleRate);
            }
            
            fInChannel = new FAUSTFLOAT*[fDSP->getNumInputs()];
            fOutChannel = new FAUSTFLOAT*[fDSP->getNumOutputs()];
            
            for (int i = 0; i < fDSP->getNumInputs(); i++) {
                fInChannel[i] = new FAUSTFLOAT[fBufferSize];
                memset(fInChannel[i], 0, sizeof(FAUSTFLOAT) * fBufferSize);
            }
            for (int i = 0; i < fDSP->getNumOutputs(); i++) {
                fOutChannel[i] = new FAUSTFLOAT[fBufferSize];
                memset(fOutChannel[i], 0, sizeof(FAUSTFLOAT) * fBufferSize);
            }
            return true;
        }
    
        virtual bool start()
        {
            fRender = fCount;
            fRunning = true;
            if (fCount == INT_MAX) {
#ifdef USE_PTHREAD
                if (pthread_create(&fAudioThread, 0, run, this) != 0) {
                    fRunning = false;
                }
#else
				fAudioThread = new std::thread (dummyaudio::run, this);
#endif
                return fRunning;
            } else {
                process();
                return true;
            }
        }
    
        virtual void stop()
        {
            if (fRunning) {
                fRunning = false;
#ifdef USE_PTHREAD
                pthread_join(fAudioThread, 0);
#else
				fAudioThread->join();
				delete fAudioThread;
				fAudioThread = 0;
#endif
            }
        }

        void render()
        {
            fDSP->compute(fBufferSize, fInChannel, fOutChannel);
            if (fDSP->getNumInputs() > 0) {
                for (int frame = 0; frame < fSample; frame++) {
                    std::cout << std::fixed << std::setprecision(6) << "sample in " << fInChannel[0][frame] << std::endl;
                }
            }
            if (fDSP->getNumOutputs() > 0) {
                for (int frame = 0; frame < fSample; frame++) {
                    std::cout << std::fixed << std::setprecision(6) << "sample out " << fOutChannel[0][frame] << std::endl;
                }
            }
        }
    
        virtual int getBufferSize() { return fBufferSize; }
        virtual int getSampleRate() { return fSampleRate; }
    
        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
    
};

#endif
#endif

//**************************************************************
// Interface
//**************************************************************

#if MIDICTRL
#if JACK_DRIVER
    // Nothing to add since jack-dsp.h contains MIDI
#elif JUCE_DRIVER
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __juce_midi__
#define __juce_midi__
 

class MapUI;

//-----------------------------------------------
// MIDI input/output handling using JUCE library
//-----------------------------------------------

class juce_midi_handler : public midi_handler {
    
    protected:
    
        MidiBuffer fOutputBuffer;
        CriticalSection fMutex;
    
        void decodeMessage(const MidiMessage& message)
        {
            const uint8* data = message.getRawData();
            
            if (message.isNoteOff()) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyOff(message.getTimeStamp(), message.getChannel(), data[1], data[2]);
                }
            } else if (message.isNoteOn()) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    if (data[1] != 0) {
                        fMidiInputs[i]->keyOn(message.getTimeStamp(), message.getChannel(), data[1], data[2]);
                    } else {
                        fMidiInputs[i]->keyOff(message.getTimeStamp(), message.getChannel(), data[1], data[2]);
                    }
                }
            } else if (message.isAftertouch()) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->keyPress(message.getTimeStamp(), message.getChannel(), data[1], data[2]);
                }
            } else if (message.isController()) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->ctrlChange(message.getTimeStamp(), message.getChannel(), data[1], data[2]);
                }
            } else if (message.isProgramChange()) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->progChange(message.getTimeStamp(), message.getChannel(), data[1]);
                }
            } else if (message.isChannelPressure()) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->chanPress(message.getTimeStamp(), message.getChannel(), data[1]);
                }
            } else if (message.isPitchWheel()) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->pitchWheel(message.getTimeStamp(), message.getChannel(), ((data[1] << 7) + data[2]));
                }
            } else if (message.isMidiClock()) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->clock(message.getTimeStamp());
                }
            } else if (message.isMidiStart()) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->startSync(message.getTimeStamp());
                }
            } else if (message.isMidiStop()) {
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->stopSync(message.getTimeStamp());
                }
            } else if (message.isSysEx()) {
                std::vector<unsigned char> sysex(data, data + message.getRawDataSize());
                for (unsigned int i = 0; i < fMidiInputs.size(); i++) {
                    fMidiInputs[i]->sysEx(message.getTimeStamp(), sysex);
                }
            } else {
                std::cerr << "Unused MIDI message" << std::endl;
            }
        }
    
    public:
    
        juce_midi_handler():midi_handler("JUCE")
        {}
    
        virtual ~juce_midi_handler() {}
    
        // Used with MidiBuffer (containing several messages)
        void encodeBuffer(MidiBuffer& buffer)
        {
            const ScopedTryLock lock(fMutex);
            if (lock.isLocked()) {
                buffer.swapWith(fOutputBuffer);
                fOutputBuffer.clear();
            } else {
                std::cerr << "encodeBuffer fails..." << std::endl;
            }
        }
        
        void decodeBuffer(MidiBuffer& buffer)
        {
            MidiMessage msg;
            int ignore;

            for (MidiBuffer::Iterator it(buffer); it.getNextEvent(msg, ignore);) {
                decodeMessage(msg);
            }
            
            buffer.clear();
        }
    
        // MIDI output API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            fOutputBuffer.addEvent(MidiMessage::noteOn(channel + 1, pitch, uint8(velocity)), 0);
            return nullptr;
        }
        
        void keyOff(int channel, int pitch, int velocity)
        {
            fOutputBuffer.addEvent(MidiMessage::noteOff(channel + 1, pitch, uint8(velocity)), 0);
        }
        
        void ctrlChange(int channel, int ctrl, int val)
        {
            fOutputBuffer.addEvent(MidiMessage::controllerEvent(channel + 1, ctrl, uint8(val)), 0);
        }
        
        void chanPress(int channel, int press)
        {
            fOutputBuffer.addEvent(MidiMessage::channelPressureChange(channel + 1, press), 0);
        }
        
        void progChange(int channel, int pgm)
        {
            fOutputBuffer.addEvent(MidiMessage::programChange(channel + 1, pgm), 0);
        }
        
        void keyPress(int channel, int pitch, int press)
        {
            fOutputBuffer.addEvent(MidiMessage::aftertouchChange(channel + 1, pitch, press), 0);
        }
        
        void pitchWheel(int channel, int wheel)
        {
            fOutputBuffer.addEvent(MidiMessage::pitchWheel(channel + 1, range(0, 16383, wheel)), 0);
        }
        
        void ctrlChange14bits(int channel, int ctrl, int value)
        {
            // TODO
        }
        
        void startSync(double date)
        {
            fOutputBuffer.addEvent(MidiMessage::midiStart(), 0);
        }
        
        void stopSync(double date)
        {
            fOutputBuffer.addEvent(MidiMessage::midiStop(), 0);
        }
        
        void clock(double date)
        {
            fOutputBuffer.addEvent(MidiMessage::midiClock(), 0);
        }
    
        void sysEx(double date, std::vector<unsigned char>& message)
        {
            fOutputBuffer.addEvent(MidiMessage(message.data(), (int)message.size()), 0);
        }

};

class juce_midi : public juce_midi_handler, public MidiInputCallback {

    private:
    
        MidiInput* fMidiIn;
        MidiOutput* fMidiOut;
    
        void handleIncomingMidiMessage(MidiInput*, const MidiMessage& message)
        {
            decodeMessage(message);
        }
    
    public:
    
        virtual ~juce_midi()
        {
            stopMidi();
        }
        
        bool startMidi()
        {
            if ((fMidiIn = MidiInput::openDevice(MidiInput::getDefaultDeviceIndex(), this)) == nullptr) {
                return false;
            }
            if ((fMidiOut = MidiOutput::openDevice(MidiOutput::getDefaultDeviceIndex())) == nullptr) {
                return false;
            }
            
            fMidiIn->start();
            return true;
        }
        
        void stopMidi()
        { 
            fMidiIn->stop();
            delete fMidiIn;
            delete fMidiOut;
        }
    
        // MIDI output API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            fMidiOut->sendMessageNow(MidiMessage::noteOn(channel + 1, pitch, uint8(velocity)));
            return nullptr;
        }
        
        void keyOff(int channel, int pitch, int velocity) 
        {
            fMidiOut->sendMessageNow(MidiMessage::noteOff(channel + 1, pitch, uint8(velocity)));
        }
        
        void ctrlChange(int channel, int ctrl, int val) 
        {
            fMidiOut->sendMessageNow(MidiMessage::controllerEvent(channel + 1, ctrl, uint8(val)));
        }
        
        void chanPress(int channel, int press) 
        {
            fMidiOut->sendMessageNow(MidiMessage::channelPressureChange(channel + 1, press));
        }
        
        void progChange(int channel, int pgm) 
        {
            fMidiOut->sendMessageNow(MidiMessage::programChange(channel + 1, pgm));
        }
          
        void keyPress(int channel, int pitch, int press) 
        {
            fMidiOut->sendMessageNow(MidiMessage::aftertouchChange(channel + 1, pitch, press));
        }
   
        void pitchWheel(int channel, int wheel) 
        {
            fMidiOut->sendMessageNow(MidiMessage::pitchWheel(channel + 1, range(0, 16383, wheel)));
        }
        
        void ctrlChange14bits(int channel, int ctrl, int value)
        {
            // TODO
        }
    
        void startSync(double date) 
        {
            fMidiOut->sendMessageNow(MidiMessage::midiStart());
        }
       
        void stopSync(double date) 
        {
            fMidiOut->sendMessageNow(MidiMessage::midiStop());
        }
        
        void clock(double date) 
        {
            fMidiOut->sendMessageNow(MidiMessage::midiClock());
        }
    
        void sysEx(double date, std::vector<unsigned char>& message)
        {
            fMidiOut->sendMessageNow(MidiMessage(message.data(), (int)message.size()));
        }
    
};

#endif // __juce_midi__

#else
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __rt_midi__
#define __rt_midi__ 
 
#include <iostream>
#include <cstdlib>
/*
 File: CAHostTimeBase.h 
 Abstract: Part of CoreAudio Utility Classes  
 Version: 1.0.3 
  
 Disclaimer: IMPORTANT:  This Apple software is supplied to you by Apple 
 Inc. ("Apple") in consideration of your agreement to the following 
 terms, and your use, installation, modification or redistribution of 
 this Apple software constitutes acceptance of these terms.  If you do 
 not agree with these terms, please do not use, install, modify or 
 redistribute this Apple software. 
  
 In consideration of your agreement to abide by the following terms, and 
 subject to these terms, Apple grants you a personal, non-exclusive 
 license, under Apple's copyrights in this original Apple software (the 
 "Apple Software"), to use, reproduce, modify and redistribute the Apple 
 Software, with or without modifications, in source and/or binary forms; 
 provided that if you redistribute the Apple Software in its entirety and 
 without modifications, you must retain this notice and the following 
 text and disclaimers in all such redistributions of the Apple Software. 
 Neither the name, trademarks, service marks or logos of Apple Inc. may 
 be used to endorse or promote products derived from the Apple Software 
 without specific prior written permission from Apple.  Except as 
 expressly stated in this notice, no other rights or licenses, express or 
 implied, are granted by Apple herein, including but not limited to any 
 patent rights that may be infringed by your derivative works or by other 
 works in which the Apple Software may be incorporated. 
  
 The Apple Software is provided by Apple on an "AS IS" basis.  APPLE 
 MAKES NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION 
 THE IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS 
 FOR A PARTICULAR PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND 
 OPERATION ALONE OR IN COMBINATION WITH YOUR PRODUCTS. 
  
 IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL 
 OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 INTERRUPTION) ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION, 
 MODIFICATION AND/OR DISTRIBUTION OF THE APPLE SOFTWARE, HOWEVER CAUSED 
 AND WHETHER UNDER THEORY OF CONTRACT, TORT (INCLUDING NEGLIGENCE), 
 STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN ADVISED OF THE 
 POSSIBILITY OF SUCH DAMAGE. 
  
 Copyright (C) 2013 Apple Inc. All Rights Reserved. 
*/

#if !defined(__CAHostTimeBase_h__)
#define __CAHostTimeBase_h__

#ifdef __APPLE__

//=============================================================================
//	Includes
//=============================================================================

#if !defined(__COREAUDIO_USE_FLAT_INCLUDES__)
	#include <CoreAudio/CoreAudioTypes.h>
#else
	#include <CoreAudioTypes.h>
#endif

#if TARGET_OS_MAC
	#include <mach/mach_time.h>
#elif TARGET_OS_WIN32
	#include <windows.h>
#else
	#error	Unsupported operating system
#endif

//=============================================================================
//	CAHostTimeBase
//
//	This class provides platform independent access to the host's time base.
//=============================================================================

class CAHostTimeBase
{

public:
	static UInt64	ConvertToNanos(UInt64 inHostTime);
	static UInt64	ConvertFromNanos(UInt64 inNanos);

	static UInt64	GetTheCurrentTime();
#if TARGET_OS_MAC
	static UInt64	GetCurrentTime() { return GetTheCurrentTime(); }
#endif
	static UInt64	GetCurrentTimeInNanos();

	static Float64	GetFrequency() { if(!sIsInited) { Initialize(); } return sFrequency; }
	static Float64	GetInverseFrequency() { if(!sIsInited) { Initialize(); } return sInverseFrequency; }
	static UInt32	GetMinimumDelta() { if(!sIsInited) { Initialize(); } return sMinDelta; }

	static UInt64	AbsoluteHostDeltaToNanos(UInt64 inStartTime, UInt64 inEndTime);
	static SInt64	HostDeltaToNanos(UInt64 inStartTime, UInt64 inEndTime);
    
    static void     Initialize();

private:
	
	static bool sIsInited;
	
	static Float64 sFrequency;
	static Float64 sInverseFrequency;
	static UInt32 sMinDelta;
	static UInt32 sToNanosNumerator;
	static UInt32 sToNanosDenominator;
	static UInt32 sFromNanosNumerator;
	static UInt32 sFromNanosDenominator;
	static bool sUseMicroseconds;
#if Track_Host_TimeBase
	static UInt64	sLastTime;
#endif
};

inline UInt64 CAHostTimeBase::GetTheCurrentTime()
{
	UInt64 theTime = 0;

	#if TARGET_OS_MAC
		theTime = mach_absolute_time();
          
	#elif TARGET_OS_WIN32
		LARGE_INTEGER theValue;
		QueryPerformanceCounter(&theValue);
		theTime = *((UInt64*)&theValue);
	#endif
	
	#if	Track_Host_TimeBase
		if(sLastTime != 0)
		{
			if(theTime <= sLastTime)
			{
				DebugMessageN2("CAHostTimeBase::GetTheCurrentTime: the current time is earlier than the last time, now: %qd, then: %qd", theTime, sLastTime);
			}
			sLastTime = theTime;
		}
		else
		{
			sLastTime = theTime;
		}
	#endif

	return theTime;
}

inline UInt64 CAHostTimeBase::ConvertToNanos(UInt64 inHostTime)
{
	if(!sIsInited)
	{
		Initialize();
	}
	
	Float64 theNumerator = static_cast<Float64>(sToNanosNumerator);
	Float64 theDenominator = static_cast<Float64>(sToNanosDenominator);
	Float64 theHostTime = static_cast<Float64>(inHostTime);

	Float64 thePartialAnswer = theHostTime / theDenominator;
	Float64 theFloatAnswer = thePartialAnswer * theNumerator;
	UInt64 theAnswer = static_cast<UInt64>(theFloatAnswer);

	return theAnswer;
}

inline UInt64 CAHostTimeBase::ConvertFromNanos(UInt64 inNanos)
{
	if(!sIsInited)
	{
		Initialize();
	}

	Float64 theNumerator = static_cast<Float64>(sToNanosNumerator);
	Float64 theDenominator = static_cast<Float64>(sToNanosDenominator);
	Float64 theNanos = static_cast<Float64>(inNanos);

	Float64 thePartialAnswer = theNanos / theNumerator;
	Float64 theFloatAnswer = thePartialAnswer * theDenominator;
	UInt64 theAnswer = static_cast<UInt64>(theFloatAnswer);

	return theAnswer;
}

inline UInt64 CAHostTimeBase::GetCurrentTimeInNanos()
{
	return ConvertToNanos(GetTheCurrentTime());
}

inline UInt64 CAHostTimeBase::AbsoluteHostDeltaToNanos(UInt64 inStartTime, UInt64 inEndTime)
{
	UInt64 theAnswer;
	
	if(inStartTime <= inEndTime)
	{
		theAnswer = inEndTime - inStartTime;
	}
	else
	{
		theAnswer = inStartTime - inEndTime;
	}
	
	return ConvertToNanos(theAnswer);
}

inline SInt64 CAHostTimeBase::HostDeltaToNanos(UInt64 inStartTime, UInt64 inEndTime)
{
	SInt64 theAnswer;
	SInt64 theSign = 1;
	
	if(inStartTime <= inEndTime)
	{
		theAnswer = inEndTime - inStartTime;
	}
	else
	{
		theAnswer = inStartTime - inEndTime;
		theSign = -1;
	}
	
	return theSign * ConvertToNanos(theAnswer);
}

#endif // __APPLE__

#endif

/**********************************************************************/
/*! \class RtMidi
    \brief An abstract base class for realtime MIDI input/output.

    This class implements some common functionality for the realtime
    MIDI input/output subclasses RtMidiIn and RtMidiOut.

    RtMidi WWW site: http://music.mcgill.ca/~gary/rtmidi/

    RtMidi: realtime MIDI i/o C++ classes
    Copyright (c) 2003-2014 Gary P. Scavone

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation files
    (the "Software"), to deal in the Software without restriction,
    including without limitation the rights to use, copy, modify, merge,
    publish, distribute, sublicense, and/or sell copies of the Software,
    and to permit persons to whom the Software is furnished to do so,
    subject to the following conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    Any person wishing to distribute modifications to the Software is
    asked to send the modifications to the original developer so that
    they can be incorporated into the canonical version.  This is,
    however, not a binding provision of this license.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
    ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
    CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
/**********************************************************************/

/*!
  \file RtMidi.h
 */

#ifndef RTMIDI_H
#define RTMIDI_H

#define RTMIDI_VERSION "2.1.0"

#include <exception>
#include <iostream>
#include <string>
#include <vector>

#if __APPLE__
#define __MACOSX_CORE__ 1
//#define __UNIX_JACK__ 1
#endif

#if __linux__
#define __LINUX_ALSA__ 1
#endif

#if _WIN32
#define __WINDOWS_MM__ 1
#endif

/************************************************************************/
/*! \class RtMidiError
    \brief Exception handling class for RtMidi.

    The RtMidiError class is quite simple but it does allow errors to be
    "caught" by RtMidiError::Type. See the RtMidi documentation to know
    which methods can throw an RtMidiError.
*/
/************************************************************************/

class RtMidiError : public std::exception
{
 public:
  //! Defined RtMidiError types.
  enum Type {
    WARNING,           /*!< A non-critical error. */
    DEBUG_WARNING,     /*!< A non-critical error which might be useful for debugging. */
    UNSPECIFIED,       /*!< The default, unspecified error type. */
    NO_DEVICES_FOUND,  /*!< No devices found on system. */
    INVALID_DEVICE,    /*!< An invalid device ID was specified. */
    MEMORY_ERROR,      /*!< An error occured during memory allocation. */
    INVALID_PARAMETER, /*!< An invalid parameter was specified to a function. */
    INVALID_USE,       /*!< The function was called incorrectly. */
    DRIVER_ERROR,      /*!< A system driver error occured. */
    SYSTEM_ERROR,      /*!< A system error occured. */
    THREAD_ERROR       /*!< A thread error occured. */
  };

  //! The constructor.
  RtMidiError( const std::string& message, Type type = RtMidiError::UNSPECIFIED ) throw() : message_(message), type_(type) {}
 
  //! The destructor.
  virtual ~RtMidiError( void ) throw() {}

  //! Prints thrown error message to stderr.
  virtual void printMessage( void ) const throw() { std::cerr << '\n' << message_ << "\n\n"; }

  //! Returns the thrown error message type.
  virtual const Type& getType(void) const throw() { return type_; }

  //! Returns the thrown error message string.
  virtual const std::string& getMessage(void) const throw() { return message_; }

  //! Returns the thrown error message as a c-style string.
  virtual const char* what( void ) const throw() { return message_.c_str(); }

 protected:
  std::string message_;
  Type type_;
};

//! RtMidi error callback function prototype.
/*!
    \param type Type of error.
    \param errorText Error description.

    Note that class behaviour is undefined after a critical error (not
    a warning) is reported.
 */
typedef void (*RtMidiErrorCallback)( RtMidiError::Type type, const std::string &errorText );

class MidiApi;

class RtMidi
{
 public:

  //! MIDI API specifier arguments.
  enum Api {
    UNSPECIFIED,    /*!< Search for a working compiled API. */
    MACOSX_CORE,    /*!< Macintosh OS-X Core Midi API. */
    LINUX_ALSA,     /*!< The Advanced Linux Sound Architecture API. */
    UNIX_JACK,      /*!< The JACK Low-Latency MIDI Server API. */
    WINDOWS_MM,     /*!< The Microsoft Multimedia MIDI API. */
    RTMIDI_DUMMY    /*!< A compilable but non-functional API. */
  };

  //! A static function to determine the current RtMidi version.
  static std::string getVersion( void ) throw();

  //! A static function to determine the available compiled MIDI APIs.
  /*!
    The values returned in the std::vector can be compared against
    the enumerated list values.  Note that there can be more than one
    API compiled for certain operating systems.
  */
  static void getCompiledApi( std::vector<RtMidi::Api> &apis ) throw();

  //! Pure virtual openPort() function.
  virtual void openPort( unsigned int portNumber = 0, const std::string portName = std::string( "RtMidi" ) ) = 0;

  //! Pure virtual openVirtualPort() function.
  virtual void openVirtualPort( const std::string portName = std::string( "RtMidi" ) ) = 0;

  //! Pure virtual getPortCount() function.
  virtual unsigned int getPortCount() = 0;

  //! Pure virtual getPortName() function.
  virtual std::string getPortName( unsigned int portNumber = 0 ) = 0;

  //! Pure virtual closePort() function.
  virtual void closePort( void ) = 0;

  //! Returns true if a port is open and false if not.
  virtual bool isPortOpen( void ) const = 0;

  //! Set an error callback function to be invoked when an error has occured.
  /*!
    The callback function will be called whenever an error has occured. It is best
    to set the error callback function before opening a port.
  */
  virtual void setErrorCallback( RtMidiErrorCallback errorCallback = NULL ) = 0;

 protected:

  RtMidi();
  virtual ~RtMidi();

  MidiApi *rtapi_;
};

/**********************************************************************/
/*! \class RtMidiIn
    \brief A realtime MIDI input class.

    This class provides a common, platform-independent API for
    realtime MIDI input.  It allows access to a single MIDI input
    port.  Incoming MIDI messages are either saved to a queue for
    retrieval using the getMessage() function or immediately passed to
    a user-specified callback function.  Create multiple instances of
    this class to connect to more than one MIDI device at the same
    time.  With the OS-X, Linux ALSA, and JACK MIDI APIs, it is also
    possible to open a virtual input port to which other MIDI software
    clients can connect.

    by Gary P. Scavone, 2003-2014.
*/
/**********************************************************************/

// **************************************************************** //
//
// RtMidiIn and RtMidiOut class declarations.
//
// RtMidiIn / RtMidiOut are "controllers" used to select an available
// MIDI input or output interface.  They present common APIs for the
// user to call but all functionality is implemented by the classes
// MidiInApi, MidiOutApi and their subclasses.  RtMidiIn and RtMidiOut
// each create an instance of a MidiInApi or MidiOutApi subclass based
// on the user's API choice.  If no choice is made, they attempt to
// make a "logical" API selection.
//
// **************************************************************** //

class RtMidiIn : public RtMidi
{
 public:

  //! User callback function type definition.
  typedef void (*RtMidiCallback)( double timeStamp, std::vector<unsigned char> *message, void *userData);

  //! Default constructor that allows an optional api, client name and queue size.
  /*!
    An exception will be thrown if a MIDI system initialization
    error occurs.  The queue size defines the maximum number of
    messages that can be held in the MIDI queue (when not using a
    callback function).  If the queue size limit is reached,
    incoming messages will be ignored.

    If no API argument is specified and multiple API support has been
    compiled, the default order of use is ALSA, JACK (Linux) and CORE,
    JACK (OS-X).

    \param api        An optional API id can be specified.
    \param clientName An optional client name can be specified. This
                      will be used to group the ports that are created
                      by the application.
    \param queueSizeLimit An optional size of the MIDI input queue can be specified.
  */
  RtMidiIn( RtMidi::Api api=UNSPECIFIED,
            const std::string clientName = std::string( "RtMidi Input Client"),
            unsigned int queueSizeLimit = 100 );

  //! If a MIDI connection is still open, it will be closed by the destructor.
  ~RtMidiIn ( void ) throw();

  //! Returns the MIDI API specifier for the current instance of RtMidiIn.
  RtMidi::Api getCurrentApi( void ) throw();

  //! Open a MIDI input connection given by enumeration number.
  /*!
    \param portNumber An optional port number greater than 0 can be specified.
                      Otherwise, the default or first port found is opened.
    \param portName An optional name for the application port that is used to connect to portId can be specified.
  */
  void openPort( unsigned int portNumber = 0, const std::string portName = std::string( "RtMidi Input" ) );

  //! Create a virtual input port, with optional name, to allow software connections (OS X, JACK and ALSA only).
  /*!
    This function creates a virtual MIDI input port to which other
    software applications can connect.  This type of functionality
    is currently only supported by the Macintosh OS-X, any JACK,
    and Linux ALSA APIs (the function returns an error for the other APIs).

    \param portName An optional name for the application port that is
                    used to connect to portId can be specified.
  */
  void openVirtualPort( const std::string portName = std::string( "RtMidi Input" ) );

  //! Set a callback function to be invoked for incoming MIDI messages.
  /*!
    The callback function will be called whenever an incoming MIDI
    message is received.  While not absolutely necessary, it is best
    to set the callback function before opening a MIDI port to avoid
    leaving some messages in the queue.

    \param callback A callback function must be given.
    \param userData Optionally, a pointer to additional data can be
                    passed to the callback function whenever it is called.
  */
  void setCallback( RtMidiCallback callback, void *userData = 0 );

  //! Cancel use of the current callback function (if one exists).
  /*!
    Subsequent incoming MIDI messages will be written to the queue
    and can be retrieved with the \e getMessage function.
  */
  void cancelCallback();

  //! Close an open MIDI connection (if one exists).
  void closePort( void );

  //! Returns true if a port is open and false if not.
  virtual bool isPortOpen() const;

  //! Return the number of available MIDI input ports.
  /*!
    \return This function returns the number of MIDI ports of the selected API.
  */
  unsigned int getPortCount();

  //! Return a string identifier for the specified MIDI input port number.
  /*!
    \return The name of the port with the given Id is returned.
    \retval An empty string is returned if an invalid port specifier is provided.
  */
  std::string getPortName( unsigned int portNumber = 0 );

  //! Specify whether certain MIDI message types should be queued or ignored during input.
  /*!
    By default, MIDI timing and active sensing messages are ignored
    during message input because of their relative high data rates.
    MIDI sysex messages are ignored by default as well.  Variable
    values of "true" imply that the respective message type will be
    ignored.
  */
  void ignoreTypes( bool midiSysex = true, bool midiTime = true, bool midiSense = true );

  //! Fill the user-provided vector with the data bytes for the next available MIDI message in the input queue and return the event delta-time in seconds.
  /*!
    This function returns immediately whether a new message is
    available or not.  A valid message is indicated by a non-zero
    vector size.  An exception is thrown if an error occurs during
    message retrieval or an input connection was not previously
    established.
  */
  double getMessage( std::vector<unsigned char> *message );

  //! Set an error callback function to be invoked when an error has occured.
  /*!
    The callback function will be called whenever an error has occured. It is best
    to set the error callback function before opening a port.
  */
  virtual void setErrorCallback( RtMidiErrorCallback errorCallback = NULL );

 protected:
  void openMidiApi( RtMidi::Api api, const std::string clientName, unsigned int queueSizeLimit );

};

/**********************************************************************/
/*! \class RtMidiOut
    \brief A realtime MIDI output class.

    This class provides a common, platform-independent API for MIDI
    output.  It allows one to probe available MIDI output ports, to
    connect to one such port, and to send MIDI bytes immediately over
    the connection.  Create multiple instances of this class to
    connect to more than one MIDI device at the same time.  With the
    OS-X, Linux ALSA and JACK MIDI APIs, it is also possible to open a
    virtual port to which other MIDI software clients can connect.

    by Gary P. Scavone, 2003-2014.
*/
/**********************************************************************/

class RtMidiOut : public RtMidi
{
 public:

  //! Default constructor that allows an optional client name.
  /*!
    An exception will be thrown if a MIDI system initialization error occurs.

    If no API argument is specified and multiple API support has been
    compiled, the default order of use is ALSA, JACK (Linux) and CORE,
    JACK (OS-X).
  */
  RtMidiOut( RtMidi::Api api=UNSPECIFIED,
             const std::string clientName = std::string( "RtMidi Output Client") );

  //! The destructor closes any open MIDI connections.
  ~RtMidiOut( void ) throw();

  //! Returns the MIDI API specifier for the current instance of RtMidiOut.
  RtMidi::Api getCurrentApi( void ) throw();

  //! Open a MIDI output connection.
  /*!
      An optional port number greater than 0 can be specified.
      Otherwise, the default or first port found is opened.  An
      exception is thrown if an error occurs while attempting to make
      the port connection.
  */
  void openPort( unsigned int portNumber = 0, const std::string portName = std::string( "RtMidi Output" ) );

  //! Close an open MIDI connection (if one exists).
  void closePort( void );

  //! Returns true if a port is open and false if not.
  virtual bool isPortOpen() const;

  //! Create a virtual output port, with optional name, to allow software connections (OS X, JACK and ALSA only).
  /*!
      This function creates a virtual MIDI output port to which other
      software applications can connect.  This type of functionality
      is currently only supported by the Macintosh OS-X, Linux ALSA
      and JACK APIs (the function does nothing with the other APIs).
      An exception is thrown if an error occurs while attempting to
      create the virtual port.
  */
  void openVirtualPort( const std::string portName = std::string( "RtMidi Output" ) );

  //! Return the number of available MIDI output ports.
  unsigned int getPortCount( void );

  //! Return a string identifier for the specified MIDI port type and number.
  /*!
      An empty string is returned if an invalid port specifier is provided.
  */
  std::string getPortName( unsigned int portNumber = 0 );

  //! Immediately send a single message out an open MIDI output port.
  /*!
      An exception is thrown if an error occurs during output or an
      output connection was not previously established.
  */
  void sendMessage( std::vector<unsigned char> *message );

  //! Set an error callback function to be invoked when an error has occured.
  /*!
    The callback function will be called whenever an error has occured. It is best
    to set the error callback function before opening a port.
  */
  virtual void setErrorCallback( RtMidiErrorCallback errorCallback = NULL );

 protected:
  void openMidiApi( RtMidi::Api api, const std::string clientName );
};


// **************************************************************** //
//
// MidiInApi / MidiOutApi class declarations.
//
// Subclasses of MidiInApi and MidiOutApi contain all API- and
// OS-specific code necessary to fully implement the RtMidi API.
//
// Note that MidiInApi and MidiOutApi are abstract base classes and
// cannot be explicitly instantiated.  RtMidiIn and RtMidiOut will
// create instances of a MidiInApi or MidiOutApi subclass.
//
// **************************************************************** //

class MidiApi
{
 public:

  MidiApi();
  virtual ~MidiApi();
  virtual RtMidi::Api getCurrentApi( void ) = 0;
  virtual void openPort( unsigned int portNumber, const std::string portName ) = 0;
  virtual void openVirtualPort( const std::string portName ) = 0;
  virtual void closePort( void ) = 0;

  virtual unsigned int getPortCount( void ) = 0;
  virtual std::string getPortName( unsigned int portNumber ) = 0;

  inline bool isPortOpen() const { return connected_; }
  void setErrorCallback( RtMidiErrorCallback errorCallback );

  //! A basic error reporting function for RtMidi classes.
  void error( RtMidiError::Type type, std::string errorString );

protected:
  virtual void initialize( const std::string& clientName ) = 0;

  void *apiData_;
  bool connected_;
  std::string errorString_;
  RtMidiErrorCallback errorCallback_;
};

class MidiInApi : public MidiApi
{
 public:

  MidiInApi( unsigned int queueSizeLimit );
  virtual ~MidiInApi( void );
  void setCallback( RtMidiIn::RtMidiCallback callback, void *userData );
  void cancelCallback( void );
  virtual void ignoreTypes( bool midiSysex, bool midiTime, bool midiSense );
  double getMessage( std::vector<unsigned char> *message );

  // A MIDI structure used internally by the class to store incoming
  // messages.  Each message represents one and only one MIDI message.
  struct MidiMessage { 
    std::vector<unsigned char> bytes; 
    double timeStamp;

    // Default constructor.
  MidiMessage()
  :bytes(0), timeStamp(0.0) {}
  };

  struct MidiQueue {
    unsigned int front;
    unsigned int back;
    unsigned int size;
    unsigned int ringSize;
    MidiMessage *ring;

    // Default constructor.
  MidiQueue()
  :front(0), back(0), size(0), ringSize(0) {}
  };

  // The RtMidiInData structure is used to pass private class data to
  // the MIDI input handling function or thread.
  struct RtMidiInData {
    MidiQueue queue;
    MidiMessage message;
    unsigned char ignoreFlags;
    bool doInput;
    bool firstMessage;
    void *apiData;
    bool usingCallback;
    RtMidiIn::RtMidiCallback userCallback;
    void *userData;
    bool continueSysex;

    // Default constructor.
  RtMidiInData()
  : ignoreFlags(7), doInput(false), firstMessage(true),
      apiData(0), usingCallback(false), userCallback(0), userData(0),
      continueSysex(false) {}
  };

 protected:
  RtMidiInData inputData_;
};

class MidiOutApi : public MidiApi
{
 public:

  MidiOutApi( void );
  virtual ~MidiOutApi( void );
  virtual void sendMessage( std::vector<unsigned char> *message ) = 0;
};

// **************************************************************** //
//
// Inline RtMidiIn and RtMidiOut definitions.
//
// **************************************************************** //

inline RtMidi::Api RtMidiIn :: getCurrentApi( void ) throw() { return rtapi_->getCurrentApi(); }
inline void RtMidiIn :: openPort( unsigned int portNumber, const std::string portName ) { rtapi_->openPort( portNumber, portName ); }
inline void RtMidiIn :: openVirtualPort( const std::string portName ) { rtapi_->openVirtualPort( portName ); }
inline void RtMidiIn :: closePort( void ) { rtapi_->closePort(); }
inline bool RtMidiIn :: isPortOpen() const { return rtapi_->isPortOpen(); }
inline void RtMidiIn :: setCallback( RtMidiCallback callback, void *userData ) { ((MidiInApi *)rtapi_)->setCallback( callback, userData ); }
inline void RtMidiIn :: cancelCallback( void ) { ((MidiInApi *)rtapi_)->cancelCallback(); }
inline unsigned int RtMidiIn :: getPortCount( void ) { return rtapi_->getPortCount(); }
inline std::string RtMidiIn :: getPortName( unsigned int portNumber ) { return rtapi_->getPortName( portNumber ); }
inline void RtMidiIn :: ignoreTypes( bool midiSysex, bool midiTime, bool midiSense ) { ((MidiInApi *)rtapi_)->ignoreTypes( midiSysex, midiTime, midiSense ); }
inline double RtMidiIn :: getMessage( std::vector<unsigned char> *message ) { return ((MidiInApi *)rtapi_)->getMessage( message ); }
inline void RtMidiIn :: setErrorCallback( RtMidiErrorCallback errorCallback ) { rtapi_->setErrorCallback(errorCallback); }

inline RtMidi::Api RtMidiOut :: getCurrentApi( void ) throw() { return rtapi_->getCurrentApi(); }
inline void RtMidiOut :: openPort( unsigned int portNumber, const std::string portName ) { rtapi_->openPort( portNumber, portName ); }
inline void RtMidiOut :: openVirtualPort( const std::string portName ) { rtapi_->openVirtualPort( portName ); }
inline void RtMidiOut :: closePort( void ) { rtapi_->closePort(); }
inline bool RtMidiOut :: isPortOpen() const { return rtapi_->isPortOpen(); }
inline unsigned int RtMidiOut :: getPortCount( void ) { return rtapi_->getPortCount(); }
inline std::string RtMidiOut :: getPortName( unsigned int portNumber ) { return rtapi_->getPortName( portNumber ); }
inline void RtMidiOut :: sendMessage( std::vector<unsigned char> *message ) { ((MidiOutApi *)rtapi_)->sendMessage( message ); }
inline void RtMidiOut :: setErrorCallback( RtMidiErrorCallback errorCallback ) { rtapi_->setErrorCallback(errorCallback); }

// **************************************************************** //
//
// MidiInApi and MidiOutApi subclass prototypes.
//
// **************************************************************** //

#if !defined(__LINUX_ALSA__) && !defined(__UNIX_JACK__) && !defined(__MACOSX_CORE__) && !defined(__WINDOWS_MM__)
  #define __RTMIDI_DUMMY__
#endif

#if defined(__MACOSX_CORE__)

class MidiInCore: public MidiInApi
{
 public:
  MidiInCore( const std::string clientName, unsigned int queueSizeLimit );
  ~MidiInCore( void );
  RtMidi::Api getCurrentApi( void ) { return RtMidi::MACOSX_CORE; };
  void openPort( unsigned int portNumber, const std::string portName );
  void openVirtualPort( const std::string portName );
  void closePort( void );
  unsigned int getPortCount( void );
  std::string getPortName( unsigned int portNumber );

 protected:
  void initialize( const std::string& clientName );
};

class MidiOutCore: public MidiOutApi
{
 public:
  MidiOutCore( const std::string clientName );
  ~MidiOutCore( void );
  RtMidi::Api getCurrentApi( void ) { return RtMidi::MACOSX_CORE; };
  void openPort( unsigned int portNumber, const std::string portName );
  void openVirtualPort( const std::string portName );
  void closePort( void );
  unsigned int getPortCount( void );
  std::string getPortName( unsigned int portNumber );
  void sendMessage( std::vector<unsigned char> *message );

 protected:
  void initialize( const std::string& clientName );
};

#endif

#if defined(__UNIX_JACK__)

class MidiInJack: public MidiInApi
{
 public:
  MidiInJack( const std::string clientName, unsigned int queueSizeLimit );
  ~MidiInJack( void );
  RtMidi::Api getCurrentApi( void ) { return RtMidi::UNIX_JACK; };
  void openPort( unsigned int portNumber, const std::string portName );
  void openVirtualPort( const std::string portName );
  void closePort( void );
  unsigned int getPortCount( void );
  std::string getPortName( unsigned int portNumber );

 protected:
  std::string clientName;

  void connect( void );
  void initialize( const std::string& clientName );
};

class MidiOutJack: public MidiOutApi
{
 public:
  MidiOutJack( const std::string clientName );
  ~MidiOutJack( void );
  RtMidi::Api getCurrentApi( void ) { return RtMidi::UNIX_JACK; };
  void openPort( unsigned int portNumber, const std::string portName );
  void openVirtualPort( const std::string portName );
  void closePort( void );
  unsigned int getPortCount( void );
  std::string getPortName( unsigned int portNumber );
  void sendMessage( std::vector<unsigned char> *message );

 protected:
  std::string clientName;

  void connect( void );
  void initialize( const std::string& clientName );
};

#endif

#if defined(__LINUX_ALSA__)

class MidiInAlsa: public MidiInApi
{
 public:
  MidiInAlsa( const std::string clientName, unsigned int queueSizeLimit );
  ~MidiInAlsa( void );
  RtMidi::Api getCurrentApi( void ) { return RtMidi::LINUX_ALSA; };
  void openPort( unsigned int portNumber, const std::string portName );
  void openVirtualPort( const std::string portName );
  void closePort( void );
  unsigned int getPortCount( void );
  std::string getPortName( unsigned int portNumber );

 protected:
  void initialize( const std::string& clientName );
};

class MidiOutAlsa: public MidiOutApi
{
 public:
  MidiOutAlsa( const std::string clientName );
  ~MidiOutAlsa( void );
  RtMidi::Api getCurrentApi( void ) { return RtMidi::LINUX_ALSA; };
  void openPort( unsigned int portNumber, const std::string portName );
  void openVirtualPort( const std::string portName );
  void closePort( void );
  unsigned int getPortCount( void );
  std::string getPortName( unsigned int portNumber );
  void sendMessage( std::vector<unsigned char> *message );

 protected:
  void initialize( const std::string& clientName );
};

#endif

#if defined(__WINDOWS_MM__)

class MidiInWinMM: public MidiInApi
{
 public:
  MidiInWinMM( const std::string clientName, unsigned int queueSizeLimit );
  ~MidiInWinMM( void );
  RtMidi::Api getCurrentApi( void ) { return RtMidi::WINDOWS_MM; };
  void openPort( unsigned int portNumber, const std::string portName );
  void openVirtualPort( const std::string portName );
  void closePort( void );
  unsigned int getPortCount( void );
  std::string getPortName( unsigned int portNumber );

 protected:
  void initialize( const std::string& clientName );
};

class MidiOutWinMM: public MidiOutApi
{
 public:
  MidiOutWinMM( const std::string clientName );
  ~MidiOutWinMM( void );
  RtMidi::Api getCurrentApi( void ) { return RtMidi::WINDOWS_MM; };
  void openPort( unsigned int portNumber, const std::string portName );
  void openVirtualPort( const std::string portName );
  void closePort( void );
  unsigned int getPortCount( void );
  std::string getPortName( unsigned int portNumber );
  void sendMessage( std::vector<unsigned char> *message );

 protected:
  void initialize( const std::string& clientName );
};

#endif

#if defined(__RTMIDI_DUMMY__)

class MidiInDummy: public MidiInApi
{
 public:
 MidiInDummy( const std::string /*clientName*/, unsigned int queueSizeLimit ) : MidiInApi( queueSizeLimit ) { errorString_ = "MidiInDummy: This class provides no functionality."; error( RtMidiError::WARNING, errorString_ ); }
  RtMidi::Api getCurrentApi( void ) { return RtMidi::RTMIDI_DUMMY; }
  void openPort( unsigned int /*portNumber*/, const std::string /*portName*/ ) {}
  void openVirtualPort( const std::string /*portName*/ ) {}
  void closePort( void ) {}
  unsigned int getPortCount( void ) { return 0; }
  std::string getPortName( unsigned int portNumber ) { return ""; }

 protected:
  void initialize( const std::string& /*clientName*/ ) {}
};

class MidiOutDummy: public MidiOutApi
{
 public:
  MidiOutDummy( const std::string /*clientName*/ ) { errorString_ = "MidiOutDummy: This class provides no functionality."; error( RtMidiError::WARNING, errorString_ ); }
  RtMidi::Api getCurrentApi( void ) { return RtMidi::RTMIDI_DUMMY; }
  void openPort( unsigned int /*portNumber*/, const std::string /*portName*/ ) {}
  void openVirtualPort( const std::string /*portName*/ ) {}
  void closePort( void ) {}
  unsigned int getPortCount( void ) { return 0; }
  std::string getPortName( unsigned int /*portNumber*/ ) { return ""; }
  void sendMessage( std::vector<unsigned char> * /*message*/ ) {}

 protected:
  void initialize( const std::string& /*clientName*/ ) {}
};

#endif

#endif

class MapUI;

//-------------------------------------------------
// MIDI input/output handling using RtMidi library
//-------------------------------------------------

class rt_midi : public midi_handler {

    private:
    
        std::vector<RtMidiIn*> fInput;
        std::vector<RtMidiOut*> fOutput;
        bool fIsVirtual;
    
        static void midiCallback(double time, std::vector<unsigned char>* message, void* arg)
        {
            rt_midi* midi = static_cast<rt_midi*>(arg);
            size_t nBytes = message->size();
            int type = (int)message->at(0) & 0xf0;
            int channel = (int)message->at(0) & 0x0f;
            
            // MIDI sync
            if (nBytes == 1) {
                midi->handleSync(time, (int)message->at(0));
            // One data byte messages
            } else if (nBytes == 2) {
                midi->handleData1(time, type, channel, (int)message->at(1));
            // Two data bytes messages
            } else if (nBytes == 3) {
                midi->handleData2(time, type, channel, (int)message->at(1), (int)message->at(2));
            } else {
                midi->handleMessage(time, (int)message->at(0), *message);
            }
        }
        
        bool openMidiInputPorts()
        {
            // Get number of input ports
            RtMidiIn midi_in;
            unsigned nInPorts = midi_in.getPortCount();
            if (nInPorts == 0) {
                std::cout << "No input ports available!" << std::endl;
                return false;
            }
    
            // Then open all of them
            for (unsigned int i = 0; i < nInPorts; i++) {
                RtMidiIn* midi_in = new RtMidiIn();
                midi_in->ignoreTypes(true, false, true);
                fInput.push_back(midi_in);
                midi_in->openPort(i);
                midi_in->setCallback(&midiCallback, this);
                //std::cout << "Input port #" << i << ": " << midi_in->getPortName(i) << '\n';
            }
            return true;
        }
        
        bool openMidiOutputPorts()
        {
            // Get number of output ports
            RtMidiOut midi_out;
            unsigned nOutPorts = midi_out.getPortCount();
            if (nOutPorts == 0) {
                std::cout << "No output ports available!" << std::endl;
                return false;
            }
    
            // Then open all of them
            for (unsigned int i = 0; i < nOutPorts; i++) {
                RtMidiOut* midi_out = new RtMidiOut();
                fOutput.push_back(midi_out);
                midi_out->openPort(i);
                //std::cout << "Output port #" << i << ": " << midi_out->getPortName(i) << '\n';
            }
            return true;
        }
        
        void chooseMidiInputPort(const std::string& name)
        {
            RtMidiIn* midi_in = new RtMidiIn();
            midi_in->ignoreTypes(true, false, true);
            fInput.push_back(midi_in);
            midi_in->setCallback(&midiCallback, this);
            midi_in->openVirtualPort(name);
        }
        
        void chooseMidiOutPort(const std::string& name)
        {
            RtMidiOut* midi_out = new RtMidiOut();
            fOutput.push_back(midi_out);
            midi_out->openVirtualPort(name);
        }
        
        void sendMessage(std::vector<unsigned char>& message)
        {
            std::vector<RtMidiOut*>::iterator it;
            for (it = fOutput.begin(); it != fOutput.end(); it++) {
                (*it)->sendMessage(&message);
            }
        }
    
    public:
    
        rt_midi(const std::string& name = "RtMidi", bool is_virtual = false):midi_handler(name), fIsVirtual(is_virtual)
        {}
        
        virtual ~rt_midi()
        {
            stopMidi();
        }
        
        bool startMidi()
        {
            try {
            
            #if TARGET_OS_IPHONE
                if (!openMidiInputPorts())  { stopMidi(); return false; }
                if (!openMidiOutputPorts()) { stopMidi(); return false; }
            #else
                if (fIsVirtual) {
                    chooseMidiInputPort(fName);
                    chooseMidiOutPort(fName);
                } else {
                    if (!openMidiInputPorts())  { stopMidi(); return false; }
                    //std::cout << "Warning : MIDI outputs are not started in this mode !\n";
                }
            #endif
                return true;
                
            } catch (RtMidiError &error) {
                error.printMessage();
                stopMidi();
                return false;
            }
        }
        
        void stopMidi()
        {
            std::vector<RtMidiIn*>::iterator it1;
            for (it1 = fInput.begin(); it1 != fInput.end(); it1++) {
                delete (*it1);
            }
            fInput.clear();
            
            std::vector<RtMidiOut*>::iterator it2;
            for (it2 = fOutput.begin(); it2 != fOutput.end(); it2++) {
                delete (*it2);
            }
            fOutput.clear();
        }
    
        // MIDI output API
        MapUI* keyOn(int channel, int pitch, int velocity)
        {
            std::vector<unsigned char> message;
            message.push_back(MIDI_NOTE_ON + channel);
            message.push_back(pitch);
            message.push_back(velocity);
            sendMessage(message);
            return 0;
        }
        
        void keyOff(int channel, int pitch, int velocity) 
        {
            std::vector<unsigned char> message;
            message.push_back(MIDI_NOTE_OFF + channel);
            message.push_back(pitch);
            message.push_back(velocity);
            sendMessage(message);
        }
        
        void ctrlChange(int channel, int ctrl, int val) 
        {
            std::vector<unsigned char> message;
            message.push_back(MIDI_CONTROL_CHANGE + channel);
            message.push_back(ctrl);
            message.push_back(val);
            sendMessage(message);
        }
        
        void chanPress(int channel, int press) 
        {
            std::vector<unsigned char> message;
            message.push_back(MIDI_AFTERTOUCH + channel);
            message.push_back(press);
            sendMessage(message);
        }
        
        void progChange(int channel, int pgm) 
        {
            std::vector<unsigned char> message;
            message.push_back(MIDI_PROGRAM_CHANGE + channel);
            message.push_back(pgm);
            sendMessage(message);
        }
          
        void keyPress(int channel, int pitch, int press) 
        {
            std::vector<unsigned char> message;
            message.push_back(MIDI_POLY_AFTERTOUCH + channel);
            message.push_back(pitch);
            message.push_back(press);
            sendMessage(message);
        }
   
        void pitchWheel(int channel, int wheel) 
        {
            std::vector<unsigned char> message;
            message.push_back(MIDI_PITCH_BEND + channel);
            message.push_back(wheel & 0x7F);		// lsb 7bit
            message.push_back((wheel >> 7) & 0x7F);	// msb 7bit
            sendMessage(message);
        }
        
        void ctrlChange14bits(int channel, int ctrl, int value) {}
         
        void startSync(double date)
        {
            std::vector<unsigned char> message;
            message.push_back(MIDI_START);
            sendMessage(message);
        }
       
        void stopSync(double date)
        {
            std::vector<unsigned char> message;
            message.push_back(MIDI_STOP);
            sendMessage(message);
        }
        
        void clock(double date) 
        {
            std::vector<unsigned char> message;
            message.push_back(MIDI_CLOCK);
            sendMessage(message);
        }
    
        void sysEx(double, std::vector<unsigned char>& message)
        {
            sendMessage(message);
        }
    
};


#endif // __rt_midi__
/**********************************************************************/
/*! \class RtMidi
    \brief An abstract base class for realtime MIDI input/output.

    This class implements some common functionality for the realtime
    MIDI input/output subclasses RtMidiIn and RtMidiOut.

    RtMidi WWW site: http://music.mcgill.ca/~gary/rtmidi/

    RtMidi: realtime MIDI i/o C++ classes
    Copyright (c) 2003-2014 Gary P. Scavone

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation files
    (the "Software"), to deal in the Software without restriction,
    including without limitation the rights to use, copy, modify, merge,
    publish, distribute, sublicense, and/or sell copies of the Software,
    and to permit persons to whom the Software is furnished to do so,
    subject to the following conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    Any person wishing to distribute modifications to the Software is
    asked to send the modifications to the original developer so that
    they can be incorporated into the canonical version.  This is,
    however, not a binding provision of this license.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
    ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
    CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
/**********************************************************************/

#include <sstream>

#ifdef __APPLE__

Float64 CAHostTimeBase::sFrequency = 0;
Float64 CAHostTimeBase::sInverseFrequency = 0;
UInt32 CAHostTimeBase::sMinDelta = 0;
UInt32 CAHostTimeBase::sToNanosNumerator = 0;
UInt32 CAHostTimeBase::sToNanosDenominator = 0;
UInt32 CAHostTimeBase::sFromNanosNumerator = 0;
UInt32 CAHostTimeBase::sFromNanosDenominator = 0;
bool CAHostTimeBase::sUseMicroseconds = false;
bool CAHostTimeBase::sIsInited = false;
#if Track_Host_TimeBase
UInt64 CAHostTimeBase::sLastTime = 0;
#endif

//=============================================================================
//	CAHostTimeBase
//
//	This class provides platform independent access to the host's time base.
//=============================================================================

void CAHostTimeBase::Initialize()
{
    if (!sIsInited) {
       
        //	get the info about Absolute time
        #if TARGET_OS_MAC
            struct mach_timebase_info	theTimeBaseInfo;
            mach_timebase_info(&theTimeBaseInfo);
            sMinDelta = 1;
            sToNanosNumerator = theTimeBaseInfo.numer;
            sToNanosDenominator = theTimeBaseInfo.denom;
            sFromNanosNumerator = sToNanosDenominator;
            sFromNanosDenominator = sToNanosNumerator;

            //	the frequency of that clock is: (sToNanosDenominator / sToNanosNumerator) * 10^9
            sFrequency = static_cast<Float64>(sToNanosDenominator) / static_cast<Float64>(sToNanosNumerator);
            sFrequency *= 1000000000.0;
        #elif TARGET_OS_WIN32
            LARGE_INTEGER theFrequency;
            QueryPerformanceFrequency(&theFrequency);
            sMinDelta = 1;
            sToNanosNumerator = 1000000000ULL;
            sToNanosDenominator = *((UInt64*)&theFrequency);
            sFromNanosNumerator = sToNanosDenominator;
            sFromNanosDenominator = sToNanosNumerator;
            sFrequency = static_cast<Float64>(*((UInt64*)&theFrequency));
        #endif
        sInverseFrequency = 1.0 / sFrequency;
        
        #if	Log_Host_Time_Base_Parameters
            DebugMessage(  "Host Time Base Parameters");
            DebugMessageN1(" Minimum Delta:          %lu", sMinDelta);
            DebugMessageN1(" Frequency:              %f", sFrequency);
            DebugMessageN1(" To Nanos Numerator:     %lu", sToNanosNumerator);
            DebugMessageN1(" To Nanos Denominator:   %lu", sToNanosDenominator);
            DebugMessageN1(" From Nanos Numerator:   %lu", sFromNanosNumerator);
            DebugMessageN1(" From Nanos Denominator: %lu", sFromNanosDenominator);
        #endif

        sIsInited = true;
    }
}

#endif

#if defined(__MACOSX_CORE__)
    #if TARGET_OS_IPHONE
        #define AudioGetCurrentHostTime CAHostTimeBase::GetCurrentTime
        #define AudioConvertHostTimeToNanos CAHostTimeBase::ConvertToNanos
    #endif
#endif

//*********************************************************************//
//  RtMidi Definitions
//*********************************************************************//

RtMidi :: RtMidi()
  : rtapi_(0)
{
#if defined(__MACOSX_CORE__)
    #if TARGET_OS_IPHONE
        CAHostTimeBase::Initialize();
    #endif
#endif
}

RtMidi :: ~RtMidi()
{
  if ( rtapi_ )
    delete rtapi_;
  rtapi_ = 0;
}

std::string RtMidi :: getVersion( void ) throw()
{
  return std::string( RTMIDI_VERSION );
}

void RtMidi :: getCompiledApi( std::vector<RtMidi::Api> &apis ) throw()
{
  apis.clear();

  // The order here will control the order of RtMidi's API search in
  // the constructor.
#if defined(__MACOSX_CORE__)
  apis.push_back( MACOSX_CORE );
#endif
#if defined(__LINUX_ALSA__)
  apis.push_back( LINUX_ALSA );
#endif
#if defined(__UNIX_JACK__)
  apis.push_back( UNIX_JACK );
#endif
#if defined(__WINDOWS_MM__)
  apis.push_back( WINDOWS_MM );
#endif
#if defined(__RTMIDI_DUMMY__)
  apis.push_back( RTMIDI_DUMMY );
#endif
}

//*********************************************************************//
//  RtMidiIn Definitions
//*********************************************************************//

void RtMidiIn :: openMidiApi( RtMidi::Api api, const std::string clientName, unsigned int queueSizeLimit )
{
  if ( rtapi_ )
    delete rtapi_;
  rtapi_ = 0;

#if defined(__UNIX_JACK__)
  if ( api == UNIX_JACK )
    rtapi_ = new MidiInJack( clientName, queueSizeLimit );
#endif
#if defined(__LINUX_ALSA__)
  if ( api == LINUX_ALSA )
    rtapi_ = new MidiInAlsa( clientName, queueSizeLimit );
#endif
#if defined(__WINDOWS_MM__)
  if ( api == WINDOWS_MM )
    rtapi_ = new MidiInWinMM( clientName, queueSizeLimit );
#endif
#if defined(__MACOSX_CORE__)
  if ( api == MACOSX_CORE )
    rtapi_ = new MidiInCore( clientName, queueSizeLimit );
#endif
#if defined(__RTMIDI_DUMMY__)
  if ( api == RTMIDI_DUMMY )
    rtapi_ = new MidiInDummy( clientName, queueSizeLimit );
#endif
}

RtMidiIn :: RtMidiIn( RtMidi::Api api, const std::string clientName, unsigned int queueSizeLimit )
  : RtMidi()
{
  if ( api != UNSPECIFIED ) {
    // Attempt to open the specified API.
    openMidiApi( api, clientName, queueSizeLimit );
    if ( rtapi_ ) return;

    // No compiled support for specified API value.  Issue a warning
    // and continue as if no API was specified.
    std::cerr << "\nRtMidiIn: no compiled support for specified API argument!\n\n" << std::endl;
  }

  // Iterate through the compiled APIs and return as soon as we find
  // one with at least one port or we reach the end of the list.
  std::vector< RtMidi::Api > apis;
  getCompiledApi( apis );
  for ( unsigned int i=0; i<apis.size(); i++ ) {
    openMidiApi( apis[i], clientName, queueSizeLimit );
    if ( rtapi_->getPortCount() ) break;
  }

  if ( rtapi_ ) return;

  // It should not be possible to get here because the preprocessor
  // definition __RTMIDI_DUMMY__ is automatically defined if no
  // API-specific definitions are passed to the compiler. But just in
  // case something weird happens, we'll throw an error.
  std::string errorText = "RtMidiIn: no compiled API support found ... critical error!!";
  throw( RtMidiError( errorText, RtMidiError::UNSPECIFIED ) );
}

RtMidiIn :: ~RtMidiIn() throw()
{
}


//*********************************************************************//
//  RtMidiOut Definitions
//*********************************************************************//

void RtMidiOut :: openMidiApi( RtMidi::Api api, const std::string clientName )
{
  if ( rtapi_ )
    delete rtapi_;
  rtapi_ = 0;

#if defined(__UNIX_JACK__)
  if ( api == UNIX_JACK )
    rtapi_ = new MidiOutJack( clientName );
#endif
#if defined(__LINUX_ALSA__)
  if ( api == LINUX_ALSA )
    rtapi_ = new MidiOutAlsa( clientName );
#endif
#if defined(__WINDOWS_MM__)
  if ( api == WINDOWS_MM )
    rtapi_ = new MidiOutWinMM( clientName );
#endif
#if defined(__MACOSX_CORE__)
  if ( api == MACOSX_CORE )
    rtapi_ = new MidiOutCore( clientName );
#endif
#if defined(__RTMIDI_DUMMY__)
  if ( api == RTMIDI_DUMMY )
    rtapi_ = new MidiOutDummy( clientName );
#endif
}

RtMidiOut :: RtMidiOut( RtMidi::Api api, const std::string clientName )
{
  if ( api != UNSPECIFIED ) {
    // Attempt to open the specified API.
    openMidiApi( api, clientName );
    if ( rtapi_ ) return;

    // No compiled support for specified API value.  Issue a warning
    // and continue as if no API was specified.
    std::cerr << "\nRtMidiOut: no compiled support for specified API argument!\n\n" << std::endl;
  }

  // Iterate through the compiled APIs and return as soon as we find
  // one with at least one port or we reach the end of the list.
  std::vector< RtMidi::Api > apis;
  getCompiledApi( apis );
  for ( unsigned int i=0; i<apis.size(); i++ ) {
    openMidiApi( apis[i], clientName );
    if ( rtapi_->getPortCount() ) break;
  }

  if ( rtapi_ ) return;

  // It should not be possible to get here because the preprocessor
  // definition __RTMIDI_DUMMY__ is automatically defined if no
  // API-specific definitions are passed to the compiler. But just in
  // case something weird happens, we'll thrown an error.
  std::string errorText = "RtMidiOut: no compiled API support found ... critical error!!";
  throw( RtMidiError( errorText, RtMidiError::UNSPECIFIED ) );
}

RtMidiOut :: ~RtMidiOut() throw()
{
}

//*********************************************************************//
//  Common MidiApi Definitions
//*********************************************************************//

MidiApi :: MidiApi( void )
  : apiData_( 0 ), connected_( false ), errorCallback_(0)
{
}

MidiApi :: ~MidiApi( void )
{
}

void MidiApi :: setErrorCallback( RtMidiErrorCallback errorCallback )
{
    errorCallback_ = errorCallback;
}

void MidiApi :: error( RtMidiError::Type type, std::string errorString )
{
  if ( errorCallback_ ) {
    static bool firstErrorOccured = false;

    if ( firstErrorOccured )
      return;

    firstErrorOccured = true;
    const std::string errorMessage = errorString;

    errorCallback_( type, errorMessage );
    firstErrorOccured = false;
    return;
  }

  if ( type == RtMidiError::WARNING ) {
    std::cerr << '\n' << errorString << "\n\n";
  }
  else if ( type == RtMidiError::DEBUG_WARNING ) {
#if defined(__RTMIDI_DEBUG__)
    std::cerr << '\n' << errorString << "\n\n";
#endif
  }
  else {
    std::cerr << '\n' << errorString << "\n\n";
    throw RtMidiError( errorString, type );
  }
}

//*********************************************************************//
//  Common MidiInApi Definitions
//*********************************************************************//

MidiInApi :: MidiInApi( unsigned int queueSizeLimit )
  : MidiApi()
{
  // Allocate the MIDI queue.
  inputData_.queue.ringSize = queueSizeLimit;
  if ( inputData_.queue.ringSize > 0 )
    inputData_.queue.ring = new MidiMessage[ inputData_.queue.ringSize ];
}

MidiInApi :: ~MidiInApi( void )
{
  // Delete the MIDI queue.
  if ( inputData_.queue.ringSize > 0 ) delete [] inputData_.queue.ring;
}

void MidiInApi :: setCallback( RtMidiIn::RtMidiCallback callback, void *userData )
{
  if ( inputData_.usingCallback ) {
    errorString_ = "MidiInApi::setCallback: a callback function is already set!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  if ( !callback ) {
    errorString_ = "RtMidiIn::setCallback: callback function value is invalid!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  inputData_.userCallback = callback;
  inputData_.userData = userData;
  inputData_.usingCallback = true;
}

void MidiInApi :: cancelCallback()
{
  if ( !inputData_.usingCallback ) {
    errorString_ = "RtMidiIn::cancelCallback: no callback function was set!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  inputData_.userCallback = 0;
  inputData_.userData = 0;
  inputData_.usingCallback = false;
}

void MidiInApi :: ignoreTypes( bool midiSysex, bool midiTime, bool midiSense )
{
  inputData_.ignoreFlags = 0;
  if ( midiSysex ) inputData_.ignoreFlags = 0x01;
  if ( midiTime ) inputData_.ignoreFlags |= 0x02;
  if ( midiSense ) inputData_.ignoreFlags |= 0x04;
}

double MidiInApi :: getMessage( std::vector<unsigned char> *message )
{
  message->clear();

  if ( inputData_.usingCallback ) {
    errorString_ = "RtMidiIn::getNextMessage: a user callback is currently set for this port.";
    error( RtMidiError::WARNING, errorString_ );
    return 0.0;
  }

  if ( inputData_.queue.size == 0 ) return 0.0;

  // Copy queued message to the vector pointer argument and then "pop" it.
  std::vector<unsigned char> *bytes = &(inputData_.queue.ring[inputData_.queue.front].bytes);
  message->assign( bytes->begin(), bytes->end() );
  double deltaTime = inputData_.queue.ring[inputData_.queue.front].timeStamp;
  inputData_.queue.size--;
  inputData_.queue.front++;
  if ( inputData_.queue.front == inputData_.queue.ringSize )
    inputData_.queue.front = 0;

  return deltaTime;
}

//*********************************************************************//
//  Common MidiOutApi Definitions
//*********************************************************************//

MidiOutApi :: MidiOutApi( void )
  : MidiApi()
{
}

MidiOutApi :: ~MidiOutApi( void )
{
}

// *************************************************** //
//
// OS/API-specific methods.
//
// *************************************************** //

#if defined(__MACOSX_CORE__)

// The CoreMIDI API is based on the use of a callback function for
// MIDI input.  We convert the system specific time stamps to delta
// time values.

// OS-X CoreMIDI header files.
#include <CoreMIDI/CoreMIDI.h>

#if defined(__MACOSX_CORE__)
    #if TARGET_OS_IPHONE
        static inline UInt32 EndianS32_BtoN(UInt32 x)
        {
            return ((x << 24) & 0xFF000000) | ((x << 8) & 0x00FF0000)
            | ((x >> 8) & 0x0000FF00) | ((x >> 24) & 0x000000FF);
        }
    #else
        #include <CoreAudio/HostTime.h>
        #include <CoreServices/CoreServices.h>
    #endif
#endif


// A structure to hold variables related to the CoreMIDI API
// implementation.
struct CoreMidiData {
  MIDIClientRef client;
  MIDIPortRef port;
  MIDIEndpointRef endpoint;
  MIDIEndpointRef destinationId;
  unsigned long long lastTime;
  MIDISysexSendRequest sysexreq;
};

//*********************************************************************//
//  API: OS-X
//  Class Definitions: MidiInCore
//*********************************************************************//

static void midiInputCallback( const MIDIPacketList *list, void *procRef, void */*srcRef*/ )
{
  MidiInApi::RtMidiInData *data = static_cast<MidiInApi::RtMidiInData *> (procRef);
  CoreMidiData *apiData = static_cast<CoreMidiData *> (data->apiData);

  unsigned char status;
  unsigned short nBytes, iByte, size;
  unsigned long long time;
  
  bool& continueSysex = data->continueSysex;
  MidiInApi::MidiMessage& message = data->message;
  
  const MIDIPacket *packet = &list->packet[0];
  for ( unsigned int i=0; i<list->numPackets; ++i ) {

    // My interpretation of the CoreMIDI documentation: all message
    // types, except sysex, are complete within a packet and there may
    // be several of them in a single packet.  Sysex messages can be
    // broken across multiple packets and PacketLists but are bundled
    // alone within each packet (these packets do not contain other
    // message types).  If sysex messages are split across multiple
    // MIDIPacketLists, they must be handled by multiple calls to this
    // function.

    nBytes = packet->length;
    if ( nBytes == 0 ) continue;

    // Calculate time stamp.

    /*
    if ( data->firstMessage ) {
      message.timeStamp = 0.0;
      data->firstMessage = false;
    }
    else {
      time = packet->timeStamp;
      if ( time == 0 ) { // this happens when receiving asynchronous sysex messages
        time = AudioGetCurrentHostTime();
      }
      time -= apiData->lastTime;
      time = AudioConvertHostTimeToNanos( time );
      if ( !continueSysex )
        message.timeStamp = time * 0.000000001;
    }
    apiData->lastTime = packet->timeStamp;
    if ( apiData->lastTime == 0 ) { // this happens when receiving asynchronous sysex messages
      apiData->lastTime = AudioGetCurrentHostTime();
    }
    */
    
    // Absolute usec based time stamp
    message.timeStamp = AudioConvertHostTimeToNanos(packet->timeStamp) / 1000;
  
    iByte = 0;
    if ( continueSysex ) {
      // We have a continuing, segmented sysex message.
      if ( !( data->ignoreFlags & 0x01 ) ) {
        // If we're not ignoring sysex messages, copy the entire packet.
        for ( unsigned int j=0; j<nBytes; ++j )
          message.bytes.push_back( packet->data[j] );
      }
      continueSysex = packet->data[nBytes-1] != 0xF7;

      if ( !( data->ignoreFlags & 0x01 ) && !continueSysex ) {
        // If not a continuing sysex message, invoke the user callback function or queue the message.
        if ( data->usingCallback ) {
          RtMidiIn::RtMidiCallback callback = (RtMidiIn::RtMidiCallback) data->userCallback;
          callback( message.timeStamp, &message.bytes, data->userData );
        }
        else {
          // As long as we haven't reached our queue size limit, push the message.
          if ( data->queue.size < data->queue.ringSize ) {
            data->queue.ring[data->queue.back++] = message;
            if ( data->queue.back == data->queue.ringSize )
              data->queue.back = 0;
            data->queue.size++;
          }
          else
            std::cerr << "\nMidiInCore: message queue limit reached!!\n\n";
        }
        message.bytes.clear();
      }
    }
    else {
      while ( iByte < nBytes ) {
        size = 0;
        // We are expecting that the next byte in the packet is a status byte.
        status = packet->data[iByte];
        if ( !(status & 0x80) ) break;
        // Determine the number of bytes in the MIDI message.
        if ( status < 0xC0 ) size = 3;
        else if ( status < 0xE0 ) size = 2;
        else if ( status < 0xF0 ) size = 3;
        else if ( status == 0xF0 ) {
          // A MIDI sysex
          if ( data->ignoreFlags & 0x01 ) {
            size = 0;
            iByte = nBytes;
          }
          else size = nBytes - iByte;
          continueSysex = packet->data[nBytes-1] != 0xF7;
        }
        else if ( status == 0xF1 ) {
            // A MIDI time code message
           if ( data->ignoreFlags & 0x02 ) {
            size = 0;
            iByte += 2;
           }
           else size = 2;
        }
        else if ( status == 0xF2 ) size = 3;
        else if ( status == 0xF3 ) size = 2;
        else if ( status == 0xF8 && ( data->ignoreFlags & 0x02 ) ) {
          // A MIDI timing tick message and we're ignoring it.
          size = 0;
          iByte += 1;
        }
        else if ( status == 0xFE && ( data->ignoreFlags & 0x04 ) ) {
          // A MIDI active sensing message and we're ignoring it.
          size = 0;
          iByte += 1;
        }
        else size = 1;

        // Copy the MIDI data to our vector.
        if ( size ) {
          message.bytes.assign( &packet->data[iByte], &packet->data[iByte+size] );
          if ( !continueSysex ) {
            // If not a continuing sysex message, invoke the user callback function or queue the message.
            if ( data->usingCallback ) {
              RtMidiIn::RtMidiCallback callback = (RtMidiIn::RtMidiCallback) data->userCallback;
              callback( message.timeStamp, &message.bytes, data->userData );
            }
            else {
              // As long as we haven't reached our queue size limit, push the message.
              if ( data->queue.size < data->queue.ringSize ) {
                data->queue.ring[data->queue.back++] = message;
                if ( data->queue.back == data->queue.ringSize )
                  data->queue.back = 0;
                data->queue.size++;
              }
              else
                std::cerr << "\nMidiInCore: message queue limit reached!!\n\n";
            }
            message.bytes.clear();
          }
          iByte += size;
        }
      }
    }
    packet = MIDIPacketNext(packet);
  }
}

MidiInCore :: MidiInCore( const std::string clientName, unsigned int queueSizeLimit ) : MidiInApi( queueSizeLimit )
{
  initialize( clientName );
}

MidiInCore :: ~MidiInCore( void )
{
  // Close a connection if it exists.
  closePort();

  // Cleanup.
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);
  MIDIClientDispose( data->client );
  if ( data->endpoint ) MIDIEndpointDispose( data->endpoint );
  delete data;
}

void MidiInCore :: initialize( const std::string& clientName )
{
  // Set up our client.
  MIDIClientRef client;
  OSStatus result = MIDIClientCreate( CFStringCreateWithCString( NULL, clientName.c_str(), kCFStringEncodingASCII ), NULL, NULL, &client );
  if ( result != noErr ) {
    errorString_ = "MidiInCore::initialize: error creating OS-X MIDI client object.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Save our api-specific connection information.
  CoreMidiData *data = (CoreMidiData *) new CoreMidiData;
  data->client = client;
  data->endpoint = 0;
  apiData_ = (void *) data;
  inputData_.apiData = (void *) data;
}

void MidiInCore :: openPort( unsigned int portNumber, const std::string portName )
{
  if ( connected_ ) {
    errorString_ = "MidiInCore::openPort: a valid connection already exists!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  CFRunLoopRunInMode( kCFRunLoopDefaultMode, 0, false );
  unsigned int nSrc = MIDIGetNumberOfSources();
  if (nSrc < 1) {
    errorString_ = "MidiInCore::openPort: no MIDI input sources found!";
    error( RtMidiError::NO_DEVICES_FOUND, errorString_ );
    return;
  }

  if ( portNumber >= nSrc ) {
    std::ostringstream ost;
    ost << "MidiInCore::openPort: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::INVALID_PARAMETER, errorString_ );
    return;
  }

  MIDIPortRef port;
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);
  OSStatus result = MIDIInputPortCreate( data->client, 
                                         CFStringCreateWithCString( NULL, portName.c_str(), kCFStringEncodingASCII ),
                                         midiInputCallback, (void *)&inputData_, &port );
  if ( result != noErr ) {
    MIDIClientDispose( data->client );
    errorString_ = "MidiInCore::openPort: error creating OS-X MIDI input port.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Get the desired input source identifier.
  MIDIEndpointRef endpoint = MIDIGetSource( portNumber );
  if ( endpoint == 0 ) {
    MIDIPortDispose( port );
    MIDIClientDispose( data->client );
    errorString_ = "MidiInCore::openPort: error getting MIDI input source reference.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Make the connection.
  result = MIDIPortConnectSource( port, endpoint, NULL );
  if ( result != noErr ) {
    MIDIPortDispose( port );
    MIDIClientDispose( data->client );
    errorString_ = "MidiInCore::openPort: error connecting OS-X MIDI input port.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Save our api-specific port information.
  data->port = port;

  connected_ = true;
}

void MidiInCore :: openVirtualPort( const std::string portName )
{
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);

  // Create a virtual MIDI input destination.
  MIDIEndpointRef endpoint;
  OSStatus result = MIDIDestinationCreate( data->client,
                                           CFStringCreateWithCString( NULL, portName.c_str(), kCFStringEncodingASCII ),
                                           midiInputCallback, (void *)&inputData_, &endpoint );
  if ( result != noErr ) {
    errorString_ = "MidiInCore::openVirtualPort: error creating virtual OS-X MIDI destination.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Save our api-specific connection information.
  data->endpoint = endpoint;
}

void MidiInCore :: closePort( void )
{
  if ( connected_ ) {
    CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);
    MIDIPortDispose( data->port );
    connected_ = false;
  }
}

unsigned int MidiInCore :: getPortCount()
{
  CFRunLoopRunInMode( kCFRunLoopDefaultMode, 0, false );
  return MIDIGetNumberOfSources();
}

// This function was submitted by Douglas Casey Tucker and apparently
// derived largely from PortMidi.
CFStringRef EndpointName( MIDIEndpointRef endpoint, bool isExternal )
{
  CFMutableStringRef result = CFStringCreateMutable( NULL, 0 );
  CFStringRef str;

  // Begin with the endpoint's name.
  str = NULL;
  MIDIObjectGetStringProperty( endpoint, kMIDIPropertyName, &str );
  if ( str != NULL ) {
    CFStringAppend( result, str );
    CFRelease( str );
  }

  MIDIEntityRef entity = 0;
  MIDIEndpointGetEntity( endpoint, &entity );
  if ( entity == 0 )
    // probably virtual
    return result;

  if ( CFStringGetLength( result ) == 0 ) {
    // endpoint name has zero length -- try the entity
    str = NULL;
    MIDIObjectGetStringProperty( entity, kMIDIPropertyName, &str );
    if ( str != NULL ) {
      CFStringAppend( result, str );
      CFRelease( str );
    }
  }
  // now consider the device's name
  MIDIDeviceRef device = 0;
  MIDIEntityGetDevice( entity, &device );
  if ( device == 0 )
    return result;

  str = NULL;
  MIDIObjectGetStringProperty( device, kMIDIPropertyName, &str );
  if ( CFStringGetLength( result ) == 0 ) {
      CFRelease( result );
      return str;
  }
  if ( str != NULL ) {
    // if an external device has only one entity, throw away
    // the endpoint name and just use the device name
    if ( isExternal && MIDIDeviceGetNumberOfEntities( device ) < 2 ) {
      CFRelease( result );
      return str;
    } else {
      if ( CFStringGetLength( str ) == 0 ) {
        CFRelease( str );
        return result;
      }
      // does the entity name already start with the device name?
      // (some drivers do this though they shouldn't)
      // if so, do not prepend
        if ( CFStringCompareWithOptions( result, /* endpoint name */
             str /* device name */,
             CFRangeMake(0, CFStringGetLength( str ) ), 0 ) != kCFCompareEqualTo ) {
        // prepend the device name to the entity name
        if ( CFStringGetLength( result ) > 0 )
          CFStringInsert( result, 0, CFSTR(" ") );
        CFStringInsert( result, 0, str );
      }
      CFRelease( str );
    }
  }
  return result;
}

// This function was submitted by Douglas Casey Tucker and apparently
// derived largely from PortMidi.
static CFStringRef ConnectedEndpointName( MIDIEndpointRef endpoint )
{
  CFMutableStringRef result = CFStringCreateMutable( NULL, 0 );
  CFStringRef str;
  OSStatus err;
  int i;

  // Does the endpoint have connections?
  CFDataRef connections = NULL;
  int nConnected = 0;
  bool anyStrings = false;
  err = MIDIObjectGetDataProperty( endpoint, kMIDIPropertyConnectionUniqueID, &connections );
  if ( connections != NULL ) {
    // It has connections, follow them
    // Concatenate the names of all connected devices
    nConnected = CFDataGetLength( connections ) / sizeof(MIDIUniqueID);
    if ( nConnected ) {
      const SInt32 *pid = (const SInt32 *)(CFDataGetBytePtr(connections));
      for ( i=0; i<nConnected; ++i, ++pid ) {
        MIDIUniqueID id = EndianS32_BtoN( *pid );
        MIDIObjectRef connObject;
        MIDIObjectType connObjectType;
        err = MIDIObjectFindByUniqueID( id, &connObject, &connObjectType );
        if ( err == noErr ) {
          if ( connObjectType == kMIDIObjectType_ExternalSource  ||
              connObjectType == kMIDIObjectType_ExternalDestination ) {
            // Connected to an external device's endpoint (10.3 and later).
            str = EndpointName( (MIDIEndpointRef)(connObject), true );
          } else {
            // Connected to an external device (10.2) (or something else, catch-
            str = NULL;
            MIDIObjectGetStringProperty( connObject, kMIDIPropertyName, &str );
          }
          if ( str != NULL ) {
            if ( anyStrings )
              CFStringAppend( result, CFSTR(", ") );
            else anyStrings = true;
            CFStringAppend( result, str );
            CFRelease( str );
          }
        }
      }
    }
    CFRelease( connections );
  }
  if ( anyStrings )
    return result;

  // Here, either the endpoint had no connections, or we failed to obtain names 
  return EndpointName( endpoint, false );
}

std::string MidiInCore :: getPortName( unsigned int portNumber )
{
  CFStringRef nameRef;
  MIDIEndpointRef portRef;
  char name[128];

  std::string stringName;
  CFRunLoopRunInMode( kCFRunLoopDefaultMode, 0, false );
  if ( portNumber >= MIDIGetNumberOfSources() ) {
    std::ostringstream ost;
    ost << "MidiInCore::getPortName: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::WARNING, errorString_ );
    return stringName;
  }

  portRef = MIDIGetSource( portNumber );
  nameRef = ConnectedEndpointName(portRef);
  CFStringGetCString( nameRef, name, sizeof(name), CFStringGetSystemEncoding());
  CFRelease( nameRef );

  return stringName = name;
}

//*********************************************************************//
//  API: OS-X
//  Class Definitions: MidiOutCore
//*********************************************************************//

MidiOutCore :: MidiOutCore( const std::string clientName ) : MidiOutApi()
{
  initialize( clientName );
}

MidiOutCore :: ~MidiOutCore( void )
{
  // Close a connection if it exists.
  closePort();

  // Cleanup.
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);
  MIDIClientDispose( data->client );
  if ( data->endpoint ) MIDIEndpointDispose( data->endpoint );
  delete data;
}

void MidiOutCore :: initialize( const std::string& clientName )
{
  // Set up our client.
  MIDIClientRef client;
  OSStatus result = MIDIClientCreate( CFStringCreateWithCString( NULL, clientName.c_str(), kCFStringEncodingASCII ), NULL, NULL, &client );
  if ( result != noErr ) {
    errorString_ = "MidiOutCore::initialize: error creating OS-X MIDI client object.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Save our api-specific connection information.
  CoreMidiData *data = (CoreMidiData *) new CoreMidiData;
  data->client = client;
  data->endpoint = 0;
  apiData_ = (void *) data;
}

unsigned int MidiOutCore :: getPortCount()
{
  CFRunLoopRunInMode( kCFRunLoopDefaultMode, 0, false );
  return MIDIGetNumberOfDestinations();
}

std::string MidiOutCore :: getPortName( unsigned int portNumber )
{
  CFStringRef nameRef;
  MIDIEndpointRef portRef;
  char name[128];

  std::string stringName;
  CFRunLoopRunInMode( kCFRunLoopDefaultMode, 0, false );
  if ( portNumber >= MIDIGetNumberOfDestinations() ) {
    std::ostringstream ost;
    ost << "MidiOutCore::getPortName: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::WARNING, errorString_ );
    return stringName;
  }

  portRef = MIDIGetDestination( portNumber );
  nameRef = ConnectedEndpointName(portRef);
  CFStringGetCString( nameRef, name, sizeof(name), CFStringGetSystemEncoding());
  CFRelease( nameRef );
  
  return stringName = name;
}

void MidiOutCore :: openPort( unsigned int portNumber, const std::string portName )
{
  if ( connected_ ) {
    errorString_ = "MidiOutCore::openPort: a valid connection already exists!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  CFRunLoopRunInMode( kCFRunLoopDefaultMode, 0, false );
  unsigned int nDest = MIDIGetNumberOfDestinations();
  if (nDest < 1) {
    errorString_ = "MidiOutCore::openPort: no MIDI output destinations found!";
    error( RtMidiError::NO_DEVICES_FOUND, errorString_ );
    return;
  }

  if ( portNumber >= nDest ) {
    std::ostringstream ost;
    ost << "MidiOutCore::openPort: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::INVALID_PARAMETER, errorString_ );
    return;
  }

  MIDIPortRef port;
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);
  OSStatus result = MIDIOutputPortCreate( data->client, 
                                          CFStringCreateWithCString( NULL, portName.c_str(), kCFStringEncodingASCII ),
                                          &port );
  if ( result != noErr ) {
    MIDIClientDispose( data->client );
    errorString_ = "MidiOutCore::openPort: error creating OS-X MIDI output port.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Get the desired output port identifier.
  MIDIEndpointRef destination = MIDIGetDestination( portNumber );
  if ( destination == 0 ) {
    MIDIPortDispose( port );
    MIDIClientDispose( data->client );
    errorString_ = "MidiOutCore::openPort: error getting MIDI output destination reference.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Save our api-specific connection information.
  data->port = port;
  data->destinationId = destination;
  connected_ = true;
}

void MidiOutCore :: closePort( void )
{
  if ( connected_ ) {
    CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);
    MIDIPortDispose( data->port );
    connected_ = false;
  }
}

void MidiOutCore :: openVirtualPort( std::string portName )
{
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);

  if ( data->endpoint ) {
    errorString_ = "MidiOutCore::openVirtualPort: a virtual output port already exists!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  // Create a virtual MIDI output source.
  MIDIEndpointRef endpoint;
  OSStatus result = MIDISourceCreate( data->client,
                                      CFStringCreateWithCString( NULL, portName.c_str(), kCFStringEncodingASCII ),
                                      &endpoint );
  if ( result != noErr ) {
    errorString_ = "MidiOutCore::initialize: error creating OS-X virtual MIDI source.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Save our api-specific connection information.
  data->endpoint = endpoint;
}

// Not necessary if we don't treat sysex messages any differently than
// normal messages ... see below.
//static void sysexCompletionProc( MIDISysexSendRequest *sreq )
//{
//  free( sreq );
//}

void MidiOutCore :: sendMessage( std::vector<unsigned char> *message )
{
  // We use the MIDISendSysex() function to asynchronously send sysex
  // messages.  Otherwise, we use a single CoreMidi MIDIPacket.
  unsigned int nBytes = message->size();
  if ( nBytes == 0 ) {
    errorString_ = "MidiOutCore::sendMessage: no data in message argument!";      
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  //  unsigned int packetBytes, bytesLeft = nBytes;
  //  unsigned int messageIndex = 0;
  MIDITimeStamp timeStamp = AudioGetCurrentHostTime();
  CoreMidiData *data = static_cast<CoreMidiData *> (apiData_);
  OSStatus result;

  /*
    // I don't think this code is necessary.  We can send sysex
    // messages through the normal mechanism.  In addition, this avoids
    // the problem of virtual ports not receiving sysex messages.

  if ( message->at(0) == 0xF0 ) {

    // Apple's fantastic API requires us to free the allocated data in
    // the completion callback but trashes the pointer and size before
    // we get a chance to free it!!  This is a somewhat ugly hack
    // submitted by ptarabbia that puts the sysex buffer data right at
    // the end of the MIDISysexSendRequest structure.  This solution
    // does not require that we wait for a previous sysex buffer to be
    // sent before sending a new one, which was the old way we did it.
    MIDISysexSendRequest *newRequest = (MIDISysexSendRequest *) malloc(sizeof(struct MIDISysexSendRequest) + nBytes);
    char * sysexBuffer = ((char *) newRequest) + sizeof(struct MIDISysexSendRequest);

    // Copy data to buffer.
    for ( unsigned int i=0; i<nBytes; ++i ) sysexBuffer[i] = message->at(i);

    newRequest->destination = data->destinationId;
    newRequest->data = (Byte *)sysexBuffer;
    newRequest->bytesToSend = nBytes;
    newRequest->complete = 0;
    newRequest->completionProc = sysexCompletionProc;
    newRequest->completionRefCon = newRequest;

    result = MIDISendSysex(newRequest);
    if ( result != noErr ) {
      free( newRequest );
      errorString_ = "MidiOutCore::sendMessage: error sending MIDI to virtual destinations.";
      error( RtMidiError::WARNING, errorString_ );
      return;
    }
    return;
  }
  else if ( nBytes > 3 ) {
    errorString_ = "MidiOutCore::sendMessage: message format problem ... not sysex but > 3 bytes?";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }
  */

  MIDIPacketList packetList;
  MIDIPacket *packet = MIDIPacketListInit( &packetList );
  packet = MIDIPacketListAdd( &packetList, sizeof(packetList), packet, timeStamp, nBytes, (const Byte *) &message->at( 0 ) );
  if ( !packet ) {
    errorString_ = "MidiOutCore::sendMessage: could not allocate packet list";      
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Send to any destinations that may have connected to us.
  if ( data->endpoint ) {
    result = MIDIReceived( data->endpoint, &packetList );
    if ( result != noErr ) {
      errorString_ = "MidiOutCore::sendMessage: error sending MIDI to virtual destinations.";
      error( RtMidiError::WARNING, errorString_ );
    }
  }

  // And send to an explicit destination port if we're connected.
  if ( connected_ ) {
    result = MIDISend( data->port, data->destinationId, &packetList );
    if ( result != noErr ) {
      errorString_ = "MidiOutCore::sendMessage: error sending MIDI message to port.";
      error( RtMidiError::WARNING, errorString_ );
    }
  }
}

#endif  // __MACOSX_CORE__


//*********************************************************************//
//  API: LINUX ALSA SEQUENCER
//*********************************************************************//

// API information found at:
//   - http://www.alsa-project.org/documentation.php#Library

#if defined(__LINUX_ALSA__)

// The ALSA Sequencer API is based on the use of a callback function for
// MIDI input.
//
// Thanks to Pedro Lopez-Cabanillas for help with the ALSA sequencer
// time stamps and other assorted fixes!!!

// If you don't need timestamping for incoming MIDI events, define the
// preprocessor definition AVOID_TIMESTAMPING to save resources
// associated with the ALSA sequencer queues.

#include <pthread.h>
#include <sys/time.h>

// ALSA header file.
#include <alsa/asoundlib.h>

// A structure to hold variables related to the ALSA API
// implementation.
struct AlsaMidiData {
  snd_seq_t *seq;
  unsigned int portNum;
  int vport;
  snd_seq_port_subscribe_t *subscription;
  snd_midi_event_t *coder;
  unsigned int bufferSize;
  unsigned char *buffer;
  pthread_t thread;
  pthread_t dummy_thread_id;
  unsigned long long lastTime;
  int queue_id; // an input queue is needed to get timestamped events
  int trigger_fds[2];
};

#define PORT_TYPE( pinfo, bits ) ((snd_seq_port_info_get_capability(pinfo) & (bits)) == (bits))

//*********************************************************************//
//  API: LINUX ALSA
//  Class Definitions: MidiInAlsa
//*********************************************************************//

static void *alsaMidiHandler( void *ptr )
{
  MidiInApi::RtMidiInData *data = static_cast<MidiInApi::RtMidiInData *> (ptr);
  AlsaMidiData *apiData = static_cast<AlsaMidiData *> (data->apiData);

  long nBytes;
  unsigned long long time, lastTime;
  bool continueSysex = false;
  bool doDecode = false;
  MidiInApi::MidiMessage message;
  int poll_fd_count;
  struct pollfd *poll_fds;

  snd_seq_event_t *ev;
  int result;
  apiData->bufferSize = 32;
  result = snd_midi_event_new( 0, &apiData->coder );
  if ( result < 0 ) {
    data->doInput = false;
    std::cerr << "\nMidiInAlsa::alsaMidiHandler: error initializing MIDI event parser!\n\n";
    return 0;
  }
  unsigned char *buffer = (unsigned char *) malloc( apiData->bufferSize );
  if ( buffer == NULL ) {
    data->doInput = false;
    snd_midi_event_free( apiData->coder );
    apiData->coder = 0;
    std::cerr << "\nMidiInAlsa::alsaMidiHandler: error initializing buffer memory!\n\n";
    return 0;
  }
  snd_midi_event_init( apiData->coder );
  snd_midi_event_no_status( apiData->coder, 1 ); // suppress running status messages

  poll_fd_count = snd_seq_poll_descriptors_count( apiData->seq, POLLIN ) + 1;
  poll_fds = (struct pollfd*)alloca( poll_fd_count * sizeof( struct pollfd ));
  snd_seq_poll_descriptors( apiData->seq, poll_fds + 1, poll_fd_count - 1, POLLIN );
  poll_fds[0].fd = apiData->trigger_fds[0];
  poll_fds[0].events = POLLIN;

  while ( data->doInput ) {

    if ( snd_seq_event_input_pending( apiData->seq, 1 ) == 0 ) {
      // No data pending
      if ( poll( poll_fds, poll_fd_count, -1) >= 0 ) {
        if ( poll_fds[0].revents & POLLIN ) {
          bool dummy;
          int res = read( poll_fds[0].fd, &dummy, sizeof(dummy) );
          (void) res;
        }
      }
      continue;
    }

    // If here, there should be data.
    result = snd_seq_event_input( apiData->seq, &ev );
    if ( result == -ENOSPC ) {
      std::cerr << "\nMidiInAlsa::alsaMidiHandler: MIDI input buffer overrun!\n\n";
      continue;
    }
    else if ( result <= 0 ) {
      std::cerr << "\nMidiInAlsa::alsaMidiHandler: unknown MIDI input error!\n";
      perror("System reports");
      continue;
    }

    // This is a bit weird, but we now have to decode an ALSA MIDI
    // event (back) into MIDI bytes.  We'll ignore non-MIDI types.
    if ( !continueSysex ) message.bytes.clear();

    doDecode = false;
    switch ( ev->type ) {

    case SND_SEQ_EVENT_PORT_SUBSCRIBED:
#if defined(__RTMIDI_DEBUG__)
      std::cout << "MidiInAlsa::alsaMidiHandler: port connection made!\n";
#endif
      break;

    case SND_SEQ_EVENT_PORT_UNSUBSCRIBED:
#if defined(__RTMIDI_DEBUG__)
      std::cerr << "MidiInAlsa::alsaMidiHandler: port connection has closed!\n";
      std::cout << "sender = " << (int) ev->data.connect.sender.client << ":"
                << (int) ev->data.connect.sender.port
                << ", dest = " << (int) ev->data.connect.dest.client << ":"
                << (int) ev->data.connect.dest.port
                << std::endl;
#endif
      break;

    case SND_SEQ_EVENT_QFRAME: // MIDI time code
      if ( !( data->ignoreFlags & 0x02 ) ) doDecode = true;
      break;

    case SND_SEQ_EVENT_TICK: // 0xF9 ... MIDI timing tick
      if ( !( data->ignoreFlags & 0x02 ) ) doDecode = true;
      break;

    case SND_SEQ_EVENT_CLOCK: // 0xF8 ... MIDI timing (clock) tick
      if ( !( data->ignoreFlags & 0x02 ) ) doDecode = true;
      break;

    case SND_SEQ_EVENT_SENSING: // Active sensing
      if ( !( data->ignoreFlags & 0x04 ) ) doDecode = true;
      break;

		case SND_SEQ_EVENT_SYSEX:
      if ( (data->ignoreFlags & 0x01) ) break;
      if ( ev->data.ext.len > apiData->bufferSize ) {
        apiData->bufferSize = ev->data.ext.len;
        free( buffer );
        buffer = (unsigned char *) malloc( apiData->bufferSize );
        if ( buffer == NULL ) {
          data->doInput = false;
          std::cerr << "\nMidiInAlsa::alsaMidiHandler: error resizing buffer memory!\n\n";
          break;
        }
      }

    default:
      doDecode = true;
    }

    if ( doDecode ) {

      nBytes = snd_midi_event_decode( apiData->coder, buffer, apiData->bufferSize, ev );
      if ( nBytes > 0 ) {
        // The ALSA sequencer has a maximum buffer size for MIDI sysex
        // events of 256 bytes.  If a device sends sysex messages larger
        // than this, they are segmented into 256 byte chunks.  So,
        // we'll watch for this and concatenate sysex chunks into a
        // single sysex message if necessary.
        if ( !continueSysex )
          message.bytes.assign( buffer, &buffer[nBytes] );
        else
          message.bytes.insert( message.bytes.end(), buffer, &buffer[nBytes] );

        continueSysex = ( ( ev->type == SND_SEQ_EVENT_SYSEX ) && ( message.bytes.back() != 0xF7 ) );
        if ( !continueSysex ) {

          // Calculate the time stamp:
          message.timeStamp = 0.0;

          // Method 1: Use the system time.
          //(void)gettimeofday(&tv, (struct timezone *)NULL);
          //time = (tv.tv_sec * 1000000) + tv.tv_usec;

          // Method 2: Use the ALSA sequencer event time data.
          // (thanks to Pedro Lopez-Cabanillas!).
          time = ( ev->time.time.tv_sec * 1000000 ) + ( ev->time.time.tv_nsec/1000 );
          
          /*
          lastTime = time;
          time -= apiData->lastTime;
          apiData->lastTime = lastTime;
          if ( data->firstMessage == true )
            data->firstMessage = false;
          else
            message.timeStamp = time * 0.000001;
          */
          
          // Absolute usec based time stamp
          message.timeStamp = time;
        }
        else {
#if defined(__RTMIDI_DEBUG__)
          std::cerr << "\nMidiInAlsa::alsaMidiHandler: event parsing error or not a MIDI event!\n\n";
#endif
        }
      }
    }

    snd_seq_free_event( ev );
    if ( message.bytes.size() == 0 || continueSysex ) continue;

    if ( data->usingCallback ) {
      RtMidiIn::RtMidiCallback callback = (RtMidiIn::RtMidiCallback) data->userCallback;
      callback( message.timeStamp, &message.bytes, data->userData );
    }
    else {
      // As long as we haven't reached our queue size limit, push the message.
      if ( data->queue.size < data->queue.ringSize ) {
        data->queue.ring[data->queue.back++] = message;
        if ( data->queue.back == data->queue.ringSize )
          data->queue.back = 0;
        data->queue.size++;
      }
      else
        std::cerr << "\nMidiInAlsa: message queue limit reached!!\n\n";
    }
  }

  if ( buffer ) free( buffer );
  snd_midi_event_free( apiData->coder );
  apiData->coder = 0;
  apiData->thread = apiData->dummy_thread_id;
  return 0;
}

MidiInAlsa :: MidiInAlsa( const std::string clientName, unsigned int queueSizeLimit ) : MidiInApi( queueSizeLimit )
{
  initialize( clientName );
}

MidiInAlsa :: ~MidiInAlsa()
{
  // Close a connection if it exists.
  closePort();

  // Shutdown the input thread.
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( inputData_.doInput ) {
    inputData_.doInput = false;
    int res = write( data->trigger_fds[1], &inputData_.doInput, sizeof(inputData_.doInput) );
    (void) res;
    if ( !pthread_equal(data->thread, data->dummy_thread_id) )
      pthread_join( data->thread, NULL );
  }

  // Cleanup.
  close ( data->trigger_fds[0] );
  close ( data->trigger_fds[1] );
  if ( data->vport >= 0 ) snd_seq_delete_port( data->seq, data->vport );
#ifndef AVOID_TIMESTAMPING
  snd_seq_free_queue( data->seq, data->queue_id );
#endif
  snd_seq_close( data->seq );
  delete data;
}

void MidiInAlsa :: initialize( const std::string& clientName )
{
  // Set up the ALSA sequencer client.
  snd_seq_t *seq;
  int result = snd_seq_open(&seq, "default", SND_SEQ_OPEN_DUPLEX, SND_SEQ_NONBLOCK);
  if ( result < 0 ) {
    errorString_ = "MidiInAlsa::initialize: error creating ALSA sequencer client object.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Set client name.
  snd_seq_set_client_name( seq, clientName.c_str() );

  // Save our api-specific connection information.
  AlsaMidiData *data = (AlsaMidiData *) new AlsaMidiData;
  data->seq = seq;
  data->portNum = -1;
  data->vport = -1;
  data->subscription = 0;
  data->dummy_thread_id = pthread_self();
  data->thread = data->dummy_thread_id;
  data->trigger_fds[0] = -1;
  data->trigger_fds[1] = -1;
  apiData_ = (void *) data;
  inputData_.apiData = (void *) data;

   if ( pipe(data->trigger_fds) == -1 ) {
    errorString_ = "MidiInAlsa::initialize: error creating pipe objects.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Create the input queue
#ifndef AVOID_TIMESTAMPING
  data->queue_id = snd_seq_alloc_named_queue(seq, "RtMidi Queue");
  // Set arbitrary tempo (mm=100) and resolution (240)
  snd_seq_queue_tempo_t *qtempo;
  snd_seq_queue_tempo_alloca(&qtempo);
  snd_seq_queue_tempo_set_tempo(qtempo, 600000);
  snd_seq_queue_tempo_set_ppq(qtempo, 240);
  snd_seq_set_queue_tempo(data->seq, data->queue_id, qtempo);
  snd_seq_drain_output(data->seq);
#endif
}

// This function is used to count or get the pinfo structure for a given port number.
unsigned int portInfo( snd_seq_t *seq, snd_seq_port_info_t *pinfo, unsigned int type, int portNumber )
{
  snd_seq_client_info_t *cinfo;
  int client;
  int count = 0;
  snd_seq_client_info_alloca( &cinfo );

  snd_seq_client_info_set_client( cinfo, -1 );
  while ( snd_seq_query_next_client( seq, cinfo ) >= 0 ) {
    client = snd_seq_client_info_get_client( cinfo );
    if ( client == 0 ) continue;
    // Reset query info
    snd_seq_port_info_set_client( pinfo, client );
    snd_seq_port_info_set_port( pinfo, -1 );
    while ( snd_seq_query_next_port( seq, pinfo ) >= 0 ) {
      unsigned int atyp = snd_seq_port_info_get_type( pinfo );
      if ( ( atyp & SND_SEQ_PORT_TYPE_MIDI_GENERIC ) == 0 ) continue;
      unsigned int caps = snd_seq_port_info_get_capability( pinfo );
      if ( ( caps & type ) != type ) continue;
      if ( count == portNumber ) return 1;
      ++count;
    }
  }

  // If a negative portNumber was used, return the port count.
  if ( portNumber < 0 ) return count;
  return 0;
}

unsigned int MidiInAlsa :: getPortCount()
{
  snd_seq_port_info_t *pinfo;
  snd_seq_port_info_alloca( &pinfo );

  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  return portInfo( data->seq, pinfo, SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ, -1 );
}

std::string MidiInAlsa :: getPortName( unsigned int portNumber )
{
  snd_seq_client_info_t *cinfo;
  snd_seq_port_info_t *pinfo;
  snd_seq_client_info_alloca( &cinfo );
  snd_seq_port_info_alloca( &pinfo );

  std::string stringName;
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( portInfo( data->seq, pinfo, SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ, (int) portNumber ) ) {
    int cnum = snd_seq_port_info_get_client( pinfo );
    snd_seq_get_any_client_info( data->seq, cnum, cinfo );
    std::ostringstream os;
    os << snd_seq_client_info_get_name( cinfo );
    os << " ";                                    // These lines added to make sure devices are listed
    os << snd_seq_port_info_get_client( pinfo );  // with full portnames added to ensure individual device names
    os << ":";
    os << snd_seq_port_info_get_port( pinfo );
    stringName = os.str();
    return stringName;
  }

  // If we get here, we didn't find a match.
  errorString_ = "MidiInAlsa::getPortName: error looking for port name!";
  error( RtMidiError::WARNING, errorString_ );
  return stringName;
}

void MidiInAlsa :: openPort( unsigned int portNumber, const std::string portName )
{
  if ( connected_ ) {
    errorString_ = "MidiInAlsa::openPort: a valid connection already exists!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  unsigned int nSrc = this->getPortCount();
  if ( nSrc < 1 ) {
    errorString_ = "MidiInAlsa::openPort: no MIDI input sources found!";
    error( RtMidiError::NO_DEVICES_FOUND, errorString_ );
    return;
  }

  snd_seq_port_info_t *src_pinfo;
  snd_seq_port_info_alloca( &src_pinfo );
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( portInfo( data->seq, src_pinfo, SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ, (int) portNumber ) == 0 ) {
    std::ostringstream ost;
    ost << "MidiInAlsa::openPort: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::INVALID_PARAMETER, errorString_ );
    return;
  }

  snd_seq_addr_t sender, receiver;
  sender.client = snd_seq_port_info_get_client( src_pinfo );
  sender.port = snd_seq_port_info_get_port( src_pinfo );

  snd_seq_port_info_t *pinfo;
  snd_seq_port_info_alloca( &pinfo );
  if ( data->vport < 0 ) {
    snd_seq_port_info_set_client( pinfo, 0 );
    snd_seq_port_info_set_port( pinfo, 0 );
    snd_seq_port_info_set_capability( pinfo,
                                      SND_SEQ_PORT_CAP_WRITE |
                                      SND_SEQ_PORT_CAP_SUBS_WRITE );
    snd_seq_port_info_set_type( pinfo,
                                SND_SEQ_PORT_TYPE_MIDI_GENERIC |
                                SND_SEQ_PORT_TYPE_APPLICATION );
    snd_seq_port_info_set_midi_channels(pinfo, 16);
#ifndef AVOID_TIMESTAMPING
    snd_seq_port_info_set_timestamping(pinfo, 1);
    snd_seq_port_info_set_timestamp_real(pinfo, 1);    
    snd_seq_port_info_set_timestamp_queue(pinfo, data->queue_id);
#endif
    snd_seq_port_info_set_name(pinfo,  portName.c_str() );
    data->vport = snd_seq_create_port(data->seq, pinfo);
  
    if ( data->vport < 0 ) {
      errorString_ = "MidiInAlsa::openPort: ALSA error creating input port.";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
      return;
    }
    data->vport = snd_seq_port_info_get_port(pinfo);
  }

  receiver.client = snd_seq_port_info_get_client( pinfo );
  receiver.port = data->vport;

  if ( !data->subscription ) {
    // Make subscription
    if (snd_seq_port_subscribe_malloc( &data->subscription ) < 0) {
      errorString_ = "MidiInAlsa::openPort: ALSA error allocation port subscription.";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
      return;
    }
    snd_seq_port_subscribe_set_sender(data->subscription, &sender);
    snd_seq_port_subscribe_set_dest(data->subscription, &receiver);
    if ( snd_seq_subscribe_port(data->seq, data->subscription) ) {
      snd_seq_port_subscribe_free( data->subscription );
      data->subscription = 0;
      errorString_ = "MidiInAlsa::openPort: ALSA error making port connection.";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
      return;
    }
  }

  if ( inputData_.doInput == false ) {
    // Start the input queue
#ifndef AVOID_TIMESTAMPING
    snd_seq_start_queue( data->seq, data->queue_id, NULL );
    snd_seq_drain_output( data->seq );
#endif
    // Start our MIDI input thread.
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_attr_setschedpolicy(&attr, SCHED_OTHER);

    inputData_.doInput = true;
    int err = pthread_create(&data->thread, &attr, alsaMidiHandler, &inputData_);
    pthread_attr_destroy(&attr);
    if ( err ) {
      snd_seq_unsubscribe_port( data->seq, data->subscription );
      snd_seq_port_subscribe_free( data->subscription );
      data->subscription = 0;
      inputData_.doInput = false;
      errorString_ = "MidiInAlsa::openPort: error starting MIDI input thread!";
      error( RtMidiError::THREAD_ERROR, errorString_ );
      return;
    }
  }

  connected_ = true;
}

void MidiInAlsa :: openVirtualPort( std::string portName )
{
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( data->vport < 0 ) {
    snd_seq_port_info_t *pinfo;
    snd_seq_port_info_alloca( &pinfo );
    snd_seq_port_info_set_capability( pinfo,
				      SND_SEQ_PORT_CAP_WRITE |
				      SND_SEQ_PORT_CAP_SUBS_WRITE );
    snd_seq_port_info_set_type( pinfo,
				SND_SEQ_PORT_TYPE_MIDI_GENERIC |
				SND_SEQ_PORT_TYPE_APPLICATION );
    snd_seq_port_info_set_midi_channels(pinfo, 16);
#ifndef AVOID_TIMESTAMPING
    snd_seq_port_info_set_timestamping(pinfo, 1);
    snd_seq_port_info_set_timestamp_real(pinfo, 1);    
    snd_seq_port_info_set_timestamp_queue(pinfo, data->queue_id);
#endif
    snd_seq_port_info_set_name(pinfo, portName.c_str());
    data->vport = snd_seq_create_port(data->seq, pinfo);

    if ( data->vport < 0 ) {
      errorString_ = "MidiInAlsa::openVirtualPort: ALSA error creating virtual port.";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
      return;
    }
    data->vport = snd_seq_port_info_get_port(pinfo);
  }

  if ( inputData_.doInput == false ) {
    // Wait for old thread to stop, if still running
    if ( !pthread_equal(data->thread, data->dummy_thread_id) )
      pthread_join( data->thread, NULL );

    // Start the input queue
#ifndef AVOID_TIMESTAMPING
    snd_seq_start_queue( data->seq, data->queue_id, NULL );
    snd_seq_drain_output( data->seq );
#endif
    // Start our MIDI input thread.
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_attr_setschedpolicy(&attr, SCHED_OTHER);

    inputData_.doInput = true;
    int err = pthread_create(&data->thread, &attr, alsaMidiHandler, &inputData_);
    pthread_attr_destroy(&attr);
    if ( err ) {
      if ( data->subscription ) {
        snd_seq_unsubscribe_port( data->seq, data->subscription );
        snd_seq_port_subscribe_free( data->subscription );
        data->subscription = 0;
      }
      inputData_.doInput = false;
      errorString_ = "MidiInAlsa::openPort: error starting MIDI input thread!";
      error( RtMidiError::THREAD_ERROR, errorString_ );
      return;
    }
  }
}

void MidiInAlsa :: closePort( void )
{
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);

  if ( connected_ ) {
    if ( data->subscription ) {
      snd_seq_unsubscribe_port( data->seq, data->subscription );
      snd_seq_port_subscribe_free( data->subscription );
      data->subscription = 0;
    }
    // Stop the input queue
#ifndef AVOID_TIMESTAMPING
    snd_seq_stop_queue( data->seq, data->queue_id, NULL );
    snd_seq_drain_output( data->seq );
#endif
    connected_ = false;
  }

  // Stop thread to avoid triggering the callback, while the port is intended to be closed
  if ( inputData_.doInput ) {
    inputData_.doInput = false;
    int res = write( data->trigger_fds[1], &inputData_.doInput, sizeof(inputData_.doInput) );
    (void) res;
    if ( !pthread_equal(data->thread, data->dummy_thread_id) )
      pthread_join( data->thread, NULL );
  }
}

//*********************************************************************//
//  API: LINUX ALSA
//  Class Definitions: MidiOutAlsa
//*********************************************************************//

MidiOutAlsa :: MidiOutAlsa( const std::string clientName ) : MidiOutApi()
{
  initialize( clientName );
}

MidiOutAlsa :: ~MidiOutAlsa()
{
  // Close a connection if it exists.
  closePort();

  // Cleanup.
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( data->vport >= 0 ) snd_seq_delete_port( data->seq, data->vport );
  if ( data->coder ) snd_midi_event_free( data->coder );
  if ( data->buffer ) free( data->buffer );
  snd_seq_close( data->seq );
  delete data;
}

void MidiOutAlsa :: initialize( const std::string& clientName )
{
  // Set up the ALSA sequencer client.
  snd_seq_t *seq;
  int result1 = snd_seq_open( &seq, "default", SND_SEQ_OPEN_OUTPUT, SND_SEQ_NONBLOCK );
  if ( result1 < 0 ) {
    errorString_ = "MidiOutAlsa::initialize: error creating ALSA sequencer client object.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
	}

  // Set client name.
  snd_seq_set_client_name( seq, clientName.c_str() );

  // Save our api-specific connection information.
  AlsaMidiData *data = (AlsaMidiData *) new AlsaMidiData;
  data->seq = seq;
  data->portNum = -1;
  data->vport = -1;
  data->bufferSize = 32;
  data->coder = 0;
  data->buffer = 0;
  int result = snd_midi_event_new( data->bufferSize, &data->coder );
  if ( result < 0 ) {
    delete data;
    errorString_ = "MidiOutAlsa::initialize: error initializing MIDI event parser!\n\n";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }
  data->buffer = (unsigned char *) malloc( data->bufferSize );
  if ( data->buffer == NULL ) {
    delete data;
    errorString_ = "MidiOutAlsa::initialize: error allocating buffer memory!\n\n";
    error( RtMidiError::MEMORY_ERROR, errorString_ );
    return;
  }
  snd_midi_event_init( data->coder );
  apiData_ = (void *) data;
}

unsigned int MidiOutAlsa :: getPortCount()
{
	snd_seq_port_info_t *pinfo;
	snd_seq_port_info_alloca( &pinfo );

  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  return portInfo( data->seq, pinfo, SND_SEQ_PORT_CAP_WRITE|SND_SEQ_PORT_CAP_SUBS_WRITE, -1 );
}

std::string MidiOutAlsa :: getPortName( unsigned int portNumber )
{
  snd_seq_client_info_t *cinfo;
  snd_seq_port_info_t *pinfo;
  snd_seq_client_info_alloca( &cinfo );
  snd_seq_port_info_alloca( &pinfo );

  std::string stringName;
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( portInfo( data->seq, pinfo, SND_SEQ_PORT_CAP_WRITE|SND_SEQ_PORT_CAP_SUBS_WRITE, (int) portNumber ) ) {
    int cnum = snd_seq_port_info_get_client(pinfo);
    snd_seq_get_any_client_info( data->seq, cnum, cinfo );
    std::ostringstream os;
    os << snd_seq_client_info_get_name(cinfo);
    os << " ";                                    // These lines added to make sure devices are listed
    os << snd_seq_port_info_get_client( pinfo );  // with full portnames added to ensure individual device names
    os << ":";
    os << snd_seq_port_info_get_port(pinfo);
    stringName = os.str();
    return stringName;
  }

  // If we get here, we didn't find a match.
  errorString_ = "MidiOutAlsa::getPortName: error looking for port name!";
  error( RtMidiError::WARNING, errorString_ );
  return stringName;
}

void MidiOutAlsa :: openPort( unsigned int portNumber, const std::string portName )
{
  if ( connected_ ) {
    errorString_ = "MidiOutAlsa::openPort: a valid connection already exists!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  unsigned int nSrc = this->getPortCount();
  if (nSrc < 1) {
    errorString_ = "MidiOutAlsa::openPort: no MIDI output sources found!";
    error( RtMidiError::NO_DEVICES_FOUND, errorString_ );
    return;
  }

	snd_seq_port_info_t *pinfo;
	snd_seq_port_info_alloca( &pinfo );
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( portInfo( data->seq, pinfo, SND_SEQ_PORT_CAP_WRITE|SND_SEQ_PORT_CAP_SUBS_WRITE, (int) portNumber ) == 0 ) {
    std::ostringstream ost;
    ost << "MidiOutAlsa::openPort: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::INVALID_PARAMETER, errorString_ );
    return;
  }

  snd_seq_addr_t sender, receiver;
  receiver.client = snd_seq_port_info_get_client( pinfo );
  receiver.port = snd_seq_port_info_get_port( pinfo );
  sender.client = snd_seq_client_id( data->seq );

  if ( data->vport < 0 ) {
    data->vport = snd_seq_create_simple_port( data->seq, portName.c_str(),
                                              SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ,
                                              SND_SEQ_PORT_TYPE_MIDI_GENERIC|SND_SEQ_PORT_TYPE_APPLICATION );
    if ( data->vport < 0 ) {
      errorString_ = "MidiOutAlsa::openPort: ALSA error creating output port.";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
      return;
    }
  }

  sender.port = data->vport;

  // Make subscription
  if (snd_seq_port_subscribe_malloc( &data->subscription ) < 0) {
    snd_seq_port_subscribe_free( data->subscription );
    errorString_ = "MidiOutAlsa::openPort: error allocating port subscription.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }
  snd_seq_port_subscribe_set_sender(data->subscription, &sender);
  snd_seq_port_subscribe_set_dest(data->subscription, &receiver);
  snd_seq_port_subscribe_set_time_update(data->subscription, 1);
  snd_seq_port_subscribe_set_time_real(data->subscription, 1);
  if ( snd_seq_subscribe_port(data->seq, data->subscription) ) {
    snd_seq_port_subscribe_free( data->subscription );
    errorString_ = "MidiOutAlsa::openPort: ALSA error making port connection.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  connected_ = true;
}

void MidiOutAlsa :: closePort( void )
{
  if ( connected_ ) {
    AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
    snd_seq_unsubscribe_port( data->seq, data->subscription );
    snd_seq_port_subscribe_free( data->subscription );
    connected_ = false;
  }
}

void MidiOutAlsa :: openVirtualPort( std::string portName )
{
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  if ( data->vport < 0 ) {
    data->vport = snd_seq_create_simple_port( data->seq, portName.c_str(),
                                              SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ,
                                              SND_SEQ_PORT_TYPE_MIDI_GENERIC|SND_SEQ_PORT_TYPE_APPLICATION );

    if ( data->vport < 0 ) {
      errorString_ = "MidiOutAlsa::openVirtualPort: ALSA error creating virtual port.";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
    }
  }
}

void MidiOutAlsa :: sendMessage( std::vector<unsigned char> *message )
{
  int result;
  AlsaMidiData *data = static_cast<AlsaMidiData *> (apiData_);
  unsigned int nBytes = message->size();
  if ( nBytes > data->bufferSize ) {
    data->bufferSize = nBytes;
    result = snd_midi_event_resize_buffer ( data->coder, nBytes);
    if ( result != 0 ) {
      errorString_ = "MidiOutAlsa::sendMessage: ALSA error resizing MIDI event buffer.";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
      return;
    }
    free (data->buffer);
    data->buffer = (unsigned char *) malloc( data->bufferSize );
    if ( data->buffer == NULL ) {
    errorString_ = "MidiOutAlsa::initialize: error allocating buffer memory!\n\n";
    error( RtMidiError::MEMORY_ERROR, errorString_ );
    return;
    }
  }

  snd_seq_event_t ev;
  snd_seq_ev_clear(&ev);
  snd_seq_ev_set_source(&ev, data->vport);
  snd_seq_ev_set_subs(&ev);
  snd_seq_ev_set_direct(&ev);
  for ( unsigned int i=0; i<nBytes; ++i ) data->buffer[i] = message->at(i);
  result = snd_midi_event_encode( data->coder, data->buffer, (long)nBytes, &ev );
  if ( result < (int)nBytes ) {
    errorString_ = "MidiOutAlsa::sendMessage: event parsing error!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  // Send the event.
  result = snd_seq_event_output(data->seq, &ev);
  if ( result < 0 ) {
    errorString_ = "MidiOutAlsa::sendMessage: error sending MIDI message to port.";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }
  snd_seq_drain_output(data->seq);
}

#endif // __LINUX_ALSA__


//*********************************************************************//
//  API: Windows Multimedia Library (MM)
//*********************************************************************//

// API information deciphered from:
//  - http://msdn.microsoft.com/library/default.asp?url=/library/en-us/multimed/htm/_win32_midi_reference.asp

// Thanks to Jean-Baptiste Berruchon for the sysex code.

#if defined(__WINDOWS_MM__)

// The Windows MM API is based on the use of a callback function for
// MIDI input.  We convert the system specific time stamps to delta
// time values.

// Windows MM MIDI header files.
#include <windows.h>
#include <mmsystem.h>

#define  RT_SYSEX_BUFFER_SIZE 1024
#define  RT_SYSEX_BUFFER_COUNT 4

// A structure to hold variables related to the CoreMIDI API
// implementation.
struct WinMidiData {
  HMIDIIN inHandle;    // Handle to Midi Input Device
  HMIDIOUT outHandle;  // Handle to Midi Output Device
  DWORD lastTime;
  MidiInApi::MidiMessage message;
  LPMIDIHDR sysexBuffer[RT_SYSEX_BUFFER_COUNT];
  CRITICAL_SECTION _mutex; // [Patrice] see https://groups.google.com/forum/#!topic/mididev/6OUjHutMpEo
};

//*********************************************************************//
//  API: Windows MM
//  Class Definitions: MidiInWinMM
//*********************************************************************//

static void CALLBACK midiInputCallback( HMIDIIN /*hmin*/,
                                        UINT inputStatus, 
                                        DWORD_PTR instancePtr,
                                        DWORD_PTR midiMessage,
                                        DWORD timestamp )
{
  if ( inputStatus != MIM_DATA && inputStatus != MIM_LONGDATA && inputStatus != MIM_LONGERROR ) return;

  //MidiInApi::RtMidiInData *data = static_cast<MidiInApi::RtMidiInData *> (instancePtr);
  MidiInApi::RtMidiInData *data = (MidiInApi::RtMidiInData *)instancePtr;
  WinMidiData *apiData = static_cast<WinMidiData *> (data->apiData);

  // Calculate time stamp.
  /*
  if ( data->firstMessage == true ) {
    apiData->message.timeStamp = 0.0;
    data->firstMessage = false;
  }
  else apiData->message.timeStamp = (double) ( timestamp - apiData->lastTime ) * 0.001;
  apiData->lastTime = timestamp;
  
  */
  
  // Absolute usec based time stamp
  apiData->message.timeStamp = double(timestamp - apiData->lastTime) * 1000;

  if ( inputStatus == MIM_DATA ) { // Channel or system message

    // Make sure the first byte is a status byte.
    unsigned char status = (unsigned char) (midiMessage & 0x000000FF);
    if ( !(status & 0x80) ) return;

    // Determine the number of bytes in the MIDI message.
    unsigned short nBytes = 1;
    if ( status < 0xC0 ) nBytes = 3;
    else if ( status < 0xE0 ) nBytes = 2;
    else if ( status < 0xF0 ) nBytes = 3;
    else if ( status == 0xF1 ) {
      if ( data->ignoreFlags & 0x02 ) return;
      else nBytes = 2;
    }
    else if ( status == 0xF2 ) nBytes = 3;
    else if ( status == 0xF3 ) nBytes = 2;
    else if ( status == 0xF8 && (data->ignoreFlags & 0x02) ) {
      // A MIDI timing tick message and we're ignoring it.
      return;
    }
    else if ( status == 0xFE && (data->ignoreFlags & 0x04) ) {
      // A MIDI active sensing message and we're ignoring it.
      return;
    }

    // Copy bytes to our MIDI message.
    unsigned char *ptr = (unsigned char *) &midiMessage;
    for ( int i=0; i<nBytes; ++i ) apiData->message.bytes.push_back( *ptr++ );
  }
  else { // Sysex message ( MIM_LONGDATA or MIM_LONGERROR )
    MIDIHDR *sysex = ( MIDIHDR *) midiMessage; 
    if ( !( data->ignoreFlags & 0x01 ) && inputStatus != MIM_LONGERROR ) {  
      // Sysex message and we're not ignoring it
      for ( int i=0; i<(int)sysex->dwBytesRecorded; ++i )
        apiData->message.bytes.push_back( sysex->lpData[i] );
    }

    // The WinMM API requires that the sysex buffer be requeued after
    // input of each sysex message.  Even if we are ignoring sysex
    // messages, we still need to requeue the buffer in case the user
    // decides to not ignore sysex messages in the future.  However,
    // it seems that WinMM calls this function with an empty sysex
    // buffer when an application closes and in this case, we should
    // avoid requeueing it, else the computer suddenly reboots after
    // one or two minutes.
    if ( apiData->sysexBuffer[sysex->dwUser]->dwBytesRecorded > 0 ) {
      //if ( sysex->dwBytesRecorded > 0 ) {
      EnterCriticalSection( &(apiData->_mutex) );
      MMRESULT result = midiInAddBuffer( apiData->inHandle, apiData->sysexBuffer[sysex->dwUser], sizeof(MIDIHDR) );
      LeaveCriticalSection( &(apiData->_mutex) );
      if ( result != MMSYSERR_NOERROR )
        std::cerr << "\nRtMidiIn::midiInputCallback: error sending sysex to Midi device!!\n\n";

      if ( data->ignoreFlags & 0x01 ) return;
    }
    else return;
  }

  if ( data->usingCallback ) {
    RtMidiIn::RtMidiCallback callback = (RtMidiIn::RtMidiCallback) data->userCallback;
    callback( apiData->message.timeStamp, &apiData->message.bytes, data->userData );
  }
  else {
    // As long as we haven't reached our queue size limit, push the message.
    if ( data->queue.size < data->queue.ringSize ) {
      data->queue.ring[data->queue.back++] = apiData->message;
      if ( data->queue.back == data->queue.ringSize )
        data->queue.back = 0;
      data->queue.size++;
    }
    else
      std::cerr << "\nRtMidiIn: message queue limit reached!!\n\n";
  }

  // Clear the vector for the next input message.
  apiData->message.bytes.clear();
}

MidiInWinMM :: MidiInWinMM( const std::string clientName, unsigned int queueSizeLimit ) : MidiInApi( queueSizeLimit )
{
  initialize( clientName );
}

MidiInWinMM :: ~MidiInWinMM()
{
  // Close a connection if it exists.
  closePort();

  WinMidiData *data = static_cast<WinMidiData *> (apiData_);
  DeleteCriticalSection( &(data->_mutex) );

  // Cleanup.
  delete data;
}

void MidiInWinMM :: initialize( const std::string& /*clientName*/ )
{
  // We'll issue a warning here if no devices are available but not
  // throw an error since the user can plugin something later.
  unsigned int nDevices = midiInGetNumDevs();
  if ( nDevices == 0 ) {
    errorString_ = "MidiInWinMM::initialize: no MIDI input devices currently available.";
    error( RtMidiError::WARNING, errorString_ );
  }

  // Save our api-specific connection information.
  WinMidiData *data = (WinMidiData *) new WinMidiData;
  apiData_ = (void *) data;
  inputData_.apiData = (void *) data;
  data->message.bytes.clear();  // needs to be empty for first input message

  if ( !InitializeCriticalSectionAndSpinCount(&(data->_mutex), 0x00000400) ) {
    errorString_ = "MidiInWinMM::initialize: InitializeCriticalSectionAndSpinCount failed.";
    error( RtMidiError::WARNING, errorString_ );
  }
}

void MidiInWinMM :: openPort( unsigned int portNumber, const std::string /*portName*/ )
{
  if ( connected_ ) {
    errorString_ = "MidiInWinMM::openPort: a valid connection already exists!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  unsigned int nDevices = midiInGetNumDevs();
  if (nDevices == 0) {
    errorString_ = "MidiInWinMM::openPort: no MIDI input sources found!";
    error( RtMidiError::NO_DEVICES_FOUND, errorString_ );
    return;
  }

  if ( portNumber >= nDevices ) {
    std::ostringstream ost;
    ost << "MidiInWinMM::openPort: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::INVALID_PARAMETER, errorString_ );
    return;
  }

  WinMidiData *data = static_cast<WinMidiData *> (apiData_);
  MMRESULT result = midiInOpen( &data->inHandle,
                                portNumber,
                                (DWORD_PTR)&midiInputCallback,
                                (DWORD_PTR)&inputData_,
                                CALLBACK_FUNCTION );
  if ( result != MMSYSERR_NOERROR ) {
    errorString_ = "MidiInWinMM::openPort: error creating Windows MM MIDI input port.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Allocate and init the sysex buffers.
  for ( int i=0; i<RT_SYSEX_BUFFER_COUNT; ++i ) {
    data->sysexBuffer[i] = (MIDIHDR*) new char[ sizeof(MIDIHDR) ];
    data->sysexBuffer[i]->lpData = new char[ RT_SYSEX_BUFFER_SIZE ];
    data->sysexBuffer[i]->dwBufferLength = RT_SYSEX_BUFFER_SIZE;
    data->sysexBuffer[i]->dwUser = i; // We use the dwUser parameter as buffer indicator
    data->sysexBuffer[i]->dwFlags = 0;

    result = midiInPrepareHeader( data->inHandle, data->sysexBuffer[i], sizeof(MIDIHDR) );
    if ( result != MMSYSERR_NOERROR ) {
      midiInClose( data->inHandle );
      errorString_ = "MidiInWinMM::openPort: error starting Windows MM MIDI input port (PrepareHeader).";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
      return;
    }

    // Register the buffer.
    result = midiInAddBuffer( data->inHandle, data->sysexBuffer[i], sizeof(MIDIHDR) );
    if ( result != MMSYSERR_NOERROR ) {
      midiInClose( data->inHandle );
      errorString_ = "MidiInWinMM::openPort: error starting Windows MM MIDI input port (AddBuffer).";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
      return;
    }
  }

  result = midiInStart( data->inHandle );
  if ( result != MMSYSERR_NOERROR ) {
    midiInClose( data->inHandle );
    errorString_ = "MidiInWinMM::openPort: error starting Windows MM MIDI input port.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  connected_ = true;
}

void MidiInWinMM :: openVirtualPort( std::string /*portName*/ )
{
  // This function cannot be implemented for the Windows MM MIDI API.
  errorString_ = "MidiInWinMM::openVirtualPort: cannot be implemented in Windows MM MIDI API!";
  error( RtMidiError::WARNING, errorString_ );
}

void MidiInWinMM :: closePort( void )
{
  if ( connected_ ) {
    WinMidiData *data = static_cast<WinMidiData *> (apiData_);
    EnterCriticalSection( &(data->_mutex) );
    midiInReset( data->inHandle );
    midiInStop( data->inHandle );

    for ( int i=0; i<RT_SYSEX_BUFFER_COUNT; ++i ) {
      int result = midiInUnprepareHeader(data->inHandle, data->sysexBuffer[i], sizeof(MIDIHDR));
      delete [] data->sysexBuffer[i]->lpData;
      delete [] data->sysexBuffer[i];
      if ( result != MMSYSERR_NOERROR ) {
        midiInClose( data->inHandle );
        errorString_ = "MidiInWinMM::openPort: error closing Windows MM MIDI input port (midiInUnprepareHeader).";
        error( RtMidiError::DRIVER_ERROR, errorString_ );
        return;
      }
    }

    midiInClose( data->inHandle );
    connected_ = false;
    LeaveCriticalSection( &(data->_mutex) );
  }
}

unsigned int MidiInWinMM :: getPortCount()
{
  return midiInGetNumDevs();
}

std::string MidiInWinMM :: getPortName( unsigned int portNumber )
{
  std::string stringName;
  unsigned int nDevices = midiInGetNumDevs();
  if ( portNumber >= nDevices ) {
    std::ostringstream ost;
    ost << "MidiInWinMM::getPortName: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::WARNING, errorString_ );
    return stringName;
  }

  MIDIINCAPS deviceCaps;
  midiInGetDevCaps( portNumber, &deviceCaps, sizeof(MIDIINCAPS));

#if defined( UNICODE ) || defined( _UNICODE )
  int length = WideCharToMultiByte(CP_UTF8, 0, deviceCaps.szPname, -1, NULL, 0, NULL, NULL) - 1;
  stringName.assign( length, 0 );
  length = WideCharToMultiByte(CP_UTF8, 0, deviceCaps.szPname, static_cast<int>(wcslen(deviceCaps.szPname)), &stringName[0], length, NULL, NULL);
#else
  stringName = std::string( deviceCaps.szPname );
#endif

  // Next lines added to add the portNumber to the name so that 
  // the device's names are sure to be listed with individual names
  // even when they have the same brand name
  std::ostringstream os;
  os << " ";
  os << portNumber;
  stringName += os.str();

  return stringName;
}

//*********************************************************************//
//  API: Windows MM
//  Class Definitions: MidiOutWinMM
//*********************************************************************//

MidiOutWinMM :: MidiOutWinMM( const std::string clientName ) : MidiOutApi()
{
  initialize( clientName );
}

MidiOutWinMM :: ~MidiOutWinMM()
{
  // Close a connection if it exists.
  closePort();

  // Cleanup.
  WinMidiData *data = static_cast<WinMidiData *> (apiData_);
  delete data;
}

void MidiOutWinMM :: initialize( const std::string& /*clientName*/ )
{
  // We'll issue a warning here if no devices are available but not
  // throw an error since the user can plug something in later.
  unsigned int nDevices = midiOutGetNumDevs();
  if ( nDevices == 0 ) {
    errorString_ = "MidiOutWinMM::initialize: no MIDI output devices currently available.";
    error( RtMidiError::WARNING, errorString_ );
  }

  // Save our api-specific connection information.
  WinMidiData *data = (WinMidiData *) new WinMidiData;
  apiData_ = (void *) data;
}

unsigned int MidiOutWinMM :: getPortCount()
{
  return midiOutGetNumDevs();
}

std::string MidiOutWinMM :: getPortName( unsigned int portNumber )
{
  std::string stringName;
  unsigned int nDevices = midiOutGetNumDevs();
  if ( portNumber >= nDevices ) {
    std::ostringstream ost;
    ost << "MidiOutWinMM::getPortName: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::WARNING, errorString_ );
    return stringName;
  }

  MIDIOUTCAPS deviceCaps;
  midiOutGetDevCaps( portNumber, &deviceCaps, sizeof(MIDIOUTCAPS));

#if defined( UNICODE ) || defined( _UNICODE )
  int length = WideCharToMultiByte(CP_UTF8, 0, deviceCaps.szPname, -1, NULL, 0, NULL, NULL) - 1;
  stringName.assign( length, 0 );
  length = WideCharToMultiByte(CP_UTF8, 0, deviceCaps.szPname, static_cast<int>(wcslen(deviceCaps.szPname)), &stringName[0], length, NULL, NULL);
#else
  stringName = std::string( deviceCaps.szPname );
#endif

  return stringName;
}

void MidiOutWinMM :: openPort( unsigned int portNumber, const std::string /*portName*/ )
{
  if ( connected_ ) {
    errorString_ = "MidiOutWinMM::openPort: a valid connection already exists!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  unsigned int nDevices = midiOutGetNumDevs();
  if (nDevices < 1) {
    errorString_ = "MidiOutWinMM::openPort: no MIDI output destinations found!";
    error( RtMidiError::NO_DEVICES_FOUND, errorString_ );
    return;
  }

  if ( portNumber >= nDevices ) {
    std::ostringstream ost;
    ost << "MidiOutWinMM::openPort: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::INVALID_PARAMETER, errorString_ );
    return;
  }

  WinMidiData *data = static_cast<WinMidiData *> (apiData_);
  MMRESULT result = midiOutOpen( &data->outHandle,
                                 portNumber,
                                 (DWORD)NULL,
                                 (DWORD)NULL,
                                 CALLBACK_NULL );
  if ( result != MMSYSERR_NOERROR ) {
    errorString_ = "MidiOutWinMM::openPort: error creating Windows MM MIDI output port.";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  connected_ = true;
}

void MidiOutWinMM :: closePort( void )
{
  if ( connected_ ) {
    WinMidiData *data = static_cast<WinMidiData *> (apiData_);
    midiOutReset( data->outHandle );
    midiOutClose( data->outHandle );
    connected_ = false;
  }
}

void MidiOutWinMM :: openVirtualPort( std::string /*portName*/ )
{
  // This function cannot be implemented for the Windows MM MIDI API.
  errorString_ = "MidiOutWinMM::openVirtualPort: cannot be implemented in Windows MM MIDI API!";
  error( RtMidiError::WARNING, errorString_ );
}

void MidiOutWinMM :: sendMessage( std::vector<unsigned char> *message )
{
  if ( !connected_ ) return;

  unsigned int nBytes = static_cast<unsigned int>(message->size());
  if ( nBytes == 0 ) {
    errorString_ = "MidiOutWinMM::sendMessage: message argument is empty!";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  MMRESULT result;
  WinMidiData *data = static_cast<WinMidiData *> (apiData_);
  if ( message->at(0) == 0xF0 ) { // Sysex message

    // Allocate buffer for sysex data.
    char *buffer = (char *) malloc( nBytes );
    if ( buffer == NULL ) {
      errorString_ = "MidiOutWinMM::sendMessage: error allocating sysex message memory!";
      error( RtMidiError::MEMORY_ERROR, errorString_ );
      return;
    }

    // Copy data to buffer.
    for ( unsigned int i=0; i<nBytes; ++i ) buffer[i] = message->at(i);

    // Create and prepare MIDIHDR structure.
    MIDIHDR sysex;
    sysex.lpData = (LPSTR) buffer;
    sysex.dwBufferLength = nBytes;
    sysex.dwFlags = 0;
    result = midiOutPrepareHeader( data->outHandle,  &sysex, sizeof(MIDIHDR) ); 
    if ( result != MMSYSERR_NOERROR ) {
      free( buffer );
      errorString_ = "MidiOutWinMM::sendMessage: error preparing sysex header.";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
      return;
    }

    // Send the message.
    result = midiOutLongMsg( data->outHandle, &sysex, sizeof(MIDIHDR) );
    if ( result != MMSYSERR_NOERROR ) {
      free( buffer );
      errorString_ = "MidiOutWinMM::sendMessage: error sending sysex message.";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
      return;
    }

    // Unprepare the buffer and MIDIHDR.
    while ( MIDIERR_STILLPLAYING == midiOutUnprepareHeader( data->outHandle, &sysex, sizeof (MIDIHDR) ) ) Sleep( 1 );
    free( buffer );
  }
  else { // Channel or system message.

    // Make sure the message size isn't too big.
    if ( nBytes > 3 ) {
      errorString_ = "MidiOutWinMM::sendMessage: message size is greater than 3 bytes (and not sysex)!";
      error( RtMidiError::WARNING, errorString_ );
      return;
    }

    // Pack MIDI bytes into double word.
    DWORD packet;
    unsigned char *ptr = (unsigned char *) &packet;
    for ( unsigned int i=0; i<nBytes; ++i ) {
      *ptr = message->at(i);
      ++ptr;
    }

    // Send the message immediately.
    result = midiOutShortMsg( data->outHandle, packet );
    if ( result != MMSYSERR_NOERROR ) {
      errorString_ = "MidiOutWinMM::sendMessage: error sending MIDI message.";
      error( RtMidiError::DRIVER_ERROR, errorString_ );
    }
  }
}

#endif  // __WINDOWS_MM__


//*********************************************************************//
//  API: UNIX JACK
//
//  Written primarily by Alexander Svetalkin, with updates for delta
//  time by Gary Scavone, April 2011.
//
//  *********************************************************************//

#if defined(__UNIX_JACK__)

// JACK header files
#include <jack/jack.h>
#include <jack/midiport.h>
#include <jack/ringbuffer.h>

#define JACK_RINGBUFFER_SIZE 16384 // Default size for ringbuffer

struct JackMidiData {
  jack_client_t *client;
  jack_port_t *port;
  jack_ringbuffer_t *buffSize;
  jack_ringbuffer_t *buffMessage;
  jack_time_t lastTime;
  MidiInApi :: RtMidiInData *rtMidiIn;
  };

//*********************************************************************//
//  API: JACK
//  Class Definitions: MidiInJack
//*********************************************************************//

static int jackProcessIn( jack_nframes_t nframes, void *arg )
{
  JackMidiData *jData = (JackMidiData *) arg;
  MidiInApi :: RtMidiInData *rtData = jData->rtMidiIn;
  jack_midi_event_t event;
  jack_time_t time;

  // Is port created?
  if ( jData->port == NULL ) return 0;
  void *buff = jack_port_get_buffer( jData->port, nframes );

  // We have midi events in buffer
  int evCount = jack_midi_get_event_count( buff );
  for (int j = 0; j < evCount; j++) {
    MidiInApi::MidiMessage message;
    message.bytes.clear();

    jack_midi_event_get( &event, buff, j );

    for ( unsigned int i = 0; i < event.size; i++ )
      message.bytes.push_back( event.buffer[i] );

    // TODO: incorrect time stamps...
    
    // Compute the delta time.
    time = jack_get_time();
    
    if ( rtData->firstMessage == true )
      rtData->firstMessage = false;
    else
      message.timeStamp = ( time - jData->lastTime ) * 0.000001;

    jData->lastTime = time;
   
    if ( !rtData->continueSysex ) {
      if ( rtData->usingCallback ) {
        RtMidiIn::RtMidiCallback callback = (RtMidiIn::RtMidiCallback) rtData->userCallback;
        callback( message.timeStamp, &message.bytes, rtData->userData );
      }
      else {
        // As long as we haven't reached our queue size limit, push the message.
        if ( rtData->queue.size < rtData->queue.ringSize ) {
          rtData->queue.ring[rtData->queue.back++] = message;
          if ( rtData->queue.back == rtData->queue.ringSize )
            rtData->queue.back = 0;
          rtData->queue.size++;
        }
        else
          std::cerr << "\nMidiInJack: message queue limit reached!!\n\n";
      }
    }
  }

  return 0;
}

MidiInJack :: MidiInJack( const std::string clientName, unsigned int queueSizeLimit ) : MidiInApi( queueSizeLimit )
{
  initialize( clientName );
}

void MidiInJack :: initialize( const std::string& clientName )
{
  JackMidiData *data = new JackMidiData;
  apiData_ = (void *) data;

  data->rtMidiIn = &inputData_;
  data->port = NULL;
  data->client = NULL;
  this->clientName = clientName;

  connect();
}

void MidiInJack :: connect()
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);
  if ( data->client )
    return;

  // Initialize JACK client
  if ((data->client = jack_client_open( clientName.c_str(), JackNoStartServer, NULL )) == 0) {
    errorString_ = "MidiInJack::initialize: JACK server not running?";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  jack_set_process_callback( data->client, jackProcessIn, data );
  jack_activate( data->client );
}

MidiInJack :: ~MidiInJack()
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);
  closePort();

  if ( data->client )
    jack_client_close( data->client );
  delete data;
}

void MidiInJack :: openPort( unsigned int portNumber, const std::string portName )
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);

  connect();

  // Creating new port
  if ( data->port == NULL)
    data->port = jack_port_register( data->client, portName.c_str(),
                                     JACK_DEFAULT_MIDI_TYPE, JackPortIsInput, 0 );

  if ( data->port == NULL) {
    errorString_ = "MidiInJack::openPort: JACK error creating port";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Connecting to the output
  std::string name = getPortName( portNumber );
  jack_connect( data->client, name.c_str(), jack_port_name( data->port ) );
}

void MidiInJack :: openVirtualPort( const std::string portName )
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);

  connect();
  if ( data->port == NULL )
    data->port = jack_port_register( data->client, portName.c_str(),
                                     JACK_DEFAULT_MIDI_TYPE, JackPortIsInput, 0 );

  if ( data->port == NULL ) {
    errorString_ = "MidiInJack::openVirtualPort: JACK error creating virtual port";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
  }
}

unsigned int MidiInJack :: getPortCount()
{
  int count = 0;
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);
  connect();
  if ( !data->client )
    return 0;

  // List of available ports
  const char **ports = jack_get_ports( data->client, NULL, JACK_DEFAULT_MIDI_TYPE, JackPortIsOutput );

  if ( ports == NULL ) return 0;
  while ( ports[count] != NULL )
    count++;

  free( ports );

  return count;
}

std::string MidiInJack :: getPortName( unsigned int portNumber )
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);
  std::string retStr("");

  connect();

  // List of available ports
  const char **ports = jack_get_ports( data->client, NULL,
                                       JACK_DEFAULT_MIDI_TYPE, JackPortIsOutput );

  // Check port validity
  if ( ports == NULL ) {
    errorString_ = "MidiInJack::getPortName: no ports available!";
    error( RtMidiError::WARNING, errorString_ );
    return retStr;
  }

  if ( ports[portNumber] == NULL ) {
    std::ostringstream ost;
    ost << "MidiInJack::getPortName: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::WARNING, errorString_ );
  }
  else retStr.assign( ports[portNumber] );

  free( ports );
  return retStr;
}

void MidiInJack :: closePort()
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);

  if ( data->port == NULL ) return;
  jack_port_unregister( data->client, data->port );
  data->port = NULL;
}

//*********************************************************************//
//  API: JACK
//  Class Definitions: MidiOutJack
//*********************************************************************//

// Jack process callback
static int jackProcessOut( jack_nframes_t nframes, void *arg )
{
  JackMidiData *data = (JackMidiData *) arg;
  jack_midi_data_t *midiData;
  int space;

  // Is port created?
  if ( data->port == NULL ) return 0;

  void *buff = jack_port_get_buffer( data->port, nframes );
  jack_midi_clear_buffer( buff );

  while ( jack_ringbuffer_read_space( data->buffSize ) > 0 ) {
    jack_ringbuffer_read( data->buffSize, (char *) &space, (size_t) sizeof(space) );
    midiData = jack_midi_event_reserve( buff, 0, space );

    jack_ringbuffer_read( data->buffMessage, (char *) midiData, (size_t) space );
  }

  return 0;
}

MidiOutJack :: MidiOutJack( const std::string clientName ) : MidiOutApi()
{
  initialize( clientName );
}

void MidiOutJack :: initialize( const std::string& clientName )
{
  JackMidiData *data = new JackMidiData;
  apiData_ = (void *) data;

  data->port = NULL;
  data->client = NULL;
  this->clientName = clientName;

  connect();
}

void MidiOutJack :: connect()
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);
  if ( data->client )
    return;

  // Initialize JACK client
  if (( data->client = jack_client_open( clientName.c_str(), JackNoStartServer, NULL )) == 0) {
    errorString_ = "MidiOutJack::initialize: JACK server not running?";
    error( RtMidiError::WARNING, errorString_ );
    return;
  }

  jack_set_process_callback( data->client, jackProcessOut, data );
  data->buffSize = jack_ringbuffer_create( JACK_RINGBUFFER_SIZE );
  data->buffMessage = jack_ringbuffer_create( JACK_RINGBUFFER_SIZE );
  jack_activate( data->client );
}

MidiOutJack :: ~MidiOutJack()
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);
  closePort();

  if ( data->client ) {
    // Cleanup
    jack_client_close( data->client );
    jack_ringbuffer_free( data->buffSize );
    jack_ringbuffer_free( data->buffMessage );
  }

  delete data;
}

void MidiOutJack :: openPort( unsigned int portNumber, const std::string portName )
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);

  connect();

  // Creating new port
  if ( data->port == NULL )
    data->port = jack_port_register( data->client, portName.c_str(),
      JACK_DEFAULT_MIDI_TYPE, JackPortIsOutput, 0 );

  if ( data->port == NULL ) {
    errorString_ = "MidiOutJack::openPort: JACK error creating port";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
    return;
  }

  // Connecting to the output
  std::string name = getPortName( portNumber );
  jack_connect( data->client, jack_port_name( data->port ), name.c_str() );
}

void MidiOutJack :: openVirtualPort( const std::string portName )
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);

  connect();
  if ( data->port == NULL )
    data->port = jack_port_register( data->client, portName.c_str(),
      JACK_DEFAULT_MIDI_TYPE, JackPortIsOutput, 0 );

  if ( data->port == NULL ) {
    errorString_ = "MidiOutJack::openVirtualPort: JACK error creating virtual port";
    error( RtMidiError::DRIVER_ERROR, errorString_ );
  }
}

unsigned int MidiOutJack :: getPortCount()
{
  int count = 0;
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);
  connect();
  if ( !data->client )
    return 0;

  // List of available ports
  const char **ports = jack_get_ports( data->client, NULL,
    JACK_DEFAULT_MIDI_TYPE, JackPortIsInput );

  if ( ports == NULL ) return 0;
  while ( ports[count] != NULL )
    count++;

  free( ports );

  return count;
}

std::string MidiOutJack :: getPortName( unsigned int portNumber )
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);
  std::string retStr("");

  connect();

  // List of available ports
  const char **ports = jack_get_ports( data->client, NULL,
    JACK_DEFAULT_MIDI_TYPE, JackPortIsInput );

  // Check port validity
  if ( ports == NULL) {
    errorString_ = "MidiOutJack::getPortName: no ports available!";
    error( RtMidiError::WARNING, errorString_ );
    return retStr;
  }

  if ( ports[portNumber] == NULL) {
    std::ostringstream ost;
    ost << "MidiOutJack::getPortName: the 'portNumber' argument (" << portNumber << ") is invalid.";
    errorString_ = ost.str();
    error( RtMidiError::WARNING, errorString_ );
  }
  else retStr.assign( ports[portNumber] );

  free( ports );
  return retStr;
}

void MidiOutJack :: closePort()
{
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);

  if ( data->port == NULL ) return;
  jack_port_unregister( data->client, data->port );
  data->port = NULL;
}

void MidiOutJack :: sendMessage( std::vector<unsigned char> *message )
{
  int nBytes = message->size();
  JackMidiData *data = static_cast<JackMidiData *> (apiData_);

  // Write full message to buffer
  jack_ringbuffer_write( data->buffMessage, ( const char * ) &( *message )[0],
                         message->size() );
  jack_ringbuffer_write( data->buffSize, ( char * ) &nBytes, sizeof( nBytes ) );
}

#endif  // __UNIX_JACK__
#endif
#endif

#if OSCCTRL
#if JUCE_DRIVER
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __juce_osc__
#define __juce_osc__
 
#include "../JuceLibraryCode/JuceHeader.h"


class oscItem : public uiItem {
    
    protected:
        
        OSCSender* fSender;
        String fPath;
        
    public:
        
        oscItem(OSCSender* sender, GUI* ui, const String& path, FAUSTFLOAT* zone)
        :uiItem(ui, zone), fSender(sender), fPath(path) {}
        virtual ~oscItem()
        {}
        
        virtual void reflectZone()
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fSender->send(fPath, float(v));
        }
    
};

class JuceOSCUI : private OSCReceiver, private OSCReceiver::Listener<OSCReceiver::RealtimeCallback>, public GUI {
    
    private:
        
        OSCSender fSender;
        String fIP;
        int fInputPort, fOutputPort;
        APIUI fAPIUI;
        Array<oscItem*> fOSCItems;  // Pointers are kept and desallocated by the GUI class
        
    public:
        
        JuceOSCUI(const std::string& ip, int in_port, int out_port)
        :fIP(ip), fInputPort(in_port), fOutputPort(out_port)
        {}
        
        virtual ~JuceOSCUI()
        {}
        
        void oscMessageReceived(const OSCMessage& message) override
        {
            String address = message.getAddressPattern().toString();
            
            for (int i = 0; i < message.size(); ++i) {
                if (message[i].isFloat32()) {
                    fAPIUI.setParamValue(fAPIUI.getParamIndex(address.toStdString().c_str()), FAUSTFLOAT(message[i].getFloat32()));
                    // "get" message with correct address
                } else if (message[i].isString()
                           && message[i].getString().equalsIgnoreCase("get")
                           && String(fAPIUI.getParamAddress(0)).startsWith(address)) {
                    for (int p = 0; p < fAPIUI.getParamsCount(); ++p) {
                        fSender.send(fAPIUI.getParamAddress(p), float(fAPIUI.getParamValue(p)), float(fAPIUI.getParamMin(p)), float(fAPIUI.getParamMax(p)));
                    }
                    // "hello" message
                } else if (message[i].isString()
                           && address.equalsIgnoreCase("/*")
                           && message[i].getString().equalsIgnoreCase("hello")) {
                    String path = fAPIUI.getParamAddress(0);
                    int pos1 = path.indexOfChar('/');
                    int pos2 = path.indexOfChar(pos1 + 1, '/');
                    fSender.send(path.substring(pos1, pos2), fIP, fInputPort, fOutputPort);
                }
            }
        }
        
        bool run() override
        {
            // Keep all zones for update when OSC messages are received
            if (fOSCItems.size() == 0) {
                for (int p = 0; p < fAPIUI.getParamsCount(); ++p) {
                    fOSCItems.add(new oscItem(&fSender, this, fAPIUI.getParamAddress(p), fAPIUI.getParamZone(p)));
                }
            }
            
            if (!fSender.connect(fIP, fOutputPort)) {
                std::cerr << "Error: could not connect to UDP port " << fInputPort << std::endl;
                return false;
            }
            
            if (!connect(fInputPort)) {
                std::cerr << "Error: could not connect to UDP port " << fOutputPort << std::endl;
                return false;
            }
            addListener(this);
            return true;
        }
        
        void stop() override
        {
            fSender.disconnect();
            disconnect();
            removeListener(this);
        }
        
        // -- widget's layouts
        
        void openTabBox(const char* label) override { fAPIUI.openTabBox(label); }
        void openHorizontalBox(const char* label) override { fAPIUI.openHorizontalBox(label); }
        void openVerticalBox(const char* label) override { fAPIUI.openVerticalBox(label); }
        void closeBox() override { fAPIUI.closeBox(); }
        
        // -- active widgets
        
        void addButton(const char* label, FAUSTFLOAT* zone) override { fAPIUI.addButton(label, zone); }
        void addCheckButton(const char* label, FAUSTFLOAT* zone) override { fAPIUI.addCheckButton(label, zone); }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override
        { fAPIUI.addVerticalSlider(label, zone, init, min, max, step); }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override
        { fAPIUI.addHorizontalSlider(label, zone, init, min, max, step); }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) override
        { fAPIUI.addNumEntry(label, zone, init, min, max, step); }
        
        // -- passive widgets
        
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) override
        { fAPIUI.addHorizontalBargraph(label, zone, min, max); }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) override
        { fAPIUI.addVerticalBargraph(label, zone, min, max); }
        
        // -- metadata declarations
        
        void declare(FAUSTFLOAT* zone, const char* key, const char* val) override { fAPIUI.declare(zone, key, val); }
    
};

#endif // __juce_osc__

#else
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

/*
   Copyright (C) 2011 Grame - Lyon
   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted.
*/

#ifndef __OSCUI__
#define __OSCUI__

#include <vector>
#include <string>

/*

  Faust Project

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __OSCControler__
#define __OSCControler__

#include <string>
/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __FaustFactory__
#define __FaustFactory__

#include <stack>
#include <string>
#include <sstream>

/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __FaustNode__
#define __FaustNode__

#include <string>
#include <vector>

/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __MessageDriven__
#define __MessageDriven__

#include <string>
#include <vector>

/*

  Copyright (C) 2010  Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __MessageProcessor__
#define __MessageProcessor__

namespace oscfaust
{

class Message;
//--------------------------------------------------------------------------
/*!
	\brief an abstract class for objects able to process OSC messages	
*/
class MessageProcessor
{
	public:
		virtual		~MessageProcessor() {}
		virtual void processMessage( const Message* msg ) = 0;
};

} // end namespoace

#endif
/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __smartpointer__
#define __smartpointer__

#include <cassert>

namespace oscfaust
{

/*!
\brief the base class for smart pointers implementation

	Any object that want to support smart pointers should
	inherit from the smartable class which provides reference counting
	and automatic delete when the reference count drops to zero.
*/
class smartable {
	private:
		unsigned 	refCount;		
	public:
		//! gives the reference count of the object
		unsigned refs() const         { return refCount; }
		//! addReference increments the ref count and checks for refCount overflow
		void addReference()           { refCount++; assert(refCount != 0); }
		//! removeReference delete the object when refCount is zero		
		void removeReference()		  { if (--refCount == 0) delete this; }
		
	protected:
		smartable() : refCount(0) {}
		smartable(const smartable&): refCount(0) {}
		//! destructor checks for non-zero refCount
		virtual ~smartable()    
        { 
            /* 
                See "Static SFaustNode create (const char* name, C* zone, C init, C min, C max, const char* prefix, GUI* ui)" comment.
                assert (refCount == 0); 
            */
        }
		smartable& operator=(const smartable&) { return *this; }
};

/*!
\brief the smart pointer implementation

	A smart pointer is in charge of maintaining the objects reference count 
	by the way of pointers operators overloading. It supports class 
	inheritance and conversion whenever possible.
\n	Instances of the SMARTP class are supposed to use \e smartable types (or at least
	objects that implements the \e addReference and \e removeReference
	methods in a consistent way).
*/
template<class T> class SMARTP {
	private:
		//! the actual pointer to the class
		T* fSmartPtr;

	public:
		//! an empty constructor - points to null
		SMARTP()	: fSmartPtr(0) {}
		//! build a smart pointer from a class pointer
		SMARTP(T* rawptr) : fSmartPtr(rawptr)              { if (fSmartPtr) fSmartPtr->addReference(); }
		//! build a smart pointer from an convertible class reference
		template<class T2> 
		SMARTP(const SMARTP<T2>& ptr) : fSmartPtr((T*)ptr) { if (fSmartPtr) fSmartPtr->addReference(); }
		//! build a smart pointer from another smart pointer reference
		SMARTP(const SMARTP& ptr) : fSmartPtr((T*)ptr)     { if (fSmartPtr) fSmartPtr->addReference(); }

		//! the smart pointer destructor: simply removes one reference count
		~SMARTP()  { if (fSmartPtr) fSmartPtr->removeReference(); }
		
		//! cast operator to retrieve the actual class pointer
		operator T*() const  { return fSmartPtr;	}

		//! '*' operator to access the actual class pointer
		T& operator*() const {
			// checks for null dereference
			assert (fSmartPtr != 0);
			return *fSmartPtr;
		}

		//! operator -> overloading to access the actual class pointer
		T* operator->() const	{ 
			// checks for null dereference
			assert (fSmartPtr != 0);
			return fSmartPtr;
		}

		//! operator = that moves the actual class pointer
		template <class T2>
		SMARTP& operator=(T2 p1_)	{ *this=(T*)p1_; return *this; }

		//! operator = that moves the actual class pointer
		SMARTP& operator=(T* p_)	{
			// check first that pointers differ
			if (fSmartPtr != p_) {
				// increments the ref count of the new pointer if not null
				if (p_ != 0) p_->addReference();
				// decrements the ref count of the old pointer if not null
				if (fSmartPtr != 0) fSmartPtr->removeReference();
				// and finally stores the new actual pointer
				fSmartPtr = p_;
			}
			return *this;
		}
		//! operator < to support SMARTP map with Visual C++
		bool operator<(const SMARTP<T>& p_)	const			  { return fSmartPtr < ((T *) p_); }
		//! operator = to support inherited class reference
		SMARTP& operator=(const SMARTP<T>& p_)                { return operator=((T *) p_); }
		//! dynamic cast support
		template<class T2> SMARTP& cast(T2* p_)               { return operator=(dynamic_cast<T*>(p_)); }
		//! dynamic cast support
		template<class T2> SMARTP& cast(const SMARTP<T2>& p_) { return operator=(dynamic_cast<T*>(p_)); }
};

}

#endif

namespace oscfaust
{

class Message;
class OSCRegexp;
class MessageDriven;
typedef class SMARTP<MessageDriven>	SMessageDriven;

//--------------------------------------------------------------------------
/*!
	\brief a base class for objects accepting OSC messages
	
	Message driven objects are hierarchically organized in a tree.
	They provides the necessary to dispatch an OSC message to its destination
	node, according to the message OSC address. 
	
	The principle of the dispatch is the following:
	- first the processMessage() method should be called on the top level node
	- next processMessage call propose 
*/
class MessageDriven : public MessageProcessor, public smartable
{
	std::string						fName;			///< the node name
	std::string						fOSCPrefix;		///< the node OSC address prefix (OSCAddress = fOSCPrefix + '/' + fName)
	std::vector<SMessageDriven>		fSubNodes;		///< the subnodes of the current node

	protected:
				 MessageDriven(const char *name, const char *oscprefix) : fName (name), fOSCPrefix(oscprefix) {}
		virtual ~MessageDriven() {}

	public:
		static SMessageDriven create(const char* name, const char *oscprefix)	{ return new MessageDriven(name, oscprefix); }

		/*!
			\brief OSC message processing method.
			\param msg the osc message to be processed
			The method should be called on the top level node.
		*/
		virtual void	processMessage(const Message* msg);

		/*!
			\brief propose an OSc message at a given hierarchy level.
			\param msg the osc message currently processed
			\param regexp a regular expression based on the osc address head
			\param addrTail the osc address tail
			
			The method first tries to match the regular expression with the object name. 
			When it matches:
			- it calls \c accept when \c addrTail is empty 
			- or it \c propose the message to its subnodes when \c addrTail is not empty. 
			  In this case a new \c regexp is computed with the head of \c addrTail and a new \c addrTail as well.
		*/
		virtual void	propose(const Message* msg, const OSCRegexp* regexp, const std::string addrTail);

		/*!
			\brief accept an OSC message. 
			\param msg the osc message currently processed
			\return true when the message is processed by the node
			
			The method is called only for the destination nodes. The real message acceptance is the node 
			responsability and may depend on the message content.
		*/
		virtual bool	accept(const Message* msg);

		/*!
			\brief handler for the \c 'get' message
			\param ipdest the output message destination IP
			
			The \c 'get' message is supported by every node:
			- it is propagated to the subnodes until it reaches terminal nodes
			- a terminal node send its state on \c 'get' request to the IP address given as parameter.
			The \c get method is basically called by the accept method.
		*/
		virtual void	get(unsigned long ipdest) const;

		/*!
			\brief handler for the \c 'get' 'attribute' message
			\param ipdest the output message destination IP
			\param what the requested attribute
			
			The \c 'get' message is supported by every node:
			- it is propagated to the subnodes until it reaches terminal nodes
			- a terminal node send its state on \c 'get' request to the IP address given as parameter.
			The \c get method is basically called by the accept method.
		*/
		virtual void	get (unsigned long ipdest, const std::string & what) const {}

		void			add(SMessageDriven node)	{ fSubNodes.push_back (node); }
		const char*		getName() const				{ return fName.c_str(); }
		std::string		getOSCAddress() const;
		int				size() const				{ return (int)fSubNodes.size (); }
		
		const std::string&	name() const			{ return fName; }
		SMessageDriven	subnode(int i)              { return fSubNodes[i]; }
};

} // end namespoace

#endif
/*

  Copyright (C) 2011  Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/


#ifndef __Message__
#define __Message__

#include <string>
#include <vector>

namespace oscfaust
{

class OSCStream;
template <typename T> class MsgParam;
class baseparam;
typedef SMARTP<baseparam>	Sbaseparam;

//--------------------------------------------------------------------------
/*!
	\brief base class of a message parameters
*/
class baseparam : public smartable
{
	public:
		virtual ~baseparam() {}

		/*!
		 \brief utility for parameter type checking
		*/
		template<typename X> bool isType() const { return dynamic_cast<const MsgParam<X>*> (this) != 0; }
		/*!
		 \brief utility for parameter convertion
		 \param errvalue the returned value when no conversion applies
		 \return the parameter value when the type matches
		*/
		template<typename X> X	value(X errvalue) const 
			{ const MsgParam<X>* o = dynamic_cast<const MsgParam<X>*> (this); return o ? o->getValue() : errvalue; }
		/*!
		 \brief utility for parameter comparison
		*/
		template<typename X> bool	equal(const baseparam& p) const 
			{ 
				const MsgParam<X>* a = dynamic_cast<const MsgParam<X>*> (this); 
				const MsgParam<X>* b = dynamic_cast<const MsgParam<X>*> (&p);
				return a && b && (a->getValue() == b->getValue());
			}
		/*!
		 \brief utility for parameter comparison
		*/
		bool operator==(const baseparam& p) const 
			{ 
				return equal<float>(p) || equal<int>(p) || equal<std::string>(p);
			}
		bool operator!=(const baseparam& p) const
			{ 
				return !equal<float>(p) && !equal<int>(p) && !equal<std::string>(p);
			}
			
		virtual SMARTP<baseparam> copy() const = 0;
};

//--------------------------------------------------------------------------
/*!
	\brief template for a message parameter
*/
template <typename T> class MsgParam : public baseparam
{
	T fParam;
	public:
				 MsgParam(T val) : fParam(val)	{}
		virtual ~MsgParam() {}
		
		T getValue() const { return fParam; }
		
		virtual Sbaseparam copy() const { return new MsgParam<T>(fParam); }
};

//--------------------------------------------------------------------------
/*!
	\brief a message description
	
	A message is composed of an address (actually an OSC address),
	a message string that may be viewed as a method name
	and a list of message parameters.
*/
class Message
{
    public:
        typedef SMARTP<baseparam>		argPtr;		///< a message argument ptr type
        typedef std::vector<argPtr>		argslist;	///< args list type

    private:
        unsigned long	fSrcIP;			///< the message source IP number
        std::string	fAddress;			///< the message osc destination address
        std::string	fAlias;             ///< the message alias osc destination address
        argslist	fArguments;			///< the message arguments

    public:
            /*!
                \brief an empty message constructor
            */
             Message() {}
            /*!
                \brief a message constructor
                \param address the message destination address
            */
            Message(const std::string& address) : fAddress(address), fAlias("") {}
             
            Message(const std::string& address, const std::string& alias) : fAddress(address), fAlias(alias) {}
            /*!
                \brief a message constructor
                \param address the message destination address
                \param args the message parameters
            */
            Message(const std::string& address, const argslist& args) 
                : fAddress(address), fArguments(args) {}
            /*!
                \brief a message constructor
                \param msg a message
            */
             Message(const Message& msg);
    virtual ~Message() {} //{ freed++; std::cout << "running messages: " << (allocated - freed) << std::endl; }

    /*!
        \brief adds a parameter to the message
        \param val the parameter
    */
    template <typename T> void add(T val)	{ fArguments.push_back(new MsgParam<T>(val)); }
    /*!
        \brief adds a float parameter to the message
        \param val the parameter value
    */
    void	add(float val)					{ add<float>(val); }
    /*!
        \brief adds an int parameter to the message
        \param val the parameter value
    */
    void	add(int val)					{ add<int>(val); }
    /*!
        \brief adds a string parameter to the message
        \param val the parameter value
    */
    void	add(const std::string& val)		{ add<std::string>(val); }

    /*!
        \brief adds a parameter to the message
        \param val the parameter
    */
    void	add(argPtr val)                 { fArguments.push_back( val ); }

    /*!
        \brief sets the message address
        \param addr the address
    */
    void				setSrcIP(unsigned long addr)		{ fSrcIP = addr; }

    /*!
        \brief sets the message address
        \param addr the address
    */
    void				setAddress(const std::string& addr)		{ fAddress = addr; }
    /*!
        \brief print the message
        \param out the output stream
    */
    void				print(std::ostream& out) const;
    /*!
        \brief send the message to OSC
        \param out the OSC output stream
    */
    void				print(OSCStream& out) const;
    /*!
        \brief print message arguments
        \param out the OSC output stream
    */
    void				printArgs(OSCStream& out) const;

    /// \brief gives the message address
    const std::string&	address() const		{ return fAddress; }
    /// \brief gives the message alias
    const std::string&	alias() const		{ return fAlias; }
    /// \brief gives the message parameters list
    const argslist&		params() const		{ return fArguments; }
    /// \brief gives the message parameters list
    argslist&			params()			{ return fArguments; }
    /// \brief gives the message source IP 
    unsigned long		src() const			{ return fSrcIP; }
    /// \brief gives the message parameters count
    int					size() const		{ return (int)fArguments.size(); }

    bool operator == (const Message& other) const;	

    /*!
        \brief gives a message float parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, float& val) const		{ val = params()[i]->value<float>(val); return params()[i]->isType<float>(); }
    /*!
        \brief gives a message int parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, int& val) const		{ val = params()[i]->value<int>(val); return params()[i]->isType<int>(); }
    /*!
        \brief gives a message int parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, unsigned int& val) const		{ val = params()[i]->value<int>(val); return params()[i]->isType<int>(); }
    /*!
        \brief gives a message int parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
        \note a boolean value is handled as integer
    */
    bool	param(int i, bool& val) const		{ int ival = 0; ival = params()[i]->value<int>(ival); val = ival!=0; return params()[i]->isType<int>(); }
    /*!
        \brief gives a message int parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, long int& val) const	{ val = long(params()[i]->value<int>(val)); return params()[i]->isType<int>(); }
    /*!
        \brief gives a message string parameter
        \param i the parameter index (0 <= i < size())
        \param val on output: the parameter value when the parameter type matches
        \return false when types don't match
    */
    bool	param(int i, std::string& val) const { val = params()[i]->value<std::string>(val); return params()[i]->isType<std::string>(); }
};


} // end namespoace

#endif
/*

  Copyright (C) 2011 Grame

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

*/

#ifndef __RootNode__
#define __RootNode__

#include <map>
#include <string>
#include <vector>


namespace oscfaust
{

class OSCIO;
class RootNode;
typedef class SMARTP<RootNode> SRootNode;

/**
 * an alias target includes a map to rescale input values to output values
 * and a target osc address. The input values can be given in reversed order
 * to reverse the control
 */
struct aliastarget
{
	float       fMinIn;
	float       fMaxIn;
	float       fMinOut;
	float       fMaxOut;
	std::string fTarget;	// the real osc address

	aliastarget(const char* address, float imin, float imax, float omin, float omax)
		: fMinIn(imin), fMaxIn(imax), fMinOut(omin), fMaxOut(omax), fTarget(address) {}

	aliastarget(const aliastarget& t)
		: fMinIn(t.fMinIn), fMaxIn(t.fMaxIn), fMinOut(t.fMinOut), fMaxOut(t.fMaxOut), fTarget(t.fTarget) {}

	float scale(float x) const 
    {
        if (fMinIn < fMaxIn) {
            // increasing control
            float z = (x < fMinIn) ? fMinIn : (x > fMaxIn) ? fMaxIn : x;
            return fMinOut + (z-fMinIn)*(fMaxOut-fMinOut)/(fMaxIn-fMinIn);
            
        } else if (fMinIn > fMaxIn) {
            // reversed control
            float z = (x < fMaxIn) ? fMaxIn : (x > fMinIn) ? fMinIn : x;
            return fMinOut + (fMinIn-z)*(fMaxOut-fMinOut)/(fMinIn-fMaxIn);
            
        } else {
            // no control !
            return (fMinOut+fMaxOut)/2.0f;
        }
    }
    
    float invscale(float x) const
    {
        if (fMinOut < fMaxOut) {
            // increasing control
            float z = (x < fMinOut) ? fMinOut : (x > fMaxOut) ? fMaxOut : x;
            return fMinIn + (z-fMinOut)*(fMaxIn-fMinIn)/(fMaxOut-fMinOut);
            
        } else if (fMinOut > fMaxOut) {
            // reversed control
            float z = (x < fMaxOut) ? fMaxOut : (x > fMinOut) ? fMinOut : x;
            return fMinIn + (fMinOut-z)*(fMaxIn-fMinIn)/(fMinOut-fMaxOut);
            
        } else {
            // no control !
            return (fMinIn+fMaxIn)/2.0f;
        }
    }
};

//--------------------------------------------------------------------------
/*!
	\brief a faust root node

	A Faust root node handles the \c 'hello' message and provides support
	for incoming osc signal data. 
*/
class RootNode : public MessageDriven
{
	int *fUPDIn, *fUDPOut, *fUDPErr;	// the osc port numbers (required by the hello method)
	OSCIO* fIO;                         // an OSC IO controler
	
	typedef std::map<std::string, std::vector<aliastarget> > TAliasMap;
	TAliasMap fAliases;

	void processAlias(const std::string& address, float val);
	void eraseAliases(const std::string& target);
	void eraseAlias  (const std::string& target, const std::string& alias);
	bool aliasError  (const Message* msg);

	protected:
				 RootNode(const char *name, OSCIO* io = 0) : MessageDriven(name, ""), fUPDIn(0), fUDPOut(0), fUDPErr(0), fIO(io) {}
		virtual ~RootNode() {}

	public:
		static SRootNode create(const char* name, OSCIO* io = 0) { return new RootNode(name, io); }

		virtual void processMessage(const Message* msg);
		virtual bool accept(const Message* msg);
		virtual void get(unsigned long ipdest) const;
		virtual void get(unsigned long ipdest, const std::string& what) const;

        bool aliasMsg(const Message* msg, float omin, float omax);
        void addAlias(const char* alias, const char* address, float imin, float imax, float omin, float omax);
        bool acceptSignal(const Message* msg);				///< handler for signal data
        void hello(unsigned long ipdest) const;				///< handler for the 'hello' message
        void setPorts(int* in, int* out, int* err);
        
        std::vector<std::pair<std::string, double> > getAliases(const std::string& address, double value);
};

} // end namespoace

#endif

class GUI;

namespace oscfaust
{

/**
 * map (rescale) input values to output values
 */
template <typename C> struct mapping
{
	const C fMinOut;
	const C fMaxOut;
	mapping(C omin, C omax) : fMinOut(omin), fMaxOut(omax) {}
	C clip (C x) { return (x < fMinOut) ? fMinOut : (x > fMaxOut) ? fMaxOut : x; }
};

//--------------------------------------------------------------------------
/*!
	\brief a faust node is a terminal node and represents a faust parameter controler
*/
template <typename C> class FaustNode : public MessageDriven, public uiTypedItem<C>
{
	mapping<C>	fMapping;
    RootNode* fRoot;
    bool fInput;  // true for input nodes (slider, button...)
	
	//---------------------------------------------------------------------
	// Warning !!!
	// The cast (C *)fZone is necessary because the real size allocated is
	// only known at execution time. When the library is compiled, fZone is
	// uniquely defined by FAUSTFLOAT.
	//---------------------------------------------------------------------
	bool	store(C val) { *(C *)this->fZone = fMapping.clip(val); return true; }
	void	sendOSC() const;

	protected:
		FaustNode(RootNode* root, const char *name, C* zone, C init, C min, C max, const char* prefix, GUI* ui, bool initZone, bool input) 
			: MessageDriven(name, prefix), uiTypedItem<C>(ui, zone), fMapping(min, max), fRoot(root), fInput(input)
			{
                if (initZone) {
                    *zone = init; 
                }
            }
			
		virtual ~FaustNode() {}

	public:
		typedef SMARTP<FaustNode<C> > SFaustNode;
		static SFaustNode create(RootNode* root, const char* name, C* zone, C init, C min, C max, const char* prefix, GUI* ui, bool initZone, bool input)	
        { 
            SFaustNode node = new FaustNode(root, name, zone, init, min, max, prefix, ui, initZone, input); 
            /*
                Since FaustNode is a subclass of uiItem, the pointer will also be kept in the GUI class, and it's desallocation will be done there.
                So we don't want to have smartpointer logic desallocate it and we increment the refcount.
            */
            node->addReference();
            return node; 
        }
    
		bool accept(const Message* msg);
		void get(unsigned long ipdest) const;		///< handler for the 'get' message
		virtual void reflectZone() { sendOSC(); this->fCache = *this->fZone; }
};

} // end namespace

#endif

class GUI;
namespace oscfaust
{

class OSCIO;
class RootNode;
typedef class SMARTP<RootNode> SRootNode;
class MessageDriven;
typedef class SMARTP<MessageDriven>	SMessageDriven;

//--------------------------------------------------------------------------
/*!
	\brief a factory to build a OSC UI hierarchy
	
	Actually, makes use of a stack to build the UI hierarchy.
	It includes a pointer to a OSCIO controler, but just to give it to the root node.
*/
class FaustFactory
{
	std::stack<SMessageDriven>	fNodes;		///< maintains the current hierarchy level
	SRootNode					fRoot;		///< keep track of the root node
	OSCIO*                      fIO;		///< hack to support audio IO via OSC, actually the field is given to the root node
	GUI*						fGUI;		///< a GUI pointer to support updateAllGuis(), required for bi-directionnal OSC

	private:
		std::string addressFirst(const std::string& address) const;
		std::string addressTail(const std::string& address) const;

	public:
				 FaustFactory(GUI* ui, OSCIO * io = 0); 
		virtual ~FaustFactory(); 

		template <typename C> void addnode(const char* label, C* zone, C init, C min, C max, bool initZone, bool input);
		template <typename C> void addAlias(const std::string& fullpath, C* zone, C imin, C imax, C init, C min, C max, const char* label);
        
		void addAlias(const char* alias, const char* address, float imin, float imax, float omin, float omax);
		void opengroup(const char* label);
		void closegroup();

		SRootNode root() const; 
};

/**
 * Add a node to the OSC UI tree in the current group at the top of the stack 
 */
template <typename C> void FaustFactory::addnode(const char* label, C* zone, C init, C min, C max, bool initZone, bool input) 
{
	SMessageDriven top;
	if (fNodes.size()) top = fNodes.top();
	if (top) {
		std::string prefix = top->getOSCAddress();
		top->add(FaustNode<C>::create(root(), label, zone, init, min, max, prefix.c_str(), fGUI, initZone, input));
	}
}

/**
 * Add an alias (actually stored and handled at root node level
 */
template <typename C> void FaustFactory::addAlias(const std::string& fullpath, C* zone, C imin, C imax, C init, C min, C max, const char* label)
{
	std::istringstream 	ss(fullpath);
	std::string 		realpath; 
 
	ss >> realpath >> imin >> imax;
	SMessageDriven top = fNodes.top();
	if (top) {
		std::string target = top->getOSCAddress() + "/" + label;
		addAlias(realpath.c_str(), target.c_str(), float(imin), float(imax), float(min), float(max));
	}
}

} // end namespoace

#endif

class GUI;

typedef void (*ErrorCallback)(void*);  

namespace oscfaust
{

class OSCIO;
class OSCSetup;
class OSCRegexp;
    
//--------------------------------------------------------------------------
/*!
	\brief the main Faust OSC Lib API
	
	The OSCControler is essentially a glue between the memory representation (in charge of the FaustFactory),
	and the network services (in charge of OSCSetup).
*/
class OSCControler
{
	int fUDPPort,   fUDPOut, fUPDErr;	// the udp ports numbers
	std::string     fDestAddress;		// the osc messages destination address, used at initialization only
										// to collect the address from the command line
	std::string     fBindAddress;		// when non empty, the address used to bind the socket for listening
	OSCSetup*		fOsc;				// the network manager (handles the udp sockets)
	OSCIO*			fIO;				// hack for OSC IO support (actually only relayed to the factory)
	FaustFactory*	fFactory;			// a factory to build the memory represetnatin

    bool            fInit;
    
	public:
		/*
			base udp port is chosen in an unassigned range from IANA PORT NUMBERS (last updated 2011-01-24)
			see at http://www.iana.org/assignments/port-numbers
			5507-5552  Unassigned
		*/
		enum { kUDPBasePort = 5510};
            
        OSCControler(int argc, char *argv[], GUI* ui, OSCIO* io = 0, ErrorCallback errCallback = NULL, void* arg = NULL, bool init = true);

        virtual ~OSCControler();
	
		//--------------------------------------------------------------------------
		// addnode, opengroup and closegroup are simply relayed to the factory
		//--------------------------------------------------------------------------
		// Add a node in the current group (top of the group stack)
		template <typename T> void addnode(const char* label, T* zone, T init, T min, T max, bool input = true)
							{ fFactory->addnode(label, zone, init, min, max, fInit, input); }
		
		//--------------------------------------------------------------------------
		// This method is used for alias messages. The arguments imin and imax allow
		// to map incomming values from the alias input range to the actual range 
		template <typename T> void addAlias(const std::string& fullpath, T* zone, T imin, T imax, T init, T min, T max, const char* label)
							{ fFactory->addAlias(fullpath, zone, imin, imax, init, min, max, label); }

		void opengroup(const char* label)		{ fFactory->opengroup(label); }
		void closegroup()						{ fFactory->closegroup(); }
	   
		//--------------------------------------------------------------------------
		void run();				// starts the network services
		void endBundle();		// when bundle mode is on, close and send the current bundle (if any)
		void stop();			// stop the network services
		std::string getInfos() const; // gives information about the current environment (version, port numbers,...)

		int	getUDPPort() const			{ return fUDPPort; }
		int	getUDPOut()	const			{ return fUDPOut; }
		int	getUDPErr()	const			{ return fUPDErr; }
		const char*	getDestAddress() const { return fDestAddress.c_str(); }
		const char*	getRootName() const;	// probably useless, introduced for UI extension experiments
    
        void setUDPPort(int port) { fUDPPort = port; }
        void setUDPOut(int port) { fUDPOut = port; }
        void setUDPErr(int port) { fUPDErr = port; }
        void setDestAddress(const char* address) { fDestAddress = address; }

        // By default, an osc interface emits all parameters. You can filter specific params dynamically.
        static std::vector<OSCRegexp*>     fFilteredPaths; // filtered paths will not be emitted
        static void addFilteredPath(std::string path);
        static bool isPathFiltered(std::string path);
        static void resetFilteredPaths();
    
		static float version();				// the Faust OSC library version number
		static const char* versionstr();	// the Faust OSC library version number as a string
		static int gXmit;                   // a static variable to control the transmission of values
                                            // i.e. the use of the interface as a controler
		static int gBundle;                 // a static variable to control the osc bundle mode
};

#define kNoXmit     0
#define kAll        1
#define kAlias      2

}

#endif

#ifdef _WIN32
#define strcasecmp _stricmp
#endif

/******************************************************************************
*******************************************************************************

					OSC (Open Sound Control) USER INTERFACE

*******************************************************************************
*******************************************************************************/
/*

Note about the OSC addresses and the Faust UI names:
----------------------------------------------------
There are potential conflicts between the Faust UI objects naming scheme and 
the OSC address space. An OSC symbolic names is an ASCII string consisting of
printable characters other than the following:
	space 
#	number sign
*	asterisk
,	comma
/	forward
?	question mark
[	open bracket
]	close bracket
{	open curly brace
}	close curly brace

a simple solution to address the problem consists in replacing 
space or tabulation with '_' (underscore)
all the other osc excluded characters with '-' (hyphen)

This solution is implemented in the proposed OSC UI;
*/

class OSCUI : public GUI 
{
     
	oscfaust::OSCControler*	fCtrl;
	std::vector<const char*> fAlias;
	
    const char* tr(const char* label) const
    {
        static char buffer[1024];
        char * ptr = buffer; int n=1;
        while (*label && (n++ < 1024)) {
            switch (*label) {
                case ' ': case '	':
                    *ptr++ = '_';
                    break;
                case '#': case '*': case ',': case '/': case '?':
                case '[': case ']': case '{': case '}': case '(': case ')':
                    *ptr++ = '_';
                    break;
                default: 
                    *ptr++ = *label;
            }
            label++;
        }
        *ptr = 0;
        return buffer;
    }
	
	// add all accumulated alias
	void addalias(FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, const char* label)
	{
		for (unsigned int i = 0; i < fAlias.size(); i++) {
			fCtrl->addAlias(fAlias[i], zone, FAUSTFLOAT(0), FAUSTFLOAT(1), init, min, max, label);
		}
		fAlias.clear();
	}
	
 public:

    OSCUI(const char* /*applicationname*/, int argc, char *argv[], oscfaust::OSCIO* io = 0, ErrorCallback errCallback = NULL, void* arg = NULL, bool init = true) : GUI() 
    { 
		fCtrl = new oscfaust::OSCControler(argc, argv, this, io, errCallback, arg, init); 
        //		fCtrl->opengroup(applicationname);
	}
    
	virtual ~OSCUI() { delete fCtrl; }
    
    // -- widget's layouts
    
  	virtual void openTabBox(const char* label)          { fCtrl->opengroup(tr(label)); }
	virtual void openHorizontalBox(const char* label)   { fCtrl->opengroup(tr(label)); }
	virtual void openVerticalBox(const char* label)     { fCtrl->opengroup(tr(label)); }
	virtual void closeBox()                             { fCtrl->closegroup(); }
	
	// -- active widgets
	virtual void addButton(const char* label, FAUSTFLOAT* zone) 		{ const char* l = tr(label); addalias(zone, 0, 0, 1, l); fCtrl->addnode(l, zone, FAUSTFLOAT(0), FAUSTFLOAT(0), FAUSTFLOAT(1)); }
	virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) 	{ const char* l = tr(label); addalias(zone, 0, 0, 1, l); fCtrl->addnode(l, zone, FAUSTFLOAT(0), FAUSTFLOAT(0), FAUSTFLOAT(1)); }
	virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT /*step*/)
																		{ const char* l = tr(label); addalias(zone, init, min, max, l); fCtrl->addnode(l, zone, init, min, max); }
	virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT /*step*/)
																		{ const char* l = tr(label); addalias(zone, init, min, max, l); fCtrl->addnode(l, zone, init, min, max); }
	virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT /*step*/)
																		{ const char* l = tr(label); addalias(zone, init, min, max, l); fCtrl->addnode(l, zone, init, min, max); }
	
	// -- passive widgets
	
    virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
    {
        const char* l = tr(label); addalias(zone, 0, min, max, l); fCtrl->addnode(l, zone, FAUSTFLOAT(0), min, max, false);
    }
    virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
    {
        const char* l = tr(label); addalias(zone, 0, min, max, l); fCtrl->addnode(l, zone, FAUSTFLOAT(0), min, max, false);
    }
  		
	// -- metadata declarations
    
	virtual void declare(FAUSTFLOAT*, const char* key, const char* alias)
	{ 
		if (strcasecmp(key, "OSC") == 0) fAlias.push_back(alias);
	}

	virtual void show() {}

    bool run()
    {
        fCtrl->run();
        return true;
    }
	
    void stop()			{ fCtrl->stop(); }
    void endBundle() 	{ fCtrl->endBundle(); }
    
    std::string getInfos()          { return fCtrl->getInfos(); }

    const char* getRootName()		{ return fCtrl->getRootName(); }
    int getUDPPort()                { return fCtrl->getUDPPort(); }
    int getUDPOut()                 { return fCtrl->getUDPOut(); }
    int getUDPErr()                 { return fCtrl->getUDPErr(); }
    const char* getDestAddress()    { return fCtrl->getDestAddress(); }

    void setUDPPort(int port)       { fCtrl->setUDPPort(port); }
    void setUDPOut(int port)        { fCtrl->setUDPOut(port); }
    void setUDPErr(int port)        { fCtrl->setUDPErr(port); }
    void setDestAddress(const char* address)    { return fCtrl->setDestAddress(address); }

};

#endif // __OSCUI__
#endif
static void osc_compute_callback(void* arg)
{
    static_cast<OSCUI*>(arg)->endBundle();
}
#endif

#if DYNAMIC_DSP
/************************************************************************
 ************************************************************************
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 2.1 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 
 ************************************************************************
 ************************************************************************/

#ifndef LLVM_DSP_H
#define LLVM_DSP_H

#ifdef _WIN32
#define DEPRECATED(fun) __declspec(deprecated) fun
#else
#define DEPRECATED(fun) fun __attribute__ ((deprecated));
#endif

#include <vector>

/*!
 \addtogroup llvmcpp C++ interface for compiling Faust code. Note that the API is not thread safe : use 'startMTDSPFactories/stopMTDSPFactories' to use it in a multi-thread context.
 @{
 */
 
/**
 * Get the library version.
 * 
 * @return the library version as a static string.
 */
extern "C" const char* getCLibFaustVersion();

/**
 * DSP instance class with methods.
 */
class llvm_dsp : public dsp {
    
    private:
    
        // llvm_dsp objects are allocated using llvm_dsp_factory::createDSPInstance();
        llvm_dsp() {}
    
    public:
        
        int getNumInputs();
       
        int getNumOutputs();
        
        void buildUserInterface(UI* ui_interface);
       
        int getSampleRate();
        
        void init(int samplingRate);
       
        void instanceInit(int samplingRate);
    
        void instanceConstants(int samplingRate);
    
        void instanceResetUserInterface();
        
        void instanceClear();
        
        llvm_dsp* clone();
        
        void metadata(Meta* m);
        
        void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs);
    
};

/**
 * DSP factory class.
 */

class llvm_dsp_factory : public dsp_factory {

     public:
    
        virtual ~llvm_dsp_factory();
        
        /**
         *  Return factory name:
         *  either the name declared in DSP with [declare name "foo"] syntax
         *  or 'filename' (if createDSPFactoryFromFile is used)
         *  or 'name_app' (if createDSPFactoryFromString is used)
        */
        std::string getName();
        
        /* Return factory LLVM target (like 'i386-apple-macosx10.6.0:opteron')*/
        std::string getTarget();
        
        /* Return factory SHA key */
        std::string getSHAKey();
  
        /* Return factory expanded DSP code */
        std::string getDSPCode();
    
        /* Create a new DSP instance, to be deleted with C++ 'delete' */
        llvm_dsp* createDSPInstance();
    
        /* Set a custom memory manager to be used when creating instances */
        void setMemoryManager(dsp_memory_manager* manager);
    
        /* Return the currently set custom memory manager */
        dsp_memory_manager* getMemoryManager();
    
        /* Get the Faust DSP factory list of library dependancies */
        std::vector<std::string> getLibraryList();
    
        /* Get the list of all used includes */
        std::vector<std::string> getIncludePathnames();
};

/**
 * Get the target (triple + CPU) of the machine.
 * 
 * @return the target as a string.
 */
std::string getDSPMachineTarget();

/**
 * Get the Faust DSP factory associated with a given SHA key (created from the 'expanded' DSP source), 
 * if already allocated in the factories cache and increment it's reference counter. You will have to explicitly
 * use deleteDSPFactory to properly decrement reference counter when the factory is no more needed.
 *
 * @param sha_key - the SHA key for an already created factory, kept in the factory cache
 *
 * @return a DSP factory if one is associated with the SHA key, otherwise a null pointer.
 */
llvm_dsp_factory* getDSPFactoryFromSHAKey(const std::string& sha_key);

/**
 * Create a Faust DSP factory from a DSP source code as a file. Note that the library keeps an internal cache of all 
 * allocated factories so that the compilation of the same DSP code (that is same source code and 
 * same set of 'normalized' compilations options) will return the same (reference counted) factory pointer. You will have to explicitly
 * use deleteDSPFactory to properly decrement the reference counter when the factory is no more needed.
 * 
 * @param filename - the DSP filename
 * @param argc - the number of parameters in argv array 
 * @param argv - the array of parameters (Warning : aux files generation options will be filtered (-svg, ...) --> use generateAuxFiles)
 * @param target - the LLVM machine target: like 'i386-apple-macosx10.6.0:opteron',
 *                 using an empty string takes the current machine settings,
 *                 and i386-apple-macosx10.6.0:generic kind of syntax for a generic processor
 * @param error_msg - the error string to be filled
 * @param opt_level - LLVM IR to IR optimization level (from -1 to 4, -1 means 'maximum possible value' 
 * since the maximum value may change with new LLVM versions)
 *
 * @return a DSP factory on success, otherwise a null pointer.
 */ 
llvm_dsp_factory* createDSPFactoryFromFile(const std::string& filename, 
                                           int argc, const char* argv[], 
                                           const std::string& target, 
                                           std::string& error_msg,
                                           int opt_level = -1);

/**
 * Create a Faust DSP factory from a DSP source code as a string. Note that the library keeps an internal cache of all 
 * allocated factories so that the compilation of the same DSP code (that is same source code and 
 * same set of 'normalized' compilations options) will return the same (reference counted) factory pointer. You will have to explicitly
 * use deleteDSPFactory to properly decrement reference counter when the factory is no more needed.
 * 
 * @param name_app - the name of the Faust program
 * @param dsp_content - the Faust program as a string
 * @param argc - the number of parameters in argv array
 * @param argv - the array of parameters (Warning : aux files generation options will be filtered (-svg, ...) --> use generateAuxFiles)
 * @param target - the LLVM machine target: like 'i386-apple-macosx10.6.0:opteron',
 *                 using an empty string takes the current machine settings,
 *                 and i386-apple-macosx10.6.0:generic kind of syntax for a generic processor
 * @param error_msg - the error string to be filled
 * @param opt_level - LLVM IR to IR optimization level (from -1 to 4, -1 means 'maximum possible value' 
 * since the maximum value may change with new LLVM versions)
 *
 * @return a DSP factory on success, otherwise a null pointer.
 */ 
llvm_dsp_factory* createDSPFactoryFromString(const std::string& name_app,
                                             const std::string& dsp_content,
                                             int argc, const char* argv[], 
                                             const std::string& target, 
                                             std::string& error_msg,
                                             int opt_level = -1);

/**
 * Delete a Faust DSP factory, that is decrements it's reference counter, possibly really deleting the internal pointer. 
 * Possibly also delete DSP pointers associated with this factory, if they were not explicitly deleted with C++ delete.
 * Beware : all kept factories and DSP pointers (in local variables...) thus become invalid.
 * 
 * @param factory - the DSP factory
 *
 * @return true if the factory internal pointer was really deleted, and false if only 'decremented'.
 */                                 
bool deleteDSPFactory(llvm_dsp_factory* factory);

/**
 * Get the Faust DSP factory list of library dependancies.
 *
 * @deprecated : use factory getDSPFactoryLibraryList method.
 *
 * @param factory - the DSP factory
 * 
 * @return the list as a vector of strings.
 */
DEPRECATED(std::vector<std::string> getDSPFactoryLibraryList(llvm_dsp_factory* factory));

/**
 * Delete all Faust DSP factories kept in the library cache. Beware : all kept factory and DSP pointers (in local variables...) thus become invalid.
 * 
 */                                 
void deleteAllDSPFactories();

/**
 * Return Faust DSP factories of the library cache as a vector of their SHA keys.
 * 
 * @return the Faust DSP factories.
 */                                 
std::vector<std::string> getAllDSPFactories();

/**
 * Start multi-thread access mode (since by default the library is not 'multi-thread' safe).
 * 
 * @return true if 'multi-thread' safe access is started.
 */ 
bool startMTDSPFactories();

/**
 * Stop multi-thread access mode.
 * 
 */ 
void stopMTDSPFactories();

/**
 * Create a Faust DSP factory from a base64 encoded LLVM bitcode string. Note that the library keeps an internal cache of all 
 * allocated factories so that the compilation of the same DSP code (that is the same LLVM bitcode string) will return 
 * the same (reference counted) factory pointer. You will have to explicitly use deleteDSPFactory to properly 
 * decrement reference counter when the factory is no more needed.
 * 
 * @param bit_code - the LLVM bitcode string
 * @param target - the LLVM machine target: like 'i386-apple-macosx10.6.0:opteron',
 *                 using an empty string takes the current machine settings,
 *                 and i386-apple-macosx10.6.0:generic kind of syntax for a generic processor
 * @param error_msg - the error string to be filled
 * @param opt_level - LLVM IR to IR optimization level (from -1 to 4, -1 means 'maximum possible value'
 * since the maximum value may change with new LLVM versions). A higher value than the one used when calling createDSPFactory can possibly be used.
 *
 * @return the DSP factory on success, otherwise a null pointer.
 */
llvm_dsp_factory* readDSPFactoryFromBitcode(const std::string& bit_code, const std::string& target, std::string& error_msg, int opt_level = -1);

/**
 * Write a Faust DSP factory into a base64 encoded LLVM bitcode string.
 * 
 * @param factory - the DSP factory
 *
 * @return the LLVM bitcode as a string.
 */
std::string writeDSPFactoryToBitcode(llvm_dsp_factory* factory);

/**
 * Create a Faust DSP factory from a LLVM bitcode file. Note that the library keeps an internal cache of all 
 * allocated factories so that the compilation of the same DSP code (that is the same LLVM bitcode file) will return 
 * the same (reference counted) factory pointer. You will have to explicitly use deleteDSPFactory to properly 
 * decrement reference counter when the factory is no more needed.
 * 
 * @param bit_code_path - the LLVM bitcode file pathname
 * @param target - the LLVM machine target: like 'i386-apple-macosx10.6.0:opteron',
 *                 using an empty string takes the current machine settings,
 *                 and i386-apple-macosx10.6.0:generic kind of syntax for a generic processor
 * @param error_msg - the error string to be filled
 * @param opt_level - LLVM IR to IR optimization level (from -1 to 4, -1 means 'maximum possible value'
 * since the maximum value may change with new LLVM versions). A higher value than the one used when calling 
 * createDSPFactory can possibly be used.
 * 
 * @return the DSP factory on success, otherwise a null pointer.
 */
llvm_dsp_factory* readDSPFactoryFromBitcodeFile(const std::string& bit_code_path, const std::string& target, std::string& error_msg, int opt_level = -1);

/**
 * Write a Faust DSP factory into a LLVM bitcode file.
 * 
 * @param factory - the DSP factory
 * @param bit_code_path - the LLVM bitcode file pathname.
 *
 */
void writeDSPFactoryToBitcodeFile(llvm_dsp_factory* factory, const std::string& bit_code_path);

/**
 * Create a Faust DSP factory from a LLVM IR (textual) string. Note that the library keeps an internal cache of all 
 * allocated factories so that the compilation of the same DSP code (that is the same LLVM IR string) will return 
 * the same (reference counted) factory pointer. You will have to explicitly use deleteDSPFactory to properly 
 * decrement reference counter when the factory is no more needed.
 * 
 * @param ir_code - the LLVM IR (textual) string
 * @param target - the LLVM machine target: like 'i386-apple-macosx10.6.0:opteron',
 *                 using an empty string takes the current machine settings,
 *                 and i386-apple-macosx10.6.0:generic kind of syntax for a generic processor
 * @param error_msg - the error string to be filled
 * @param opt_level - LLVM IR to IR optimization level (from -1 to 4, -1 means 'maximum possible value'
 * since the maximum value may change with new LLVM versions). A higher value than the one used when calling 
 * createDSPFactory can possibly be used.
 *
 * @return the DSP factory on success, otherwise a null pointer.
 */
llvm_dsp_factory* readDSPFactoryFromIR(const std::string& ir_code, const std::string& target, std::string& error_msg, int opt_level = -1);

/**
 * Write a Faust DSP factory into a LLVM IR (textual) string.
 * 
 * @param factory - the DSP factory
 *
 * @return the LLVM IR (textual) as a string.
 */
std::string writeDSPFactoryToIR(llvm_dsp_factory* factory);

/**
 * Create a Faust DSP factory from a LLVM IR (textual) file. Note that the library keeps an internal cache of all 
 * allocated factories so that the compilation of the same DSP code (that is the same LLVM IR file) will return 
 * the same (reference counted) factory pointer. You will have to explicitly use deleteDSPFactory to properly 
 * decrement reference counter when the factory is no more needed.
 * 
 * @param ir_code_path - the LLVM IR (textual) file pathname
 * @param target - the LLVM machine target: like 'i386-apple-macosx10.6.0:opteron',
 *                 using an empty string takes the current machine settings,
 *                 and i386-apple-macosx10.6.0:generic kind of syntax for a generic processor
 * @param error_msg - the error string to be filled
 * @param opt_level - LLVM IR to IR optimization level (from -1 to 4, -1 means 'maximum possible value'
 * since the maximum value may change with new LLVM versions), a higher value 
 * than the one used when calling createDSPFactory can possibly be used.
 *
 * @return the DSP factory on success, otherwise a null pointer.
 */
llvm_dsp_factory* readDSPFactoryFromIRFile(const std::string& ir_code_path, const std::string& target, std::string& error_msg, int opt_level = -1);

/**
 * Write a Faust DSP factory into a LLVM IR (textual) file.
 * 
 * @param factory - the DSP factory
 * @param ir_code_path - the LLVM bitcode file pathname.
 *
 */
void writeDSPFactoryToIRFile(llvm_dsp_factory* factory, const std::string& ir_code_path);

/**
 * Create a Faust DSP factory from a base64 encoded machine code string. Note that the library keeps an internal cache of all 
 * allocated factories so that the compilation of the same DSP code (that is the same machine code string) will return 
 * the same (reference counted) factory pointer. You will have to explicitly use deleteDSPFactory to properly 
 * decrement reference counter when the factory is no more needed.
 * 
 * @param machine_code - the machine code string
 * @param error_msg - the error string to be filled
 * @param target - the LLVM machine target: like 'i386-apple-macosx10.6.0:opteron',
 *                 using an empty string takes the current machine settings,
 *                 and i386-apple-macosx10.6.0:generic kind of syntax for a generic processor
 *
 * @return the DSP factory on success, otherwise a null pointer.
 */
llvm_dsp_factory* readDSPFactoryFromMachine(const std::string& machine_code, const std::string& target, std::string& error_msg);

/**
 * Write a Faust DSP factory into a base64 encoded machine code string.
 * 
 * @param factory - the DSP factory
 * @param target - the LLVM machine target: like 'i386-apple-macosx10.6.0:opteron',
 *                 using an empty string takes the current machine settings,
 *                 and i386-apple-macosx10.6.0:generic kind of syntax for a generic processor
 *
 * @return the machine code as a string.
 */
std::string writeDSPFactoryToMachine(llvm_dsp_factory* factory, const std::string& target);

/**
 * Create a Faust DSP factory from a machine code file. Note that the library keeps an internal cache of all 
 * allocated factories so that the compilation of the same DSP code (that is the same machine code file) will return 
 * the same (reference counted) factory pointer. You will have to explicitly use deleteDSPFactory to properly 
 * decrement reference counter when the factory is no more needed.
 * 
 * @param machine_code_path - the machine code file pathname
 * @param error_msg - the error string to be filled
 * @param target - the LLVM machine target: like 'i386-apple-macosx10.6.0:opteron',
 *                 using an empty string takes the current machine settings,
 *                 and i386-apple-macosx10.6.0:generic kind of syntax for a generic processor
 *
 * @return the DSP factory on success, otherwise a null pointer.
 */
llvm_dsp_factory* readDSPFactoryFromMachineFile(const std::string& machine_code_path, const std::string& target, std::string& error_msg);

/**
 * Write a Faust DSP factory into a machine code file.
 * 
 * @param factory - the DSP factory
 * @param machine_code_path - the machine code file pathname
 * @param target - the LLVM machine target: like 'i386-apple-macosx10.6.0:opteron',
 *                 using an empty string takes the current machine settings,
 *                 and i386-apple-macosx10.6.0:generic kind of syntax for a generic processor
 *
 */
void writeDSPFactoryToMachineFile(llvm_dsp_factory* factory, const std::string& machine_code_path, const std::string& target);

/**
 * Call global declarations with the given meta object.
 * 
 * @deprecated : use DSP instance metadata method.
 * @param factory - the DSP factory
 * @param meta - the meta object to be used.
 *
 */
DEPRECATED(void metadataDSPFactory(llvm_dsp_factory* factory, Meta* meta));

/**
 * Create a Faust DSP instance.
 * 
 * @deprecated : use factory createDSPInstance method.
 * @param factory - the DSP factory
 * 
 * @return the DSP instance on success, otherwise a null pointer.
 */
DEPRECATED(llvm_dsp* createDSPInstance(llvm_dsp_factory* factory));

/**
 * Delete a Faust DSP instance. You can also simply use C++ 'delete'. 
 * 
 * @deprecated : simply use C++ delete.
 * @param dsp - the DSP instance to be deleted.
 */ 
DEPRECATED(void deleteDSPInstance(llvm_dsp* dsp));

/*!
 @}
 */

#endif
#endif

#include "DspFaust.h"

std::list<GUI*> GUI::fGuiList;
ztimedmap GUI::gTimedZoneMap;

DspFaust::DspFaust()
{
    audio* driver = 0;
#if JACK_DRIVER
    // JACK has its own sample rate and buffer size
#if MIDICTRL
    driver = new jackaudio_midi();
#else
    driver = new jackaudio();
#endif
#elif JUCE_DRIVER
    // JUCE audio device has its own sample rate and buffer size
    driver = new juceaudio();
#else
    std::cout << "You are not setting 'sample_rate' and 'buffer_size', but the audio driver needs it !\n";
    throw std::bad_alloc();
#endif
    init(NULL, driver);
}

DspFaust::DspFaust(int sample_rate, int buffer_size)
{
    init(NULL, createDriver(sample_rate, buffer_size));
}

#if DYNAMIC_DSP
DspFaust::DspFaust(const string& dsp_content, int sample_rate, int buffer_size)
{
    string error_msg;

    // Is dsp_content a filename ?
    fFactory = createDSPFactoryFromFile(dsp_content, 0, NULL, "", error_msg, -1);
    if (!fFactory) {
        std::cerr << error_msg;
        // Is dsp_content a string ?
        fFactory = createDSPFactoryFromString("FaustDSP", dsp_content, 0, NULL, "", error_msg);
        if (!fFactory) {
            std::cerr << error_msg;
            throw bad_alloc();
        }
    }

    dsp* dsp = fFactory->createDSPInstance();
    if (!dsp) {
        std::cerr << "Cannot allocate DSP instance\n";
        throw bad_alloc();
    }
    init(dsp, createDriver(sample_rate, buffer_size));
}
#endif

audio* DspFaust::createDriver(int sample_rate, int buffer_size)
{
#if COREAUDIO_DRIVER
    audio* driver = new coreaudio(sample_rate, buffer_size);
#elif IOS_DRIVER
    audio* driver = new iosaudio(sample_rate, buffer_size);
#elif ANDROID_DRIVER
    audio* driver = new androidaudio(sample_rate, buffer_size);
#elif ALSA_DRIVER
    audio* driver = new alsaaudio(sample_rate, buffer_size);
#elif JACK_DRIVER
    // JACK has its own sample rate and buffer size
    std::cout << "You are setting 'sample_rate' and 'buffer_size' with a driver that does not need it !\n";
#if MIDICTRL
    audio* driver = new jackaudio_midi();
#else
    audio* driver = new jackaudio();
#endif
#elif PORTAUDIO_DRIVER
    audio* driver = new portaudio(sample_rate, buffer_size);
#elif RTAUDIO_DRIVER
    audio* driver = new rtaudio(sample_rate, buffer_size);
#elif OPEN_FRAMEWORK_DRIVER
    audio* driver = new ofaudio(sample_rate, buffer_size);
#elif JUCE_DRIVER
    // JUCE audio device has its own sample rate and buffer size
    std::cout << "You are setting 'sample_rate' and 'buffer_size' with a driver that does not need it !\n";
    audio* driver = new juceaudio();
#elif DUMMY_DRIVER
    audio* driver = new dummyaudio(sample_rate, buffer_size);
#endif
    return driver;
}

void DspFaust::init(dsp* mono_dsp, audio* driver)
{
#if MIDICTRL
    midi_handler* midi;
#if JACK_DRIVER
    midi = static_cast<jackaudio_midi*>(driver);
    fMidiInterface = new MidiUI(midi);
#elif JUCE_DRIVER
    midi = new juce_midi();
    fMidiInterface = new MidiUI(midi, true);
#else
    midi = new rt_midi();
    fMidiInterface = new MidiUI(midi, true);
#endif
    fPolyEngine = new FaustPolyEngine(mono_dsp, driver, midi);
    fPolyEngine->buildUserInterface(fMidiInterface);
#else
    fPolyEngine = new FaustPolyEngine(mono_dsp, driver);
#endif

#if OSCCTRL
#if JUCE_DRIVER
    fOSCInterface = new JuceOSCUI(OSC_IP_ADDRESS, atoi(OSC_IN_PORT), atoi(OSC_OUT_PORT));
#else
    const char* argv[11];
    argv[0] = "Faust";  // TODO may be should retrieve the actual name
    argv[1] = "-xmit";
    argv[2] = "1";      // TODO retrieve that from command line or somewhere
    argv[3] = "-desthost";
    argv[4] = OSC_IP_ADDRESS;   // TODO same
    argv[5] = "-port";
    argv[6] = OSC_IN_PORT;      // TODO same
    argv[7] = "-outport";
    argv[8] = OSC_OUT_PORT;     // TODO same
    argv[9] = "-bundle";
    argv[10] = "1";             // TODO same
    fOSCInterface = new OSCUI("Faust", 11, (char**)argv); // TODO fix name
    driver->setComputeCb(osc_compute_callback, fOSCInterface);
#endif
    fPolyEngine->buildUserInterface(fOSCInterface);
#endif

#if SOUNDFILE
#if JUCE_DRIVER
    auto file = File::getSpecialLocation(File::currentExecutableFile)
        .getParentDirectory().getParentDirectory().getChildFile("Resources");
    fSoundInterface = new SoundUI(file.getFullPathName().toStdString());
#else
    // Use bundle path
    fSoundInterface = new SoundUI(SoundUI::getBinaryPath());
#endif
    // SoundUI has to be dispatched on all internal voices
    fPolyEngine->setGroup(false);
    fPolyEngine->buildUserInterface(fSoundInterface);
    fPolyEngine->setGroup(true);
#endif
}

DspFaust::~DspFaust()
{
#if OSCCTRL
    delete fOSCInterface;
#endif
#if MIDICTRL
    delete fMidiInterface;
#endif
#if SOUNDFILE
    delete fSoundInterface;
#endif
    delete fPolyEngine;
#if DYNAMIC_DSP
    deleteDSPFactory(static_cast<llvm_dsp_factory*>(fFactory));
#endif
}

bool DspFaust::start()
{
#if OSCCTRL
    fOSCInterface->run();
#endif
#if MIDICTRL
    if (!fMidiInterface->run()) {
        std::cerr << "MIDI run error...\n";
    }
#endif
	return fPolyEngine->start();
}

void DspFaust::stop()
{
#if OSCCTRL
    fOSCInterface->stop();
#endif
#if MIDICTRL
    fMidiInterface->stop();
#endif
	fPolyEngine->stop();
}

bool DspFaust::configureOSC(bool xmit, int inport, int outport, int errport, const char* address)
{
#if OSCCTRL
#if JUCE_DRIVER
    // Nothing for now
    return false;
#else
    if (isRunning()) {
        return false;
    } else {
        oscfaust::OSCControler::gXmit = xmit;
        fOSCInterface->setUDPPort(inport);
        fOSCInterface->setUDPOut(outport);
        fOSCInterface->setUDPErr(errport);
        fOSCInterface->setDestAddress(address);
        return true;
    }
#endif
#else
    return false;
#endif
}

bool DspFaust::isRunning()
{
	return fPolyEngine->isRunning();
}

unsigned long DspFaust::keyOn(int pitch, int velocity)
{
	return (unsigned long)fPolyEngine->keyOn(pitch, velocity);
}

int DspFaust::keyOff(int pitch)
{
	return fPolyEngine->keyOff(pitch);
}

unsigned long DspFaust::newVoice()
{
	return (unsigned long)fPolyEngine->newVoice();
}

int DspFaust::deleteVoice(unsigned long voice)
{
	return fPolyEngine->deleteVoice(voice);
}

void DspFaust::allNotesOff()
{
    fPolyEngine->allNotesOff();
}

void DspFaust::propagateMidi(int count, double time, int type, int channel, int data1, int data2)
{
    fPolyEngine->propagateMidi(count, time, type, channel, data1, data2);
}

const char* DspFaust::getJSONUI()
{
	return fPolyEngine->getJSONUI();
}

const char* DspFaust::getJSONMeta()
{
	return fPolyEngine->getJSONMeta();
}

int DspFaust::getParamsCount()
{
	return fPolyEngine->getParamsCount();
}

void DspFaust::setParamValue(const char* address, float value)
{
	fPolyEngine->setParamValue(address, value);
}

void DspFaust::setParamValue(int id, float value)
{
	fPolyEngine->setParamValue(id, value);
}

float DspFaust::getParamValue(const char* address)
{
	return fPolyEngine->getParamValue(address);
}

float DspFaust::getParamValue(int id)
{
	return fPolyEngine->getParamValue(id);
}

void DspFaust::setVoiceParamValue(const char* address, unsigned long voice, float value)
{
	fPolyEngine->setVoiceParamValue(address, voice, value);
}

void DspFaust::setVoiceParamValue(int id, unsigned long voice, float value)
{
	fPolyEngine->setVoiceParamValue(id, voice, value);
}

float DspFaust::getVoiceParamValue(const char* address, unsigned long voice)
{
	return fPolyEngine->getVoiceParamValue(address, voice);
}

float DspFaust::getVoiceParamValue(int id, unsigned long voice)
{
	return fPolyEngine->getVoiceParamValue(id, voice);
}

const char* DspFaust::getParamAddress(int id)
{
	return fPolyEngine->getParamAddress(id);
}

const char* DspFaust::getVoiceParamAddress(int id, unsigned long voice)
{
	return fPolyEngine->getVoiceParamAddress(id, voice);
}

float DspFaust::getParamMin(const char* address)
{
    return fPolyEngine->getParamMin(address);
}

float DspFaust::getParamMin(int id)
{
    return fPolyEngine->getParamMin(id);
}

float DspFaust::getParamMax(const char* address)
{
    return fPolyEngine->getParamMax(address);
}

float DspFaust::getParamMax(int id)
{
    return fPolyEngine->getParamMax(id);
}

float DspFaust::getParamInit(const char* address)
{
    return fPolyEngine->getParamInit(address);
}

float DspFaust::getParamInit(int id)
{
    return fPolyEngine->getParamInit(id);
}

const char* DspFaust::getMetadata(const char* address, const char* key)
{
    return fPolyEngine->getMetadata(address, key);
}

const char* DspFaust::getMetadata(int id, const char* key)
{
    return fPolyEngine->getMetadata(id, key);
}

void DspFaust::propagateAcc(int acc, float v)
{
	fPolyEngine->propagateAcc(acc, v);
}

void DspFaust::setAccConverter(int p, int acc, int curve, float amin, float amid, float amax)
{
	fPolyEngine->setAccConverter(p, acc, curve, amin, amid, amax);
}

void DspFaust::propagateGyr(int acc, float v)
{
	fPolyEngine->propagateGyr(acc, v);
}

void DspFaust::setGyrConverter(int p, int gyr, int curve, float amin, float amid, float amax)
{
	fPolyEngine->setGyrConverter(p, gyr, curve, amin, amid, amax);
}

float DspFaust::getCPULoad()
{
	return fPolyEngine->getCPULoad();
}

int DspFaust::getScreenColor()
{
	return fPolyEngine->getScreenColor();
}

#ifdef BUILD
#include <unistd.h>

int main(int argc, char* argv[])
{
#ifdef DYNAMIC_DSP
    DspFaust* dsp = new DspFaust(argv[1], 44100, 512);
#else
    DspFaust* dsp = new DspFaust(44100, 512);
#endif
    dsp->start();
    std::cout << "Type 'q' to quit\n";
    char c;
    while ((c = getchar()) && (c != 'q')) { usleep(100000); }
    dsp->stop();
    delete dsp;
}

#endif

#endif
