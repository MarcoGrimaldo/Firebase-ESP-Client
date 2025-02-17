/**
 * Created February 17, 2021
 * 
 * This work is a part of Firebase ESP Client library
 * Copyright (c) 2021, K. Suwatchai (Mobizt)
 * 
 * The MIT License (MIT)
 * Copyright (c) 2021, K. Suwatchai (Mobizt)
 * 
 * 
 * Permission is hereby granted, free of charge, to any person returning a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef FB_HTTP_CODE_H_
#define FB_HTTP_CODE_H_

#define FIREBASE_DEFAULT_TCP_TIMEOUT 10000 //10 seconds

/// HTTP client errors
#define FIREBASE_ERROR_HTTPC_ERROR_CONNECTION_REFUSED (-1)
#define FIREBASE_ERROR_HTTPC_ERROR_SEND_HEADER_FAILED (-2)
#define FIREBASE_ERROR_HTTPC_ERROR_SEND_PAYLOAD_FAILED (-3)
#define FIREBASE_ERROR_HTTPC_ERROR_NOT_CONNECTED (-4)
#define FIREBASE_ERROR_HTTPC_ERROR_CONNECTION_LOST (-5)
#define FIREBASE_ERROR_HTTPC_ERROR_NO_STREAM (-6)
#define FIREBASE_ERROR_HTTPC_ERROR_NO_HTTP_SERVER (-7)
#define FIREBASE_ERROR_HTTPC_ERROR_TOO_LESS_RAM (-8)
#define FIREBASE_ERROR_HTTPC_ERROR_ENCODING (-9)
#define FIREBASE_ERROR_HTTPC_ERROR_STREAM_WRITE (-10)
#define FIREBASE_ERROR_HTTPC_ERROR_READ_TIMEOUT (-11)
#define FIREBASE_ERROR_BUFFER_OVERFLOW (-12)
#define FIREBASE_ERROR_DATA_TYPE_MISMATCH -13
#define FIREBASE_ERROR_PATH_NOT_EXIST -14
#define FIREBASE_ERROR_HTTPC_ERROR_CONNECTION_INUSED -15
#define FIREBASE_ERROR_HTTPC_NO_FCM_REGISTRATION_ID_PROVIDED -16
#define FIREBASE_ERROR_HTTPC_NO_FCM_SERVER_KEY_PROVIDED -17
#define FIREBASE_ERROR_HTTPC_FCM_OAUTH2_REQUIRED -18
#define FIREBASE_ERROR_HTTPC_MAX_REDIRECT_REACHED -19
#define FIREBASE_ERROR_EXPECTED_JSON_DATA -20
#define FIREBASE_ERROR_CANNOT_CONFIG_TIME -21
#define FIREBASE_ERROR_SSL_RX_BUFFER_SIZE_TOO_SMALL -22
#define FIREBASE_ERROR_FILE_IO_ERROR -23
#define FIREBASE_ERROR_FILE_NOT_FOUND -24
#define FIREBASE_ERROR_ARCHIVE_NOT_FOUND -25
#define FIREBASE_ERROR_UNINITIALIZED -26

#define FIREBASE_ERROR_TOKEN_SET_TIME -27
#define FIREBASE_ERROR_TOKEN_CREATE_HASH -28
#define FIREBASE_ERROR_TOKEN_PARSE_PK -29
#define FIREBASE_ERROR_TOKEN_SIGN -30
#define FIREBASE_ERROR_TOKEN_EXCHANGE -31
#define FIREBASE_ERROR_TOKEN_EXCHANGE_MAX_RETRY_REACHED -32
#define FIREBASE_ERROR_TOKEN_NOT_READY -33
#define FIREBASE_ERROR_LONG_RUNNING_TASK -34
#define FIREBASE_ERROR_UPLOAD_TIME_OUT -35
#define FIREBASE_ERROR_UPLOAD_DATA_ERRROR -36

#define FIREBASE_ERROR_HTTPC_NO_FCM_TOPIC_PROVIDED -37
#define FIREBASE_ERROR_HTTPC_NO_FCM_DEVICE_TOKEN_PROVIDED -38
#define FIREBASE_ERROR_HTTPC_NO_FCM_INDEX_NOT_FOUND_IN_DEVICE_TOKEN_PROVIDED -39

#define FIREBASE_ERROR_HTTP_CODE_UNDEFINED -1000

/// HTTP codes see RFC7231

#define FIREBASE_ERROR_HTTP_CODE_OK 200
#define FIREBASE_ERROR_HTTP_CODE_NON_AUTHORITATIVE_INFORMATION 203
#define FIREBASE_ERROR_HTTP_CODE_NO_CONTENT 204
#define FIREBASE_ERROR_HTTP_CODE_MOVED_PERMANENTLY 301
#define FIREBASE_ERROR_HTTP_CODE_FOUND 302
#define FIREBASE_ERROR_HTTP_CODE_USE_PROXY 305
#define FIREBASE_ERROR_HTTP_CODE_TEMPORARY_REDIRECT 307
#define FIREBASE_ERROR_HTTP_CODE_PERMANENT_REDIRECT 308
#define FIREBASE_ERROR_HTTP_CODE_BAD_REQUEST 400
#define FIREBASE_ERROR_HTTP_CODE_UNAUTHORIZED 401
#define FIREBASE_ERROR_HTTP_CODE_FORBIDDEN 403
#define FIREBASE_ERROR_HTTP_CODE_NOT_FOUND 404
#define FIREBASE_ERROR_HTTP_CODE_METHOD_NOT_ALLOWED 405
#define FIREBASE_ERROR_HTTP_CODE_NOT_ACCEPTABLE 406
#define FIREBASE_ERROR_HTTP_CODE_PROXY_AUTHENTICATION_REQUIRED 407
#define FIREBASE_ERROR_HTTP_CODE_REQUEST_TIMEOUT 408
#define FIREBASE_ERROR_HTTP_CODE_LENGTH_REQUIRED 411
#define FIREBASE_ERROR_HTTP_CODE_PRECONDITION_FAILED 412
#define FIREBASE_ERROR_HTTP_CODE_PAYLOAD_TOO_LARGE 413
#define FIREBASE_ERROR_HTTP_CODE_URI_TOO_LONG 414
#define FIREBASE_ERROR_HTTP_CODE_MISDIRECTED_REQUEST 421
#define FIREBASE_ERROR_HTTP_CODE_UNPROCESSABLE_ENTITY 422
#define FIREBASE_ERROR_HTTP_CODE_TOO_MANY_REQUESTS 429
#define FIREBASE_ERROR_HTTP_CODE_REQUEST_HEADER_FIELDS_TOO_LARGE 431
#define FIREBASE_ERROR_HTTP_CODE_INTERNAL_SERVER_ERROR 500
#define FIREBASE_ERROR_HTTP_CODE_NOT_IMPLEMENTED 501
#define FIREBASE_ERROR_HTTP_CODE_BAD_GATEWAY 502
#define FIREBASE_ERROR_HTTP_CODE_SERVICE_UNAVAILABLE 503
#define FIREBASE_ERROR_HTTP_CODE_GATEWAY_TIMEOUT 504
#define FIREBASE_ERROR_HTTP_CODE_HTTP_VERSION_NOT_SUPPORTED 505
#define FIREBASE_ERROR_HTTP_CODE_LOOP_DETECTED 508
#define FIREBASE_ERROR_HTTP_CODE_NETWORK_AUTHENTICATION_REQUIRED 511

#endif