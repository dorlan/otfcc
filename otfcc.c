#include <stdio.h>
#include <stdint.h>

typedef struct {
  uint32_t sfnt_version;
  uint16_t numTables;
  uint16_t searchRange;
  uint16_t entrySelector;
  uint16_t rangeShift;
} opentype_offset_table;

typedef struct {
  uint32_t tag;
  uint32_t checkSum;
  uint32_t offset;
  uint32_t length;
} opentype_table_record;

typedef struct {
  uint32_t TTCTag;
  uint32_t version;
  uint32_t numFonts;
  uint32_t*OffsetTable;
  uint32_t ulDsigTag;
  uint32_t ulDsigLength;
  uint32_t ulDsigOffset;
} opentype_collection_header;

typedef enum {
  TABLE_REQUIRED,
    // 'cmap', 'head', 'hhea', 'hmtx'
    // 'maxp', 'name', 'OS/2', 'post'
  TABLE_TRUETYPE,
    // 'cvt ', 'fpgm', 'glyf', 'loca'
    // 'prep', 'gasp'
  TABLE_POSTSCRIPT,
    // 'CFF ', 'VORG'
  TABLE_SVG,
    // 'SVG '
  TABLE_BITMAP,
    // 'EBDT', 'EBLC', 'EBSC', 'CBDT'
    // 'CBLT'
  TABLE_ADVANCED_TYPOGRAPHIC,
    // 'BASE', 'GDEF', 'GPOS', 'GSUB'
    // 'JSTF', 'MATH'
  TABLE_OTHER
    // 'DSIG', 'hdmx', 'kern', 'LTSH'
    // 'PLCT', 'VDMX', 'vhea', 'vmtx'
    // 'COLR', 'CPAL'
} opentype_table_type;

typedef struct {
  uint32_t table_version_number;
  uint32_t fontRevison;
  uint32_t checkSumAdjustment;
  uint32_t magicNumber;
  uint16_t flags;
  uint16_t unitsPerEm;
  int64_t  created;
  int64_t  modified;
  int16_t  xMin;
  int16_t  yMin;
  int16_t  xMax;
  int16_t  yMax;
  uint16_t macStyle;
  uint16_t lowestRecPPEM;
  int16_t  fontDirectoryHint;
  int16_t  indexToLocFormat;
  int16_t  glyphDataFormat;
} opentype_table_head;

typedef struct {
  uint32_t table_version_number;
  int16_t  Ascender;
  int16_t  Descender;
  int16_t  LineGap;
  uint16_t advanceWithMax;
  int16_t  minLeftSideBearing;
  int16_t  minRightSideBearing;
  int16_t  xMaxExtent;
  int16_t  caretSlopeRise;
  int16_t  caretSlopeRun;
  int16_t  dummy0;
  int16_t  dummy1;
  int16_t  dummy2;
  int16_t  dummy3;
  int16_t  metricDataFormat;
  uint16_t numberOfMetrics;
} opentype_table_hhea;

typedef struct {
  uint16_t version;
  int16_t  xAvgCharWidth;
  uint16_t usWeightClass;
  uint16_t usWidthClass;
  uint16_t fsType;
  int16_t  ySubscriptXSize;
  int16_t  ySubscriptYSize;
  int16_t  ySubscriptXOffset;
  int16_t  ySubscriptYOffset;
  int16_t  ySupscriptXSize;
  int16_t  ySupscriptYSize;
  int16_t  ySupscriptXOffset;
  int16_t  ySupscriptYOffset;
  int16_t  yStrikeoutSize;
  int16_t  yStrikeoutPosition;
  int16_t  sFamilyClass;
  uint8_t  panose[10];
  uint32_t ulUnicodeRange1;
  uint32_t ulUnicodeRange2;
  uint32_t ulUnicodeRange3;
  uint32_t ulUnicodeRange4;
  int8_t   achVendID[4];
  uint16_t fsSelection;
  uint16_t usFirstCharIndex;
  uint16_t usLastCharIndex;
  int16_t  sTypoAscender;
  int16_t  sTypoDescender;
  uint32_t ulCodePageRange1;
  uint32_t ulCodePageRange2;
  int16_t  sxHeight;
  int16_t  sCapHeight;
  uint16_t usDefaultCHar;
  uint16_t usBreakChar;
  uint16_t usMaxContext;
  uint16_t usLowerOpticalPointSize;
  uint16_t usUpperOpticalPointSize;
} opentype_table_os2;

