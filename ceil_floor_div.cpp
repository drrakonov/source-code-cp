// Seem Doubtful and Correct at the same time

ll ceil_div(ll a, ll b)
{
    return a / b + ((a ^ b > 0) && (a % b != 0));
}

ll floor_div(ll a, ll b)
{
    return a / b - ((a ^ b < 0) && (a % b != 0));
}

ll floor_div(ll a, ll b)
{
    return a / b - (a % b != 0 && ((a < 0) != (b < 0)));
}

ll ceil_div(ll a, ll b)
{
    return a / b + (a % b != 0 && ((a < 0) == (b < 0)));
}