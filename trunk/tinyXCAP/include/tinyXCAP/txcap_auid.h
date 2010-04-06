/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou(at)doubango.org>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/
/**@file txcap_auid.h
 * @brief XCAP AUID manager.
 *
 * @author Mamadou Diop <diopmamadou(at)doubango.org>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#ifndef TINYXCAP_TXCAP_AUID_H
#define TINYXCAP_TXCAP_AUID_H

#include "tinyXCAP_config.h"

#include "tsk_list.h"

TXCAP_BEGIN_DECLS

#define TXCAP_AUID_CREATE(type, id, content_type, document_name)	tsk_object_new(txcap_auid_def_t, (txcap_auid_type_t)type, (const char*)id, (const char*)content_type, (const char*)document_name)

/** List of supported AUIDs.
*/
typedef enum txcap_auid_type_e
{
	tauid_ietf_xcap_caps,			/**< xcap-caps */
	tauid_ietf_resource_lists,	/**< resource-lists */
	tauid_ietf_rls_services,		/**< rls-services */
	tauid_ietf_pres_rules,		/**< pres-rules */
	tauid_ietf_directory,			/**< directory */

	tauid_oma_conv_history,		/**< org.openmobilealliance.conv-history */
	tauid_oma_pres_rules,			/**< org.openmobilealliance.pres-rules */
	tauid_oma_directory,			/**< org.openmobilealliance.xcap-directory */
	tauid_oma_deferred_list,		/**< org.openmobilealliance.deferred-list */
	tauid_oma_pres_content,		/**< org.openmobilealliance.pres-content*/
	tauid_oma_shared_groups		/**< org.openmobilealliance.groups */
}
txcap_auid_type_t;

/** XCAP AUID.
*/
typedef struct txcap_auid_s
{
	TSK_DECLARE_OBJECT;

	txcap_auid_type_t type;
	char* id; /**< The id of the AUID (e.g. 'xcap-caps' or 'rls-services' or 'resource-lists' or ...)*/
	char* content_type; /**< The default MIME-type of the document associated to this auid. */
	char* document_name; /**< The default name of the document associated to this auid. */
}
txcap_auid_t;

typedef tsk_list_t txcap_auids_L_t;

TINYXCAP_GEXTERN const tsk_object_def_t *txcap_auid_def_t;

TXCAP_END_DECLS

#endif // TINYXCAP_TXCAP_AUID_H
