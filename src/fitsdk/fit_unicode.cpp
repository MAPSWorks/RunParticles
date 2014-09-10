////////////////////////////////////////////////////////////////////////////////
// The following FIT Protocol software provided may be used with FIT protocol
// devices only and remains the copyrighted property of Dynastream Innovations Inc.
// The software is being provided on an "as-is" basis and as an accommodation,
// and therefore all warranties, representations, or guarantees of any kind
// (whether express, implied or statutory) including, without limitation,
// warranties of merchantability, non-infringement, or fitness for a particular
// purpose, are specifically disclaimed.
//
// Copyright 2014 Dynastream Innovations Inc.
////////////////////////////////////////////////////////////////////////////////
// ****WARNING****  This file is auto-generated!  Do NOT edit this file.
// Profile Version = 12.10Release
// Tag = $Name$
////////////////////////////////////////////////////////////////////////////////


#include "fit_config.hpp"
#include "fit_runtime_exception.hpp"
#include "fit_unicode.hpp"

///////////////////////////////////////////////////////////////////////
// Private Definitions
///////////////////////////////////////////////////////////////////////

// Encoding types.
typedef FIT_ENUM FIT_UNICODE_ENCODING;
#define FIT_UNICODE_ENCODING_UTF8            ((FIT_UNICODE_ENCODING)0)
#define FIT_UNICODE_ENCODING_UTF16           ((FIT_UNICODE_ENCODING)1)
#define FIT_UNICODE_ENCODING_UTF32           ((FIT_UNICODE_ENCODING)2)
#define FIT_UNICODE_ENCODING_INVALID         FIT_ENUM_INVALID
#define FIT_UNICODE_ENCODING_COUNT           3

#if (FIT_WIDE_CHAR_SIZE == 1)
   #define INTERNAL_UNICODE_ENCODING         FIT_UNICODE_ENCODING_UTF8
#elif (FIT_WIDE_CHAR_SIZE == 2)
   #define INTERNAL_UNICODE_ENCODING         FIT_UNICODE_ENCODING_UTF16
#elif (FIT_WIDE_CHAR_SIZE == 4)
   #define INTERNAL_UNICODE_ENCODING         FIT_UNICODE_ENCODING_UTF32
#else
   #error "Wide character size not specified as 1, 2 or 4 bytes."
#endif

// Conversion error codes.
typedef FIT_ENUM FIT_STRING_CONVERSION_ERROR;
#define FIT_STRING_CONVERSION_ERROR_UNICODE_INVALID_POINT                     ((FIT_STRING_CONVERSION_ERROR)0)
#define FIT_STRING_CONVERSION_ERROR_UNICODE_UNDEFINED_SOURCE_ENCODING         ((FIT_STRING_CONVERSION_ERROR)1)
#define FIT_STRING_CONVERSION_ERROR_UNICODE_UNDEFINED_DESTINATION_ENCODING    ((FIT_STRING_CONVERSION_ERROR)2)
#define FIT_STRING_CONVERSION_ERROR_UTF8_INVALID_UNIT                         ((FIT_STRING_CONVERSION_ERROR)3)
#define FIT_STRING_CONVERSION_ERROR_UTF8_INVALID_LEAD_UNIT                    ((FIT_STRING_CONVERSION_ERROR)4)
#define FIT_STRING_CONVERSION_ERROR_UTF8_INVALID_CONTINUATION_UNIT            ((FIT_STRING_CONVERSION_ERROR)5)
#define FIT_STRING_CONVERSION_ERROR_UTF8_NON_CONTINUATION_UNIT                ((FIT_STRING_CONVERSION_ERROR)6)
#define FIT_STRING_CONVERSION_ERROR_UTF8_OVERENCODED_POINT_1                  ((FIT_STRING_CONVERSION_ERROR)7)
#define FIT_STRING_CONVERSION_ERROR_UTF8_OVERENCODED_POINT_2                  ((FIT_STRING_CONVERSION_ERROR)8)
#define FIT_STRING_CONVERSION_ERROR_UTF8_OVERENCODED_POINT_3                  ((FIT_STRING_CONVERSION_ERROR)9)
#define FIT_STRING_CONVERSION_ERROR_UTF8_OVERENCODED_POINT_4                  ((FIT_STRING_CONVERSION_ERROR)10)
#define FIT_STRING_CONVERSION_ERROR_UTF8_INVALID_NUM_UNITS                    ((FIT_STRING_CONVERSION_ERROR)11)
#define FIT_STRING_CONVERSION_ERROR_UTF8_END_OF_STRING                        ((FIT_STRING_CONVERSION_ERROR)12)
#define FIT_STRING_CONVERSION_ERROR_UTF16_INVALID_UNIT                        ((FIT_STRING_CONVERSION_ERROR)13)
#define FIT_STRING_CONVERSION_ERROR_UTF16_INVALID_LEAD_UNIT                   ((FIT_STRING_CONVERSION_ERROR)14)
#define FIT_STRING_CONVERSION_ERROR_UTF16_INVALID_TAIL_UNIT                   ((FIT_STRING_CONVERSION_ERROR)15)
#define FIT_STRING_CONVERSION_ERROR_UTF16_NON_TAIL_UNIT                       ((FIT_STRING_CONVERSION_ERROR)16)
#define FIT_STRING_CONVERSION_ERROR_UTF16_OVERENCODED_POINT_1                 ((FIT_STRING_CONVERSION_ERROR)17)
#define FIT_STRING_CONVERSION_ERROR_UTF16_OVERENCODED_POINT_2                 ((FIT_STRING_CONVERSION_ERROR)18)
#define FIT_STRING_CONVERSION_ERROR_UTF16_INVALID_NUM_UNITS                   ((FIT_STRING_CONVERSION_ERROR)19)
#define FIT_STRING_CONVERSION_ERROR_UTF16_END_OF_STRING                       ((FIT_STRING_CONVERSION_ERROR)20)
#define FIT_STRING_CONVERSION_ERROR_UTF32_INVALID_UNIT                        ((FIT_STRING_CONVERSION_ERROR)21)
#define FIT_STRING_CONVERSION_ERROR_INVALID                                   FIT_ENUM_INVALID
#define FIT_STRING_CONVERSION_ERROR_COUNT                                     22