typedef struct {
  uint16_t advanceWidth;
  int16_t  lsb;
} opentype_horizontal_metric;

typedef struct {
  uint16_t advanceHeight;
  int16_t  topSideBearing;
} opentype_vertical_metric;

typedef struct {
  uint16_t platformID;
  uint16_t encodingID;
  uint16_t languageID;
  uint16_t nameID;
  uint16_t length;
  uint16_t offset;
} opentype_name_record;

typedef struct {
  uint16_t length;
  uint16_t offset;
} opentype_lang_tag_record;

typedef struct {
  uint16_t format;
  uint16_t count;
  uint16_t stringOffset;
  opentype_name_record*nameRecord;
  uint16_t langTagCount;
  opentype_lang_tag_record*langTagRecord;
} opentype_table_name;

typedef struct {
  uint32_t table_version_number;
  uint16_t numGlyphs;
  uint16_t maxPoints;
  uint16_t maxContours;
  uint16_t maxCompositePoints;
  uint16_t maxCompositeContours;
  uint16_t maxZones;
  uint16_t maxTwilightPoints;
  uint16_t maxStorage;
  uint16_t maxFunctionDefs;
  uint16_t maxInstructionDefs;
  uint16_t maxStackElements;
  uint16_t maxSizeOfInstructions;
  uint16_t maxComponentElements;
  uint16_t maxComponentDepth;
} opentype_table_maxp;

typedef struct {
  int16_t Value;
  uint16_t DeviceTable;
} opentype_math_value_record;

typedef struct {
  uint32_t Version;
  uint16_t MathConstants;
  uint16_t MathGlyphInfo;
  uint16_t MathVariants;
} opentype_table_math;

typedef struct {
  int16_t  ScriptPercentScaleDown;
  int16_t  ScriptScriptPercentScaleDown;
  uint16_t DelimitedSubFormulaMinHeight;
  uint16_t DisplayOperatorMinHeight;
  opentype_math_value_record MathLeading;
  opentype_math_value_record AxisHeight;
  opentype_math_value_record AccentBaseHeight;
  opentype_math_value_record FlattenedAccentBaseHeight;
  opentype_math_value_record SubscriptShiftDown;
  opentype_math_value_record SubscriptTopMax;
  opentype_math_value_record SubscriptBaselineDropMin;
  opentype_math_value_record SuperscriptShiftUp;
  opentype_math_value_record SuperscriptShiftUpCramped;
  opentype_math_value_record SuperscriptBottomMin;
  opentype_math_value_record SuperscriptBaselineDropMax;
  opentype_math_value_record SubSuperscriptGapMin;
  opentype_math_value_record SuperscriptBottomMaxWithSubscript;
  opentype_math_value_record SpaceAfterScript;
  opentype_math_value_record UpperLimitGapMin;
  opentype_math_value_record UpperLimitBaselineRiseMin;
  opentype_math_value_record LowerLimitGapMin;
  opentype_math_value_record LowerLimitBaselineDropMin;
  opentype_math_value_record StackTopShiftUp;
  opentype_math_value_record StackTopDisplayStyleShiftUp;
  opentype_math_value_record StackBottomShiftDown;
  opentype_math_value_record StackBottomDisplayStyleShiftDown;
  opentype_math_value_record StackGapMin;
  opentype_math_value_record StackDisplayStyleGapMin;
  opentype_math_value_record StretchStackTopShiftUp;
  opentype_math_value_record StretchStackBottomShiftDown;
  opentype_math_value_record StretchStackGapAboveMin;
  opentype_math_value_record StretchStackGapBelowMin;
  opentype_math_value_record FractionNumeratorShiftUp;
  opentype_math_value_record FractionNumeratorDisplayStyleShiftUp;
  opentype_math_value_record FractionDenominatorShiftDown;
  opentype_math_value_record FractionDenominatorDisplayStyleShiftDown;
  opentype_math_value_record FractionNumeratorGapMin;
  opentype_math_value_record FractionNumDisplayStyleGapMin;
  opentype_math_value_record FractionRuleThickness;
  opentype_math_value_record FractionDenominatorGapMin;
  opentype_math_value_record FractionDenomDisplayStyleGapMin;
  opentype_math_value_record SkewedFractionHorizontalGap;
  opentype_math_value_record SkewedFractionVerticalGap;
  opentype_math_value_record OverbarVerticalGap;
  opentype_math_value_record OverbarRuleThickness;
  opentype_math_value_record OverbarExtraAscender;
  opentype_math_value_record UnderbarVerticalGap;
  opentype_math_value_record UnderbarRuleThickness;
  opentype_math_value_record UnderbarExtraDescender;
  opentype_math_value_record RadicalVerticalGap;
  opentype_math_value_record RadicalDisplayStyleVerticalGap;
  opentype_math_value_record RadicalRuleThickness;
  opentype_math_value_record RadicalExtraAscender;
  opentype_math_value_record RadicalKernBeforeDegree;
  opentype_math_value_record RadicalKernAfterDegree;
  int16_t RadicalDegreeBottomRaisePercent;
} opentype_math_constants;

