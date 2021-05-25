while (true) {
    let n = parseInt(readline());
    if (n === 0)
        break;
    
    let voteCount = {};
    for (let i = 0; i < n; ++i) {
        let [d, ...votes] = readline().split(' ').map(x => parseInt(x));
        for (let j = 0; j < d; ++j) {
            chef = votes[j];
            voteCount[chef] = (voteCount[chef] || 0) + 3 - j;
        }
    }

    let maxVote = -1;
    let winners = Object.keys(voteCount).sort().reduce((res, chef) => {
        let vote = voteCount[chef];
        if (vote > maxVote) {
            maxVote = vote;
            return [chef];
        }
        if (vote === maxVote)
            return [...res, chef];
        return res;
    }, []);

    let res = winners.join(' ');
    console.log(res)
}