// General Unicode.
typedef unsigned long int FIT_LARGE_TYPE;
#define UNICODE_IS_POINT_VALID(POINT)        ((((((FIT_LARGE_TYPE)(POINT) & (FIT_LARGE_TYPE)0x1FFFFF) <= (FIT_LARGE_TYPE)0x00D7FF)) || ((((FIT_LARGE_TYPE)(POINT) & (FIT_LARGE_TYPE)0x1FFFFF) >= (FIT_LARGE_TYPE)0x00E000) && (((FIT_LARGE_TYPE)(POINT) & (FIT_LARGE_TYPE)0x1FFFFF) <= (FIT_LARGE_TYPE)0x10FFFF))) ? (FIT_TRUE) : (FIT_FALSE))

// UTF-8 encoding.
#define UTF8_IS_UNIT_VALID(UNIT)             (((((FIT_LARGE_TYPE)(UNIT) & (FIT_LARGE_TYPE)0xFF) != (FIT_LARGE_TYPE)0xC0) && (((FIT_LARGE_TYPE)(UNIT) & (FIT_LARGE_TYPE)0xFF) != (FIT_LARGE_TYPE)0xC1) && (((FIT_LARGE_TYPE)(UNIT) & (FIT_LARGE_TYPE)0xFF) <= (FIT_LARGE_TYPE)0xF4)) ? (FIT_TRUE) : (FIT_FALSE))
#define UTF8_IS_UNIT_1UNIT(UNIT)             ((((FIT_LARGE_TYPE)(UNIT) & (FIT_LARGE_TYPE)0x80) == (FIT_LARGE_TYPE)0x00) ? (FIT_TRUE) : (FIT_FALSE))
#define UTF8_IS_UNIT_2UNIT_LEAD(UNIT)        ((((FIT_LARGE_TYPE)(UNIT) & (FIT_LARGE_TYPE)0xE0) == (FIT_LARGE_TYPE)0xC0) ? (FIT_TRUE) : (FIT_FALSE))
#define UTF8_IS_UNIT_3UNIT_LEAD(UNIT)        ((((FIT_LARGE_TYPE)(UNIT) & (FIT_LARGE_TYPE)0xF0) == (FIT_LARGE_TYPE)0xE0) ? (FIT_TRUE) : (FIT_FALSE))
#define UTF8_IS_UNIT_4UNIT_LEAD(UNIT)        ((((FIT_LARGE_TYPE)(UNIT) & (FIT_LARGE_TYPE)0xF8) == (FIT_LARGE_TYPE)0xF0) ? (FIT_TRUE) : (FIT_FALSE))
#define UTF8_IS_UNIT_MULTI_CONT(UNIT)        ((((FIT_LARGE_TYPE)(UNIT) & (FIT_LARGE_TYPE)0xC0) == (FIT_LARGE_TYPE)0x80) ? (FIT_TRUE) : (FIT_FALSE))
#define UTF8_IS_POINT_1UNIT(POINT)           (((((FIT_LARGE_TYPE)(POINT) & (FIT_LARGE_TYPE)0x1FFFFF) <= (FIT_LARGE_TYPE)0x00007F)) ? (FIT_TRUE) : (FIT_FALSE))
#define UTF8_IS_POINT_2UNIT(POINT)           (((((FIT_LARGE_TYPE)(POINT) & (FIT_LARGE_TYPE)0x1FFFFF) >= (FIT_LARGE_TYPE)0x000080) && (((FIT_LARGE_TYPE)(POINT) & (FIT_LARGE_TYPE)0x1FFFFF) <= (FIT_LARGE_TYPE)0x0007FF)) ? (FIT_TRUE) : (FIT_FALSE))
#define UTF8_IS_POINT_3UNIT(POINT)           (((((FIT_LARGE_TYPE)(POINT) & (FIT_LARGE_TYPE)0x1FFFFF) >= (FIT_LARGE_TYPE)0x000800) && (((FIT_LARGE_TYPE)(POINT) & (FIT_LARGE_TYPE)0x1FFFFF) <= (FIT_LARGE_TYPE)0x00FFFF)) ? (FIT_TRUE) : (FIT_FALSE))
#define UTF8_IS_POINT_4UNIT(POINT)           (((((FIT_LARGE_TYPE)(POINT) & (FIT_LARGE_TYPE)0x1FFFFF) >= (FIT_LARGE_TYPE)0x010000) && (((FIT_LARGE_TYPE)(POINT) & (FIT_LARGE_TYPE)0x1FFFFF) <= (FIT_LARGE_TYPE)0x10FFFF)) ? (FIT_TRUE) : (FIT_FALSE))
#define UTF8_1UNIT_TO_POINT(UNIT)            ((((FIT_LARGE_TYPE)(UNIT) & (FIT_LARGE_TYPE)0x7F) <<  0))
#define UTF8_2UNIT_TO_POINT(LEAD,C1)         ((((FIT_LARGE_TYPE)(LEAD) & (FIT_LARGE_TYPE)0x1F) <<  6) | (((FIT_LARGE_TYPE)(C1) & (FIT_LARGE_TYPE)0x3F) <<  0))
#define UTF8_3UNIT_TO_POINT(LEAD,C1,C2)      ((((FIT_LARGE_TYPE)(LEAD) & (FIT_LARGE_TYPE)0x0F) << 12) | (((FIT_LARGE_TYPE)(C1) & (FIT_LARGE_TYPE)0x3F) <<  6) | (((FIT_LARGE_TYPE)(C2) & (FIT_LARGE_TYPE)0x3F) <<  0))
#define UTF8_4UNIT_TO_POINT(LEAD,C1,C2,C3)   ((((FIT_LARGE_TYPE)(LEAD) & (FIT_LARGE_TYPE)0x07) << 18) | (((FIT_LARGE_TYPE)(C1) & (FIT_LARGE_TYPE)0x3F) << 12) | (((FIT_LARGE_TYPE)(C2) & (FIT_LARGE_TYPE)0x3F) <<  6) | (((FIT_LARGE_TYPE)(C3) & (FIT_LARGE_TYPE)0x3F) <<  0))
#define UTF8_POINT_TO_1UNIT(POINT)           ((((FIT_LARGE_TYPE)(POINT) >>  0) & (FIT_LARGE_TYPE)0x7F) | (FIT_LARGE_TYPE)0x00)
#define UTF8_POINT_TO_2UNIT_LEAD(POINT)      ((((FIT_LARGE_TYPE)(POINT) >>  6) & (FIT_LARGE_TYPE)0x1F) | (FIT_LARGE_TYPE)0xC0)
#define UTF8_POINT_TO_2UNIT_CONT1(POINT)     ((((FIT_LARGE_TYPE)(POINT) >>  0) & (FIT_LARGE_TYPE)0x3F) | (FIT_LARGE_TYPE)0x80)
#define UTF8_POINT_TO_3UNIT_LEAD(POINT)      ((((FIT_LARGE_TYPE)(POINT) >> 12) & (FIT_LARGE_TYPE)0x0F) | (FIT_LARGE_TYPE)0xE0)
#define UTF8_POINT_TO_3UNIT_CONT1(POINT)     ((((FIT_LARGE_TYPE)(POINT) >>  6) & (FIT_LARGE_TYPE)0x3F) | (FIT_LARGE_TYPE)0x80)
#define UTF8_POINT_TO_3UNIT_CONT2(POINT)     ((((FIT_LARGE_TYPE)(POINT) >>  0) & (FIT_LARGE_TYPE)0x3F) | (FIT_LARGE_TYPE)0x80)
#define UTF8_POINT_TO_4UNIT_LEAD(POINT)      ((((FIT_LARGE_TYPE)(POINT) >> 18) & (FIT_LARGE_TYPE)0x07) | (FIT_LARGE_TYPE)0xF0)
#define UTF8_POINT_TO_4UNIT_CONT1(POINT)     ((((FIT_LARGE_TYPE)(POINT) >> 12) & (FIT_LARGE_TYPE)0x3F) | (FIT_LARGE_TYPE)0x80)
#define UTF8_POINT_TO_4UNIT_CONT2(POINT)     ((((FIT_LARGE_TYPE)(POINT) >>  6) & (FIT_LARGE_TYPE)0x3F) | (FIT_LARGE_TYPE)0x80)
#define UTF8_POINT_TO_4UNIT_CONT3(POINT)     ((((FIT_LARGE_TYPE)(POINT) >>  0) & (FIT_LARGE_TYPE)0x3F) | (FIT_LARGE_TYPE)0x80)

