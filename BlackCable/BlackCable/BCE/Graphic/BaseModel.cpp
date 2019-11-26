
#include "BaseModel.h"

namespace BCE
{
	namespace Graphics
	{
		void BaseModel::SetTransform(Transform* _transform)
		{
			transform = _transform;
		}

		BaseModel::BaseModel()
		{
			transform = nullptr;
		}

	}
}