typedef struct {
  uint16_t MathItalicsCorrectionInfo;
  uint16_t MathTopAccentAttachment;
  uint16_t ExtendedShapeCoverage;
  uint16_t MathKernInfo;
} opentype_math_glyph_info;

typedef struct {
} opentype_math_variants;
typedef struct {
  uint16_t Coverage;
  uint16_t ItalicsCorrectionCount;
  opentype_math_value_record * ItalicsCorrection;
} opentype_math_italics_correction_info;

typedef struct {
  uint16_t TopAccentCoverage;
  uint16_t TopAccentAttachmentCount;
  opentype_math_value_record * TopAccentAttachment;
} opentype_math_top_accent_attachment;

typedef struct {
  uint16_t TopRightMathKern;
  uint16_t TopLeftMathKern;
  uint16_t BottomRightMathKern;
  uint16_t BottomLeftMathKern;
} opentype_math_kern_info_record;

typedef struct {
  uint16_t MathKernCoverage;
  uint16_t MathKernCount;
  opentype_math_kern_info_record * MathKernInfoRecords;
} opentype_math_kern_info;

typedef struct {
  uint16_t HeightCount;
  opentype_math_value_record * CorrectionHeight;
  opentype_math_value_record * KernValue;
} opentype_math_kern;

typedef struct {
  uint16_t MinConnectorOverlap;
  uint16_t VertGlyphCoverage;
  uint16_t HorizGlyphCoverage;
  uint16_t VertGlyphCount;
  uint16_t HorizGlyphCount;
  uint16_t VertGlyphConstruction;
  uint16_t HorizGlyphConstruction;
} opentype_math_variants;

typedef struct {
  uint16_t VariantGlyph;
  uint16_t AdvanceMeasurement;
} opentype_math_glyph_variant_record;

typedef struct {
  uint16_t GlyphAssembly;
  uint16_t VariantCount;
  opentype_math_glyph_variant_record * MathGlyphVariantRecord;
} opentype_math_glyph_construction;

typedef struct {
  uint16_t Glyph;
  uint16_t StartConnectorLength;
  uint16_t EndConnectorLength;
  uint16_t FullAdvance;
  uint16_t PartFlags;
} opentype_glyph_part_record;

typedef struct {
  opentype_math_value_record ItalicsCorrection;
  uint16_t PartCount;
  opentype_glyph_part_record * PartRecords;
} opentype_glyph_assembly;

typedef struct {
  uint16_t version;
  uint16_t numGlyphs;
  uint8_t * yPels;
} opentype_table_ltsh;

typedef struct {
  uint32_t Version;
  uint32_t FontNumber;
  uint16_t Pitch;
  uint16_t xHeight;
  uint16_t Style;
  uint16_t TypeFamily;
  uint16_t CapHeight;
  uint16_t SymbolSet;
  uint8_t  Typeface[16];
  uint8_t  CharacterComplement[8];
  uint8_t  FileName[6];
  uint8_t  StrokeWeight;
  uint8_t  WidthType;
  int8_t   SerifStyle;
  int8_t   dummy0;
} opentype_table_pclt;

typedef struct {
  uint16_t version;
  uint16_t numBaseGlyphRecords;
  uint32_t offsetBaseGlyphRecord;
  uint32_t offsetLayerRecord;
  uint16_t numLayerRecords;
} opentype_table_colr;