// UTF-16 encoding.
#define UTF16_IS_UNIT_VALID(UNIT)            (FIT_TRUE)  // All units are valid *** for decoding to code points *** (once masked off by 0xFFFF).
#define UTF16_IS_UNIT_1UNIT(UNIT)            (((((FIT_LARGE_TYPE)(UNIT) & (FIT_LARGE_TYPE)0xFFFF)<= (FIT_LARGE_TYPE)0xD7FF) || (((FIT_LARGE_TYPE)(UNIT) & (FIT_LARGE_TYPE)0xFFFF)>= (FIT_LARGE_TYPE)0xE000)) ? (FIT_TRUE) : (FIT_FALSE))
#define UTF16_IS_UNIT_2UNIT_LEAD(UNIT)       (((((FIT_LARGE_TYPE)(UNIT) & (FIT_LARGE_TYPE)0xFFFF)>= (FIT_LARGE_TYPE)0xD800) && (((FIT_LARGE_TYPE)(UNIT) & (FIT_LARGE_TYPE)0xFFFF)<= (FIT_LARGE_TYPE)0xDBFF)) ? (FIT_TRUE) : (FIT_FALSE))
#define UTF16_IS_UNIT_2UNIT_TAIL(UNIT)       (((((FIT_LARGE_TYPE)(UNIT) & (FIT_LARGE_TYPE)0xFFFF)>= (FIT_LARGE_TYPE)0xDC00) && (((FIT_LARGE_TYPE)(UNIT) & (FIT_LARGE_TYPE)0xFFFF)<= (FIT_LARGE_TYPE)0xDFFF)) ? (FIT_TRUE) : (FIT_FALSE))
#define UTF16_IS_POINT_1UNIT(POINT)          (((((FIT_LARGE_TYPE)(POINT) & (FIT_LARGE_TYPE)0x1FFFFF) <= (FIT_LARGE_TYPE)0x00FFFF)) ? (FIT_TRUE) : (FIT_FALSE))
#define UTF16_IS_POINT_2UNIT(POINT)          (((((FIT_LARGE_TYPE)(POINT) & (FIT_LARGE_TYPE)0x1FFFFF) >= (FIT_LARGE_TYPE)0x010000) && (((FIT_LARGE_TYPE)(POINT) & (FIT_LARGE_TYPE)0x1FFFFF) <= (FIT_LARGE_TYPE)0x10FFFF)) ? (FIT_TRUE) : (FIT_FALSE))
#define UTF16_1UNIT_TO_POINT(UNIT)           ((FIT_LARGE_TYPE)(UNIT) & (FIT_LARGE_TYPE)0xFFFF)
#define UTF16_2UNIT_TO_POINT(LEAD,TAIL)      (((((FIT_LARGE_TYPE)(LEAD) & (FIT_LARGE_TYPE)0xFFFF) - (FIT_LARGE_TYPE)0xD800) << 10) + ((((FIT_LARGE_TYPE)(TAIL) & (FIT_LARGE_TYPE)0xFFFF) - (FIT_LARGE_TYPE)0xDC00) <<  0) + (FIT_LARGE_TYPE)0x10000)
#define UTF16_POINT_TO_1UNIT(POINT)          ((FIT_LARGE_TYPE)(POINT) & (FIT_LARGE_TYPE)0xFFFF)
#define UTF16_POINT_TO_2UNIT_LEAD(POINT)     ((((((FIT_LARGE_TYPE)(POINT) & (FIT_LARGE_TYPE)0x1FFFFF) - (FIT_LARGE_TYPE)0x10000) >> 10) & (FIT_LARGE_TYPE)0x3FF) + (FIT_LARGE_TYPE)0xD800)
#define UTF16_POINT_TO_2UNIT_TAIL(POINT)     ((((((FIT_LARGE_TYPE)(POINT) & (FIT_LARGE_TYPE)0x1FFFFF) - (FIT_LARGE_TYPE)0x10000) >>  0) & (FIT_LARGE_TYPE)0x3FF) + (FIT_LARGE_TYPE)0xDC00)

