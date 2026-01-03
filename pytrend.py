from pytrends.request import TrendReq
import pandas as pd

# Connect to Google Trends
pytrends = TrendReq(hl='en-US', tz=360)

# Get the daily trending searches for the US
df = pytrends.trending_searches(pn='united_states')

# Print the top 10 trends
print(df.head(10))