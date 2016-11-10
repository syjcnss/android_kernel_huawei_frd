
#ifndef  NAS_CC_ENTITY_MGMT_H
#define  NAS_CC_ENTITY_MGMT_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)

/*****************************************************************************
  1 ͷ�ļ�����
*****************************************************************************/
#include "vos.h"
#include "NasCcCommon.h"
#include "NasCcCtx.h"
#include "NasCcIe.h"
#include "NasSsIe.h"
#include "NasCcInclude.h"
#include "MmCcInterface.h"

/*****************************************************************************
  2 ���Ͷ���
*****************************************************************************/
/* MPTY�¼� */
typedef enum
{
    NAS_CC_MPTY_EVT_INVOKE,                                                     /* ������һ��MPTY���� */
    NAS_CC_MPTY_EVT_SUCCESS,                                                    /* MPTY�����ɹ� */
    NAS_CC_MPTY_EVT_FAIL,                                                       /* MPTY����ʧ�� */
    NAS_CC_MPTY_EVT_MAX
} NAS_CC_MPTY_EVT_ENUM;


/* DTMF״̬ */
typedef enum
{
    NAS_CC_DTMF_S_IDLE,                                                         /* ���У����Է����µ�DTMF���� */
    NAS_CC_DTMF_S_START_REQ,                                                    /* �Ѿ������緢��START DTMF��Ϣ����δ�յ��ظ� */
    NAS_CC_DTMF_S_STOP_REQ,                                                     /* �Ѿ������緢��STOP DTMF��Ϣ����δ�յ��ظ� */

    NAS_CC_DTMF_S_START_REJ,                                                    /* �յ������start dtmf rej��Ϣ*/

    NAS_CC_DTMF_S_UNKNOWN
} NAS_CC_DTMF_STATE_ENUM;

/* DTMF����״̬ */
typedef enum
{
    NAS_CC_DTMF_Q_NULL,                                                         /* ������Ϊ��*/
    NAS_CC_DTMF_Q_START_REQ,                                                    /* ��������ΪSTART DTMF��Ϣ*/
    NAS_CC_DTMF_Q_STOP_REQ,                                                     /* ��������ΪSTOP DTMF��Ϣ*/
    NAS_CC_DTMF_Q_UNKNOWN
} NAS_CC_DTMF_Q_STATE_ENUM;

/* DTMF�������� */
enum NAS_CC_DTMF_REQ_ENUM
{
    NAS_CC_DTMF_START_REQ,
    NAS_CC_DTMF_STOP_REQ,
    NAS_CC_DTMF_REQ_BUTT
};
typedef VOS_UINT8  NAS_CC_DTMF_REQ_ENUM_U8;


/* ���������������� */
enum NAS_CC_BC_PARAM_IDX_ENUM
{
    NAS_CC_BC_PARAM_1,                                                          /* ����BC1�Ĳ��� */
    NAS_CC_BC_PARAM_2,                                                          /* ����BC2�Ĳ��� */
    NAS_CC_BC_PARAM_CURR                                                        /* ��ǰʹ�õ�BC���� */
};
typedef VOS_UINT8  NAS_CC_BC_PARAM_IDX_ENUM_U8;


enum NAS_CC_OM_MSG_ID_ENUM
{
    /* CC���͸�OM����Ϣ */
    CCOM_LOG_STATE_INFO_IND                       = 0x1000,      /*_H2ASN_MsgChoice  NAS_CC_LOG_STATE_INFO_STRU */
    CCOM_LOG_BUFFER_MSG_INFO_IND                  = 0x1001,      /*_H2ASN_MsgChoice  NAS_CC_LOG_BUFFER_MSG_INFO_STRU */
    CCOM_LOG_BUTT
};
typedef VOS_UINT32 NAS_CC_OM_MSG_ID_ENUM_UINT32;

#define NAS_CC_MAX_BC_PARAM_NUM    (NAS_CC_BC_PARAM_2 + 1)


/* �������������ṹ */
typedef struct
{
    NAS_CC_INFO_TRANSFER_CAP_ENUM_U8    enItc;
} NAS_CC_BC_PARAMS_STRU;

typedef void (*NAS_CC_FUNC_VOID)(void);


typedef struct
{
    NAS_CC_SS_SWITCH_STATE_ENUM_UINT8   enHoldState;                            /* ���б���ҵ���л�״̬ */
    NAS_CC_SS_SWITCH_STATE_ENUM_UINT8   enRetrieveState;                        /* ���лָ�ҵ���л�״̬ */
    NAS_CC_FUNC_VOID                    pFunc;
} NAS_CC_SS_SWITCH_PROC_FUNC_MAP_STRU;


typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;/* ��Ϣͷ */ /*_H2ASN_Skip*/
    NAS_CC_CALL_STATE_ENUM_U8           enCcState;
    VOS_UINT8                           aucRsv3[3];
}NAS_CC_LOG_STATE_INFO_STRU;