// UTF-32 encoding.
#define UTF32_IS_UNIT_VALID(UNIT)            (FIT_TRUE)  // All units are valid *** for decoding to code points *** (once masked off by 0x1FFFFF).
#define UTF32_UNIT_TO_POINT(UNIT)            ((FIT_LARGE_TYPE)(UNIT) & (FIT_LARGE_TYPE)0x1FFFFF)
#define UTF32_POINT_TO_UNIT(POINT)           ((FIT_LARGE_TYPE)(POINT) & (FIT_LARGE_TYPE)0x1FFFFF)

namespace fit
{

///////////////////////////////////////////////////////////////////////
// Private Classes
///////////////////////////////////////////////////////////////////////

class StringConversionException : public RuntimeException
{
   public:
      StringConversionException(const FIT_STRING_CONVERSION_ERROR newErrorCode = FIT_STRING_CONVERSION_ERROR_INVALID)
         : RuntimeException(std::string("")),
           errorCode(newErrorCode)
      {
      }

   private:
      FIT_STRING_CONVERSION_ERROR errorCode;
};

///////////////////////////////////////////////////////////////////////
// Private Functions
///////////////////////////////////////////////////////////////////////

template <typename STRING_TYPE_DST, typename CHAR_TYPE_DST, typename STRING_TYPE_SRC, typename CHAR_TYPE_SRC>
FIT_BOOL ConvertStringEncoding(STRING_TYPE_DST& strDst, const FIT_UNICODE_ENCODING dstEncoding, const STRING_TYPE_SRC& strSrc, const FIT_UNICODE_ENCODING srcEncoding)
{
   STRING_TYPE_DST convertedStr;

   for (unsigned long int i = 0; i < strSrc.size(); ++i)
   {
      try
      {
         FIT_LARGE_TYPE codePoint = 0;

         // Decode the source.
         switch (srcEncoding)
         {
            case FIT_UNICODE_ENCODING_UTF8:
            {
               if (!UTF8_IS_UNIT_VALID(strSrc[i]))
                  throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UTF8_INVALID_UNIT);

               unsigned long int numUnits = 0;

               if (UTF8_IS_UNIT_1UNIT(strSrc[i]))
                  numUnits = 1;
               else if (UTF8_IS_UNIT_2UNIT_LEAD(strSrc[i]))
                  numUnits = 2;
               else if (UTF8_IS_UNIT_3UNIT_LEAD(strSrc[i]))
                  numUnits = 3;
               else if (UTF8_IS_UNIT_4UNIT_LEAD(strSrc[i]))
                  numUnits = 4;
               else
                  throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UTF8_INVALID_LEAD_UNIT);

               unsigned long int numContUnits = numUnits - 1;

               while (numContUnits--)
               {
                  if ((++i) >= strSrc.size())
                     throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UTF8_END_OF_STRING);

                  if (!UTF8_IS_UNIT_MULTI_CONT(strSrc[i]))
                     throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UTF8_NON_CONTINUATION_UNIT);

                  if (!UTF8_IS_UNIT_VALID(strSrc[i]))
                     throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UTF8_INVALID_CONTINUATION_UNIT);
               }

