/***************************************************************************************************

  Zyan Disassembler Library (Zydis)

  Original Author : Joel H�ner

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.

***************************************************************************************************/

#ifndef ZYDIS_ENCODER_H
#define ZYDIS_ENCODER_H

#include <Zydis/Defines.h>
#include <Zydis/Types.h>
#include <Zydis/Status.h>
#include <Zydis/InstructionInfo.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================================================== */
/* Types                                                                                          */
/* ============================================================================================== */

/**
 * @brief   Defines the @c ZydisInstructionEncoder struct.
 *
 * All fields in this struct are private and may change anytime.
 */
typedef struct ZydisInstructionEncoder_
{
    /**
    * @brief   The output buffer.
    */
    struct
    {
        uint8_t* buffer;
        size_t bufferLen;
    } output;
} ZydisInstructionEncoder;

/* ============================================================================================== */
/* Exported functions                                                                             */
/* ============================================================================================== */

/**
 * @brief   Initializes the given @c ZydisInstructionEncoder instance.
 * @param   decoder  A pointer to the @c ZydisInstructionEncoder instance.             
 * @return  A zydis status code.
 */
ZYDIS_EXPORT ZydisStatus ZydisEncoderInitInstructionEncoder(ZydisInstructionEncoder* encoder);

/**
 * @brief   Encodes the given instruction info to byte-code.
 *
 * @param   encoder     A pointer to the @c ZydisInstructionEncoder instance.
 * @param   buffer      A pointer to the output buffer.
 * @param   bufferLen   The length of the output buffer.
 * @param   info        A pointer to the @c ZydisInstructionInfo struct to be encoded.
 *
 * @return  A zydis status code. 
 */
ZYDIS_EXPORT ZydisStatus ZydisEncoderEncodeInstruction(ZydisInstructionEncoder* encoder,
    const void* buffer, size_t bufferLen, ZydisInstructionInfo* info);

/* ============================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* ZYDIS_ENCODER_H */
