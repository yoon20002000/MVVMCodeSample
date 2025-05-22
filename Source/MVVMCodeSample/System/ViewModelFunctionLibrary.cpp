#include "ViewModelFunctionLibrary.h"

FName UViewModelFunctionLibrary::GetContextName(EViewModelContext Context)
{
	switch (Context)
	{
	case EViewModelContext::Health:
		{
			return FName(TEXT("HealthViewModel"));
		}
	case EViewModelContext::ShootState:
		{
			return FName(TEXT("ShootState"));
		}
		default:
		{
			return NAME_None;
		}
	}
}