               switch (numUnits)
               {
                  case 1:
                     codePoint = UTF8_1UNIT_TO_POINT(strSrc[i]);
                     if (!UTF8_IS_POINT_1UNIT(codePoint))
                        throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UTF8_OVERENCODED_POINT_1);
                     break;
                  case 2:
                     codePoint = UTF8_2UNIT_TO_POINT(strSrc[i-1], strSrc[i]);
                     if (!UTF8_IS_POINT_2UNIT(codePoint))
                        throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UTF8_OVERENCODED_POINT_2);
                     break;
                  case 3:
                     codePoint = UTF8_3UNIT_TO_POINT(strSrc[i-2], strSrc[i-1], strSrc[i]);
                     if (!UTF8_IS_POINT_3UNIT(codePoint))
                        throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UTF8_OVERENCODED_POINT_3);
                     break;
                  case 4:
                     codePoint = UTF8_4UNIT_TO_POINT(strSrc[i-3], strSrc[i-2], strSrc[i-1], strSrc[i]);
                     if (!UTF8_IS_POINT_4UNIT(codePoint))
                        throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UTF8_OVERENCODED_POINT_4);
                     break;
               }
            }
            break;

            case FIT_UNICODE_ENCODING_UTF16:
            {
               if (!UTF16_IS_UNIT_VALID(strSrc[i]))
                  throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UTF16_INVALID_UNIT);

               if (UTF16_IS_UNIT_1UNIT(strSrc[i]))
               {
                  codePoint = static_cast<FIT_LARGE_TYPE>(UTF16_1UNIT_TO_POINT(strSrc[i]));

                  if (!UTF16_IS_POINT_1UNIT(codePoint))
                     throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UTF16_OVERENCODED_POINT_1);
               }
               else if (UTF16_IS_UNIT_2UNIT_LEAD(strSrc[i]))
               {
                  if ((++i) >= strSrc.size())
                     throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UTF16_END_OF_STRING);

                  if (!UTF16_IS_UNIT_2UNIT_TAIL(strSrc[i]))
                     throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UTF16_NON_TAIL_UNIT);

                  if (!UTF16_IS_UNIT_VALID(strSrc[i]))
                     throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UTF16_INVALID_TAIL_UNIT);

                  codePoint = static_cast<FIT_LARGE_TYPE>(UTF16_2UNIT_TO_POINT(strSrc[i-1], strSrc[i]));

                  if (!UTF16_IS_POINT_2UNIT(codePoint))
                      throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UTF16_OVERENCODED_POINT_2);
               }
               else
               {
                  throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UTF16_INVALID_LEAD_UNIT);
               }
            }
            break;

            case FIT_UNICODE_ENCODING_UTF32:
            {
               if (!UTF32_IS_UNIT_VALID(strSrc[i]))
                  throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UTF32_INVALID_UNIT);
               
               codePoint = static_cast<FIT_LARGE_TYPE>(UTF32_UNIT_TO_POINT(strSrc[i]));
            }
            break;

            default:
               throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UNICODE_UNDEFINED_SOURCE_ENCODING);
         }

         // Check that the code point is valid.
         if (!UNICODE_IS_POINT_VALID(codePoint))
            throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UNICODE_INVALID_POINT);

         // Encode the destination.
         switch (dstEncoding)
         {
            case FIT_UNICODE_ENCODING_UTF8:
               if (UTF8_IS_POINT_1UNIT(codePoint))
               {
                  convertedStr.push_back((CHAR_TYPE_DST) UTF8_POINT_TO_1UNIT(codePoint));
               }
               else if (UTF8_IS_POINT_2UNIT(codePoint))
               {
                  convertedStr.push_back((CHAR_TYPE_DST) UTF8_POINT_TO_2UNIT_LEAD(codePoint));
                  convertedStr.push_back((CHAR_TYPE_DST) UTF8_POINT_TO_2UNIT_CONT1(codePoint));
               }
               else if (UTF8_IS_POINT_3UNIT(codePoint))
               {
                  convertedStr.push_back((CHAR_TYPE_DST) UTF8_POINT_TO_3UNIT_LEAD(codePoint));
                  convertedStr.push_back((CHAR_TYPE_DST) UTF8_POINT_TO_3UNIT_CONT1(codePoint));
                  convertedStr.push_back((CHAR_TYPE_DST) UTF8_POINT_TO_3UNIT_CONT2(codePoint));
               }
               else if (UTF8_IS_POINT_4UNIT(codePoint))
               {
                  convertedStr.push_back((CHAR_TYPE_DST) UTF8_POINT_TO_4UNIT_LEAD(codePoint));
                  convertedStr.push_back((CHAR_TYPE_DST) UTF8_POINT_TO_4UNIT_CONT1(codePoint));
                  convertedStr.push_back((CHAR_TYPE_DST) UTF8_POINT_TO_4UNIT_CONT2(codePoint));
                  convertedStr.push_back((CHAR_TYPE_DST) UTF8_POINT_TO_4UNIT_CONT3(codePoint));
               }
               else
               {
                  throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UTF8_INVALID_NUM_UNITS);
               }
               break;

            case FIT_UNICODE_ENCODING_UTF16:
               if (UTF16_IS_POINT_1UNIT(codePoint))
               {
                  convertedStr.push_back((CHAR_TYPE_DST) UTF16_POINT_TO_1UNIT(codePoint));
               }
               else if (UTF16_IS_POINT_2UNIT(codePoint))
               {
                  convertedStr.push_back((CHAR_TYPE_DST) UTF16_POINT_TO_2UNIT_LEAD(codePoint));
                  convertedStr.push_back((CHAR_TYPE_DST) UTF16_POINT_TO_2UNIT_TAIL(codePoint));
               }
               else
               {
                  throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UTF16_INVALID_NUM_UNITS);
               }
               break;

            case FIT_UNICODE_ENCODING_UTF32:
               convertedStr.push_back((CHAR_TYPE_DST) UTF32_POINT_TO_UNIT(codePoint));
               break;

            default:
               throw StringConversionException(FIT_STRING_CONVERSION_ERROR_UNICODE_UNDEFINED_DESTINATION_ENCODING);
         }

      }  // end try
      catch (const StringConversionException&)
      {
         continue;   // Go to the next character.
      }
   }

   strDst = convertedStr;
   return FIT_TRUE;
}


