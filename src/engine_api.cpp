/*  SPMod - SourcePawn Scripting Engine for Half-Life
 *  Copyright (C) 2018  SPMod Development Team
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.

 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "spmod.hpp"

static void ChangeLevel(const char *s1, 
                        const char *s2[[maybe_unused]])
{
    using def = ForwardMngr::FwdDefault;

    const std::unique_ptr<ForwardMngr> &fwdMngr = gSPGlobal->getForwardManagerCore();
    std::shared_ptr<Forward> fwdMapChange = fwdMngr->getDefaultForward(def::MapChange);
    int result;

    fwdMapChange->pushString(s1);
    fwdMapChange->execFunc(&result);

    if (result == IForward::ReturnValue::Stop)
        RETURN_META(MRES_SUPERCEDE);

    RETURN_META(MRES_IGNORED);
}

static void MessageBegin_Pre(int msg_dest [[maybe_unused]],
                             int msg_type,
                             const float *pOrigin [[maybe_unused]],
                             edict_t *ed)
{
    if(msg_type == gmsgShowMenu || msg_type == gmsgVGUIMenu)
    {
        std::shared_ptr<Player> pPlayer = gSPGlobal->getPlayerManagerCore()->getPlayerCore(ed);
        gSPGlobal->getMenuManagerCore()->closeMenu(pPlayer);
    }
    RETURN_META(MRES_IGNORED);
}

enginefuncs_t gEngineFunctionsTable =
{
    nullptr,		// pfnPrecacheModel()
    nullptr,		// pfnPrecacheSound()
    nullptr,		// pfnSetModel()
    nullptr,		// pfnModelIndex()
    nullptr,		// pfnModelFrames()
    nullptr,		// pfnSetSize()
    ChangeLevel,    // pfnChangeLevel()
    nullptr,		// pfnGetSpawnParms()
    nullptr,		// pfnSaveSpawnParms()
    nullptr,		// pfnVecToYaw()
    nullptr,		// pfnVecToAngles()
    nullptr,		// pfnMoveToOrigin()
    nullptr,		// pfnChangeYaw()
    nullptr,		// pfnChangePitch()
    nullptr,		// pfnFindEntityByString()
    nullptr,		// pfnGetEntityIllum()
    nullptr,		// pfnFindEntityInSphere()
    nullptr,		// pfnFindClientInPVS()
    nullptr,		// pfnEntitiesInPVS()
    nullptr,		// pfnMakeVectors()
    nullptr,		// pfnAngleVectors()
    nullptr,		// pfnCreateEntity()
    nullptr,		// pfnRemoveEntity()
    nullptr,		// pfnCreateNamedEntity()
    nullptr,		// pfnMakeStatic()
    nullptr,		// pfnEntIsOnFloor()
    nullptr,		// pfnDropToFloor()
    nullptr,		// pfnWalkMove()
    nullptr,		// pfnSetOrigin()
    nullptr,		// pfnEmitSound()
    nullptr,		// pfnEmitAmbientSound()
    nullptr,		// pfnTraceLine()
    nullptr,		// pfnTraceToss()
    nullptr,		// pfnTraceMonsterHull()
    nullptr,		// pfnTraceHull()
    nullptr,		// pfnTraceModel()
    nullptr,		// pfnTraceTexture()
    nullptr,		// pfnTraceSphere()
    nullptr,		// pfnGetAimVector()
    nullptr,		// pfnServerCommand()
    nullptr,		// pfnServerExecute()
    nullptr,		// pfnClientCommand()
    nullptr,		// pfnParticleEffect()
    nullptr,		// pfnLightStyle()
    nullptr,		// pfnDecalIndex()
    nullptr,		// pfnPointContents()
    MessageBegin_Pre, // pfnMessageBegin()
    nullptr,		// pfnMessageEnd()
    nullptr,		// pfnWriteByte()
    nullptr,		// pfnWriteChar()
    nullptr,		// pfnWriteShort()
    nullptr,		// pfnWriteLong()
    nullptr,		// pfnWriteAngle()
    nullptr,		// pfnWriteCoord()
    nullptr,		// pfnWriteString()
    nullptr,		// pfnWriteEntity()
    nullptr,		// pfnCVarRegister()
    nullptr,		// pfnCVarGetFloat()
    nullptr,		// pfnCVarGetString()
    nullptr,		// pfnCVarSetFloat()
    nullptr,		// pfnCVarSetString()
    nullptr,		// pfnAlertMessage()
    nullptr,		// pfnEngineFprintf()
    nullptr,		// pfnPvAllocEntPrivateData()
    nullptr,		// pfnPvEntPrivateData()
    nullptr,		// pfnFreeEntPrivateData()
    nullptr,		// pfnSzFromIndex()
    nullptr,		// pfnAllocString()
    nullptr,		// pfnGetVarsOfEnt()
    nullptr,		// pfnPEntityOfEntOffset()
    nullptr,		// pfnEntOffsetOfPEntity()
    nullptr,		// pfnIndexOfEdict()
    nullptr,		// pfnPEntityOfEntIndex()
    nullptr,		// pfnFindEntityByVars()
    nullptr,		// pfnGetModelPtr()
    nullptr,		// pfnRegUserMsg()
    nullptr,		// pfnAnimationAutomove()
    nullptr,		// pfnGetBonePosition()
    nullptr,		// pfnFunctionFromName()
    nullptr,		// pfnNameForFunction()
    nullptr,		// pfnClientPrintf()
    nullptr,		// pfnServerPrint()
    nullptr,		// pfnCmd_Args()
    nullptr,		// pfnCmd_Argv()
    nullptr,		// pfnCmd_Argc()
    nullptr,		// pfnGetAttachment()
    nullptr,		// pfnCRC32_Init()
    nullptr,		// pfnCRC32_ProcessBuffer()
    nullptr,		// pfnCRC32_ProcessByte()
    nullptr,		// pfnCRC32_Final()
    nullptr,		// pfnRandomLong()
    nullptr,		// pfnRandomFloat()
    nullptr,		// pfnSetView()
    nullptr,		// pfnTime()
    nullptr,		// pfnCrosshairAngle()
    nullptr,		// pfnLoadFileForMe()
    nullptr,		// pfnFreeFile()
    nullptr,		// pfnEndSection()
    nullptr,		// pfnCompareFileTime()
    nullptr,		// pfnGetGameDir()
    nullptr,		// pfnCvar_RegisterVariable()
    nullptr,		// pfnFadeClientVolume()
    nullptr,		// pfnSetClientMaxspeed()
    nullptr,		// pfnCreateFakeClient()
    nullptr,		// pfnRunPlayerMove()
    nullptr,		// pfnNumberOfEntities()
    nullptr,		// pfnGetInfoKeyBuffer()
    nullptr,		// pfnInfoKeyValue()
    nullptr,		// pfnSetKeyValue()
    nullptr,		// pfnSetClientKeyValue()
    nullptr,		// pfnIsMapValid()
    nullptr,		// pfnStaticDecal()
    nullptr,		// pfnPrecacheGeneric()
    nullptr,		// pfnGetPlayerUserId()
    nullptr,		// pfnBuildSoundMsg()
    nullptr,		// pfnIsDedicatedServer()
    nullptr,		// pfnCVarGetPointer()
    nullptr,		// pfnGetPlayerWONId()
    nullptr,		// pfnInfo_RemoveKey()
    nullptr,		// pfnGetPhysicsKeyValue()
    nullptr,		// pfnSetPhysicsKeyValue()
    nullptr,		// pfnGetPhysicsInfoString()
    nullptr,		// pfnPrecacheEvent()
    nullptr,		// pfnPlaybackEvent()
    nullptr,		// pfnSetFatPVS()
    nullptr,		// pfnSetFatPAS()
    nullptr,		// pfnCheckVisibility()
    nullptr,		// pfnDeltaSetField()
    nullptr,		// pfnDeltaUnsetField()
    nullptr,		// pfnDeltaAddEncoder()
    nullptr,		// pfnGetCurrentPlayer()
    nullptr,		// pfnCanSkipPlayer()
    nullptr,		// pfnDeltaFindField()
    nullptr,		// pfnDeltaSetFieldByIndex()
    nullptr,		// pfnDeltaUnsetFieldByIndex()
    nullptr,		// pfnSetGroupMask()
    nullptr,		// pfnCreateInstancedBaseline()
    nullptr,		// pfnCvar_DirectSet()
    nullptr,		// pfnForceUnmodified()
    nullptr,		// pfnGetPlayerStats()
    nullptr,		// pfnAddServerCommand()

    // Added in SDK 2.2:
    nullptr,		// pfnVoice_GetClientListening()
    nullptr,		// pfnVoice_SetClientListening()

    // Added for HL 1109 (no SDK update):
    nullptr,		// pfnGetPlayerAuthId()

    // Added 2003/11/10 (no SDK update):
    nullptr,		// pfnSequenceGet()
    nullptr,		// pfnSequencePickSentence()
    nullptr,		// pfnGetFileSize()
    nullptr,		// pfnGetApproxWavePlayLen()
    nullptr,		// pfnIsCareerMatch()
    nullptr,		// pfnGetLocalizedStringLength()
    nullptr,		// pfnRegisterTutorMessageShown()
    nullptr,		// pfnGetTimesTutorMessageShown()
    nullptr,		// pfnProcessTutorMessageDecayBuffer()
    nullptr,		// pfnConstructTutorMessageDecayBuffer()
    nullptr,		// pfnResetTutorMessageDecayData()

    // Added Added 2005-08-11 (no SDK update)
    nullptr,		// pfnQueryClientCvarValue()
    // Added Added 2005-11-22 (no SDK update)
    nullptr,		// pfnQueryClientCvarValue2()
    // Added 2009-06-17 (no SDK update)
    nullptr,	    // pfnEngCheckParm()
};

static int RegUserMsg_Post(const char *pszName,
                           int iSize [[maybe_unused]])
{
    if(!strcmp(pszName, "ShowMenu"))
    {
        gmsgShowMenu = META_RESULT_ORIG_RET(int);
    }
    else if(!strcmp(pszName, "VGUIMenu"))
    {
        gmsgVGUIMenu = META_RESULT_ORIG_RET(int);
    }
     RETURN_META_VALUE(MRES_IGNORED, 0);
}

enginefuncs_t gEngineFunctionsTablePost =
{
    nullptr,		// pfnPrecacheModel()
    nullptr,		// pfnPrecacheSound()
    nullptr,		// pfnSetModel()
    nullptr,		// pfnModelIndex()
    nullptr,		// pfnModelFrames()
    nullptr,		// pfnSetSize()
    nullptr,		// pfnChangeLevel()
    nullptr,		// pfnGetSpawnParms()
    nullptr,		// pfnSaveSpawnParms()
    nullptr,		// pfnVecToYaw()
    nullptr,		// pfnVecToAngles()
    nullptr,		// pfnMoveToOrigin()
    nullptr,		// pfnChangeYaw()
    nullptr,		// pfnChangePitch()
    nullptr,		// pfnFindEntityByString()
    nullptr,		// pfnGetEntityIllum()
    nullptr,		// pfnFindEntityInSphere()
    nullptr,		// pfnFindClientInPVS()
    nullptr,		// pfnEntitiesInPVS()
    nullptr,		// pfnMakeVectors()
    nullptr,		// pfnAngleVectors()
    nullptr,		// pfnCreateEntity()
    nullptr,		// pfnRemoveEntity()
    nullptr,		// pfnCreateNamedEntity()
    nullptr,		// pfnMakeStatic()
    nullptr,		// pfnEntIsOnFloor()
    nullptr,		// pfnDropToFloor()
    nullptr,		// pfnWalkMove()
    nullptr,		// pfnSetOrigin()
    nullptr,		// pfnEmitSound()
    nullptr,		// pfnEmitAmbientSound()
    nullptr,		// pfnTraceLine()
    nullptr,		// pfnTraceToss()
    nullptr,		// pfnTraceMonsterHull()
    nullptr,		// pfnTraceHull()
    nullptr,		// pfnTraceModel()
    nullptr,		// pfnTraceTexture()
    nullptr,		// pfnTraceSphere()
    nullptr,		// pfnGetAimVector()
    nullptr,		// pfnServerCommand()
    nullptr,		// pfnServerExecute()
    nullptr,		// pfnClientCommand()
    nullptr,		// pfnParticleEffect()
    nullptr,		// pfnLightStyle()
    nullptr,		// pfnDecalIndex()
    nullptr,		// pfnPointContents()
    nullptr,		// pfnMessageBegin()
    nullptr,		// pfnMessageEnd()
    nullptr,		// pfnWriteByte()
    nullptr,		// pfnWriteChar()
    nullptr,		// pfnWriteShort()
    nullptr,		// pfnWriteLong()
    nullptr,		// pfnWriteAngle()
    nullptr,		// pfnWriteCoord()
    nullptr,		// pfnWriteString()
    nullptr,		// pfnWriteEntity()
    nullptr,		// pfnCVarRegister()
    nullptr,		// pfnCVarGetFloat()
    nullptr,		// pfnCVarGetString()
    nullptr,		// pfnCVarSetFloat()
    nullptr,		// pfnCVarSetString()
    nullptr,		// pfnAlertMessage()
    nullptr,		// pfnEngineFprintf()
    nullptr,		// pfnPvAllocEntPrivateData()
    nullptr,		// pfnPvEntPrivateData()
    nullptr,		// pfnFreeEntPrivateData()
    nullptr,		// pfnSzFromIndex()
    nullptr,		// pfnAllocString()
    nullptr,		// pfnGetVarsOfEnt()
    nullptr,		// pfnPEntityOfEntOffset()
    nullptr,		// pfnEntOffsetOfPEntity()
    nullptr,		// pfnIndexOfEdict()
    nullptr,		// pfnPEntityOfEntIndex()
    nullptr,		// pfnFindEntityByVars()
    nullptr,		// pfnGetModelPtr()
    RegUserMsg_Post,// pfnRegUserMsg()
    nullptr,		// pfnAnimationAutomove()
    nullptr,		// pfnGetBonePosition()
    nullptr,		// pfnFunctionFromName()
    nullptr,		// pfnNameForFunction()
    nullptr,		// pfnClientPrintf()
    nullptr,		// pfnServerPrint()
    nullptr,		// pfnCmd_Args()
    nullptr,		// pfnCmd_Argv()
    nullptr,		// pfnCmd_Argc()
    nullptr,		// pfnGetAttachment()
    nullptr,		// pfnCRC32_Init()
    nullptr,		// pfnCRC32_ProcessBuffer()
    nullptr,		// pfnCRC32_ProcessByte()
    nullptr,		// pfnCRC32_Final()
    nullptr,		// pfnRandomLong()
    nullptr,		// pfnRandomFloat()
    nullptr,		// pfnSetView()
    nullptr,		// pfnTime()
    nullptr,		// pfnCrosshairAngle()
    nullptr,		// pfnLoadFileForMe()
    nullptr,		// pfnFreeFile()
    nullptr,		// pfnEndSection()
    nullptr,		// pfnCompareFileTime()
    nullptr,		// pfnGetGameDir()
    nullptr,		// pfnCvar_RegisterVariable()
    nullptr,		// pfnFadeClientVolume()
    nullptr,		// pfnSetClientMaxspeed()
    nullptr,		// pfnCreateFakeClient()
    nullptr,		// pfnRunPlayerMove()
    nullptr,		// pfnNumberOfEntities()
    nullptr,		// pfnGetInfoKeyBuffer()
    nullptr,		// pfnInfoKeyValue()
    nullptr,		// pfnSetKeyValue()
    nullptr,		// pfnSetClientKeyValue()
    nullptr,		// pfnIsMapValid()
    nullptr,		// pfnStaticDecal()
    nullptr,		// pfnPrecacheGeneric()
    nullptr,		// pfnGetPlayerUserId()
    nullptr,		// pfnBuildSoundMsg()
    nullptr,		// pfnIsDedicatedServer()
    nullptr,		// pfnCVarGetPointer()
    nullptr,		// pfnGetPlayerWONId()
    nullptr,		// pfnInfo_RemoveKey()
    nullptr,		// pfnGetPhysicsKeyValue()
    nullptr,		// pfnSetPhysicsKeyValue()
    nullptr,		// pfnGetPhysicsInfoString()
    nullptr,		// pfnPrecacheEvent()
    nullptr,		// pfnPlaybackEvent()
    nullptr,		// pfnSetFatPVS()
    nullptr,		// pfnSetFatPAS()
    nullptr,		// pfnCheckVisibility()
    nullptr,		// pfnDeltaSetField()
    nullptr,		// pfnDeltaUnsetField()
    nullptr,		// pfnDeltaAddEncoder()
    nullptr,		// pfnGetCurrentPlayer()
    nullptr,		// pfnCanSkipPlayer()
    nullptr,		// pfnDeltaFindField()
    nullptr,		// pfnDeltaSetFieldByIndex()
    nullptr,		// pfnDeltaUnsetFieldByIndex()
    nullptr,		// pfnSetGroupMask()
    nullptr,		// pfnCreateInstancedBaseline()
    nullptr,		// pfnCvar_DirectSet()
    nullptr,		// pfnForceUnmodified()
    nullptr,		// pfnGetPlayerStats()
    nullptr,		// pfnAddServerCommand()

    // Added in SDK 2.2:
    nullptr,		// pfnVoice_GetClientListening()
    nullptr,		// pfnVoice_SetClientListening()

    // Added for HL 1109 (no SDK update):
    nullptr,		// pfnGetPlayerAuthId()

    // Added 2003/11/10 (no SDK update):
    nullptr,		// pfnSequenceGet()
    nullptr,		// pfnSequencePickSentence()
    nullptr,		// pfnGetFileSize()
    nullptr,		// pfnGetApproxWavePlayLen()
    nullptr,		// pfnIsCareerMatch()
    nullptr,		// pfnGetLocalizedStringLength()
    nullptr,		// pfnRegisterTutorMessageShown()
    nullptr,		// pfnGetTimesTutorMessageShown()
    nullptr,		// pfnProcessTutorMessageDecayBuffer()
    nullptr,		// pfnConstructTutorMessageDecayBuffer()
    nullptr,		// pfnResetTutorMessageDecayData()

    // Added Added 2005-08-11 (no SDK update)
    nullptr,		// pfnQueryClientCvarValue()
    // Added Added 2005-11-22 (no SDK update)
    nullptr,		// pfnQueryClientCvarValue2()
    // Added 2009-06-17 (no SDK update)
    nullptr,	    // pfnEngCheckParm()
};

C_DLLEXPORT int GetEngineFunctions(enginefuncs_t *pengfuncsFromEngine,
                                    int *interfaceVersion)
{
    if (!pengfuncsFromEngine)
        return 0;

    if (*interfaceVersion != ENGINE_INTERFACE_VERSION) {
        *interfaceVersion = ENGINE_INTERFACE_VERSION;
        return 0;
    }

    memcpy(pengfuncsFromEngine, &gEngineFunctionsTable, sizeof(enginefuncs_t));
    return 1;
}

C_DLLEXPORT int GetEngineFunctions_Post(enginefuncs_t *pengfuncsFromEngine,
                                        int *interfaceVersion)
{
    if (!pengfuncsFromEngine)
        return 0;

    if (*interfaceVersion != ENGINE_INTERFACE_VERSION) {
        *interfaceVersion = ENGINE_INTERFACE_VERSION;
        return 0;
    }

    memcpy(pengfuncsFromEngine, &gEngineFunctionsTablePost, sizeof(enginefuncs_t));
    return 1;
}
