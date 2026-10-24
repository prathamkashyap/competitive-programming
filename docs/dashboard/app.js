// Dashboard application
let externalStats = null;
let problemIndex = null;
let filteredProblems = [];

// Load data on page load
document.addEventListener('DOMContentLoaded', async () => {
    await loadData();
    setupEventListeners();
});

async function loadData() {
    try {
        // Load external stats
        const statsResponse = await fetch('../generated/external-stats.json');
        externalStats = await statsResponse.json();
        renderStats();

        // Load problem index
        const problemsResponse = await fetch('../generated/problem-index.json');
        problemIndex = await problemsResponse.json();
        filteredProblems = problemIndex.problems;
        renderProblems();
        populateFilters();
    } catch (error) {
        console.error('Error loading data:', error);
        document.getElementById('stats-loading').textContent = 'Error loading statistics';
        document.getElementById('problems-loading').textContent = 'Error loading problems';
    }
}

function renderStats() {
    const container = document.getElementById('stats-container');
    document.getElementById('stats-loading').style.display = 'none';

    if (!externalStats || externalStats.length === 0) {
        container.innerHTML = '<p>No statistics available</p>';
        return;
    }

    const html = externalStats.map(stat => {
        const platform = stat.platform.toLowerCase();
        const metrics = stat.metrics || {};
        const statusClass = stat.source_type === 'live' ? 'status-live' : 'status-snapshot';
        const statusText = stat.source_type === 'live' ? '🟢 Live' : '📸 Snapshot';

        let detailHtml = '';
        if (platform === 'leetcode') {
            detailHtml = `
                <div class="stat-detail">${metrics.solved || 0} solved</div>
                <div class="stat-detail">${metrics.easy || 0}E / ${metrics.medium || 0}M / ${metrics.hard || 0}H</div>
                ${metrics.streak_days ? `<div class="stat-detail">${metrics.streak_days} day streak</div>` : ''}
            `;
        } else if (platform === 'codeforces') {
            detailHtml = `
                <div class="stat-detail">Rating: ${metrics.rating || 'N/A'} (${metrics.rank || 'N/A'})</div>
                <div class="stat-detail">${metrics.solved || 0} solved</div>
            `;
        } else if (platform === 'codechef') {
            detailHtml = `
                <div class="stat-detail">Rating: ${metrics.rating || 'N/A'} (★${metrics.stars || 0})</div>
                <div class="stat-detail">${metrics.solved || 0} solved</div>
                ${metrics.league ? `<div class="stat-detail">${metrics.league}</div>` : ''}
            `;
        } else if (platform === 'hackerrank') {
            detailHtml = `
                <div class="stat-detail">${metrics.total_stars || 0} stars</div>
                <div class="stat-detail">${metrics.total_challenges_solved || 0} solved</div>
            `;
        } else if (platform === 'hackerearth') {
            detailHtml = `
                <div class="stat-detail">${metrics.points || 0} points</div>
                <div class="stat-detail">${metrics.solved || 0} solved</div>
            `;
        } else if (platform === 'geeksforgeeks') {
            detailHtml = `
                <div class="stat-detail">Score: ${metrics.coding_score || 0}</div>
                <div class="stat-detail">${metrics.solved || 0} solved</div>
            `;
        } else {
            detailHtml = `<div class="stat-detail">Platform data available</div>`;
        }

        return `
            <div class="stat-card">
                <h3>${stat.platform}</h3>
                <div class="stat-value">${Object.keys(metrics).length > 0 ? 'Active' : 'N/A'}</div>
                ${detailHtml}
                <span class="status-badge ${statusClass}">${statusText}</span>
            </div>
        `;
    }).join('');

    container.innerHTML = html;
}

