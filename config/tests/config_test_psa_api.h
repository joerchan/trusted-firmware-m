/*
 * Copyright (c) 2022, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __CONFIG_TEST_PSA_API_H__
#define __CONFIG_TEST_PSA_API_H__

/* Platform Partition Configs */

/* Size of input buffer in platform service */
#define PLATFORM_SERVICE_INPUT_BUFFER_SIZE     64

/* Size of output buffer in platform service */
#define PLATFORM_SERVICE_OUTPUT_BUFFER_SIZE    64

/* The stack size of the Platform Secure Partition */
#define PLATFORM_SP_STACK_SIZE                 0x500

/* Disable Non-volatile counter module */
#define PLATFORM_NV_COUNTER_MODULE_DISABLED    0

/* Crypto Partition Configs */

/*
 * Heap size for the crypto backend
 * CRYPTO_ENGINE_BUF_SIZE needs to be much larger for PSA API tests.
 */
#define CRYPTO_ENGINE_BUF_SIZE                 0x5000

/* The max number of concurrent operations that can be active (allocated) at any time in Crypto */
#define CRYPTO_CONC_OPER_NUM                   8

/* Disable PSA Crypto random number generator module */
#define CRYPTO_RNG_MODULE_DISABLED             0

/* Disable PSA Crypto Key module */
#define CRYPTO_KEY_MODULE_DISABLED             0

/* Disable PSA Crypto AEAD module */
#define CRYPTO_AEAD_MODULE_DISABLED            0

/* Disable PSA Crypto MAC module */
#define CRYPTO_MAC_MODULE_DISABLED             0

/* Disable PSA Crypto Hash module */
#define CRYPTO_HASH_MODULE_DISABLED            0

/* Disable PSA Crypto Cipher module */
#define CRYPTO_CIPHER_MODULE_DISABLED          0

/* Disable PSA Crypto asymmetric key signature module */
#define CRYPTO_ASYM_SIGN_MODULE_DISABLED       0

/* Disable PSA Crypto asymmetric key encryption module */
#define CRYPTO_ASYM_ENCRYPT_MODULE_DISABLED    0

/* Disable PSA Crypto key derivation module */
#define CRYPTO_KEY_DERIVATION_MODULE_DISABLED  0

/* Default size of the internal scratch buffer used for PSA FF IOVec allocations */
#define CRYPTO_IOVEC_BUFFER_SIZE               5120

/* Use stored NV seed to provide entropy */
#define CRYPTO_NV_SEED                         1

/*
 * Only enable multi-part operations in Hash, MAC, AEAD and symmetric ciphers,
 * to optimize memory footprint in resource-constrained devices.
 */
#define CRYPTO_SINGLE_PART_FUNCS_DISABLED      0

/* The stack size of the Crypto Secure Partition */
#define CRYPTO_STACK_SIZE                      0x1B00

/* FWU Partition Configs */

/* Size of the FWU internal data transfer buffer */
#define TFM_FWU_BUF_SIZE                       PSA_FWU_MAX_WRITE_SIZE

/* The stack size of the Firmware Update Secure Partition */
#define FWU_STACK_SIZE                         0x600

/* Attest Partition Configs */

/* Include optional claims in initial attestation token */
#define ATTEST_INCLUDE_OPTIONAL_CLAIMS         1

/* Include COSE key-id in initial attestation token */
#define ATTEST_INCLUDE_COSE_KEY_ID             0

/* The stack size of the Initial Attestation Secure Partition */
#define ATTEST_STACK_SIZE                      0x700

/* Set the initial attestation token profile */
#define ATTEST_TOKEN_PROFILE_PSA_IOT_1         1

/* ITS Partition Configs */

/* Create flash FS if it doesn't exist for Internal Trusted Storage partition */
#define ITS_CREATE_FLASH_LAYOUT                1

/* Enable emulated RAM FS for platforms that don't have flash for Internal Trusted Storage partition */
#define ITS_RAM_FS                             0

/* Validate filesystem metadata every time it is read from flash */
#define ITS_VALIDATE_METADATA_FROM_FLASH       1

/* The maximum asset size to be stored in the Internal Trusted Storage */
#define ITS_MAX_ASSET_SIZE                     512

/*
 * Size of the ITS internal data transfer buffer
 * (Default to the max asset size so that all requests can be handled in one iteration.)
 */
#define ITS_BUF_SIZE                           ITS_MAX_ASSET_SIZE

/* The maximum number of assets to be stored in the Internal Trusted Storage */
#define ITS_NUM_ASSETS                         10

/* The stack size of the Internal Trusted Storage Secure Partition */
#define ITS_STACK_SIZE                         0x720

#endif /* __CONFIG_TEST_PSA_API_H__ */
