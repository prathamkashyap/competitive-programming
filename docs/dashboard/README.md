# Interactive Dashboard

This directory contains a lightweight, static interactive dashboard for browsing competitive programming solutions and viewing live platform statistics.

## Features

- **Live Statistics Panel**: Displays real-time stats from Codeforces, LeetCode, CodeChef, HackerRank, HackerEarth, and GeeksforGeeks
- **Searchable Problem Browser**: Filter and search through all solutions in the repository
- **Random Problem Button**: Get a random problem from your filtered results
- **Mobile-Friendly**: Responsive design that works on all devices
- **Zero Dependencies**: Pure HTML, CSS, and JavaScript - no build step required

## File Structure

```
docs/dashboard/
├── index.html    # Main dashboard page
├── styles.css    # Responsive styling
├── app.js        # Client-side logic for data loading and filtering
└── README.md     # This file
```

## Data Sources

The dashboard reads from auto-generated JSON files:

- `../generated/external-stats.json` - Live platform statistics
- `../generated/problem-index.json` - Complete problem index with metadata

These files are regenerated automatically by GitHub Actions and local scripts.

## How It Works

1. **Data Loading**: `app.js` fetches JSON files on page load using the Fetch API
2. **Rendering**: Stats and problems are rendered dynamically based on the loaded data
3. **Filtering**: Client-side filtering allows instant search without server requests
4. **Linking**: Each problem links directly to its solution file on GitHub

## Local Development

To test the dashboard locally:

```bash
# Start a simple HTTP server
python3 -m http.server 8000 --directory docs

# Then open in browser
open http://localhost:8000/dashboard/
```

Or use any static file server (e.g., VS Code Live Server extension).

## GitHub Pages Setup

To enable GitHub Pages for this dashboard:

1. Go to repository Settings → Pages
2. Select "Deploy from a branch"
3. Choose branch: `main` (or your default branch)
4. Set folder to `/docs`
5. Click Save

After a few minutes, your dashboard will be available at:
```
https://prathamkashyap.github.io/competitive-programming/dashboard/
```

## Updating the Dashboard

The dashboard automatically updates when:
- External stats are regenerated (daily via GitHub Actions or manually)
- Problem index is regenerated (when new solutions are added)

No manual changes to dashboard files are needed for data updates.

## Customization

- **Styling**: Edit `styles.css` to change colors, layout, or design
- **Features**: Edit `app.js` to add new filtering options or display logic
- **Layout**: Edit `index.html` to restructure the page

## Browser Compatibility

Works in all modern browsers:
- Chrome/Edge (latest)
- Firefox (latest)
- Safari (latest)
- Mobile browsers