typedef struct {
  uint16_t GID;
  uint16_t firstLayerIndex;
  uint16_t numLayers;
} opentype_base_glyph_record;

typedef struct {
  uint16_t GID;
  uint16_t paletteIndex;
} opentype_layer_record;

typedef struct {
  uint32_t ulVersion;
  uint16_t usNumSigs;
  uint16_t usFlag;
  uint32_t ulFormat;
  uint32_t ulLength;
  uint32_t ulOffset;
  uint16_t usReserved1;
  uint16_t usReserved2;
  uint32_t cbSignature;
  uint8_t * bSignature;
} opentype_table_dsig;

typedef struct {
  uint16_t majorVersion;
  uint16_t minorVersion;
  int16_t  defaultVertOriginY;
  uint16_t numVertOriginYMetrics;
} opentype_table_vorg;

typedef struct {
  uint16_t glyphIndex;
  int16_t  vertOriginY;
} opentype_vert_origin_y_metrics;

typedef struct {
  uint16_t version;
  uint32_t offsetToSVGDocIndex;
  uint32_t reserved;
} opentype_table_svg;

typedef struct {
  uint16_t startGlyphID;
  uint16_t endGlyphID;
  uint32_t svgDocOffset;
  uint32_t svgDocLength;
} opentype_svg_document_index_entry;

typedef struct {
  uint16_t numEntries;
  opentype_svg_document_index_entry * entries;
} opentype_svg_document_index;

typedef struct {
  int32_t Version;
  uint16_t HorizAxis;
  uint16_t VertAxis;
} opentype_table_base;

typedef struct {
  uint16_t BaseTagList;
  uint16_t BaseScriptList;
} opentype_axis_table;

typedef struct {
  uint16_t BaseTagCount;
  uint32_t * BaselineTag;
} opentype_base_tag_list_table;

typedef struct {
  uint32_t BaseScriptTag;
  uint16_t BaseScript;
} opentype_base_script_record;

typedef struct {
  uint16_t BaseScriptCount;
  opentype_base_script_record * BaseScriptRecord;
} opentype_base_script_list_table;

typedef struct {
  uint32_t BaseLangSysTag;
  uint16_t MinMax;
} opentype_base_lang_sys_record;

typedef struct {
  uint16_t BaseValues;
  uint16_t DefaultMinMax;
  uint16_t BaseLangSysCount;
  opentype_base_lang_sys_record * BaseLangSysRecord;
} opentype_base_script_table;

typedef struct {
  uint16_t DefaultIndex;
  uint16_t BaseCoordCount;
  uint16_t BaseCoord;
} opentype_base_values_table;

typedef struct {
  uint32_t FeatureTableTag;
  uint16_t MinCoord;
  uint16_t MaxCoord;
} opentype_feat_min_max_record;

typedef struct {
  uint16_t MinCoord;
  uint16_t MaxCoord;
  uint16_t FeatMinMaxCount;
  opentype_feat_min_max_record * FeatMinMaxRecord;
} opentype_min_max_table;

typedef struct {
  uint16_t BaseCoordFormat;
  int16_t  Coordinate;
  uint16_t ReferenceGlyph;
  uint16_t BaseCoordPoint;
  uint16_t DeviceTable;
} opentype_base_coord;

typedef struct {
  uint16_t version;
  uint16_t numTables;
} opentype_table_cmap;

typedef struct {
  uint16_t platformID;
  uint16_t encodingID;
  uint32_t offset;
} opentype_encoding_record;

typedef struct {
  uint16_t format;
  uint16_t length;
  uint16_t language;
  uint8_t  glyphIdArray[256];
} opentype_subtable_format0;

typedef struct {
  uint16_t firstCode;
  uint16_t entryCount;
  int16_t  idDelta;
  uint16_t idRangeOffset;
} opentype_subheader;

typedef struct {
  uint16_t format;
  uint16_t length;
  uint16_t language;
  uint16_t subHeaderKeys[256];
  opentype_subheader * subHeaders;
  uint16_t * glyphIndexArray;
} opentype_subtable_format2;

typedef struct {
  uint16_t format;
  uint16_t length;
  uint16_t language;
  uint16_t segCountX2;
  uint16_t searchRange;
  uint16_t entrySelector;
  uint16_t rangeShift;
  uint16_t * endCount;
  uint16_t reservedPad;
  uint16_t * startCount;
  int16_t  idDelta;
  uint16_t * idRangeOffset;
  uint16_t * glyphIdArray;
} opentype_subtable_format4;