function renderProblems() {
    const tbody = document.getElementById('problems-body');
    document.getElementById('problems-loading').style.display = 'none';
    document.getElementById('results-count').textContent = `Showing ${filteredProblems.length} of ${problemIndex.total_problems} problems`;

    if (filteredProblems.length === 0) {
        tbody.innerHTML = '<tr><td colspan="6" style="text-align: center; padding: 40px;">No problems match your filters</td></tr>';
        return;
    }

    const html = filteredProblems.map(problem => {
        const platform = problem.platform || 'unknown';
        const code = problem.code || '-';
        const title = problem.title || '';
        const rating = problem.rating || null;
        const language = problem.language || 'other';
        const path = problem.path || '';

        // Generate GitHub URL
        const githubUrl = `https://github.com/prathamkashyap/competitive-programming/blob/main/${path}`;

        // Rating badge class
        let ratingClass = '';
        if (rating) {
            if (rating < 1200) ratingClass = 'rating-800-1200';
            else if (rating < 1400) ratingClass = 'rating-1200-1400';
            else if (rating < 1600) ratingClass = 'rating-1400-1600';
            else if (rating < 1800) ratingClass = 'rating-1600-1800';
            else if (rating < 2000) ratingClass = 'rating-1800-2000';
            else ratingClass = 'rating-2000';
        }

        return `
            <tr>
                <td><span class="platform-badge platform-${platform}">${platform}</span></td>
                <td><code>${code}</code></td>
                <td>${title || '<em style="color: #999;">No title</em>'}</td>
                <td>${rating ? `<span class="rating-badge ${ratingClass}">${rating}</span>` : '-'}</td>
                <td><span class="language-badge language-${language}">${language}</span></td>
                <td><a href="${githubUrl}" target="_blank">View Solution →</a></td>
            </tr>
        `;
    }).join('');

    tbody.innerHTML = html;
}

function populateFilters() {
    const platformSelect = document.getElementById('platform');
    const platforms = [...new Set(problemIndex.problems.map(p => p.platform))].sort();
    platforms.forEach(platform => {
        const option = document.createElement('option');
        option.value = platform;
        option.textContent = platform.charAt(0).toUpperCase() + platform.slice(1);
        platformSelect.appendChild(option);
    });
}

function setupEventListeners() {
    const searchInput = document.getElementById('search');
    const platformSelect = document.getElementById('platform');
    const ratingSelect = document.getElementById('rating');
    const languageSelect = document.getElementById('language');
    const randomBtn = document.getElementById('random-btn');
    const clearBtn = document.getElementById('clear-btn');

    searchInput.addEventListener('input', applyFilters);
    platformSelect.addEventListener('change', applyFilters);
    ratingSelect.addEventListener('change', applyFilters);
    languageSelect.addEventListener('change', applyFilters);
    randomBtn.addEventListener('click', pickRandomProblem);
    clearBtn.addEventListener('click', clearFilters);
}

function applyFilters() {
    const search = document.getElementById('search').value.toLowerCase();
    const platform = document.getElementById('platform').value;
    const ratingRange = document.getElementById('rating').value;
    const language = document.getElementById('language').value;

    filteredProblems = problemIndex.problems.filter(problem => {
        // Search filter
        if (search) {
            const code = (problem.code || '').toLowerCase();
            const title = (problem.title || '').toLowerCase();
            const path = (problem.path || '').toLowerCase();
            if (!code.includes(search) && !title.includes(search) && !path.includes(search)) {
                return false;
            }
        }

        // Platform filter
        if (platform && problem.platform !== platform) {
            return false;
        }

        // Rating filter
        if (ratingRange && problem.rating) {
            const rating = problem.rating;
            if (ratingRange === '800-1200' && (rating < 800 || rating > 1200)) return false;
            if (ratingRange === '1200-1400' && (rating < 1200 || rating > 1400)) return false;
            if (ratingRange === '1400-1600' && (rating < 1400 || rating > 1600)) return false;
            if (ratingRange === '1600-1800' && (rating < 1600 || rating > 1800)) return false;
            if (ratingRange === '1800-2000' && (rating < 1800 || rating > 2000)) return false;
            if (ratingRange === '2000+' && rating < 2000) return false;
        } else if (ratingRange && !problem.rating) {
            return false;
        }

        // Language filter
        if (language && problem.language !== language) {
            return false;
        }

        return true;
    });

    renderProblems();
}

function pickRandomProblem() {
    if (filteredProblems.length === 0) {
        alert('No problems to choose from. Try clearing your filters.');
        return;
    }

    const randomIndex = Math.floor(Math.random() * filteredProblems.length);
    const problem = filteredProblems[randomIndex];
    const path = problem.path || '';
    const githubUrl = `https://github.com/prathamkashyap/competitive-programming/blob/main/${path}`;

    // Open in new tab
    window.open(githubUrl, '_blank');
}

function clearFilters() {
    document.getElementById('search').value = '';
    document.getElementById('platform').value = '';
    document.getElementById('rating').value = '';
    document.getElementById('language').value = '';
    applyFilters();
}