/*****************************************************************************
  3 ��������
*****************************************************************************/

VOS_VOID  NAS_CC_InitEntities(VOS_VOID);



VOS_UINT32  NAS_CC_CreateEntity(
    NAS_CC_CALL_TYPE_ENUM_U8            enCallType,
    VOS_UINT8                           ucCallId,
    VOS_UINT8                           ucTi,
    NAS_CC_ENTITY_ID_T                  *pEntityId
);



VOS_VOID  NAS_CC_DeleteEntity(
    NAS_CC_ENTITY_ID_T                  entityId
);



NAS_CC_ENTITY_ID_T  NAS_CC_GetEntityByTi(
    VOS_UINT8                           ucTi
);



VOS_UINT8  NAS_CC_GetEntityTi(
    NAS_CC_ENTITY_ID_T                  entityId
);



VOS_UINT8  NAS_CC_GetCallId(
    NAS_CC_ENTITY_ID_T                  entityId
);




VOS_VOID  NAS_CC_UpdateCallId(
    NAS_CC_ENTITY_ID_T                  entityId,
    VOS_UINT8                           ucCallId
);



VOS_VOID  NAS_CC_UpdateBcParams(
    NAS_CC_ENTITY_ID_T                  entityId,
    NAS_CC_BC_PARAM_IDX_ENUM_U8         enIdx,
    const NAS_CC_BC_PARAMS_STRU         *pstParams
);



VOS_VOID  NAS_CC_GetBcParams(
    NAS_CC_ENTITY_ID_T                  entityId,
    NAS_CC_BC_PARAM_IDX_ENUM_U8         enIdx,
    NAS_CC_BC_PARAMS_STRU               *pstParams
);



VOS_VOID  NAS_CC_BcAlertnate(
    NAS_CC_ENTITY_ID_T                  entityId
);



NAS_CC_CALL_STATE_ENUM_U8  NAS_CC_GetCallState(
    NAS_CC_ENTITY_ID_T                  entityId
);



VOS_VOID  NAS_CC_ChangeCallState(
    NAS_CC_ENTITY_ID_T                  entityId,
    NAS_CC_CALL_STATE_ENUM_U8           enState
);



NAS_CC_HOLD_AUX_STATE_ENUM_U8 NAS_CC_GetHoldAuxState(
    NAS_CC_ENTITY_ID_T                  entityId
);



VOS_VOID  NAS_CC_ChangeHoldAuxState(
    NAS_CC_ENTITY_ID_T                  entityId,
    NAS_CC_HOLD_AUX_STATE_ENUM_U8       state
);



NAS_CC_MPTY_AUX_STATE_ENUM_U8 NAS_CC_GetMptyAuxState(
    NAS_CC_ENTITY_ID_T                  entityId
);



VOS_VOID  NAS_CC_ChangeMptyAuxState(
    NAS_CC_ENTITY_ID_T                  entityId,
    NAS_CC_MPTY_AUX_STATE_ENUM_U8       enState
);



VOS_UINT32 NAS_CC_CheckMptyOperation(
    NAS_CC_ENTITY_ID_T                  entityId,
    NAS_SS_OPERATION_ENUM_U8            enSsOperation
);



VOS_VOID  NAS_CC_HandleMptyEvent(
    NAS_CC_ENTITY_ID_T                  entityId,
    NAS_CC_MPTY_EVT_ENUM                enMptyEvent,
    NAS_SS_OPERATION_ENUM_U8            enSsOperation
);



NAS_CC_DTMF_STATE_ENUM  NAS_CC_GetDtmfState(
    NAS_CC_ENTITY_ID_T                  entityId
);



VOS_VOID  NAS_CC_ChangeDtmfState(
    NAS_CC_ENTITY_ID_T                  entityId,
    NAS_CC_DTMF_STATE_ENUM              enState
);



VOS_VOID  NAS_CC_QueueDtmfReq(
    NAS_CC_ENTITY_ID_T                  entityId,
    NAS_CC_DTMF_REQ_ENUM_U8             enDtmfReq,
    VOS_UINT8                           ucKey
);



VOS_VOID  NAS_CC_SendBufferedDtmfReq(
    NAS_CC_ENTITY_ID_T                  entityId
);



VOS_VOID NAS_CC_StoreSsOperation(
    NAS_CC_ENTITY_ID_T                  entityId,
    VOS_UINT8                           ucInvokeId,
    NAS_SS_OPERATION_ENUM_U8            enSsOperation
);



VOS_UINT32 NAS_CC_RestoreSsOperation(
    NAS_CC_ENTITY_ID_T                  entityId,
    VOS_UINT8                           ucInvokeId,
    NAS_SS_OPERATION_ENUM_U8            *penSsOperation
);



