std::unordered_map<File::StringType, int32_t> AActor::MemberOffsets{};

AActor::EActorBeginPlayState& AActor::GetActorHasBegunPlay()
{
    static auto offset = MemberOffsets.find(STR("ActorHasBegunPlay"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::ActorHasBegunPlay' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<AActor::EActorBeginPlayState*>(this, offset->second);
}
const AActor::EActorBeginPlayState& AActor::GetActorHasBegunPlay() const
{
    static auto offset = MemberOffsets.find(STR("ActorHasBegunPlay"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::ActorHasBegunPlay' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const AActor::EActorBeginPlayState*>(this, offset->second);
}

FRepAttachment& AActor::GetAttachmentReplication()
{
    static auto offset = MemberOffsets.find(STR("AttachmentReplication"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::AttachmentReplication' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FRepAttachment*>(this, offset->second);
}
const FRepAttachment& AActor::GetAttachmentReplication() const
{
    static auto offset = MemberOffsets.find(STR("AttachmentReplication"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::AttachmentReplication' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FRepAttachment*>(this, offset->second);
}

TEnumAsByte<enum EAutoReceiveInput::Type>& AActor::GetAutoReceiveInput()
{
    static auto offset = MemberOffsets.find(STR("AutoReceiveInput"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::AutoReceiveInput' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TEnumAsByte<enum EAutoReceiveInput::Type>*>(this, offset->second);
}
const TEnumAsByte<enum EAutoReceiveInput::Type>& AActor::GetAutoReceiveInput() const
{
    static auto offset = MemberOffsets.find(STR("AutoReceiveInput"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::AutoReceiveInput' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TEnumAsByte<enum EAutoReceiveInput::Type>*>(this, offset->second);
}

float& AActor::GetCachedLastRenderTime()
{
    static auto offset = MemberOffsets.find(STR("CachedLastRenderTime"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::CachedLastRenderTime' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& AActor::GetCachedLastRenderTime() const
{
    static auto offset = MemberOffsets.find(STR("CachedLastRenderTime"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::CachedLastRenderTime' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

TArray<TObjectPtr<AActor>,TSizedDefaultAllocator<32> >& AActor::GetChildren()
{
    static auto offset = MemberOffsets.find(STR("Children"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::Children' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<TObjectPtr<AActor>,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<TObjectPtr<AActor>,TSizedDefaultAllocator<32> >& AActor::GetChildren() const
{
    static auto offset = MemberOffsets.find(STR("Children"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::Children' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<TObjectPtr<AActor>,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

TArray<AMatineeActor *,TSizedDefaultAllocator<32> >& AActor::GetControllingMatineeActors()
{
    static auto offset = MemberOffsets.find(STR("ControllingMatineeActors"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::ControllingMatineeActors' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<AMatineeActor *,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<AMatineeActor *,TSizedDefaultAllocator<32> >& AActor::GetControllingMatineeActors() const
{
    static auto offset = MemberOffsets.find(STR("ControllingMatineeActors"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::ControllingMatineeActors' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<AMatineeActor *,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

float& AActor::GetCreationTime()
{
    static auto offset = MemberOffsets.find(STR("CreationTime"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::CreationTime' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& AActor::GetCreationTime() const
{
    static auto offset = MemberOffsets.find(STR("CreationTime"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::CreationTime' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

float& AActor::GetCustomTimeDilation()
{
    static auto offset = MemberOffsets.find(STR("CustomTimeDilation"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::CustomTimeDilation' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& AActor::GetCustomTimeDilation() const
{
    static auto offset = MemberOffsets.find(STR("CustomTimeDilation"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::CustomTimeDilation' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

EActorUpdateOverlapsMethod& AActor::GetDefaultUpdateOverlapsMethodDuringLevelStreaming()
{
    static auto offset = MemberOffsets.find(STR("DefaultUpdateOverlapsMethodDuringLevelStreaming"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::DefaultUpdateOverlapsMethodDuringLevelStreaming' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<EActorUpdateOverlapsMethod*>(this, offset->second);
}
const EActorUpdateOverlapsMethod& AActor::GetDefaultUpdateOverlapsMethodDuringLevelStreaming() const
{
    static auto offset = MemberOffsets.find(STR("DefaultUpdateOverlapsMethodDuringLevelStreaming"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::DefaultUpdateOverlapsMethodDuringLevelStreaming' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const EActorUpdateOverlapsMethod*>(this, offset->second);
}

FRenderCommandFence& AActor::GetDetachFence()
{
    static auto offset = MemberOffsets.find(STR("DetachFence"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::DetachFence' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FRenderCommandFence*>(this, offset->second);
}
const FRenderCommandFence& AActor::GetDetachFence() const
{
    static auto offset = MemberOffsets.find(STR("DetachFence"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::DetachFence' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FRenderCommandFence*>(this, offset->second);
}

uint64& AActor::GetHiddenEditorViews()
{
    static auto offset = MemberOffsets.find(STR("HiddenEditorViews"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::HiddenEditorViews' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint64*>(this, offset->second);
}
const uint64& AActor::GetHiddenEditorViews() const
{
    static auto offset = MemberOffsets.find(STR("HiddenEditorViews"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::HiddenEditorViews' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint64*>(this, offset->second);
}

float& AActor::GetInitialLifeSpan()
{
    static auto offset = MemberOffsets.find(STR("InitialLifeSpan"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::InitialLifeSpan' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& AActor::GetInitialLifeSpan() const
{
    static auto offset = MemberOffsets.find(STR("InitialLifeSpan"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::InitialLifeSpan' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

TObjectPtr<UInputComponent>& AActor::GetInputComponent()
{
    static auto offset = MemberOffsets.find(STR("InputComponent"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::InputComponent' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TObjectPtr<UInputComponent>*>(this, offset->second);
}
const TObjectPtr<UInputComponent>& AActor::GetInputComponent() const
{
    static auto offset = MemberOffsets.find(STR("InputComponent"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::InputComponent' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TObjectPtr<UInputComponent>*>(this, offset->second);
}

TEnumAsByte<enum EInputConsumeOptions>& AActor::GetInputConsumeOption_DEPRECATED()
{
    static auto offset = MemberOffsets.find(STR("InputConsumeOption_DEPRECATED"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::InputConsumeOption_DEPRECATED' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TEnumAsByte<enum EInputConsumeOptions>*>(this, offset->second);
}
const TEnumAsByte<enum EInputConsumeOptions>& AActor::GetInputConsumeOption_DEPRECATED() const
{
    static auto offset = MemberOffsets.find(STR("InputConsumeOption_DEPRECATED"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::InputConsumeOption_DEPRECATED' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TEnumAsByte<enum EInputConsumeOptions>*>(this, offset->second);
}

int32& AActor::GetInputPriority()
{
    static auto offset = MemberOffsets.find(STR("InputPriority"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::InputPriority' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& AActor::GetInputPriority() const
{
    static auto offset = MemberOffsets.find(STR("InputPriority"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::InputPriority' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

float& AActor::GetLastNetUpdateTime()
{
    static auto offset = MemberOffsets.find(STR("LastNetUpdateTime"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::LastNetUpdateTime' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& AActor::GetLastNetUpdateTime() const
{
    static auto offset = MemberOffsets.find(STR("LastNetUpdateTime"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::LastNetUpdateTime' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

float& AActor::GetLastRenderTime()
{
    static auto offset = MemberOffsets.find(STR("LastRenderTime"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::LastRenderTime' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& AActor::GetLastRenderTime() const
{
    static auto offset = MemberOffsets.find(STR("LastRenderTime"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::LastRenderTime' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

TArray<FName,TSizedDefaultAllocator<32> >& AActor::GetLayers()
{
    static auto offset = MemberOffsets.find(STR("Layers"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::Layers' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<FName,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<FName,TSizedDefaultAllocator<32> >& AActor::GetLayers() const
{
    static auto offset = MemberOffsets.find(STR("Layers"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::Layers' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<FName,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

float& AActor::GetMinNetUpdateFrequency()
{
    static auto offset = MemberOffsets.find(STR("MinNetUpdateFrequency"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::MinNetUpdateFrequency' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& AActor::GetMinNetUpdateFrequency() const
{
    static auto offset = MemberOffsets.find(STR("MinNetUpdateFrequency"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::MinNetUpdateFrequency' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

float& AActor::GetNetCullDistanceSquared()
{
    static auto offset = MemberOffsets.find(STR("NetCullDistanceSquared"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::NetCullDistanceSquared' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& AActor::GetNetCullDistanceSquared() const
{
    static auto offset = MemberOffsets.find(STR("NetCullDistanceSquared"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::NetCullDistanceSquared' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

TEnumAsByte<enum ENetDormancy>& AActor::GetNetDormancy()
{
    static auto offset = MemberOffsets.find(STR("NetDormancy"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::NetDormancy' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TEnumAsByte<enum ENetDormancy>*>(this, offset->second);
}
const TEnumAsByte<enum ENetDormancy>& AActor::GetNetDormancy() const
{
    static auto offset = MemberOffsets.find(STR("NetDormancy"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::NetDormancy' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TEnumAsByte<enum ENetDormancy>*>(this, offset->second);
}

FName& AActor::GetNetDriverName()
{
    static auto offset = MemberOffsets.find(STR("NetDriverName"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::NetDriverName' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FName*>(this, offset->second);
}
const FName& AActor::GetNetDriverName() const
{
    static auto offset = MemberOffsets.find(STR("NetDriverName"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::NetDriverName' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FName*>(this, offset->second);
}

float& AActor::GetNetPriority()
{
    static auto offset = MemberOffsets.find(STR("NetPriority"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::NetPriority' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& AActor::GetNetPriority() const
{
    static auto offset = MemberOffsets.find(STR("NetPriority"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::NetPriority' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

int32& AActor::GetNetTag()
{
    static auto offset = MemberOffsets.find(STR("NetTag"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::NetTag' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& AActor::GetNetTag() const
{
    static auto offset = MemberOffsets.find(STR("NetTag"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::NetTag' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

float& AActor::GetNetUpdateFrequency()
{
    static auto offset = MemberOffsets.find(STR("NetUpdateFrequency"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::NetUpdateFrequency' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& AActor::GetNetUpdateFrequency() const
{
    static auto offset = MemberOffsets.find(STR("NetUpdateFrequency"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::NetUpdateFrequency' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

float& AActor::GetNetUpdateTime()
{
    static auto offset = MemberOffsets.find(STR("NetUpdateTime"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::NetUpdateTime' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<float*>(this, offset->second);
}
const float& AActor::GetNetUpdateTime() const
{
    static auto offset = MemberOffsets.find(STR("NetUpdateTime"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::NetUpdateTime' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const float*>(this, offset->second);
}

FActorBeginOverlapSignature& AActor::GetOnActorBeginOverlap()
{
    static auto offset = MemberOffsets.find(STR("OnActorBeginOverlap"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnActorBeginOverlap' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FActorBeginOverlapSignature*>(this, offset->second);
}
const FActorBeginOverlapSignature& AActor::GetOnActorBeginOverlap() const
{
    static auto offset = MemberOffsets.find(STR("OnActorBeginOverlap"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnActorBeginOverlap' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FActorBeginOverlapSignature*>(this, offset->second);
}

FActorEndOverlapSignature& AActor::GetOnActorEndOverlap()
{
    static auto offset = MemberOffsets.find(STR("OnActorEndOverlap"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnActorEndOverlap' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FActorEndOverlapSignature*>(this, offset->second);
}
const FActorEndOverlapSignature& AActor::GetOnActorEndOverlap() const
{
    static auto offset = MemberOffsets.find(STR("OnActorEndOverlap"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnActorEndOverlap' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FActorEndOverlapSignature*>(this, offset->second);
}

FActorHitSignature& AActor::GetOnActorHit()
{
    static auto offset = MemberOffsets.find(STR("OnActorHit"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnActorHit' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FActorHitSignature*>(this, offset->second);
}
const FActorHitSignature& AActor::GetOnActorHit() const
{
    static auto offset = MemberOffsets.find(STR("OnActorHit"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnActorHit' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FActorHitSignature*>(this, offset->second);
}

FActorBeginCursorOverSignature& AActor::GetOnBeginCursorOver()
{
    static auto offset = MemberOffsets.find(STR("OnBeginCursorOver"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnBeginCursorOver' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FActorBeginCursorOverSignature*>(this, offset->second);
}
const FActorBeginCursorOverSignature& AActor::GetOnBeginCursorOver() const
{
    static auto offset = MemberOffsets.find(STR("OnBeginCursorOver"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnBeginCursorOver' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FActorBeginCursorOverSignature*>(this, offset->second);
}

FActorOnClickedSignature& AActor::GetOnClicked()
{
    static auto offset = MemberOffsets.find(STR("OnClicked"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnClicked' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FActorOnClickedSignature*>(this, offset->second);
}
const FActorOnClickedSignature& AActor::GetOnClicked() const
{
    static auto offset = MemberOffsets.find(STR("OnClicked"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnClicked' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FActorOnClickedSignature*>(this, offset->second);
}

FActorDestroyedSignature& AActor::GetOnDestroyed()
{
    static auto offset = MemberOffsets.find(STR("OnDestroyed"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnDestroyed' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FActorDestroyedSignature*>(this, offset->second);
}
const FActorDestroyedSignature& AActor::GetOnDestroyed() const
{
    static auto offset = MemberOffsets.find(STR("OnDestroyed"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnDestroyed' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FActorDestroyedSignature*>(this, offset->second);
}

FActorEndCursorOverSignature& AActor::GetOnEndCursorOver()
{
    static auto offset = MemberOffsets.find(STR("OnEndCursorOver"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnEndCursorOver' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FActorEndCursorOverSignature*>(this, offset->second);
}
const FActorEndCursorOverSignature& AActor::GetOnEndCursorOver() const
{
    static auto offset = MemberOffsets.find(STR("OnEndCursorOver"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnEndCursorOver' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FActorEndCursorOverSignature*>(this, offset->second);
}

FActorEndPlaySignature& AActor::GetOnEndPlay()
{
    static auto offset = MemberOffsets.find(STR("OnEndPlay"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnEndPlay' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FActorEndPlaySignature*>(this, offset->second);
}
const FActorEndPlaySignature& AActor::GetOnEndPlay() const
{
    static auto offset = MemberOffsets.find(STR("OnEndPlay"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnEndPlay' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FActorEndPlaySignature*>(this, offset->second);
}

FActorOnInputTouchBeginSignature& AActor::GetOnInputTouchBegin()
{
    static auto offset = MemberOffsets.find(STR("OnInputTouchBegin"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnInputTouchBegin' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FActorOnInputTouchBeginSignature*>(this, offset->second);
}
const FActorOnInputTouchBeginSignature& AActor::GetOnInputTouchBegin() const
{
    static auto offset = MemberOffsets.find(STR("OnInputTouchBegin"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnInputTouchBegin' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FActorOnInputTouchBeginSignature*>(this, offset->second);
}

FActorOnInputTouchEndSignature& AActor::GetOnInputTouchEnd()
{
    static auto offset = MemberOffsets.find(STR("OnInputTouchEnd"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnInputTouchEnd' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FActorOnInputTouchEndSignature*>(this, offset->second);
}
const FActorOnInputTouchEndSignature& AActor::GetOnInputTouchEnd() const
{
    static auto offset = MemberOffsets.find(STR("OnInputTouchEnd"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnInputTouchEnd' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FActorOnInputTouchEndSignature*>(this, offset->second);
}

FActorBeginTouchOverSignature& AActor::GetOnInputTouchEnter()
{
    static auto offset = MemberOffsets.find(STR("OnInputTouchEnter"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnInputTouchEnter' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FActorBeginTouchOverSignature*>(this, offset->second);
}
const FActorBeginTouchOverSignature& AActor::GetOnInputTouchEnter() const
{
    static auto offset = MemberOffsets.find(STR("OnInputTouchEnter"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnInputTouchEnter' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FActorBeginTouchOverSignature*>(this, offset->second);
}

FActorEndTouchOverSignature& AActor::GetOnInputTouchLeave()
{
    static auto offset = MemberOffsets.find(STR("OnInputTouchLeave"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnInputTouchLeave' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FActorEndTouchOverSignature*>(this, offset->second);
}
const FActorEndTouchOverSignature& AActor::GetOnInputTouchLeave() const
{
    static auto offset = MemberOffsets.find(STR("OnInputTouchLeave"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnInputTouchLeave' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FActorEndTouchOverSignature*>(this, offset->second);
}

FActorOnReleasedSignature& AActor::GetOnReleased()
{
    static auto offset = MemberOffsets.find(STR("OnReleased"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnReleased' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FActorOnReleasedSignature*>(this, offset->second);
}
const FActorOnReleasedSignature& AActor::GetOnReleased() const
{
    static auto offset = MemberOffsets.find(STR("OnReleased"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnReleased' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FActorOnReleasedSignature*>(this, offset->second);
}

FTakeAnyDamageSignature& AActor::GetOnTakeAnyDamage()
{
    static auto offset = MemberOffsets.find(STR("OnTakeAnyDamage"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnTakeAnyDamage' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FTakeAnyDamageSignature*>(this, offset->second);
}
const FTakeAnyDamageSignature& AActor::GetOnTakeAnyDamage() const
{
    static auto offset = MemberOffsets.find(STR("OnTakeAnyDamage"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnTakeAnyDamage' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FTakeAnyDamageSignature*>(this, offset->second);
}

FTakePointDamageSignature& AActor::GetOnTakePointDamage()
{
    static auto offset = MemberOffsets.find(STR("OnTakePointDamage"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnTakePointDamage' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FTakePointDamageSignature*>(this, offset->second);
}
const FTakePointDamageSignature& AActor::GetOnTakePointDamage() const
{
    static auto offset = MemberOffsets.find(STR("OnTakePointDamage"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnTakePointDamage' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FTakePointDamageSignature*>(this, offset->second);
}

FTakeRadialDamageSignature& AActor::GetOnTakeRadialDamage()
{
    static auto offset = MemberOffsets.find(STR("OnTakeRadialDamage"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnTakeRadialDamage' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FTakeRadialDamageSignature*>(this, offset->second);
}
const FTakeRadialDamageSignature& AActor::GetOnTakeRadialDamage() const
{
    static auto offset = MemberOffsets.find(STR("OnTakeRadialDamage"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::OnTakeRadialDamage' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FTakeRadialDamageSignature*>(this, offset->second);
}

TObjectPtr<AActor>& AActor::GetOwner()
{
    static auto offset = MemberOffsets.find(STR("Owner"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::Owner' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TObjectPtr<AActor>*>(this, offset->second);
}
const TObjectPtr<AActor>& AActor::GetOwner() const
{
    static auto offset = MemberOffsets.find(STR("Owner"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::Owner' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TObjectPtr<AActor>*>(this, offset->second);
}

TWeakObjectPtr<UChildActorComponent,FWeakObjectPtr>& AActor::GetParentComponent()
{
    static auto offset = MemberOffsets.find(STR("ParentComponent"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::ParentComponent' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TWeakObjectPtr<UChildActorComponent,FWeakObjectPtr>*>(this, offset->second);
}
const TWeakObjectPtr<UChildActorComponent,FWeakObjectPtr>& AActor::GetParentComponent() const
{
    static auto offset = MemberOffsets.find(STR("ParentComponent"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::ParentComponent' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TWeakObjectPtr<UChildActorComponent,FWeakObjectPtr>*>(this, offset->second);
}

TWeakObjectPtr<AActor,FWeakObjectPtr>& AActor::GetParentComponentActor_DEPRECATED()
{
    static auto offset = MemberOffsets.find(STR("ParentComponentActor_DEPRECATED"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::ParentComponentActor_DEPRECATED' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TWeakObjectPtr<AActor,FWeakObjectPtr>*>(this, offset->second);
}
const TWeakObjectPtr<AActor,FWeakObjectPtr>& AActor::GetParentComponentActor_DEPRECATED() const
{
    static auto offset = MemberOffsets.find(STR("ParentComponentActor_DEPRECATED"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::ParentComponentActor_DEPRECATED' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TWeakObjectPtr<AActor,FWeakObjectPtr>*>(this, offset->second);
}

FActorTickFunction& AActor::GetPrimaryActorTick()
{
    static auto offset = MemberOffsets.find(STR("PrimaryActorTick"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::PrimaryActorTick' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FActorTickFunction*>(this, offset->second);
}
const FActorTickFunction& AActor::GetPrimaryActorTick() const
{
    static auto offset = MemberOffsets.find(STR("PrimaryActorTick"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::PrimaryActorTick' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FActorTickFunction*>(this, offset->second);
}

int32& AActor::GetRayTracingGroupId()
{
    static auto offset = MemberOffsets.find(STR("RayTracingGroupId"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::RayTracingGroupId' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<int32*>(this, offset->second);
}
const int32& AActor::GetRayTracingGroupId() const
{
    static auto offset = MemberOffsets.find(STR("RayTracingGroupId"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::RayTracingGroupId' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const int32*>(this, offset->second);
}

TEnumAsByte<enum ENetRole>& AActor::GetRemoteRole()
{
    static auto offset = MemberOffsets.find(STR("RemoteRole"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::RemoteRole' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TEnumAsByte<enum ENetRole>*>(this, offset->second);
}
const TEnumAsByte<enum ENetRole>& AActor::GetRemoteRole() const
{
    static auto offset = MemberOffsets.find(STR("RemoteRole"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::RemoteRole' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TEnumAsByte<enum ENetRole>*>(this, offset->second);
}

TArray<UE::Net::FReplicatedComponentInfo,TSizedDefaultAllocator<32> >& AActor::GetReplicatedComponentsInfo()
{
    static auto offset = MemberOffsets.find(STR("ReplicatedComponentsInfo"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::ReplicatedComponentsInfo' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<UE::Net::FReplicatedComponentInfo,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<UE::Net::FReplicatedComponentInfo,TSizedDefaultAllocator<32> >& AActor::GetReplicatedComponentsInfo() const
{
    static auto offset = MemberOffsets.find(STR("ReplicatedComponentsInfo"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::ReplicatedComponentsInfo' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<UE::Net::FReplicatedComponentInfo,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

FRepMovement& AActor::GetReplicatedMovement()
{
    static auto offset = MemberOffsets.find(STR("ReplicatedMovement"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::ReplicatedMovement' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FRepMovement*>(this, offset->second);
}
const FRepMovement& AActor::GetReplicatedMovement() const
{
    static auto offset = MemberOffsets.find(STR("ReplicatedMovement"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::ReplicatedMovement' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FRepMovement*>(this, offset->second);
}

UE::Net::FSubObjectRegistry& AActor::GetReplicatedSubObjects()
{
    static auto offset = MemberOffsets.find(STR("ReplicatedSubObjects"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::ReplicatedSubObjects' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<UE::Net::FSubObjectRegistry*>(this, offset->second);
}
const UE::Net::FSubObjectRegistry& AActor::GetReplicatedSubObjects() const
{
    static auto offset = MemberOffsets.find(STR("ReplicatedSubObjects"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::ReplicatedSubObjects' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const UE::Net::FSubObjectRegistry*>(this, offset->second);
}

TEnumAsByte<enum ENetRole>& AActor::GetRole()
{
    static auto offset = MemberOffsets.find(STR("Role"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::Role' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TEnumAsByte<enum ENetRole>*>(this, offset->second);
}
const TEnumAsByte<enum ENetRole>& AActor::GetRole() const
{
    static auto offset = MemberOffsets.find(STR("Role"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::Role' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TEnumAsByte<enum ENetRole>*>(this, offset->second);
}

TObjectPtr<USceneComponent>& AActor::GetRootComponent()
{
    static auto offset = MemberOffsets.find(STR("RootComponent"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::RootComponent' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TObjectPtr<USceneComponent>*>(this, offset->second);
}
const TObjectPtr<USceneComponent>& AActor::GetRootComponent() const
{
    static auto offset = MemberOffsets.find(STR("RootComponent"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::RootComponent' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TObjectPtr<USceneComponent>*>(this, offset->second);
}

ESpawnActorCollisionHandlingMethod& AActor::GetSpawnCollisionHandlingMethod()
{
    static auto offset = MemberOffsets.find(STR("SpawnCollisionHandlingMethod"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::SpawnCollisionHandlingMethod' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<ESpawnActorCollisionHandlingMethod*>(this, offset->second);
}
const ESpawnActorCollisionHandlingMethod& AActor::GetSpawnCollisionHandlingMethod() const
{
    static auto offset = MemberOffsets.find(STR("SpawnCollisionHandlingMethod"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::SpawnCollisionHandlingMethod' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const ESpawnActorCollisionHandlingMethod*>(this, offset->second);
}

TArray<FName,TSizedDefaultAllocator<32> >& AActor::GetTags()
{
    static auto offset = MemberOffsets.find(STR("Tags"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::Tags' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<TArray<FName,TSizedDefaultAllocator<32> >*>(this, offset->second);
}
const TArray<FName,TSizedDefaultAllocator<32> >& AActor::GetTags() const
{
    static auto offset = MemberOffsets.find(STR("Tags"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::Tags' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const TArray<FName,TSizedDefaultAllocator<32> >*>(this, offset->second);
}

FTimerHandle& AActor::GetTimerHandle_LifeSpanExpired()
{
    static auto offset = MemberOffsets.find(STR("TimerHandle_LifeSpanExpired"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::TimerHandle_LifeSpanExpired' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<FTimerHandle*>(this, offset->second);
}
const FTimerHandle& AActor::GetTimerHandle_LifeSpanExpired() const
{
    static auto offset = MemberOffsets.find(STR("TimerHandle_LifeSpanExpired"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::TimerHandle_LifeSpanExpired' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const FTimerHandle*>(this, offset->second);
}

EActorUpdateOverlapsMethod& AActor::GetUpdateOverlapsMethodDuringLevelStreaming()
{
    static auto offset = MemberOffsets.find(STR("UpdateOverlapsMethodDuringLevelStreaming"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::UpdateOverlapsMethodDuringLevelStreaming' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<EActorUpdateOverlapsMethod*>(this, offset->second);
}
const EActorUpdateOverlapsMethod& AActor::GetUpdateOverlapsMethodDuringLevelStreaming() const
{
    static auto offset = MemberOffsets.find(STR("UpdateOverlapsMethodDuringLevelStreaming"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::UpdateOverlapsMethodDuringLevelStreaming' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const EActorUpdateOverlapsMethod*>(this, offset->second);
}

uint8& AActor::GetbActorBeginningPlayFromLevelStreaming()
{
    static auto offset = MemberOffsets.find(STR("bActorBeginningPlayFromLevelStreaming"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bActorBeginningPlayFromLevelStreaming' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbActorBeginningPlayFromLevelStreaming() const
{
    static auto offset = MemberOffsets.find(STR("bActorBeginningPlayFromLevelStreaming"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bActorBeginningPlayFromLevelStreaming' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbActorEnableCollision()
{
    static auto offset = MemberOffsets.find(STR("bActorEnableCollision"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bActorEnableCollision' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbActorEnableCollision() const
{
    static auto offset = MemberOffsets.find(STR("bActorEnableCollision"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bActorEnableCollision' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbActorInitialized()
{
    static auto offset = MemberOffsets.find(STR("bActorInitialized"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bActorInitialized' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbActorInitialized() const
{
    static auto offset = MemberOffsets.find(STR("bActorInitialized"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bActorInitialized' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbActorIsBeingConstructed()
{
    static auto offset = MemberOffsets.find(STR("bActorIsBeingConstructed"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bActorIsBeingConstructed' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbActorIsBeingConstructed() const
{
    static auto offset = MemberOffsets.find(STR("bActorIsBeingConstructed"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bActorIsBeingConstructed' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbActorIsBeingDestroyed()
{
    static auto offset = MemberOffsets.find(STR("bActorIsBeingDestroyed"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bActorIsBeingDestroyed' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbActorIsBeingDestroyed() const
{
    static auto offset = MemberOffsets.find(STR("bActorIsBeingDestroyed"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bActorIsBeingDestroyed' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbActorSeamlessTraveled()
{
    static auto offset = MemberOffsets.find(STR("bActorSeamlessTraveled"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bActorSeamlessTraveled' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbActorSeamlessTraveled() const
{
    static auto offset = MemberOffsets.find(STR("bActorSeamlessTraveled"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bActorSeamlessTraveled' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbActorWantsDestroyDuringBeginPlay()
{
    static auto offset = MemberOffsets.find(STR("bActorWantsDestroyDuringBeginPlay"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bActorWantsDestroyDuringBeginPlay' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbActorWantsDestroyDuringBeginPlay() const
{
    static auto offset = MemberOffsets.find(STR("bActorWantsDestroyDuringBeginPlay"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bActorWantsDestroyDuringBeginPlay' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbAllowReceiveTickEventOnDedicatedServer()
{
    static auto offset = MemberOffsets.find(STR("bAllowReceiveTickEventOnDedicatedServer"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bAllowReceiveTickEventOnDedicatedServer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbAllowReceiveTickEventOnDedicatedServer() const
{
    static auto offset = MemberOffsets.find(STR("bAllowReceiveTickEventOnDedicatedServer"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bAllowReceiveTickEventOnDedicatedServer' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbAllowTickBeforeBeginPlay()
{
    static auto offset = MemberOffsets.find(STR("bAllowTickBeforeBeginPlay"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bAllowTickBeforeBeginPlay' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbAllowTickBeforeBeginPlay() const
{
    static auto offset = MemberOffsets.find(STR("bAllowTickBeforeBeginPlay"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bAllowTickBeforeBeginPlay' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbAlwaysRelevant()
{
    static auto offset = MemberOffsets.find(STR("bAlwaysRelevant"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bAlwaysRelevant' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbAlwaysRelevant() const
{
    static auto offset = MemberOffsets.find(STR("bAlwaysRelevant"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bAlwaysRelevant' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbAsyncPhysicsTickEnabled()
{
    static auto offset = MemberOffsets.find(STR("bAsyncPhysicsTickEnabled"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bAsyncPhysicsTickEnabled' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbAsyncPhysicsTickEnabled() const
{
    static auto offset = MemberOffsets.find(STR("bAsyncPhysicsTickEnabled"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bAsyncPhysicsTickEnabled' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbAutoDestroyWhenFinished()
{
    static auto offset = MemberOffsets.find(STR("bAutoDestroyWhenFinished"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bAutoDestroyWhenFinished' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbAutoDestroyWhenFinished() const
{
    static auto offset = MemberOffsets.find(STR("bAutoDestroyWhenFinished"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bAutoDestroyWhenFinished' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbBlockInput()
{
    static auto offset = MemberOffsets.find(STR("bBlockInput"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bBlockInput' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbBlockInput() const
{
    static auto offset = MemberOffsets.find(STR("bBlockInput"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bBlockInput' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbCallPreReplication()
{
    static auto offset = MemberOffsets.find(STR("bCallPreReplication"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bCallPreReplication' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbCallPreReplication() const
{
    static auto offset = MemberOffsets.find(STR("bCallPreReplication"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bCallPreReplication' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbCallPreReplicationForReplay()
{
    static auto offset = MemberOffsets.find(STR("bCallPreReplicationForReplay"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bCallPreReplicationForReplay' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbCallPreReplicationForReplay() const
{
    static auto offset = MemberOffsets.find(STR("bCallPreReplicationForReplay"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bCallPreReplicationForReplay' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbCanBeDamaged()
{
    static auto offset = MemberOffsets.find(STR("bCanBeDamaged"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bCanBeDamaged' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbCanBeDamaged() const
{
    static auto offset = MemberOffsets.find(STR("bCanBeDamaged"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bCanBeDamaged' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbCanBeInCluster()
{
    static auto offset = MemberOffsets.find(STR("bCanBeInCluster"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bCanBeInCluster' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbCanBeInCluster() const
{
    static auto offset = MemberOffsets.find(STR("bCanBeInCluster"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bCanBeInCluster' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbCollideWhenPlacing()
{
    static auto offset = MemberOffsets.find(STR("bCollideWhenPlacing"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bCollideWhenPlacing' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbCollideWhenPlacing() const
{
    static auto offset = MemberOffsets.find(STR("bCollideWhenPlacing"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bCollideWhenPlacing' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbEnableAutoLODGeneration()
{
    static auto offset = MemberOffsets.find(STR("bEnableAutoLODGeneration"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bEnableAutoLODGeneration' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbEnableAutoLODGeneration() const
{
    static auto offset = MemberOffsets.find(STR("bEnableAutoLODGeneration"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bEnableAutoLODGeneration' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbExchangedRoles()
{
    static auto offset = MemberOffsets.find(STR("bExchangedRoles"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bExchangedRoles' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbExchangedRoles() const
{
    static auto offset = MemberOffsets.find(STR("bExchangedRoles"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bExchangedRoles' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbFindCameraComponentWhenViewTarget()
{
    static auto offset = MemberOffsets.find(STR("bFindCameraComponentWhenViewTarget"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bFindCameraComponentWhenViewTarget' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbFindCameraComponentWhenViewTarget() const
{
    static auto offset = MemberOffsets.find(STR("bFindCameraComponentWhenViewTarget"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bFindCameraComponentWhenViewTarget' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbForceNetAddressable()
{
    static auto offset = MemberOffsets.find(STR("bForceNetAddressable"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bForceNetAddressable' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbForceNetAddressable() const
{
    static auto offset = MemberOffsets.find(STR("bForceNetAddressable"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bForceNetAddressable' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbGenerateOverlapEventsDuringLevelStreaming()
{
    static auto offset = MemberOffsets.find(STR("bGenerateOverlapEventsDuringLevelStreaming"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bGenerateOverlapEventsDuringLevelStreaming' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbGenerateOverlapEventsDuringLevelStreaming() const
{
    static auto offset = MemberOffsets.find(STR("bGenerateOverlapEventsDuringLevelStreaming"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bGenerateOverlapEventsDuringLevelStreaming' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbHasDeferredComponentRegistration()
{
    static auto offset = MemberOffsets.find(STR("bHasDeferredComponentRegistration"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bHasDeferredComponentRegistration' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbHasDeferredComponentRegistration() const
{
    static auto offset = MemberOffsets.find(STR("bHasDeferredComponentRegistration"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bHasDeferredComponentRegistration' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbHasFinishedSpawning()
{
    static auto offset = MemberOffsets.find(STR("bHasFinishedSpawning"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bHasFinishedSpawning' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbHasFinishedSpawning() const
{
    static auto offset = MemberOffsets.find(STR("bHasFinishedSpawning"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bHasFinishedSpawning' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbHasRegisteredAllComponents()
{
    static auto offset = MemberOffsets.find(STR("bHasRegisteredAllComponents"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bHasRegisteredAllComponents' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbHasRegisteredAllComponents() const
{
    static auto offset = MemberOffsets.find(STR("bHasRegisteredAllComponents"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bHasRegisteredAllComponents' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbHidden()
{
    static auto offset = MemberOffsets.find(STR("bHidden"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bHidden' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbHidden() const
{
    static auto offset = MemberOffsets.find(STR("bHidden"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bHidden' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbIgnoresOriginShifting()
{
    static auto offset = MemberOffsets.find(STR("bIgnoresOriginShifting"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bIgnoresOriginShifting' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbIgnoresOriginShifting() const
{
    static auto offset = MemberOffsets.find(STR("bIgnoresOriginShifting"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bIgnoresOriginShifting' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbIsEditorOnlyActor()
{
    static auto offset = MemberOffsets.find(STR("bIsEditorOnlyActor"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bIsEditorOnlyActor' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbIsEditorOnlyActor() const
{
    static auto offset = MemberOffsets.find(STR("bIsEditorOnlyActor"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bIsEditorOnlyActor' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbNetCheckedInitialPhysicsState()
{
    static auto offset = MemberOffsets.find(STR("bNetCheckedInitialPhysicsState"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bNetCheckedInitialPhysicsState' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbNetCheckedInitialPhysicsState() const
{
    static auto offset = MemberOffsets.find(STR("bNetCheckedInitialPhysicsState"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bNetCheckedInitialPhysicsState' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbNetLoadOnClient()
{
    static auto offset = MemberOffsets.find(STR("bNetLoadOnClient"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bNetLoadOnClient' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbNetLoadOnClient() const
{
    static auto offset = MemberOffsets.find(STR("bNetLoadOnClient"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bNetLoadOnClient' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbNetStartup()
{
    static auto offset = MemberOffsets.find(STR("bNetStartup"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bNetStartup' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbNetStartup() const
{
    static auto offset = MemberOffsets.find(STR("bNetStartup"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bNetStartup' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbNetTemporary()
{
    static auto offset = MemberOffsets.find(STR("bNetTemporary"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bNetTemporary' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbNetTemporary() const
{
    static auto offset = MemberOffsets.find(STR("bNetTemporary"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bNetTemporary' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbNetUseOwnerRelevancy()
{
    static auto offset = MemberOffsets.find(STR("bNetUseOwnerRelevancy"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bNetUseOwnerRelevancy' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbNetUseOwnerRelevancy() const
{
    static auto offset = MemberOffsets.find(STR("bNetUseOwnerRelevancy"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bNetUseOwnerRelevancy' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbOnlyRelevantToOwner()
{
    static auto offset = MemberOffsets.find(STR("bOnlyRelevantToOwner"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bOnlyRelevantToOwner' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbOnlyRelevantToOwner() const
{
    static auto offset = MemberOffsets.find(STR("bOnlyRelevantToOwner"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bOnlyRelevantToOwner' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbPendingNetUpdate()
{
    static auto offset = MemberOffsets.find(STR("bPendingNetUpdate"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bPendingNetUpdate' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbPendingNetUpdate() const
{
    static auto offset = MemberOffsets.find(STR("bPendingNetUpdate"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bPendingNetUpdate' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbRelevantForLevelBounds()
{
    static auto offset = MemberOffsets.find(STR("bRelevantForLevelBounds"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bRelevantForLevelBounds' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbRelevantForLevelBounds() const
{
    static auto offset = MemberOffsets.find(STR("bRelevantForLevelBounds"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bRelevantForLevelBounds' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbRelevantForNetworkReplays()
{
    static auto offset = MemberOffsets.find(STR("bRelevantForNetworkReplays"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bRelevantForNetworkReplays' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbRelevantForNetworkReplays() const
{
    static auto offset = MemberOffsets.find(STR("bRelevantForNetworkReplays"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bRelevantForNetworkReplays' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbReplayRewindable()
{
    static auto offset = MemberOffsets.find(STR("bReplayRewindable"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bReplayRewindable' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbReplayRewindable() const
{
    static auto offset = MemberOffsets.find(STR("bReplayRewindable"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bReplayRewindable' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbReplicateMovement()
{
    static auto offset = MemberOffsets.find(STR("bReplicateMovement"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bReplicateMovement' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbReplicateMovement() const
{
    static auto offset = MemberOffsets.find(STR("bReplicateMovement"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bReplicateMovement' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbReplicateUsingRegisteredSubObjectList()
{
    static auto offset = MemberOffsets.find(STR("bReplicateUsingRegisteredSubObjectList"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bReplicateUsingRegisteredSubObjectList' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbReplicateUsingRegisteredSubObjectList() const
{
    static auto offset = MemberOffsets.find(STR("bReplicateUsingRegisteredSubObjectList"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bReplicateUsingRegisteredSubObjectList' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbReplicates()
{
    static auto offset = MemberOffsets.find(STR("bReplicates"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bReplicates' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbReplicates() const
{
    static auto offset = MemberOffsets.find(STR("bReplicates"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bReplicates' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbRunningUserConstructionScript()
{
    static auto offset = MemberOffsets.find(STR("bRunningUserConstructionScript"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bRunningUserConstructionScript' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbRunningUserConstructionScript() const
{
    static auto offset = MemberOffsets.find(STR("bRunningUserConstructionScript"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bRunningUserConstructionScript' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbTearOff()
{
    static auto offset = MemberOffsets.find(STR("bTearOff"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bTearOff' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbTearOff() const
{
    static auto offset = MemberOffsets.find(STR("bTearOff"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bTearOff' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

uint8& AActor::GetbTickFunctionsRegistered()
{
    static auto offset = MemberOffsets.find(STR("bTickFunctionsRegistered"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bTickFunctionsRegistered' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<uint8*>(this, offset->second);
}
const uint8& AActor::GetbTickFunctionsRegistered() const
{
    static auto offset = MemberOffsets.find(STR("bTickFunctionsRegistered"));
    if (offset == MemberOffsets.end()) { throw std::runtime_error{"Tried getting member variable 'AActor::bTickFunctionsRegistered' that doesn't exist in this engine version."}; }
    return *Helper::Casting::ptr_cast<const uint8*>(this, offset->second);
}

