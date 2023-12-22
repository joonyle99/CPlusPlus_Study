#include <algorithm>
#include <cmath>

struct Vector2
{
    float x, y;
};

struct Circle
{
    Vector2 center;
    float radius;
};

struct AABB
{
    Vector2 min, max; // min is top-left, max is bottom-right in this case
};

struct CollisionInfo
{
    Vector2 normal;
    float penetrationDepth;
};

bool TestCircleAABBCollision(const Circle& circle, const AABB& aabb, CollisionInfo& collisionInfo)
{
    // Find the point on the AABB closest to the circle center
    Vector2 closestPoint;
    closestPoint.x = std::max(aabb.min.x, std::min(circle.center.x, aabb.max.x));
    closestPoint.y = std::min(aabb.min.y, std::max(circle.center.y, aabb.max.y));

    // Calculate the direction and distance from the circle center to the closest point
    Vector2 direction = { closestPoint.x - circle.center.x, closestPoint.y - circle.center.y };
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    // If the distance is less than the circle's radius then they are colliding
    if (distance < circle.radius)
    {
        collisionInfo.normal = direction;
        collisionInfo.penetrationDepth = circle.radius - distance;
        return true;
    }

    return false;
}

int main()
{





    return 0;
}