VOS_UINT32 NAS_CC_GetStoredSsOperation(
    NAS_CC_ENTITY_ID_T                  entityId,
    VOS_UINT8                           ucInvokeId,
    NAS_SS_OPERATION_ENUM_U8            *penSsOperation
);


VOS_VOID  NAS_CC_SetStartT310Flag(
    NAS_CC_ENTITY_ID_T                  entityId,
    VOS_UINT32                          ulSet
);



VOS_UINT32 NAS_CC_GetStartT310Flag(
    NAS_CC_ENTITY_ID_T                  entityId
);


VOS_BOOL  NAS_CC_IsAllowNewMtCall(VOS_VOID);

VOS_VOID NAS_CC_FlushDTMFBuff(
    NAS_CC_ENTITY_ID_T                  entityId
);

VOS_VOID NAS_CC_SndOutsideContextData(VOS_VOID);

NAS_CC_CALL_TYPE_ENUM_U8  NAS_CC_GetCallType(
    NAS_CC_ENTITY_ID_T                  entityId
);

VOS_BOOL  NAS_CC_IsSpecCallEntityInUse(
    NAS_CC_ENTITY_ID_T                  entityId
);




#ifdef __PS_WIN32_RECUR__

VOS_UINT32 NAS_CC_RestoreContextData(struct MsgCB * pMsg);
#endif



VOS_VOID  NAS_CC_ProcAtPrimitive(
    const VOS_VOID                      *pMsg
);


VOS_VOID  NAS_CC_ProcAtCcStateQry(
    const VOS_VOID                      *pMsg
);


/*****************************************************************************
 �� �� ��  : NAS_CC_GetEntityByCallId
 ��������  : ȡ����ָ��CallIdֵ��Ӧ��CCʵ���ID
 �������  : ucCallId - ����ID
 �������  : ��
 �� �� ֵ  : ȡ�õ�CCʵ��ID. ���û���ҵ���Ӧʵ�壬�򷵻�CC_INVALID_ENTITY_ID
*****************************************************************************/
NAS_CC_ENTITY_ID_T  NAS_CC_GetEntityByCallId(
    VOS_UINT8                           ucCallId
);

VOS_UINT32 NAS_CC_CheckSsSwitchHoldAllowed(VOS_VOID);

VOS_UINT32 NAS_CC_CheckSsSwitchRetrieveAllowed(VOS_VOID);

VOS_VOID NAS_CC_ProcSsSwitchSingleCallRetrieveSucc(VOS_VOID);

VOS_VOID NAS_CC_ProcSsSwitchSingleCallRetrieveFail(VOS_VOID);

VOS_VOID NAS_CC_ProcSsSwitchSingleCallHoldSucc(VOS_VOID);

VOS_VOID NAS_CC_ProcSsSwitchSingleCallHoldFail(VOS_VOID);

VOS_VOID NAS_CC_ProcSsSwitchMultiCallSucc(VOS_VOID);

VOS_VOID NAS_CC_ProcSsSwitchMultiCallFail(VOS_VOID);

VOS_VOID NAS_CC_ProcSsSwitchMain(VOS_VOID);


VOS_VOID NAS_CC_ProcSsSwitchCallRelease(NAS_CC_ENTITY_ID_T EntityID);

#if (FEATURE_ON == FEATURE_IMS)
VOS_VOID  NAS_CC_CreateCcEntityWithCallEntityInfo(
    VOS_VOID                           *pMsg
);
#endif

VOS_VOID  NAS_CC_DeleteAllEntities(VOS_VOID);
VOS_VOID  NAS_CC_GetEntityTiInfo(
    VOS_UINT8                          *pucTiNum,
    VOS_UINT8                          *pucTi
);


VOS_UINT32  NAS_CC_IsOnlySpecTypeCall(
    NAS_CC_CALL_TYPE_ENUM_U8            enCallType
);

MMCC_SESSION_TYPE_ENUM_UINT8  NAS_CC_ConvertCallTypeToSessionType(
    NAS_CC_CALL_TYPE_ENUM_U8            enCallType
);

#if (FEATURE_ON == FEATURE_PTM)
VOS_VOID NAS_CC_SndAcpuOmErrLogRptCnf(
    VOS_CHAR                           *pbuffer,
    VOS_UINT32                          ulBufUseLen
);
VOS_VOID NAS_CC_RcvAcpuOmErrLogRptReq(
    const VOS_VOID                           *pMsg
);
VOS_VOID NAS_CC_RcvAcpuOmErrLogCtrlInd(
    const VOS_VOID                           *pMsg
);
VOS_VOID NAS_CC_RcvAcpuOmMsg(
    const VOS_VOID                     *pMsg
);
#endif

VOS_UINT32 NAS_CC_IsLastCallEntityID(NAS_CC_ENTITY_ID_T EntityID);

VOS_VOID NAS_CC_TiNonRegularProc(VOS_UINT8 *pucCcMsg);

#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* NAS_CC_ENTITY_MGMT_H */