typedef struct {
  uint16_t format;
  uint16_t length;
  uint16_t language;
  uint16_t firstCode;
  uint16_t entryCount;
  uint16_t * glyphIdArray;
} opentype_subtable_format6;

typedef struct {
  uint32_t startCharCode;
  uint32_t endCharCode;
  uint32_t startGlyphID;
} opentype_groups;

typedef struct {
  uint16_t format;
  uint16_t reserved;
  uint32_t length;
  uint32_t language;
  uint8_t  is32[8192];
  uint32_t nGroups;
} opentype_subtable_format8;

typedef struct {
  uint16_t format;
  uint16_t reserved;
  uint32_t length;
  uint32_t language;
  uint32_t startCharCode;
  uint32_t numChars;
  uint16_t glyphs;
} opentype_subtable_format10;

typedef struct {
  uint16_t format;
  uint16_t reserved;
  uint32_t length;
  uint32_t language;
  uint32_t nGroups;
} opentype_subtable_format12;

typedef struct {
  uint16_t format;
  uint16_t reserved;
  uint32_t length;
  uint32_t language;
  uint32_t nGroups;
} opentype_subtable_format13;

typedef struct {
  uint16_t format;
  uint16_t length;
  uint32_t numVarSelectorRecords;
} opentype_subtable_format14;

typedef struct {
  uint32_t varSelector;
  uint32_t defaultUVSOffset;
  uint32_t nonDefaultUVSOffset;
} opentype_num_var_selector_record;

typedef struct {
  uint32_t numUnicodeValueRanges;
} opentype_default_uvs_table;

typedef struct {
  uint32_t startUnicodeValue;
  uint8_t additionalCount;
} opentype_num_unicode_value_ranges;

typedef struct {
  uint32_t numUVSMappings;
} opentype_non_default_uvs_table;

typedef struct {
  uint32_t unicodeValue;
  uint16_t glyphID;
} opentype_num_uvs_mappings;

typedef struct {
  uint32_t JstfScriptTag;
  uint16_t JstfScript;
} opentype_jstf_script_record;

typedef struct {
  uint32_t Version;
  uint16_t JstfScriptCount;
  opentype_jstf_script_record * JstfScriptRecord;
} opentype_table_jstf;

typedef struct {
  uint32_t JstfLangSysTag;
  uint16_t JstfLangSys;
} opentype_jstf_lang_sys_record;

typedef struct {
  uint16_t ExtenderGlyph;
  uint16_t DefJstfLangSys;
  uint16_t JstfLangSysCount;
  opentype_jstf_lang_sys_record * JstfLangSysRecord;
} opentype_jstf_script;

typedef struct {
  uint16_t GlyphCount;
  uint16_t * ExtenderGlyph;
} opentype_extender_glyph_table;

typedef struct {
  uint16_t JstfPriorityCnt;
  uint16_t JstfPriority;
} opentype_jstf_lang_sys_table;

typedef struct {
  uint16_t ShrinkageEnableGSUB;
  uint16_t ShrinkageDisableGSUB;
  uint16_t ShrinkageEnableGPOS;
  uint16_t ShrinkageDisableGPOS;
  uint16_t ShrinkageJstfMax;
  uint16_t ExtensionEnableGSUB;
  uint16_t ExtensionDisableGSUB;
  uint16_t ExtensionEnableGPOS;
  uint16_t ExtensionDisableGPOS;
  uint16_t ExtensionJstfMax;
} opentype_jstf_priority;

typedef struct {
  uint16_t LookupCount;
  uint16_t * GSUBLookupIndex;
} opentype_jstf_gsub_mod_list;

typedef struct {
  uint16_t LookupCount;
  uint16_t * GPOSLookupIndex;
} opentype_jstf_gpos_mod_list;

typedef struct {
  uint16_t LookupCount;
  uint16_t Lookup;
} opentype_jstf_max;

/*
typedef struct {
  header;
  name_index;
  top_dict_index;
  string_index;
  global_subr_index;
  encodings;
  charsets;
  fdselect;
  charstring_index;
  font_dict_index;
  private_dict;
  local_subr_index;
} opentype_table_cff;
*/

int main (void)
{
  return 0;
}

