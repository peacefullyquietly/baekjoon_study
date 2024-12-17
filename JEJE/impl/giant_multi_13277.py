# SPDX-License-Identifier: AGPL-3.0-or-later
# NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
from functools import reduce
print(reduce(lambda x, y: x * y, map(int,input().split())))