///////////////////////////////////////////////////////////////////////
// Public Functions
///////////////////////////////////////////////////////////////////////

Unicode::UTF8_STRING Unicode::Encode_BaseToUTF8(const FIT_WSTRING& strSrc)
{
   Unicode::UTF8_STRING strDst;
   if (ConvertStringEncoding<Unicode::UTF8_STRING, Unicode::UTF8_STRING::value_type, FIT_WSTRING, FIT_WSTRING::value_type>(strDst, FIT_UNICODE_ENCODING_UTF8, strSrc, INTERNAL_UNICODE_ENCODING))
      return strDst;
   else
      return Unicode::UTF8_STRING();
}

FIT_WSTRING Unicode::Encode_UTF8ToBase(const Unicode::UTF8_STRING& strSrc)
{
   FIT_WSTRING strDst;
   if (ConvertStringEncoding<FIT_WSTRING, FIT_WSTRING::value_type, Unicode::UTF8_STRING, Unicode::UTF8_STRING::value_type>(strDst, INTERNAL_UNICODE_ENCODING, strSrc, FIT_UNICODE_ENCODING_UTF8))
      return strDst;
   else
      return FIT_WSTRING_INVALID;
}

Unicode::UTF8_STRING Unicode::Copy_StdToUTF8(const std::string& strSrc)
{
#if 0
   Unicode::UTF8_STRING strDst(static_cast<Unicode::UTF8_STRING::size_type>(strSrc.size()), 0);

   for (Unicode::UTF8_STRING::size_type i = 0; i < strDst.size(); i++)
      strDst[i] = static_cast<Unicode::UTF8_STRING::value_type>(strSrc[i]);

   return strDst;
#endif

   return strSrc; // Input type is typedef'd to be the same as output - this shortcut is valid.
}

std::string Unicode::Copy_UTF8ToStd(const Unicode::UTF8_STRING& strSrc)
{
#if 0
   string strDst(static_cast<string::size_type>(strSrc.size()), 0);

   for (std::string::size_type i = 0; i < strDst.size(); i++)
      strDst[i] = static_cast<string::value_type>(strSrc[i]);

   return strDst;
#endif

   return strSrc; // Input type is typedef'd to be the same as output - this shortcut is valid.
}

} // namespace fit
